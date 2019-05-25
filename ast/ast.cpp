/*!
	\file    ast.cpp
	\brief   Code of funcitons of AST clas
	\author
	\date    2018-12-13
	\version 1.0
*/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <list>

// Para usar la funciones pow y std::abs
#include <cmath>

#include "ast.hpp"

#include "../table/table.hpp"

// warning
#include "../error/error.hpp"

// Macros for the screen
#include "../includes/macros.hpp"

//
#include "../table/numericVariable.hpp"
#include "../table/logicalVariable.hpp"
#include "../table/stringVariable.hpp"

#include "../table/numericConstant.hpp"
#include "../table/logicalConstant.hpp"

#include "../table/builtinParameter0.hpp"
#include "../table/builtinParameter1.hpp"
#include "../table/builtinParameter2.hpp"

#include "../parser/interpreter.tab.h"

#include "../parser/funcionesAuxiliares.hpp"



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

extern lp::Table table; //!< Reference to the Table of Symbols


extern lp::AST *root; //!< Reference to the object at the base of the AST


///////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::VariableNode::getType()
{
	// Get the identifier in the table of symbols as Variable
	lp::Variable *var = (lp::Variable *) table.getSymbol(this->_id);

	// Return the type of the Variable
	return var->getType();
}


void lp::VariableNode::print()
{
  std::cout << "VariableNode: " << this->_id << std::endl;
  std::cout << "Type: " << this->getType() << std::endl;
}


double lp::VariableNode::evaluateNumber()
{
	double result = 0.0;

	if (this->getType() == NUMBER)
	{
		// Get the identifier in the table of symbols as NumericVariable
		lp::NumericVariable *var = (lp::NumericVariable *) table.getSymbol(this->_id);

		// Copy the value of the NumericVariable
		result = var->getValue();
	}
	else
	{
		warning("Runtime error in evaluateNumber(): the variable is not numeric",
				   this->_id);
	}

	// Return the value of the NumericVariable
	return result;
}


bool lp::VariableNode::evaluateBool()
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		// Get the identifier in the table of symbols as LogicalVariable
		lp::LogicalVariable *var = (lp::LogicalVariable *) table.getSymbol(this->_id);

		// Copy the value of the LogicalVariable
		result = var->getValue();
	}
	else
	{
		warning("Runtime error in evaluateBool(): the variable is not boolean",
				   this->_id);
	}

	// Return the value of the LogicalVariable
	return result;
}


