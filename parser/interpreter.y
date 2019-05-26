/*! 
  \file interpreter.y
  \brief Grammar file
*/

%{
#include <iostream>
#include <string>

/*******************************************/
/* pow */
#include <math.h>
/*******************************************/

/*******************************************/
/* Use for recovery of runtime errors */
#include <setjmp.h>
#include <signal.h>
/*******************************************/

/* Error recovery functions */
#include "../error/error.hpp"

/* Macros for the screen */
#include "../includes/macros.hpp"


/*******************************************/
/* 
  AST class
  IMPORTANT: this file must be before init.hpp
*/
#include "../ast/ast.hpp"


/*******************************************/
/* Table of symbol */
#include "../table/table.hpp"
/*******************************************/

/*******************************************/
#include "../table/numericVariable.hpp"
/*******************************************/

#include "../table/logicalVariable.hpp"

/*******************************************/
#include "../table/stringVariable.hpp"

/*******************************************/
#include "../table/numericConstant.hpp"
/*******************************************/

/*******************************************/
#include "../table/logicalConstant.hpp"
/*******************************************/

/*******************************************/
#include "../table/builtinParameter1.hpp"
/*******************************************/

/*******************************************/
#include "../table/builtinParameter0.hpp"
#include "../table/builtinParameter2.hpp"
/*******************************************/


/*******************************************/
#include "../table/init.hpp"
/*******************************************/

#include "funcionesAuxiliares.hpp"

/*! 
	\brief  Lexical or scanner function
	\return int
	\note   C++ requires that yylex returns an int value
	\sa     yyparser
*/
int yylex();

extern int lineNumber; //!< External line counter

extern bool interactiveMode; //!< Control the interactive mode of execution of the interpreter

extern int sentenciaDeControl; //!< External control statement

/***********************************************************/
extern std::string progname; //!<  Program name
/***********************************************************/

/*******************************************/
/*
 jhmp_buf
    This is an array type capable of storing the information of a calling environment to be restored later.
   This information is filled by calling macro setjmp and can be restored by calling function longjmp.
*/
jmp_buf begin; //!<  It enables recovery of runtime errors 
/*******************************************/


/*******************************************/

extern lp::Table table; //!< Extern Table of Symbols

/*******************************************/

extern lp::AST *root; //!< External root of the abstract syntax tree AST

%}

/* In case of a syntactic error, more information is shown */
%error-verbose

/* Initial grammar symbol */
%start program

/*******************************************/
/* Data type YYSTYPE  */
%union {
  char * identifier; 				
  double number;  
  bool logic;						 
  std::string *str;
  lp::ExpNode *expNode;  			 
  std::list<lp::ExpNode *>  *parameters;    
  lp::StatementList *stmts; 
  lp::Statement *st;				 
  lp::AST *prog;					
  lp::CaseList *cases;
  lp::Case *value;

}

/* Type of the non-terminal symbols */
%type <expNode> exp cond unary

%type <parameters> listOfExp  restOfListOfExp

%type <stmts> stmtlist

%type <cases> listOfCase

%type <value> case

%type <st> stmt asgn print read if while repeat for erase place switch

%type <prog> program

// Defined token 

/* Minimum precedence */

/*******************************************/
%token SEMICOLON COLON
/*******************************************/

%token PRINT READ READ_STRING IF THEN ELSE ENDIF WHILE DO ENDWHILE REPEAT UNTIL FOR FROM STEP ENDFOR ERASE PLACE SWITCH DEFAULT ENDSWITCH VALUE

%right ASSIGNMENT PLUS_ASSIGNMENT MINUS_ASSIGNMENT MULTIPLICATION_ASSIGNMENT DIVISION_ASSIGNMENT

%token COMMA

/*******************************************/
%token <number> NUMBER
/*******************************************/
%token <str> STRING
/*******************************************/
%token <logic> BOOL
/*******************************************/

%token <identifier> VARIABLE UNDEFINED CONSTANT BUILTIN

/* Left associativity */

/*******************************************************/
%left OR

%left AND

%left CONCATENATE 

%nonassoc GREATER_OR_EQUAL LESS_OR_EQUAL GREATER_THAN LESS_THAN  EQUAL NOT_EQUAL

%left NOT
/*******************************************************/

%left PLUS MINUS PLUS2 MINUS2

%left MULTIPLICATION INTEGER_DIVISION DIVISION MODULO

%left LPAREN RPAREN

%nonassoc  UNARY

// Maximum precedence 
%right POWER


%%
//! \name Grammar rules

program : stmtlist
		  { 
		    // Create a new AST
			$$ = new lp::AST($1); 

			// Assign the AST to the root
			root = $$; 

			// End of parsing
			//	return 1;
		  }
;

