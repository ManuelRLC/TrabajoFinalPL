/*! 
  \file interpreter.cpp
  \brief Main program
*/

/*!
 \mainpage Interprete en español
 \author   Jorge Zafra Palma
 \author   Manuel Luque Cuesta
 \date     2019 - 05 - 25
 \version  2.0
*/



// New in example 2
#include <stdio.h>
#include <string>
//

/////////////////////////////
/* 
  AST class
  IMPORTANT: must be written before interpreter.tab.h
*/
#include "ast/ast.hpp"
////////////////////////////////////////

#include "./parser/interpreter.tab.h"

int lineNumber = 1; //!< Line counter

bool interactiveMode; //!< Control the interactive mode of execution of the interpreter
int sentenciaDeControl; //!< External control statement

extern FILE * yyin; //!< Standard input device for yylex() 
std::string progname; //!<  Program name
//


//////////////////////////////////////////////

// Use for recovery of runtime errors 
#include <setjmp.h>
#include <signal.h>

// Error recovery functions 
#include "error/error.hpp"


lp::AST *root; //!< Root of the abstract syntax tree AST
///////////////////////////////////////////// 

//////////////////////////////////////////////

#include "table/init.hpp"


/*
 jhmp_buf
    This is an array type capable of storing the information of a calling environment to be restored later.
   This information is filled by calling macro setjmp and can be restored by calling function longjmp.
*/
extern jmp_buf begin; //!<  It enables recovery of runtime errors 

//////////////////////////////////////////////

#include "table/table.hpp"

lp::Table table; //!< Table of Symbols



// cout.precision
#include <iostream>
//////////////////////////////////////////////////

//! \name Main program

/*! 
	\brief  Main function
	\param  argc: number of command line parameters
	\param  argv: values of command line parameters
	\return int
	\note   C++ requires that main returns an int value
	\sa     yyparse, yylex
*/
int main(int argc, char *argv[])
{
 // Option -t needed
 // yydebug = 1;
 
 /* 
   If the input file exists 
      then 
           it is set as input device for yylex();
      otherwise
            the input device is the keyboard (stdin)
 */

 if (argc == 2) 
 {
  bool comprobar = false;


    for(int i=0; argv[1][i]!='\0';i++){

      if(argv[1][i]=='.'){
        
        if(argv[1][i+1]!='\0'){

          if(argv[1][i+1]=='e' && argv[1][i+2]=='\0'){
            comprobar =true;
          }
        }
      }
    }

    if(!comprobar){

      std::cout<<"La extensión del fichero no es correcta. Se necesita extesión .e"<<std::endl;

      exit(-1);
    }

     yyin = fopen(argv[1],"r");

     if(yyin ==NULL){
      std::cout<<"El fichero introducido no existe"<<std::endl;
      exit(-1);
     }



	 interactiveMode = false;
 }
else
 {
	interactiveMode = true;
 }
 sentenciaDeControl=0;

 // Copy the name of the interpreter 
	progname = argv[0];

 /* Number of decimal places */ 
 std::cout.precision(7);

 /* 
   Table of symbols initialization 
   Must be written before the recovery sentence: setjmp
 */
   init(table);

/* Sets a viable state to continue after a runtime error */
 setjmp(begin);

 /* The name of the function to handle floating-point errors is set */
 signal(SIGFPE,fpecatch);

 // Parser function
  yyparse();

 if (interactiveMode == false)
 {
  /*  root->print(); */
  if (root!=NULL)
        root->evaluate();
 }

 /* End of program */
 return 0;
}