std::string lp::VariableNode::evaluateString()
{
	std::string result ="";

	if (this->getType() == STRING)
	{
		// Get the identifier in the table of symbols as StringVariable
		lp::StringVariable *var = (lp::StringVariable *) table.getSymbol(this->_id);

		// Copy the value of the StringVariable
		result = var->getValue();
	}
	else
	{
		warning("Error en tiempo de ejecución en evaluateString(): la variable no es STRING",
				   this->_id);
	}

	// Return the value of the LogicalVariable
	return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


void lp::UnaryPostDecrementNode::print()
{
  std::cout << "UnaryPostDecrementNode: " << this->getId() << std::endl;
  std::cout << "Type: " << this->getType() << std::endl;
}


double lp::UnaryPostDecrementNode::evaluateNumber()
{
	double result = 0.0;

	if (this->getType() == NUMBER)
	{
		// Get the identifier in the table of symbols as NumericVariable
		lp::NumericVariable *var = (lp::NumericVariable *) table.getSymbol(this->getId());

		// Copy the value of the NumericVariable
		result = var->getValue();
		var->setValue(var->getValue()-1);
	}
	else
	{
		warning("Error en tiempo de ejecución para operador PostDecremento: la variable no es numérica",
				   this->getId());
	}

	// Return the value of the NumericVariable
	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


void lp::UnaryPreDecrementNode::print()
{
  std::cout << "UnaryPreDecrementNode: " << this->getId() << std::endl;
  std::cout << "Type: " << this->getType() << std::endl;
}


double lp::UnaryPreDecrementNode::evaluateNumber()
{
	double result = 0.0;

	if (this->getType() == NUMBER)
	{
		// Get the identifier in the table of symbols as NumericVariable
		lp::NumericVariable *var = (lp::NumericVariable *) table.getSymbol(this->getId());

		var->setValue(var->getValue()-1);
		// Copy the value of the NumericVariable
		result = var->getValue();
		
	}
	else
	{
		warning("Error en tiempo de ejecución para operador PreDecremento: la variable no es numérica",
				   this->getId());
	}

	// Return the value of the NumericVariable
	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


void lp::UnaryPostIncrementNode::print()
{
  std::cout << "UnaryPostIncrementNode: " << this->getId() << std::endl;
  std::cout << "Type: " << this->getType() << std::endl;
}


double lp::UnaryPostIncrementNode::evaluateNumber()
{
	double result = 0.0;

	if (this->getType() == NUMBER)
	{
		// Get the identifier in the table of symbols as NumericVariable
		lp::NumericVariable *var = (lp::NumericVariable *) table.getSymbol(this->getId());

		// Copy the value of the NumericVariable
		result = var->getValue();
		var->setValue(var->getValue()+1);
	}
	else
	{
		warning("Error en tiempo de ejecución para operador PosIncremento: la variable no es numérica",
				   this->getId());
	}

	// Return the value of the NumericVariable
	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


void lp::UnaryPreIncrementNode::print()
{
  std::cout << "UnaryPreIncrementNode: " << this->getId() << std::endl;
  std::cout << "Type: " << this->getType() << std::endl;
}


double lp::UnaryPreIncrementNode::evaluateNumber()
{
	double result = 0.0;

	if (this->getType() == NUMBER)
	{
		// Get the identifier in the table of symbols as NumericVariable
		lp::NumericVariable *var = (lp::NumericVariable *) table.getSymbol(this->getId());
		var->setValue(var->getValue()+1);
		// Copy the value of the NumericVariable
		result = var->getValue();
		
	}
	else
	{
		warning("Error en tiempo de ejecución para operador PreIncremento: la variable no es numérica",
				   this->getId());
	}

	// Return the value of the NumericVariable
	return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::ConstantNode::print()
{
  std::cout << "ConstantNode: " << this->_id << std::endl;
  std::cout << "Type: " << this->getType() << std::endl;
}

int lp::ConstantNode::getType()
{
	// Get the identifier in the table of symbols as Constant
	lp::Constant *var = (lp::Constant *) table.getSymbol(this->_id);

	// Return the type of the Constant
	return var->getType();
}


double lp::ConstantNode::evaluateNumber()
{
	double result = 0.0;

	if (this->getType() == NUMBER)
	{
		// Get the identifier in the table of symbols as NumericConstant
		lp::NumericConstant *constant = (lp::NumericConstant *) table.getSymbol(this->_id);

		// Copy the value of the NumericConstant
		result = constant->getValue();
	}
	else
	{
		warning("Runtime error in evaluateNumber(): the constant is not numeric",
				   this->_id);
	}

	// Return the value of the NumericVariable
	return result;
}

bool lp::ConstantNode::evaluateBool()
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		// Get the identifier in the table of symbols as LogicalConstant
		lp::LogicalConstant *constant = (lp::LogicalConstant *) table.getSymbol(this->_id);

		// Copy the value of the LogicalConstant
		result = constant->getValue();
	}
	else
	{
		warning("Runtime error in evaluateBool(): the constant is not boolean",
				   this->_id);
	}

	// Return the value of the LogicalVariable
	return result;
}


//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


int lp::NumberNode::getType()
{
	return NUMBER;
}


void lp::NumberNode::print()
{
  std::cout << "NumberNode: " << this->_number << std::endl;
}

double lp::NumberNode::evaluateNumber()
{
    return this->_number;
}

//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


int lp::StringNode::getType()
{
	return STRING;
}


void lp::StringNode::print()
{
  std::cout << "StringNode: " << *this->_string << std::endl;
}

std::string lp::StringNode::evaluateString()
{
    return *(this->_string);
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
int lp::NumericUnaryOperatorNode::getType()
{
	int result;

	if(this->_exp->getType() == NUMBER)
	{
		result = NUMBER;
	}
	else
	{
		warning("Runtime error: incompatible types for", "Numeric Unary Operator");
	}

	return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::LogicalUnaryOperatorNode::getType()
{
	int result;

	if(this->_exp->getType() == BOOL)
	{
		result = BOOL;
	}
	else
	{
		warning("Runtime error: incompatible types for", "Logical Unary Operator");
	}

	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::NumericOperatorNode::getType()
{
	int result = 0;

	if ( (this->_left->getType() == NUMBER) and (this->_right->getType() == NUMBER))
		result = NUMBER;
	else
		warning("Runtime error: incompatible types for", "Numeric Operator");

	return	result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::StringOperatorNode::getType()
{
	int result = 0;

	if ( (this->_left->getType() == STRING) and (this->_right->getType() == STRING))
		result = STRING;
	else
		warning("Error en tiempo de ejecución: incompatibles tipos para", "String operator");

	return	result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


int lp::RelationalOperatorNode::getType()
{
	int result = 0;

	if ( ( (this->_left->getType() == NUMBER) and (this->_right->getType() == NUMBER) ) or
			((this->_left->getType() == STRING) and (this->_right->getType() == STRING)))
		result = BOOL;
	else
		warning("Runtime error: incompatible types for", "Relational Operator");

	return	result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::LogicalOperatorNode:: getType()
{
	int result = 0;

	if ( (this->_left->getType() == BOOL) and (this->_right->getType() == BOOL))
	{
		//
		result = BOOL;
	}
	else
		warning("Runtime error: incompatible types for", "Logical Operator");

	return	result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


void lp::UnaryMinusNode::print()
{
  std::cout << "UnaryMinusNode: "  << std::endl;
  std::cout << "-";
  this->_exp->print();
}

double lp::UnaryMinusNode::evaluateNumber()
{
	double result = 0.0;

	// Ckeck the type of the expression
	if (this->getType() == NUMBER)
	{
		// Minus
		result = - this->_exp->evaluateNumber();
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for ", "UnaryMinus");
	}

  return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


void lp::UnaryPlusNode::print()
{
  std::cout << "UnaryPlusNode: "  << std::endl;
  this->_exp->print();
}

double lp::UnaryPlusNode::evaluateNumber()
{
	double result = 0.0;

	// Ckeck the type of the expression
	if (this->getType() == NUMBER)
	{
		result = this->_exp->evaluateNumber();
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for ","UnaryPlus");
	}

  return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::PlusNode::print()
{
  std::cout << "PlusNode: "  << std::endl;
  this->_left->print();
  std::cout << " + ";
  this->_right->print();
}

double lp::PlusNode::evaluateNumber()
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		result = this->_left->evaluateNumber() + this->_right->evaluateNumber();
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for ", "Plus");
	}

  return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::ConcatenateNode::print()
{
  std::cout << "ConcatenateNode: "  << std::endl;
  this->_left->print();
  std::cout << " || ";
  this->_right->print();
}

std::string lp::ConcatenateNode::evaluateString()
{
	std::string result = "";

	// Ckeck the types of the expressions
	if (this->getType() == STRING)
	{
		result = this->_left->evaluateString() + this->_right->evaluateString();
	}
	else
	{
		warning("Error en tiempo de ejecución: las expresiones no son numericas para ", "Concatenar");
	}

  return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::MinusNode::print()
{
  std::cout << "MinusNode: "  << std::endl;
  this->_left->print();
  std::cout << " - ";
  this->_right->print();
}

double lp::MinusNode::evaluateNumber()
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		result = this->_left->evaluateNumber() - this->_right->evaluateNumber();
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for ", "Minus");
	}

  return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


void lp::MultiplicationNode::print()
{
	std::cout << "MultiplicationNode: "  << std::endl;
	this->_left->print();
	std::cout << " * ";
	this->_right->print();
}

double lp::MultiplicationNode::evaluateNumber()
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		result = this->_left->evaluateNumber() * this->_right->evaluateNumber();
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for ","Multiplication");
	}

  return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::DivisionNode::print()
{
  std::cout << "DivisionNode: " << std::endl;
  this->_left->print();
  std::cout << " / ";
  this->_right->print();
}

double lp::DivisionNode::evaluateNumber()
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		double leftNumber, rightNumber;

		leftNumber = this->_left->evaluateNumber();
		rightNumber = this->_right->evaluateNumber();

		// The divisor is not zero
    	if(std::abs(rightNumber) > ERROR_BOUND)
		{
				result = leftNumber / rightNumber;
		}
		else
		{
			warning("Error en tiempo de ejecución", "División por cero");
		}
	}
	else
	{
		warning("Error en tiempo de ejecución: las expresiones no son númericas", "División");
	}

  return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::IntegerDivisionNode::print()
{
  std::cout << "DivisionNode: " << std::endl;
  this->_left->print();
  std::cout << " / ";
  this->_right->print();
}

double lp::IntegerDivisionNode::evaluateNumber()
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		int leftNumber, rightNumber;

		leftNumber = (int)this->_left->evaluateNumber();
		rightNumber = (int)this->_right->evaluateNumber();

		// The divisor is not zero
    	if(std::abs(rightNumber) > ERROR_BOUND)
		{
				result = leftNumber / rightNumber;
		}
		else
		{
			warning("Error en tiempo de ejecución", "División por cero");
		}
	}
	else
	{
		warning("Error en tiempo de ejecución: las expresiones no son númericas", "División");
	}

  return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::ModuloNode::print()
{
  std::cout << "ModuloNode: " << std::endl;
  this->_left->print();
  std::cout << " / ";
  this->_right->print();
}

double lp::ModuloNode::evaluateNumber()
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		double leftNumber, rightNumber;

		leftNumber = this->_left->evaluateNumber();
		rightNumber = this->_right->evaluateNumber();

    	if(std::abs(rightNumber) > ERROR_BOUND)
				result = (int) leftNumber % (int) rightNumber;
		else
			warning("Runtime error", "Division by zero");
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for", "Modulo");
	}

  return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::PowerNode::print()
{
	std::cout << "PowerNode: "  << std::endl;
	this->_left->print();
	std::cout << " ^ ";
	this->_right->print();
}

double lp::PowerNode::evaluateNumber()
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		result = pow(this->_left->evaluateNumber(), this->_right->evaluateNumber());
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for", "Power");
	}

  return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
int lp::BuiltinFunctionNode_0::getType()
{
	return	NUMBER;
}


void lp::BuiltinFunctionNode_0::print()
{
	std::cout << "BuiltinFunctionNode_0: "  << std::endl;
	std::cout << this->_id;
	std::cout << " ( ) " ;
}

double lp::BuiltinFunctionNode_0::evaluateNumber()
{
	// Get the identifier in the table of symbols as BuiltinParameter0
	lp::BuiltinParameter0 *f = (lp::BuiltinParameter0 *) table.getSymbol(this->_id);

	// Apply the function and copy the result
   	return f->getFunction()();
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::BuiltinFunctionNode_1::getType()
{
	int result = 0;

	if (this->_exp->getType() == NUMBER)
		result = NUMBER;
	else
		warning("Runtime error: incompatible type for", "BuiltinFunctionNode_1");

	return	result;
}

void lp::BuiltinFunctionNode_1::print()
{
	std::cout << "BuiltinFunctionNode_1: "  << std::endl;
	std::cout << this->_id;
	std::cout << " ( " ;
	this->_exp->print();
	std::cout << " ) " ;
}

double lp::BuiltinFunctionNode_1::evaluateNumber()
{
	double result = 0.0;

	// Ckeck the type of the expression
	if (this->getType() == NUMBER)
	{
		// Get the identifier in the table of symbols as BuiltinParameter1
		lp::BuiltinParameter1 *f = (lp::BuiltinParameter1 *) table.getSymbol( this->_id);

		// Apply the function to the parameter and copy the result
		result = f->getFunction()(this->_exp->evaluateNumber());
	}
	else
	{
		warning("Runtime error: incompatible type of parameter for ", this->_id);
	}

	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::BuiltinFunctionNode_2::getType()
{
	int result = 0;

	if (this->_exp1->getType() == this->_exp2->getType())
		result = this->_exp1->getType();
	else
		warning("Runtime error: incompatible types for", "BuiltinFunctionNode_2");

	return	result;
}


void lp::BuiltinFunctionNode_2::print()
{
	std::cout << "BuiltinFunctionNode_2: "  << std::endl;
	std::cout << this->_id;
	std::cout << " ( " ;
	this->_exp1->print();
	std::cout << " , " ;
	this->_exp2->print();
	std::cout << " ) " ;
}

double lp::BuiltinFunctionNode_2::evaluateNumber()
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		// Get the identifier in the table of symbols as BuiltinParameter2
		lp::BuiltinParameter2 *f = (lp::BuiltinParameter2 *) table.getSymbol(this->_id);

		// Apply the function to the parameters and copy the result
	  	result = f->getFunction()(this->_exp1->evaluateNumber(),this->_exp2->evaluateNumber());
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", this->_id);
	}

  return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::GreaterThanNode::print()
{
  std::cout << "GreaterThanNode: " << std::endl;
  this->_left->print();
  std::cout << " > ";
  this->_right->print();
}

bool lp::GreaterThanNode::evaluateBool()
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		if(this->_left->getType()==this->_right->getType()){

			switch (this->_left->getType()){
				case NUMBER:
					double leftNumber, rightNumber;
					leftNumber = this->_left->evaluateNumber();
					rightNumber = this->_right->evaluateNumber();

					result =  (leftNumber > rightNumber);
				break;

				case STRING:
					std::string leftString, rightString;
					leftString = this->_left->evaluateString();
					rightString = this->_right->evaluateString();

					result = (leftString>rightString);

				break;

			}

		}
		else{
			warning("Error en tiempo de ejecución: tipos diferentes para ", "operador Mayor");
		}

	}
	else
	{
		warning("Error en tiempo de ejecución: tipos incompatibles para ", "operador Mayor");
	}

	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::GreaterOrEqualNode::print()
{
  std::cout << "GreaterOrEqualNode: " << std::endl;
  this->_left->print();
  std::cout << " >= ";
  this->_right->print();
}

bool lp::GreaterOrEqualNode::evaluateBool()
{
	bool result = false;

	if (this->getType() == BOOL)
	{

		if(this->_left->getType()==this->_right->getType()){

			switch (this->_left->getType()){
				case NUMBER:
					double leftNumber, rightNumber;
					leftNumber = this->_left->evaluateNumber();
					rightNumber = this->_right->evaluateNumber();

					// ERROR_BOUND to control the precision of real numbers
					result =  (leftNumber >= rightNumber) || std::abs( (leftNumber - rightNumber)) < ERROR_BOUND;;
				break;

				case STRING:
					std::string leftString, rightString;
					leftString = this->_left->evaluateString();
					rightString = this->_right->evaluateString();

					result = (leftString>=rightString);

				break;

			}

		}
		else{
			warning("Error en tiempo de ejecución: tipos diferentes para ", "operador Mayor or igual que");
		}

	}
	else
	{
		warning("Error en tiempo de ejecución: tipos incompatibles para ", "operador Mayor or igual que");
	}

	return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::LessThanNode::print()
{
  std::cout << "LessThanNode: " << std::endl;
  this->_left->print();
  std::cout << " < ";
  this->_right->print();
}

bool lp::LessThanNode::evaluateBool()
{
	bool result = false;

	if (this->getType() == BOOL)
	{

		if(this->_left->getType()==this->_right->getType()){

			switch (this->_left->getType()){
				case NUMBER:
					double leftNumber, rightNumber;
					leftNumber = this->_left->evaluateNumber();
					rightNumber = this->_right->evaluateNumber();

					result =  (leftNumber < rightNumber);
				break;

				case STRING:
					std::string leftString, rightString;
					leftString = this->_left->evaluateString();
					rightString = this->_right->evaluateString();

					result = (leftString<rightString);

				break;

			}

		}
		else{
			warning("Error en tiempo de ejecución: tipos diferentes para ", "operador Menor que");
		}

	}
	else
	{
		warning("Error en tiempo de ejecución: tipos incompatibles para ", "operador Menor que");
	}

	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::LessOrEqualNode::print()
{
  std::cout << "LessOrEqualNode: " << std::endl;
  this->_left->print();
  std::cout << " <= ";
  this->_right->print();
}

bool lp::LessOrEqualNode::evaluateBool()
{
	bool result = false;

	if (this->getType() == BOOL)
	{

		if(this->_left->getType()==this->_right->getType()){

			switch (this->_left->getType()){
				case NUMBER:
					double leftNumber, rightNumber;
					leftNumber = this->_left->evaluateNumber();
					rightNumber = this->_right->evaluateNumber();

					// ERROR_BOUND to control the precision of real numbers
					result =  (leftNumber < rightNumber) || std::abs( (leftNumber - rightNumber)) < ERROR_BOUND;
				break;

				case STRING:
					std::string leftString, rightString;
					leftString = this->_left->evaluateString();
					rightString = this->_right->evaluateString();

					result = (leftString<=rightString);

				break;

			}

		}
		else{
			warning("Error en tiempo de ejecución: tipos diferentes para ", "operador Menor o igual que");
		}

	}
	else
	{
		warning("Error en tiempo de ejecución: tipos incompatibles para ", "operador Menor o igual que");
	}

	return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::EqualNode::print()
{
  std::cout << "EqualNode: " << std::endl;
  this->_left->print();
  std::cout << " == ";
  this->_right->print();
}

bool lp::EqualNode::evaluateBool()
{
	bool result = false;

	if (this->getType() == BOOL)
	{

		if(this->_left->getType()==this->_right->getType()){

			switch (this->_left->getType()){
				case NUMBER:
					double leftNumber, rightNumber;
					leftNumber = this->_left->evaluateNumber();
					rightNumber = this->_right->evaluateNumber();

					// ERROR_BOUND to control the precision of real numbers
					result = std::abs( (leftNumber - rightNumber)) < ERROR_BOUND ;

				break;

				case STRING:
					std::string leftString, rightString;
					leftString = this->_left->evaluateString();
					rightString = this->_right->evaluateString();

					result = (leftString==rightString);

				break;


			}

		}
		else{
			warning("Error en tiempo de ejecución: tipos diferentes para ", "operador Igual");
		}

	}
	else
	{
		warning("Error en tiempo de ejecución: tipos incompatibles para ", "operador Igual");
	}

	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::NotEqualNode::print()
{
  std::cout << "NotEqualNode: " << std::endl;
  this->_left->print();
  std::cout << " != ";
  this->_right->print();
}

bool lp::NotEqualNode::evaluateBool()
{
	bool result = false;

	if (this->getType() == BOOL)
	{

		if(this->_left->getType()==this->_right->getType()){

			switch (this->_left->getType()){
				case NUMBER:
					double leftNumber, rightNumber;
					leftNumber = this->_left->evaluateNumber();
					rightNumber = this->_right->evaluateNumber();

					// ERROR_BOUND to control the precision of real numbers
					result = std::abs( (leftNumber - rightNumber)) >= ERROR_BOUND ;
				break;

				case STRING:
					std::string leftString, rightString;
					leftString = this->_left->evaluateString();
					rightString = this->_right->evaluateString();

					result = (leftString!=rightString);

				break;
			}

		}
		else{
			warning("Error en tiempo de ejecución: tipos diferentes para ", "operador Distinto");
		}
	}
	else
	{
		warning("Error en tiempo de ejecución: tipos incompatibles para ", "operador Distinto");
	}

	return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::AndNode::print()
{
  std::cout << "AndNode: " << std::endl;
  this->_left->print();
  std::cout << " && ";
  this->_right->print();
}

bool lp::AndNode::evaluateBool()
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		bool leftBool, rightBool;

		leftBool = this->_left->evaluateBool();
		rightBool = this->_right->evaluateBool();

		result = leftBool and rightBool;
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "operator And");
	}

	return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::OrNode::print()
{
  std::cout << "OrNode: " << std::endl;
  this->_left->print();
  std::cout << " || ";
  this->_right->print();
}

bool lp::OrNode::evaluateBool()
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		bool leftBool, rightBool;

		leftBool = this->_left->evaluateBool();
		rightBool = this->_right->evaluateBool();

		result = leftBool or rightBool;
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "operator Or");
	}

	return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::NotNode::print()
{
  std::cout << "NotNode: " << std::endl;
  std::cout << " ! ";
  this->_exp->print();
}

bool lp::NotNode::evaluateBool()
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		result = not this->_exp->evaluateBool();
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "operator Not");
	}

	return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


void lp::Case::print(std::string msg){

	this->_stmts->print(msg);

}

void lp::Case::evaluate(){

	this->_stmts->evaluate();	

}

double lp::Case::evaluateNumber(){

	return this->_value;	

}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


void lp::StatementList::print(std::string msg){

  std::list<Statement *>::iterator stmtIter;

  std::cout << msg  << std::endl;

  for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++)
  {
     (*stmtIter)->print();
  }

}

void lp::StatementList::evaluate(){
  std::list<Statement *>::iterator stmtIter;


  for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++)
  {
  	
    (*stmtIter)->evaluate();
  }

}

void lp::StatementList::addStatement(lp::Statement* stmt){

	_stmts->push_back(stmt);

}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


void lp::CaseList::print(std::string msg){

  std::list<Case *>::iterator casesIter;

  std::cout << msg  << std::endl;

  for (casesIter = this->_cases->begin(); casesIter != this->_cases->end(); casesIter++)
  {
     (*casesIter)->print("");
  }

}

bool lp::CaseList::evaluate(ExpNode* exp){


  bool evaluado = false;

  //Solo se va a evaluar aquel case que cumpla la expresion

  std::list<Case *>::iterator casesIter;


  for (casesIter = this->_cases->begin(); casesIter != this->_cases->end(); casesIter++)
  {

  	if(std::abs(exp->evaluateNumber() - (*casesIter)->evaluateNumber()) < ERROR_BOUND){
  		(*casesIter)->evaluate();
  		evaluado = true;

  	}
	
  }

	return evaluado;

}

void lp::CaseList::addCase(lp::Case* value){


	//Comprobar que no hay un caso con la misma expresion que uno de los que ya estuvieran añadidos

	std::list<Case *>::iterator casesIter;

	for (casesIter = this->_cases->begin(); casesIter != this->_cases->end(); casesIter++){

		if(std::abs(value->evaluateNumber() - (*casesIter)->evaluateNumber()) < ERROR_BOUND){
			//Ya existe un caso con el mismo valor en la expresion
			execerror("Error en tiempo de ejecución: dos valores iguales para ", "SEGUN");;
		}

 	}

	_cases->push_back(value);

}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::AssignmentStmt::print()
{
  std::cout << "assignment_node: "  << std::endl;
  std::cout << this->_id << " = ";
  this->_exp->print();
  std::cout << std::endl;
}


void lp::AssignmentStmt::evaluate()
{
	/* Get the identifier in the table of symbols as Variable */
	/*
		a = 2;
		a = b = 2;

		a: firstVar
		b: secondVar
	*/

	
	//Check if only there is an unary operation.
	if(this->_id == ""){

		this->_unary->evaluateNumber();
	}
	else{
		lp::Variable *firstVar = (lp::Variable *) table.getSymbol(this->_id);
		//Check if the right member of the assignment is an unary operation
		if(this->_unary !=NULL){
			//The var must be numeric for this type of operator
			double value;
			// evaluate the expression as NUMBER
			value= this->_unary->evaluateNumber();
			if(firstVar->getType() == NUMBER){


			  	// Get the identifier in the table of symbols as NumericVariable
				lp::NumericVariable *v = (lp::NumericVariable *) table.getSymbol(this->_id);
				v->setValue(value);			

			}
			else{
				//warning("Error en tiempo de ejecución: las variables han de ser numéricas para ", "Asignación y operador Incremento/Decremento");
				// Delete the variable from the table of symbols
				table.eraseSymbol(this->_id);

				// Insert the variable in the table of symbols as NumericVariable
				// with the type NUMBER and the value
				lp::NumericVariable *v = new lp::NumericVariable(this->_id,
										VARIABLE,NUMBER,value);
				table.installSymbol(v);

			}


		}
		// Check the expression
		else if (this->_exp != NULL )
		{
			// Check the type of the expression of the asgn
			switch(this->_exp->getType())
			{
				case NUMBER:
				{
					double value;
					// evaluate the expression as NUMBER
				 	value = this->_exp->evaluateNumber();

					// Check the type of the first varible
					if (firstVar->getType() == NUMBER)
					{
					  	// Get the identifier in the table of symbols as NumericVariable
						lp::NumericVariable *v = (lp::NumericVariable *) table.getSymbol(this->_id);

						// Assignment the value to the identifier in the table of symbols
						v->setValue(value);
					}
					// The type of variable is not NUMBER
					else
					{
						// Delete the variable from the table of symbols
						table.eraseSymbol(this->_id);

						// Insert the variable in the table of symbols as NumericVariable
						// with the type NUMBER and the value
						lp::NumericVariable *v = new lp::NumericVariable(this->_id,
												VARIABLE,NUMBER,value);
						table.installSymbol(v);
					}
				}
				break;

				case BOOL:
				{
					bool value;
					// evaluate the expression as BOOL
				 	value = this->_exp->evaluateBool();

					if (firstVar->getType() == BOOL)
					{
					  	// Get the identifier in the table of symbols as LogicalVariable
						lp::LogicalVariable *v = (lp::LogicalVariable *) table.getSymbol(this->_id);

						// Assignment the value to the identifier in the table of symbols
						v->setValue(value);
					}
					// The type of variable is not BOOL
					else
					{
						// Delete the variable from the table of symbols
						table.eraseSymbol(this->_id);

						// Insert the variable in the table of symbols as NumericVariable
						// with the type BOOL and the value
						lp::LogicalVariable *v = new lp::LogicalVariable(this->_id,
												VARIABLE,BOOL,value);
						table.installSymbol(v);
					}
				}
				break;

				case STRING:
				{
					std::string value;
					// evaluate the expression as string
				 	value = this->_exp->evaluateString();

					if (firstVar->getType() == STRING)
					{

					  	// Get the identifier in the table of symbols as StringVariable
						lp::StringVariable *v = (lp::StringVariable *) table.getSymbol(this->_id);

						// Assignment the value to the identifier in the table of symbols
						v->setValue(value);
					}
					// The type of variable is not STRING
					else
					{
						// Delete the variable from the table of symbols
						table.eraseSymbol(this->_id);

						// Insert the variable in the table of symbols as StringVariable
						// with the type String and the value
						lp::StringVariable *v = new lp::StringVariable(this->_id,
												VARIABLE,STRING,value);
						table.installSymbol(v);
					}

				}


				break;

				default:
					warning("Runtime error: incompatible type of expression for ", "Assigment");
			}

		}

		//////////////////////////////////////////////
		// Allow multiple assigment -> a = b = c = 2;

		else // this->_asgn is not NULL
		{
			// IMPORTANT
			//  evaluate the assigment child
			this->_asgn->evaluate();


			/* Get the identifier of the previous asgn in the table of symbols as Variable */
			lp::Variable *secondVar = (lp::Variable *) table.getSymbol(this->_asgn->_id);

			// Get the type of the variable of the previous asgn
			switch(secondVar->getType())
			{
				case NUMBER:
				{
					/* Get the identifier of the previous asgn in the table of symbols as NumericVariable */
					lp::NumericVariable *secondVar = (lp::NumericVariable *) table.getSymbol(this->_asgn->_id);
					// Check the type of the first variable
					if (firstVar->getType() == NUMBER)
					{
					/* Get the identifier of the first variable in the table of symbols as NumericVariable */
					lp::NumericVariable *firstVar = (lp::NumericVariable *) table.getSymbol(this->_id);
					  	// Get the identifier o f the in the table of symbols as NumericVariable
	//					lp::NumericVariable *n = (lp::NumericVariable *) table.getSymbol(this->_id);

						// Assignment the value of the second variable to the first variable
						firstVar->setValue(secondVar->getValue());

					}
					// The type of variable is not NUMBER
					else
					{
						// Delete the first variable from the table of symbols
						table.eraseSymbol(this->_id);

						// Insert the first variable in the table of symbols as NumericVariable
						// with the type NUMBER and the value of the previous variable
						lp::NumericVariable *firstVar = new lp::NumericVariable(this->_id,
												VARIABLE,NUMBER,secondVar->getValue());
						table.installSymbol(firstVar);
					}
				}
				break;

				case BOOL:
				{
					/* Get the identifier of the previous asgn in the table of symbols as LogicalVariable */
					lp::LogicalVariable *secondVar = (lp::LogicalVariable *) table.getSymbol(this->_asgn->_id);
					// Check the type of the first variable
					if (firstVar->getType() == BOOL)
					{
					/* Get the identifier of the first variable in the table of symbols as LogicalVariable */
					lp::LogicalVariable *firstVar = (lp::LogicalVariable *) table.getSymbol(this->_id);
					  	// Get the identifier o f the in the table of symbols as NumericVariable
	//					lp::NumericVariable *n = (lp::NumericVariable *) table.getSymbol(this->_id);

						// Assignment the value of the second variable to the first variable
						firstVar->setValue(secondVar->getValue());

					}
					// The type of variable is not BOOL
					else
					{
						// Delete the first variable from the table of symbols
						table.eraseSymbol(this->_id);

						// Insert the first variable in the table of symbols as LogicalVariable
						// with the type BOOL and the value of the previous variable
						lp::LogicalVariable *firstVar = new lp::LogicalVariable(this->_id,
												VARIABLE,BOOL,secondVar->getValue());
						table.installSymbol(firstVar);
					}
				}
				break;
				case STRING:
				{
					/* Get the identifier of the previous asgn in the table of symbols as StringVariable */
					lp::StringVariable *secondVar = (lp::StringVariable *) table.getSymbol(this->_asgn->_id);
					// Check the type of the first variable
					if (firstVar->getType() == STRING)
					{
					/* Get the identifier of the first variable in the table of symbols as StringVariable */
					lp::StringVariable *firstVar = (lp::StringVariable *) table.getSymbol(this->_id);
					  	// Get the identifier o f the in the table of symbols as NumericVariable
	//					lp::NumericVariable *n = (lp::NumericVariable *) table.getSymbol(this->_id);

						// Assignment the value of the second variable to the first variable
						firstVar->setValue(secondVar->getValue());

					}
					// The type of variable is not NUMBER
					else
					{
						// Delete the first variable from the table of symbols
						table.eraseSymbol(this->_id);

						// Insert the first variable in the table of symbols as StringVariable
						// with the type STRING and the value of the previous variable
						lp::StringVariable *firstVar = new lp::StringVariable(this->_id,
												VARIABLE,BOOL,secondVar->getValue());
						table.installSymbol(firstVar);
					}

				}


				break;



				default:
					warning("Runtime error: incompatible type of expression for ", "Assigment");
			}
		}		
	}
	
	
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::PlusAssignmentStmt::print()
{
  std::cout << "PlusAssignmentStmt: "  << std::endl;
  std::cout << this->getId() << " = ";
  this->getExpression()->print();
  std::cout << std::endl;
}


void lp::PlusAssignmentStmt::evaluate()
{


	lp::Variable *firstVar = (lp::Variable *) table.getSymbol(this->getId());
	// Check the type of the expression of the asgn
	if(this->getExpression()->getType()==NUMBER)
	{

		if(firstVar->getType()==NUMBER){
			double value;
			// evaluate the expression as NUMBER
		 	value = this->getExpression()->evaluateNumber();

		  	// Get the identifier in the table of symbols as NumericVariable
			lp::NumericVariable *v = (lp::NumericVariable *) table.getSymbol(this->getId());		 	
		 	//Plus and assignment +:=
			v->setValue(value + v->getValue());
		}
		else{
			warning("Error en tiempo de ejecución: se experaba variable numérica en ", "Más Asignación");
		}
	}
	else{

		warning("Error en tiempo de ejecución: se experaba expresión numérica en ", "Más Asignación");
	}
		
}
	
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::MinusAssignmentStmt::print()
{
  std::cout << "MinusAssignmentStmt: "  << std::endl;
  std::cout << this->getId() << " = ";
  this->getExpression()->print();
  std::cout << std::endl;
}


void lp::MinusAssignmentStmt::evaluate()
{


	lp::Variable *firstVar = (lp::Variable *) table.getSymbol(this->getId());
	// Check the type of the expression of the asgn
	if(this->getExpression()->getType()==NUMBER)
	{

		if(firstVar->getType()==NUMBER){
			double value;
			// evaluate the expression as NUMBER
		 	value = this->getExpression()->evaluateNumber();

		  	// Get the identifier in the table of symbols as NumericVariable
			lp::NumericVariable *v = (lp::NumericVariable *) table.getSymbol(this->getId());		 	
		 	//Minus and assignment -:=
			v->setValue(v->getValue() - value );
		}
		else{
			warning("Error en tiempo de ejecución: se experaba variable numérica en ", "Más Asignación");
		}
	}
	else{

		warning("Error en tiempo de ejecución: se experaba expresión numérica en ", "Más Asignación");
	}
		
}	

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::MultiplicationAssignmentStmt::print()
{
  std::cout << "MultiplicationAssignmentStmt: "  << std::endl;
  std::cout << this->getId() << " = ";
  this->getExpression()->print();
  std::cout << std::endl;
}


void lp::MultiplicationAssignmentStmt::evaluate()
{


	lp::Variable *firstVar = (lp::Variable *) table.getSymbol(this->getId());
	// Check the type of the expression of the asgn
	if(this->getExpression()->getType()==NUMBER)
	{

		if(firstVar->getType()==NUMBER){
			double value;
			// evaluate the expression as NUMBER
		 	value = this->getExpression()->evaluateNumber();

		  	// Get the identifier in the table of symbols as NumericVariable
			lp::NumericVariable *v = (lp::NumericVariable *) table.getSymbol(this->getId());		 	
		 	//Multiplication and assignment +:=
			v->setValue(value * v->getValue());
		}
		else{
			warning("Error en tiempo de ejecución: se experaba variable numérica en ", "Más Asignación");
		}
	}
	else{

		warning("Error en tiempo de ejecución: se experaba expresión numérica en ", "Más Asignación");
	}
		
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::DivisionAssignmentStmt::print()
{
  std::cout << "DivisionAssignmentStmt: "  << std::endl;
  std::cout << this->getId() << " = ";
  this->getExpression()->print();
  std::cout << std::endl;
}


void lp::DivisionAssignmentStmt::evaluate()
{


	lp::Variable *firstVar = (lp::Variable *) table.getSymbol(this->getId());
	// Check the type of the expression of the asgn
	if(this->getExpression()->getType()==NUMBER)
	{

		if(firstVar->getType()==NUMBER){
			double value;
			// evaluate the expression as NUMBER
		 	value = this->getExpression()->evaluateNumber();

		  	// Get the identifier in the table of symbols as NumericVariable
			lp::NumericVariable *v = (lp::NumericVariable *) table.getSymbol(this->getId());		 	
		 	//Division and assignment +:=
			v->setValue(v->getValue()/value);
		}
		else{
			warning("Error en tiempo de ejecución: se experaba variable numérica en ", "Más Asignación");
		}
	}
	else{

		warning("Error en tiempo de ejecución: se experaba expresión numérica en ", "Más Asignación");
	}
		
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::PrintStmt::print()
{
  std::cout << "PrintStmt: "  << std::endl;
  std::cout << " escribir ";
  this->_exp->print();
  std::cout << std::endl;
}


void lp::PrintStmt::evaluate()
{
	/*std::cout << BIYELLOW;
	std::cout << "Escribir: ";
	std::cout << RESET; */

	switch(this->_exp->getType())
	{
		case NUMBER:
				std::cout << this->_exp->evaluateNumber();
				break;
		case BOOL:
			if (this->_exp->evaluateBool())
				std::cout << "verdadero";
			else
				std::cout << "falso";

			break;

		case STRING:
			std::cout<<this->_exp->evaluateString();
			break;

		default:
			warning("Error en tiempo de ejecución: tipo incompatible para ", "escribir");
	}
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::ReadStmt::print()
{
  std::cout << "ReadStmt: "  << std::endl;
  std::cout << " read (" << this->_id << ")";
  std::cout << std::endl;
}


void lp::ReadStmt::evaluate()
{
	/*double value;
	std::cout << BIYELLOW;
	std::cout << "Insert a numeric value --> " ;
	std::cout << RESET;
	std::cin >> value;

	// Get the identifier in the table of symbols as Variable
	lp::Variable *var = (lp::Variable *) table.getSymbol(this->_id);

	// Check if the type of the variable is NUMBER
	if (var->getType() == NUMBER)
	{
		// Get the identifier in the table of symbols as NumericVariable
		lp::NumericVariable *n = (lp::NumericVariable *) table.getSymbol(this->_id);

		//Assignment the read value to the identifier
		n->setValue(value);
	}
	// The type of variable is not NUMBER
	else
	{
		// Delete $1 from the table of symbols as Variable
		table.eraseSymbol(this->_id);

			// Insert $1 in the table of symbols as NumericVariable
		// with the type NUMBER and the read value
		lp::NumericVariable *n = new lp::NumericVariable(this->_id,
									  VARIABLE,NUMBER,value);

		table.installSymbol(n);
	}*/


	/*

	int type;
	double value;
	std::getline(std::cin,value);

	value = parseSlash((char*)value.c_str(),value.size());

	if(value[0]=='\'' && value[value.size()-1]=='\''){
		type=STRING;
	}
	else{
		type=NUMBER;
		for(unsigned i =0; i<value.size(); i++){
			if(value[i]<'0' || value[i]>'9'){
				type=UNDEFINED;
				break;
			}
		}
	}

	// Get the identifier in the table of symbols as Variable
	lp::Variable *var = (lp::Variable *) table.getSymbol(this->_id);

	switch(type){
		case NUMBER:{


			double aux = atof(value.c_str());
			// Check if the type of the variable is NUMBER
			if (var->getType() == NUMBER)
			{
				// Get the identifier in the table of symbols as NumericVariable
				lp::NumericVariable *n = (lp::NumericVariable *) table.getSymbol(this->_id);

				//Assignment the read value to the identifier
				n->setValue(aux);
			}
			// The type of variable is not NUMBER
			else
			{
				// Delete $1 from the table of symbols as Variable
				table.eraseSymbol(this->_id);

					// Insert $1 in the table of symbols as NumericVariable
				// with the type NUMBER and the read value
				lp::NumericVariable *n = new lp::NumericVariable(this->_id,
											  VARIABLE,NUMBER,aux);

				table.installSymbol(n);
			}
		}
		break;

		case STRING:{
			value=value.substr(1,value.size()-2);
			// Check if the type of the variable is STRING
			if (var->getType() == STRING)
			{
				// Get the identifier in the table of symbols as NumericVariable
				lp::StringVariable *n = (lp::StringVariable *) table.getSymbol(this->_id);

				//Assignment the read value to the identifier
				n->setValue(value);
			}
			// The type of variable is not STRING
			else
			{
				// Delete $1 from the table of symbols as Variable
				table.eraseSymbol(this->_id);

					// Insert $1 in the table of symbols as StringVariable
				// with the type STRING and the read value
				lp::StringVariable *n = new lp::StringVariable(this->_id,
											  VARIABLE,STRING,value);

				table.installSymbol(n);
			}
		}
		break;

		default:
			warning("Error en tiempo de ejecución: tipo incompatible para ", "leer");
		break;

	}
	*/

	double value;
	std::cin>>value;

	std::cin.ignore();


	// Get the identifier in the table of symbols as Variable
	lp::Variable *var = (lp::Variable *) table.getSymbol(this->_id);


	if (var->getType() == NUMBER)
	{
		// Get the identifier in the table of symbols as NumericVariable
		lp::NumericVariable *n = (lp::NumericVariable *) table.getSymbol(this->_id);

		//Assignment the read value to the identifier
		n->setValue(value);
	}
	// The type of variable is not NUMBER
	else
	{
		// Delete $1 from the table of symbols as Variable
		table.eraseSymbol(this->_id);

			// Insert $1 in the table of symbols as NumericVariable
		// with the type NUMBER and the read value
		lp::NumericVariable *n = new lp::NumericVariable(this->_id,
									  VARIABLE,NUMBER,value);

		table.installSymbol(n);
	}
		






}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::ReadStringStmt::print()
{
  std::cout << "ReadStringStmt: "  << std::endl;
  std::cout << " read (" << this->_id << ")";
  std::cout << std::endl;
}


void lp::ReadStringStmt::evaluate(){

	std::string value;
	std::getline(std::cin,value);


	// Get the identifier in the table of symbols as Variable
	lp::Variable *var = (lp::Variable *) table.getSymbol(this->_id);


	if (var->getType() == STRING)
	{
		// Get the identifier in the table of symbols as NumericVariable
		lp::StringVariable *n = (lp::StringVariable *) table.getSymbol(this->_id);

		//Assignment the read value to the identifier
		n->setValue(value);
	}
	// The type of variable is not STRING
	else
	{
		// Delete $1 from the table of symbols as Variable
		table.eraseSymbol(this->_id);

			// Insert $1 in the table of symbols as StringVariable
		// with the type STRING and the read value
		lp::StringVariable *n = new lp::StringVariable(this->_id,
									  VARIABLE,STRING,value);

		table.installSymbol(n);
	}

}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::EmptyStmt::print()
{
  std::cout << "EmptyStmt "  << std::endl;
}

void lp::EmptyStmt::evaluate()
{
  // Empty
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// NEW in example 17

void lp::IfStmt::print()
{


  std::cout << "IfStmts: "  << std::endl;
  // Condition
  this->_cond->print();

  // Consequents
	this->_consequent->print("Consequents: ");

 // The alternative is printed if exists
  if (this->_alternative != NULL)
	  this->_alternative->print("Alternatives: ");

  std::cout << std::endl;
}


void lp::IfStmt::evaluate()
{
	if(this->_cond->getType()==BOOL){
	   // If the condition is true,
		if (this->_cond->evaluateBool() == true )
	     // the consequent is run
		  this->_consequent->evaluate();

	    // Otherwise, the alternative is run if exists
		else if (this->_alternative != NULL)
			  this->_alternative->evaluate();
	}
	else{

		warning("Error en tiempo de ejecución: tipo incompatible para ", "Si Condicion");
	}

}




///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// NEW in example 17

void lp::WhileStmt::print()
{
  std::cout << "WhileStmts: "  << std::endl;
  // Condition
  this->_cond->print();

  // Body of the while loop
  this->_stmts->print("Stmts body of the loop");

  std::cout << std::endl;
}


void lp::WhileStmt::evaluate()
{

	if(this->_cond->getType()==BOOL){
	  // While the condition is true. the body is run
	  while (this->_cond->evaluateBool() == true)
	  {
		  this->_stmts->evaluate();
	  }
	}
	else{

		warning("Error en tiempo de ejecución: tipo incompatible para ", "Mientras Condicion");
	}

}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::RepeatStmt::print()
{
  std::cout << "RepeatStmts: "  << std::endl;
  // Condition
  this->_cond->print();

  // Body of the while loop
  this->_stmts->print("Stmts body of the loop");

  std::cout << std::endl;
}


void lp::RepeatStmt::evaluate()
{


  // While the condition is true. the body is run
	do {
		this->_stmts->evaluate();


		if(this->_cond->getType()!=BOOL){
			warning("Error en tiempo de ejecución: tipo incompatible para ", "Repetir Condicion");
			return;
		}


	}while (this->_cond->evaluateBool() == false);

}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::ForStmt::print()
{
  std::cout << "ForStmts: "  << std::endl;

  this->_from->print();

  this->_until->print();

  this->_step->print();

  // Body of the while loop
  this->_stmts->print("Stmts body of the loop");

  std::cout << std::endl;
}


void lp::ForStmt::evaluate()
{

	//COMPROBAR QUE EL TIPO DE LAS EXPRESIONES FROM Y UNTIL SEAN NUMERICAS

	if(this->_from->getType() != NUMBER || this->_until->getType() != NUMBER){
		warning("Error en tiempo de ejecución: tipo incompatible para las expresiones DESDE o HASTA ", "For");
		return;
	}

	//COMPROBAR SI HAY COHERENCIA ENTRE LAS EXPRESIONES FROM Y UNTIL

	if(this->_step != NULL){

		if(this->_step->getType() != NUMBER){
			warning("Error en tiempo de ejecución: tipo incompatible para la expresion PASO ", "For");
			return;
		}


		//Si el paso es positivo
		if(this->_step->evaluateNumber() > 0){

			if(this->_from->evaluateNumber() > this->_until->evaluateNumber()){
				warning("Error en tiempo de ejecución: expresiones invalidas ", "For");
				return;
			}


		//Si el paso es negativo
		}else if (this->_step->evaluateNumber() < 0){

			if(this->_from->evaluateNumber() < this->_until->evaluateNumber()){
				warning("Error en tiempo de ejecución: expresiones invalidas ", "For");
				return;
			}

		//Si el paso es igual a cero hay que comprobar que no se entre en bucle infinito
		}else{

			//Si las expresiones son distintas y el paso es 0. BUCLE INFINITO
			if(!(std::abs( (this->_from->evaluateNumber() - this->_until->evaluateNumber())) < ERROR_BOUND)){
				warning("Error en tiempo de ejecución: bucle infinito ", "For");
				return;
			}

		}

	//Paso igual a 1
	}else{

		if(this->_from->evaluateNumber() > this->_until->evaluateNumber()){
				warning("Error en tiempo de ejecución: expresiones invalidas ", "For");
				return;
			}

	}


	//INICIALIZACION DE LA VARIABLE CON EL VALOR DE LA EXPRESION DESDE

	lp::Variable *var = (lp::Variable *) table.getSymbol(this->_varID);

	// evaluate the expression as NUMBER
 	double value = this->_from->evaluateNumber();

	// Check the type of the first varible
	if (var->getType() == NUMBER)
	{
	  	// Get the identifier in the table of symbols as NumericVariable
		lp::NumericVariable *v = (lp::NumericVariable *) table.getSymbol(this->_varID);

		// Assignment the value to the identifier in the table of symbols
		v->setValue(value);
	}
	// The type of variable is not NUMBER
	else
	{
		// Delete the variable from the table of symbols
		table.eraseSymbol(this->_varID);

		// Insert the variable in the table of symbols as NumericVariable
		// with the type NUMBER and the value
		lp::NumericVariable *v = new lp::NumericVariable(this->_varID,
								VARIABLE,NUMBER,value);
		table.installSymbol(v);
	}


	//PARA INICIALIZAR EL BUCLE
	lp::NumericVariable *v = (lp::NumericVariable *) table.getSymbol(this->_varID);


	//COMPROBAR SI HAY ALGUNA EXPRESION PARA PASO
	if(this->_step==NULL){


		for(double i = v->getValue(); i < this->_until->evaluateNumber()
			|| std::abs( (this->_until->evaluateNumber() - i) ) < ERROR_BOUND; i++){


			this->_stmts->evaluate();



			var = (lp::Variable *) table.getSymbol(this->_varID);


			// Check the type of the first varible
			if (var->getType() == NUMBER)
			{
			  	// Get the identifier in the table of symbols as NumericVariable
				lp::NumericVariable *v = (lp::NumericVariable *) table.getSymbol(this->_varID);

				// Assignment the value to the identifier in the table of symbols
				v->setValue(i+1);
			}
			// The type of variable is not NUMBER
			else
			{
				// Delete the variable from the table of symbols
				table.eraseSymbol(this->_varID);

				// Insert the variable in the table of symbols as NumericVariable
				// with the type NUMBER and the value
				lp::NumericVariable *v = new lp::NumericVariable(this->_varID,
										VARIABLE,NUMBER,i+1);
				table.installSymbol(v);
			}

		}


	}else{

		if((this->_until->evaluateNumber() > this->_from->evaluateNumber() || std::abs( (this->_until->evaluateNumber() - this->_from->evaluateNumber()) ) < ERROR_BOUND )
		    && this->_step->evaluateNumber()>0){


			for(double i = v->getValue(); i < this->_until->evaluateNumber() ||
				std::abs( (this->_until->evaluateNumber() - i ) ) < ERROR_BOUND; i = i + this->_step->evaluateNumber()){


				this->_stmts->evaluate();


				var = (lp::Variable *) table.getSymbol(this->_varID);


				// Check the type of the first varible
				if (var->getType() == NUMBER)
				{
				  	// Get the identifier in the table of symbols as NumericVariable
					lp::NumericVariable *v = (lp::NumericVariable *) table.getSymbol(this->_varID);

					// Assignment the value to the identifier in the table of symbols
					v->setValue(i+this->_step->evaluateNumber());
				}
				// The type of variable is not NUMBER
				else
				{
					// Delete the variable from the table of symbols
					table.eraseSymbol(this->_varID);

					// Insert the variable in the table of symbols as NumericVariable
					// with the type NUMBER and the value
					lp::NumericVariable *v = new lp::NumericVariable(this->_varID,
											VARIABLE,NUMBER,i+this->_step->evaluateNumber());
					table.installSymbol(v);
				}

			}

		}else if((this->_until->evaluateNumber() < this->_from->evaluateNumber() || std::abs( (this->_until->evaluateNumber() - this->_from->evaluateNumber() ) ) < ERROR_BOUND )
						&& this->_step->evaluateNumber()<0){


			for(double i = v->getValue(); i > this->_until->evaluateNumber() || std::abs( (this->_until->evaluateNumber() - i ) ) < ERROR_BOUND; i = i + this->_step->evaluateNumber()){


				this->_stmts->evaluate();


				var = (lp::Variable *) table.getSymbol(this->_varID);


				// Check the type of the first varible
				if (var->getType() == NUMBER)
				{
				  	// Get the identifier in the table of symbols as NumericVariable
					lp::NumericVariable *v = (lp::NumericVariable *) table.getSymbol(this->_varID);

					// Assignment the value to the identifier in the table of symbols
					v->setValue(i+this->_step->evaluateNumber());
				}
				// The type of variable is not NUMBER
				else
				{
					// Delete the variable from the table of symbols
					table.eraseSymbol(this->_varID);

					// Insert the variable in the table of symbols as NumericVariable
					// with the type NUMBER and the value
					lp::NumericVariable *v = new lp::NumericVariable(this->_varID,
											VARIABLE,NUMBER,i+this->_step->evaluateNumber());
					table.installSymbol(v);
				}

			}

			//DESDE Y HASTA SON IGUALES Y EL PASO ES CERO. SOLO SE EJECUTAN LAS SENTENCIAS
		}else{

			this->_stmts->evaluate();

		}

	}


}



void lp::EraseStmt::evaluate()
{

	std::cout<<CLEAR_SCREEN;

}

void lp::PlaceStmt::evaluate()
{

	if(this->_x->getType() == NUMBER && this->_y->getType() == NUMBER){
		PLACE((int)this->_x->evaluateNumber(),(int)this->_y->evaluateNumber());
	}else{
		warning("Error en tiempo de ejecución: tipos incompatibles ", "Place");
	}

}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::SwitchStmt::print()
{
  std::cout << "SwitchStmt: "  << std::endl;
  this->_exp->print();
  this->_cases->print("");
  this->_default->print("");
  std::cout << std::endl;
}


void lp::SwitchStmt::evaluate()
{

	//El tipo de la expresion debe de ser numerico
	if(this->_exp->getType() != NUMBER){
		warning("Error en tiempo de ejecución: tipo incompatible para la expresion ", "SEGUN");
		return;
	} 

	bool CasoEvaluado = this->_cases->evaluate(this->_exp);

	if(this->_default != NULL && !CasoEvaluado){
		this->_default->evaluate();
	}

}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::AST::print()
{
	stmts->print("");
}



void lp::AST::evaluate()
{

  stmts->evaluate();

}
