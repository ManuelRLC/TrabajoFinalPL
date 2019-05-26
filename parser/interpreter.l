/*! 
  \file interpreter.l
  \brief Lexical or scanner file
*/
%{
#include <iostream>

/*********************/
/* atof */
#include <stdlib.h>
/*********************/

/* Macros for the screen */
#include "../includes/macros.hpp"

/*********************/
/* 
  AST class
  IMPORTANT: must be written before interpreter.tab.h
*/
#include "../ast/ast.hpp"
/*********************/

/*  interpreter.tab.h contains the numeric values of the tokens produced by the parser */
#include "interpreter.tab.h"

/********************/
#include "../error/error.hpp"
/********************/


/*********************************************/
/* Table of symbols */
#include "../table/table.hpp"

#include "../table/numericVariable.hpp"

#include "../parser/funcionesAuxiliares.hpp"

extern lp::Table table; //!< External Table of Symbols
/*********************************************/

extern int lineNumber; //!< External line counter

extern int sentenciaDeControl; //!< External control statement

extern bool interactiveMode; //!< Control the interactive mode of execution of the interpreter


%}


/*! \name REGULAR DEFINITIONS  */

DIGIT  [0-9] 

LETTER [a-zA-Z]

NUMBER1 {DIGIT}+\.?(E[+\-]?{DIGIT}+)?

NUMBER2 {DIGIT}*\.{DIGIT}+(E[+\-]?{DIGIT}+)?

IDENTIFIER  {LETTER}({LETTER}|{DIGIT}|_({LETTER}|{DIGIT}))*

IDENTIFIER_INVALID ({LETTER}|{DIGIT}|_)+

NUMBER_INVALID 	({DIGIT}+(\.{DIGIT}*)+)?(E[+\-]?{DIGIT}+)?

/* STATES  */
%x ERROR

%x ESTADO_CADENA

%x ESTADO_COMENTARIO


/*! \name REGULAR EXPRESSIONS  */
%%

[ \t] 	{ ; }    /* skip white space and tabular */

\n      { 
			/* Line counter */
           	lineNumber++; 
        }

";"		{
			return SEMICOLON;
		}

":"		{
			return COLON;
		}


","		{
			return COMMA;
		}

{NUMBER1}|{NUMBER2}  {
						/* Conversion of type and sending of the numerical value to the parser */
						yylval.number = atof(yytext); 

						return NUMBER; 
                     }

{IDENTIFIER}   		 {
						changeStringToLower(yytext);

						std::string identifier(yytext);

						/* 
						strdup() function returns a pointer to a new string 
						which  is a duplicate of the string yytext
						*/
						yylval.identifier =  strdup(yytext); 


						/* If the identifier is not in the table of symbols then it is inserted */	
						if (table.lookupSymbol(identifier) == false){
							/* 
							 The identifier is inserted into the symbol table 
							 as undefined Variable with value 0.0
							*/
							lp::NumericVariable *n = new lp::NumericVariable(identifier,VARIABLE,UNDEFINED,0.0);

							/* A pointer to the new NumericVariable is inserted into the table of symbols */
							table.installSymbol(n);

							return VARIABLE;
						}

						/* 
							If the identifier is in the table of symbols then its token is returned 
								The identifier can be a variable or a numeric constant
						*/
						else{

							lp::Symbol	*s = table.getSymbol(identifier);

							if(interactiveMode){
						  		if(isSentenciaControl(s->getToken())){
						  			sentenciaDeControl++;
						  		}
						  		if(isFinSentenciaControl(s->getToken())){
						  			sentenciaDeControl--;
						  		}  									
							}

							/*  If the identifier is in the table then its token is returned  */
							return s->getToken();

						}
                     }

"'"						{BEGIN ESTADO_CADENA;}

<ESTADO_CADENA>"'" 		{	BEGIN 0;
						 	yytext[yyleng-1]='\0';

						 	yylval.str =  new std::string(parseSlash(yytext,yyleng));
						 	return STRING;
						}

<ESTADO_CADENA>"\\\'"	{yymore();}


<ESTADO_CADENA>.|\n 	{yymore();}


"#"					{BEGIN ESTADO_COMENTARIO;}

<ESTADO_COMENTARIO>"#" {BEGIN 0;}


<ESTADO_COMENTARIO>. {;}

<ESTADO_COMENTARIO>\n {lineNumber++;}


@.+$					{;}


"--"		{ return MINUS2;  } 			
"++"		{ return PLUS2;   } 			
                     
"-"		{ return MINUS;  } 			
"+"		{ return PLUS;   } 			

"*"	    { return MULTIPLICATION; }
"/" 	{ return DIVISION; }
(?i:_div)     { return INTEGER_DIVISION; } 		

"("     { return LPAREN; } 		
")"	    { return RPAREN; } 			


(?i:_mod)    { return MODULO; }			

"**"	    { return POWER; }			

":=" 	{ return ASSIGNMENT; }		

"+:=" 	{ return PLUS_ASSIGNMENT; }	

"-:=" 	{ return MINUS_ASSIGNMENT; }	

"*:=" 	{ return MULTIPLICATION_ASSIGNMENT; }	

"/:=" 	{ return DIVISION_ASSIGNMENT; }	


"="	{ return EQUAL; }			

"<>"	{ return NOT_EQUAL; }		

">="	{ return GREATER_OR_EQUAL; }

"<="	{ return LESS_OR_EQUAL; }	

">"		{ return GREATER_THAN; }	

"<"		{ return LESS_THAN; }		

"||"    {return CONCATENATE; }

(?i:_no)		{ return NOT; }				

(?i:_o)	{ return OR; }				

(?i:_y)	{ return AND; }				

(?i:_borrar)	{ return ERASE; }

(?i:_lugar)		{ return PLACE; }


<<EOF>> { return 0; }


{IDENTIFIER_INVALID} {warning("Identificador invalido",yytext);}

{NUMBER_INVALID} {warning("Número invalido",yytext);}

.	{ 	
		/* Any other character */
		/* Change to error state */
		BEGIN(ERROR); 

		/* 
			The current value of yytext 
			will be concatenated with the next character
		*/
		yymore();  
	}

<ERROR>[^0-9+\-*/()\^% \t\n\;a-zA-Z=<>!&]	{
											  /* 
												The current value of yytext 
												will be concatenated with the next character
											  */
												yymore(); 
											}

<ERROR>(.|\n)	{ 
					/* Rewind one position */
					yyless(yyleng-1); 

					/* Display the error message */
					warning("Error léxico", yytext);

					/* Restore the initial state */
						BEGIN(INITIAL);
				}
%%