stmtlist:  /* empty: epsilon rule */
		  { 

			// create a empty list of statements
		  	$$ = new lp::StatementList();
		  }  

        | stmtlist stmt 
		  { 

			// copy up the list and add the stmt to it
			$$ = $1;

			$$->addStatement($2);

			// Control the interative mode of execution of the interpreter
			if (interactiveMode == true && sentenciaDeControl==0)
 			   $2->evaluate();

           }

        | stmtlist error 
           { 
			// just copy up the stmtlist when an error occurs
			$$ = $1;

			// The previous look-ahead token ought to be discarded with `yyclearin;'
			yyclearin; 
           } 
;
 

stmt: SEMICOLON  /* Empty statement: ";" */
	  {
		// Create a new empty statement node
		$$ = new lp::EmptyStmt(); 
	  }
	| asgn  SEMICOLON
	  {
		// Default action
		// $$ = $1;
	  }
	| unary SEMICOLON
	  {
	  	$$ = new lp::AssignmentStmt((lp::UnaryVariableNode *)$1);
	  }
	| print SEMICOLON
	  {
		// Default action
		// $$ = $1;
	  }
	| read SEMICOLON
	  {
		// Default action
		// $$ = $1;
	  }
	| if 
	 {
		// Default action
		// $$ = $1;
	 }
	| while 
	 {
		// Default action
		// $$ = $1;
	 }
	| repeat
	 {
		// Default action
		// $$ = $1;	
	 }
	| for
	 {
		// Default action
		// $$ = $1;	
	 }
	| erase SEMICOLON
	 {
		// Default action
		// $$ = $1;	
	 }
	| place SEMICOLON
	 {
		// Default action
		// $$ = $1;	
	 }
	| switch
	 {
	  	// Default action
		// $$ = $1;	
	 }
;

if:	/* Simple conditional statement */
	IF cond THEN stmtlist ENDIF
    {
		// Create a new if statement node
		$$ = new lp::IfStmt($2, $4);
	}

	/* Compound conditional statement */
	| IF cond THEN stmtlist ELSE stmtlist ENDIF
	 {
		// Create a new if statement node
		$$ = new lp::IfStmt($2, $4, $6);
	 }

	| IF cond stmtlist ENDIF
	 {
	 	warning("Error sintactico: en \"sentencia SI\": falta 'ENTONCES' ","");
	 	$$ = new lp::IfStmt($2, $3);
	 }
	|  IF cond stmtlist ELSE stmtlist ENDIF
	 {
	 	warning("Error sintactico: en \"sentencia SI\": falta 'ENTONCES' ","");
	 	$$ = new lp::IfStmt($2, $3, $5);
	 }
;

while:  WHILE cond DO stmtlist ENDWHILE
		{
			// Create a new while statement node
			$$ = new lp::WhileStmt($2, $4);
        }

       | WHILE cond stmtlist ENDWHILE
        {
        	warning("Error sintactico: en \"sentencia MIENTRAS\": falta 'HACER' ","");
			$$ = new lp::WhileStmt($2, $3);
        }
;

repeat:  REPEAT stmtlist UNTIL cond
		{
			// Create a new while statement node
			$$ = new lp::RepeatStmt($2, $4);
        } 
;

for:  FOR VARIABLE FROM exp UNTIL exp STEP exp DO stmtlist ENDFOR
		{
			// Create a new for statement node
			$$ = new lp::ForStmt($2, $4, $6, $8, $10);
        } 
    |  FOR VARIABLE FROM exp UNTIL exp DO stmtlist ENDFOR
		{
			// Create a new for statement node
			$$ = new lp::ForStmt($2, $4, $6, $8);
        }
    |	FOR STRING FROM exp UNTIL exp DO stmtlist ENDFOR
    	{
    		execerror("Error sintactico: en \"el bucle para\": se esperaba una variable ","");
    	}
    |	FOR STRING FROM exp UNTIL exp STEP exp DO stmtlist ENDFOR
    	{
    		execerror("Error sintactico: en \"el bucle para\": se esperaba una variable ","");
    	}
    |	FOR NUMBER FROM exp UNTIL exp DO stmtlist ENDFOR
    	{
    		execerror("Error sintactico: en \"el bucle para\": se esperaba una variable ","");	
    	} 
    | 	FOR NUMBER FROM exp UNTIL exp STEP exp DO stmtlist ENDFOR
    	{
    		execerror("Error sintactico: en \"el bucle para\": se esperaba una variable ","");
    	}
;


switch: SWITCH LPAREN exp RPAREN listOfCase DEFAULT COLON stmtlist ENDSWITCH
		{
			//Creacion objeto de la clase switch
			$$ = new lp::SwitchStmt($3,$5,$8);
		}
	|	SWITCH LPAREN exp RPAREN listOfCase ENDSWITCH
		{
			//Creacion objeto de la clase switch
			$$ = new lp::SwitchStmt($3,$5);
		}
;

case: VALUE NUMBER COLON stmtlist
		{
			//Creacion de un objeto de la clase case
			$$ = new lp::Case($2,$4);

		}
	| VALUE NUMBER stmtlist
		{
			warning("Error sintactico: en \"sentencia SEGUN\": falta ':' en algun valor ","");
			$$ = new lp::Case($2,$3);
		}
;


listOfCase: {
				//Declaracion de una lista de casos
				$$ = new lp::CaseList();

			}
			| case listOfCase
				{

				//Ir añadidendo este caso a la lista de casos

				$$ = $2;

				$$->addCase($1);

				}
;


cond: 	LPAREN exp RPAREN
		{ 
			$$ = $2;
		}
;

erase: 	ERASE
		{ 
			$$ = new lp::EraseStmt();
		}
;

place: 	PLACE LPAREN exp COMMA exp RPAREN
		{ 
			$$ = new lp::PlaceStmt($3,$5);
		}
;


asgn:   VARIABLE ASSIGNMENT exp 
		{ 
			// Create a new assignment node
			$$ = new lp::AssignmentStmt($1, $3);

		}

	|  VARIABLE ASSIGNMENT asgn 
		{ 
			// Create a new assignment node
			$$ = new lp::AssignmentStmt($1, (lp::AssignmentStmt *) $3);
		}

	 | VARIABLE ASSIGNMENT unary
		 {
		 	$$ = new lp::AssignmentStmt($1, (lp::UnaryVariableNode *)$3);
		 }

	| VARIABLE PLUS_ASSIGNMENT exp
		{
			$$ = (lp::AssignmentStmt *)(new lp::PlusAssignmentStmt($1, $3));
		}

	| VARIABLE MINUS_ASSIGNMENT exp
		{
			$$ = (lp::AssignmentStmt *)(new lp::MinusAssignmentStmt($1, $3));
		}

	| VARIABLE MULTIPLICATION_ASSIGNMENT exp
		{
			$$ = (lp::AssignmentStmt *)(new lp::MultiplicationAssignmentStmt($1, $3));
		}

	| VARIABLE DIVISION_ASSIGNMENT exp
		{
			$$ = (lp::AssignmentStmt *)(new lp::DivisionAssignmentStmt($1, $3));
		}

	   /* NEW in example 11 */ 
	| CONSTANT ASSIGNMENT exp 
		{   
 			execerror("Error semantico en asignación: no esta permitido modificar una constante ", $1);
		}
	   /* NEW in example 11 */ 
	| CONSTANT ASSIGNMENT asgn 
		{   
 			execerror("Error semantico en asignación multiple: no esta permitido modificar una constante ",$1);
		}
;

unary: VARIABLE MINUS2

		{
			$$ = new lp::UnaryPostDecrementNode($1);
		}

	 | MINUS2 VARIABLE 
		{
	
		  $$ = new lp::UnaryPreDecrementNode($2);
		}

	 | VARIABLE PLUS2
		{

		  $$ = new lp::UnaryPostIncrementNode($1);
		}	

	 | PLUS2 VARIABLE 
		{
		  $$ = new lp::UnaryPreIncrementNode($2);
		}

print:  PRINT LPAREN exp RPAREN 
		{
			// Create a new print node
			 $$ = new lp::PrintStmt($3);
		}
;	

read:  READ LPAREN VARIABLE RPAREN  
		{
			// Create a new read node
			 $$ = new lp::ReadStmt($3);
		}
	| READ_STRING LPAREN VARIABLE RPAREN
		{
			$$ = new lp::ReadStringStmt($3);
		}

	| READ LPAREN CONSTANT RPAREN  
		{   
 			execerror("Error semantico en \"la lectura de la setencia\": no se puede modificar una constante ",$3);
		}

	| READ_STRING LPAREN CONSTANT RPAREN  
		{   
 			execerror("Error semantico en \"la lectura de la setencia\": no se puede modificar una constante ",$3);
		}
;


exp:	NUMBER 
		{ 
			// Create a new number node
			$$ = new lp::NumberNode($1);
		}

	|	STRING
		{
			//Create a new string node
			$$ = new lp::StringNode($1);
		}

	| 	exp PLUS exp 
		{ 
			// Create a new plus node
			 $$ = new lp::PlusNode($1, $3);
		 }

	| 	exp MINUS exp
      	{
			// Create a new minus node
			$$ = new lp::MinusNode($1, $3);
		}

	| 	exp MULTIPLICATION exp 
		{ 
			// Create a new multiplication node
			$$ = new lp::MultiplicationNode($1, $3);
		}

	| 	exp DIVISION exp
		{
		  // Create a new division node	
		  $$ = new lp::DivisionNode($1, $3);
	   }

	|	exp INTEGER_DIVISION exp
		{
		  // Create a new division node	
		  $$ = new lp::IntegerDivisionNode($1, $3);
	   }	

	| 	LPAREN exp RPAREN
       	{ 
		    // just copy up the expression node 
			$$ = $2;
		 }

  	| 	PLUS exp %prec UNARY
		{ 
		  // Create a new unary plus node	
  		  $$ = new lp::UnaryPlusNode($2);
		}

	| 	MINUS exp %prec UNARY
		{ 
		  // Create a new unary minus node	
  		  $$ = new lp::UnaryMinusNode($2);
		}

	|	exp MODULO exp 
		{
		  // Create a new modulo node	

		  $$ = new lp::ModuloNode($1, $3);
       }

	|	exp POWER exp 
     	{ 
		  // Create a new power node	
  		  $$ = new lp::PowerNode($1, $3);
		}

	 | VARIABLE
		{
		  // Create a new variable node	
		  $$ = new lp::VariableNode($1);
		}

	 | CONSTANT
		{
		  // Create a new constant node	
		  $$ = new lp::ConstantNode($1);

		}

	 | exp CONCATENATE exp
	 	{
	 		$$ = new lp::ConcatenateNode($1,$3);
	 	}

	| BUILTIN LPAREN listOfExp RPAREN
		{
			// Get the identifier in the table of symbols as Builtin
			lp::Builtin *f= (lp::Builtin *) table.getSymbol($1);

			// Check the number of parameters 
			if (f->getNParameters() ==  (int) $3->size())
			{
				switch(f->getNParameters())
				{
					case 0:
						{
							// Create a new Builtin Function with 0 parameters node	
							$$ = new lp::BuiltinFunctionNode_0($1);
						}
						break;

					case 1:
						{
							// Get the expression from the list of expressions
							lp::ExpNode *e = $3->front();

							// Create a new Builtin Function with 1 parameter node	
							$$ = new lp::BuiltinFunctionNode_1($1,e);
						}
						break;

					case 2:
						{
							// Get the expressions from the list of expressions
							lp::ExpNode *e1 = $3->front();
							$3->pop_front();
							lp::ExpNode *e2 = $3->front();

							// Create a new Builtin Function with 2 parameters node	
							$$ = new lp::BuiltinFunctionNode_2($1,e1,e2);
						}
						break;

					default:
				  			 execerror("Error sintactico: demasiados parametros para la función", $1);
				} 
			}
			else
	  			 execerror("Error sintactico: numero de parametros incompatibles para la funcion", $1);
		}

	| exp GREATER_THAN exp
	 	{
		  // Create a new "greater than" node	
 			$$ = new lp::GreaterThanNode($1,$3);
		}

	| exp GREATER_OR_EQUAL exp 
	 	{
		  // Create a new "greater or equal" node	
 			$$ = new lp::GreaterOrEqualNode($1,$3);
		}

	| exp LESS_THAN exp 	
	 	{
		  // Create a new "less than" node	
 			$$ = new lp::LessThanNode($1,$3);
		}

	| exp LESS_OR_EQUAL exp 
	 	{
		  // Create a new "less or equal" node	
 			$$ = new lp::LessOrEqualNode($1,$3);
		}

	| exp EQUAL exp 	
	 	{
		  // Create a new "equal" node	
 			$$ = new lp::EqualNode($1,$3);
		}

    | exp NOT_EQUAL exp 	
	 	{
		  // Create a new "not equal" node	
 			$$ = new lp::NotEqualNode($1,$3);
		}

    | exp AND exp 
	 	{
		  // Create a new "logic and" node	
 			$$ = new lp::AndNode($1,$3);
		}

    | exp OR exp 
	 	{
		  // Create a new "logic or" node	
 			$$ = new lp::OrNode($1,$3);
		}

    | NOT exp 
	 	{
		  // Create a new "logic negation" node	
 			$$ = new lp::NotNode($2);
		}
;


listOfExp: 
			/* Empty list of numeric expressions */
			{
			    // Create a new list STL
				$$ = new std::list<lp::ExpNode *>(); 
			}

	|  exp restOfListOfExp
			{
				$$ = $2;

				// Insert the expression in the list of expressions
				$$->push_front($1);
			}
;

restOfListOfExp:
			/* Empty list of numeric expressions */
			{
			    // Create a new list STL
				$$ = new std::list<lp::ExpNode *>(); 
			}

		|	COMMA exp restOfListOfExp
			{
				// Get the list of expressions
				$$ = $3;

				// Insert the expression in the list of expressions
				$$->push_front($2);
			}
;



%%



