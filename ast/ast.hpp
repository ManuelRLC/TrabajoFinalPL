/*!
	\file    ast.hpp
	\brief   Declaration of AST class
	\date    2018-12-13
	\version 1.0
*/

#ifndef _AST_HPP_
#define _AST_HPP_

#include <iostream>
#include <stdlib.h>
#include <string>
#include <list>


#define ERROR_BOUND 1.0e-6  //!< Error bound for the comparison of real numbers.


namespace lp
{
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
/*!
  \class   ExpNode
  \brief   Definition of atributes and methods of ExpNode class
  \warning Abstract class
*/
 class ExpNode
{
  public:
	/*!
		\brief   Type of  the expression
		\warning Pure virtual function: must be redefined in the heir classes
		\return  int
		\sa		 print
	*/
    virtual int getType() = 0;


	/*!
		\brief   Print the expression
		\warning Pure virtual function: must be redefined in the heir classes
		\return  void
		\sa		 evaluate()
	*/
    virtual void print() = 0;

	/*!
		\brief   Evaluate the expression as NUMBER
		\warning Virtual function: could be redefined in the heir classes
		\return  double
		\sa		 print
	*/
    virtual double evaluateNumber()
	{
		return 0.0;
	}


	/*!
		\brief   Evaluate the expression as BOOL
		\warning Virtual function: could be redefined in the heir classes
		\return  bool
		\sa		 print
	*/
    virtual bool evaluateBool()
	{
		return false;
	}
	/*!
		\brief   Evaluate the expression as STRING
		\warning Virtual function: could be redefined in the heir classes
		\return  string
		\sa		 print
	*/
	virtual std::string evaluateString(){

		std::string cadena="";
		return cadena;
	}

};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!
  \class VariableNode
  \brief Definition of atributes and methods of VariableNode class
  \note  VariableNode Class publicly inherits from ExpNode class
*/
class VariableNode : public ExpNode
{
	private:
	  std::string _id; //!< Name of the VariableNode

	public:

	/*!
		\brief Constructor of VariableNode
		\param value: double
		\post  A new VariableNode is created with the name of the parameter
		\note  Inline function
	*/
	  VariableNode(std::string const & value)
		{
			this->_id = value;
		}

	/*!
		\brief   Observer for the id of the variable
		\return  string
		\sa		 print
	*/
	std::string getId(){
		return _id;
	}

	/*!
		\brief   Type of the Variable
		\return  int
		\sa		 print
	*/
	 int getType();

	/*!
		\brief   Print the Variable
		\return  void
		\sa		 evaluate()
	*/
	  void print();

	/*!
		\brief   Evaluate the Variable as NUMBER
		\return  double
		\sa		 print
	*/
	  double evaluateNumber();

	/*!
		\brief   Evaluate the Variable as BOOL
		\return  bool
		\sa		 print
	*/
	  bool evaluateBool();

	  /*!
		\brief   Evaluate the Variable as STRING
		\return  string
		\sa		 print
	*/
	  std::string evaluateString();

};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!
  \class UnaryVariableNode
  \brief Definition of atributes and methods of UnaryVariableNode class
  \note  UnaryVariableNode Class publicly inherits from VariableNode class
  \warning Abstract Class
*/
class UnaryVariableNode : public VariableNode
{
	private:

	public:

	/*!
		\brief Constructor of UnaryVariableNode
		\param value: string
		\post  A new UnaryVariableNode is created with the name of the parameter
		\note  Inline function
	*/
	  UnaryVariableNode(std::string const & value): VariableNode(value)
		{

		}

	/*!
		\brief   Print the Variable
		\return  void
		\sa		 evaluate()
	*/
	  virtual void print()=0;

	/*!
		\brief   Evaluate the Variable as NUMBER
		\return  double
		\sa		 print
	*/
	 virtual double evaluateNumber()=0;


};



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!
  \class UnaryPostDecrementNode
  \brief Definition of atributes and methods of UnaryPostDecrementNode class
  \note  UnaryPostDecrementNode Class publicly inherits from UnaryVariableNode class
*/
class UnaryPostDecrementNode : public UnaryVariableNode
{
	private:

	public:

	/*!
		\brief Constructor of UnaryPostDecrementNode
		\param value: double
		\post  A new UnaryPostDecrementNode is created with the name of the parameter
		\note  Inline function
	*/
	  UnaryPostDecrementNode(std::string const & value):UnaryVariableNode(value)
		{

		}

	/*!
		\brief   Print the Variable
		\return  void
		\sa		 evaluate()
	*/
	  void print();

	/*!
		\brief   Evaluate the Variable as NUMBER
		\return  double
		\sa		 print
	*/
	  double evaluateNumber();


};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!
  \class UnaryPreDecrementNode
  \brief Definition of atributes and methods of UnaryPostDecrementNode class
  \note  UnaryPostDecrementNode Class publicly inherits from UnaryVariableNode class
*/
class UnaryPreDecrementNode : public UnaryVariableNode
{
	private:

	public:

	/*!
		\brief Constructor of UnaryPreDecrementNode
		\param value: double
		\post  A new UnaryPreDecrementNode is created with the name of the parameter
		\note  Inline function
	*/
	  UnaryPreDecrementNode(std::string const & value):UnaryVariableNode(value)
		{

		}

	/*!
		\brief   Print the Variable
		\return  void
		\sa		 evaluate()
	*/
	  void print();

	/*!
		\brief   Evaluate the Variable as NUMBER
		\return  double
		\sa		 print
	*/
	  double evaluateNumber();


};

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!
  \class UnaryPostIncrementNode
  \brief Definition of atributes and methods of UnaryPostIncrementNode class
  \note  UnaryPostIncrementNode Class publicly inherits from UnaryVariableNode class
*/
class UnaryPostIncrementNode : public UnaryVariableNode
{
	private:

	public:

	/*!
		\brief Constructor of UnaryPostIncrementNode
		\param value: double
		\post  A new UnaryPostIncrementNode is created with the name of the parameter
		\note  Inline function
	*/
	  UnaryPostIncrementNode(std::string const & value):UnaryVariableNode(value)
		{

		}

	/*!
		\brief   Print the Variable
		\return  void
		\sa		 evaluate()
	*/
	  void print();

	/*!
		\brief   Evaluate the Variable as NUMBER
		\return  double
		\sa		 print
	*/
	  double evaluateNumber();


};

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!
  \class UnaryPreIncrementNode
  \brief Definition of atributes and methods of UnaryPreIncrementNode class
  \note  UnaryPreIncrementNode Class publicly inherits from UnaryVariableNode class
*/
class UnaryPreIncrementNode : public UnaryVariableNode
{
	private:

	public:

	/*!
		\brief Constructor of UnaryPreIncrementNode
		\param value: double
		\post  A new UnaryPreIncrementNode is created with the name of the parameter
		\note  Inline function
	*/
	  UnaryPreIncrementNode(std::string const & value):UnaryVariableNode(value)
		{

		}

	/*!
		\brief   Print the Variable
		\return  void
		\sa		 evaluate()
	*/
	  void print();

	/*!
		\brief   Evaluate the Variable as NUMBER
		\return  double
		\sa		 print
	*/
	  double evaluateNumber();


};
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!
  \class ConstantNode
  \brief Definition of atributes and methods of ConstantNode class
  \note  ConstantNode Class publicly inherits from ExpNode class
*/
class ConstantNode : public ExpNode
{
	private:
	  std::string _id; //!< Name of the ConstantNode

	public:

	/*!
		\brief Constructor of ConstantNode
		\param value: double
		\post  A new ConstantNode is created with the name of the parameter
	*/
	  ConstantNode(std::string value)
		{
			this->_id = value;
		}

	/*!
		\brief   Type of the Constant
		\return  int
		\sa		 print
	*/
	 int getType();

	/*!
		\brief   Print the Constant
		\return  void
		\sa		 evaluate()
	*/
	  void print();

	/*!
		\brief   Evaluate the Constant as NUMBER
		\return  double
		\sa		 print
	*/
	  double evaluateNumber();

	/*!
		\brief   Evaluate the Constant as BOOL
		\return  bool
		\sa		 print
	*/
	  bool evaluateBool();
};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!
  \class NumberNode
  \brief Definition of atributes and methods of NumberNode class
  \note  NumberNode Class publicly inherits from ExpNode class
*/
class NumberNode : public ExpNode
{
 private:
   double _number; //!< \brief number of the NumberNode

 public:

/*!
	\brief Constructor of NumberNode
	\param value: double
	\post  A new NumberNode is created with the value of the parameter
	\note  Inline function
*/
  NumberNode(double value)
	{
	    this->_number = value;
	}

	/*!
	\brief   Get the type of the expression: NUMBER
	\return  int
	\sa		 print
	*/
	int getType();

	/*!
		\brief   Print the expression
		\return  void
		\sa		 evaluate()
	*/
	void print();

	/*!
		\brief   Evaluate the expression
		\return  double
		\sa		 print
	*/
	double evaluateNumber();
};



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!
  \class StringNode
  \brief Definition of atributes and methods of StringNode class
  \note  StringNode Class publicly inherits from ExpNode class
*/

class StringNode : public ExpNode
{
 private:
   std::string *_string; //!< \brief number of the StringNode

 public:

/*!
	\brief Constructor of StringNode
	\param value: string
	\post  A new StringNode is created with the value of the parameter
	\note  Inline function
*/
  StringNode(std::string * value)
	{
	    this->_string = value;
	}

	/*!
	\brief   Get the type of the expression: STRING
	\return  int
	\sa		 print
	*/
	int getType();

	/*!
		\brief   Print the expression
		\return  void
		\sa		 evaluate()
	*/
	void print();

	/*!
		\brief   Evaluate the expression
		\return  string
		\sa		 print
	*/
	std::string evaluateString();
};

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!
  \class   UnaryOperatorNode
  \brief   Definition of atributes and methods of UnaryOperatorNode class
  \note    UnaryOperatorNode Class publicly inherits from ExpNode class
  \warning Abstract class, because it does not redefine the print method of ExpNode
*/
class UnaryOperatorNode : public ExpNode
{
 protected:
  ExpNode *_exp;  //!< Child expression

 public:

/*!
	\brief Constructor of UnaryOperatorNode links the node to it child,
           and stores the character representation of the operator.
	\param expression: pointer to ExpNode
	\post  A new OperatorNode is created with the parameters
	\note  Inline function
*/
  UnaryOperatorNode(ExpNode *expression)
	{
		this->_exp = expression;
	}

	/*!
	\brief   Get the type of the child expression
	\return  int
	\sa		 print
	*/
	inline int getType()
	{
		return this->_exp->getType();
	}
};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!
  \class   NumericUnaryOperatorNode
  \brief   Definition of atributes and methods of UnaryOperatorNode class
  \note    UnaryOperatorNode Class publicly inherits from UnaryOperatorNode class
  \warning Abstract class, because it does not redefine the print method of ExpNode
*/
class NumericUnaryOperatorNode : public UnaryOperatorNode
{
 public:

/*!
	\brief Constructor of NumericUnaryOperatorNode uses UnaryOperatorNode's constructor as member initializer
	\param expression: pointer to ExpNode
	\post  A new NumericUnaryOperatorNode is created with the parameters
	\note  Inline function
*/
  NumericUnaryOperatorNode(ExpNode *expression): UnaryOperatorNode(expression)
	{
		// Empty
	}

	/*!
	\brief   Get the type of the child expression
	\return  int
	\sa		 print
	*/
	int getType();

};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!
  \class   UnaryMinusNode
  \brief   Definition of atributes and methods of UnaryMinusNode class
  \note    UnaryMinusNode Class publicly inherits from NumericUnaryOperatorNode class
*/
class UnaryMinusNode : public NumericUnaryOperatorNode
{

 public:

/*!
	\brief Constructor of UnaryMinusNode uses NumericUnaryOperatorNode's constructor as member initializer.
	\param expression: pointer to ExpNode
	\post  A new UnaryMinusNode is created with the parameter
	\note  Inline function: the NumericUnaryOperatorNode's constructor is used ad member initializer
*/
  UnaryMinusNode(ExpNode *expression): NumericUnaryOperatorNode(expression)
	{
		// empty
	}

/*!
	\brief   Print the expression
	\return  void
	\sa		 evaluate()
*/
  void print();

/*!
	\brief   Evaluate the expression
	\return  double
	\sa		 print
*/
  double evaluateNumber();
};

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

/*!
  \class   UnaryPlusNode
  \brief   Definition of atributes and methods of UnaryPlusNode class
  \note    UnaryPlusNode Class publicly inherits from NumericUnaryOperatorNode class
*/
class UnaryPlusNode : public NumericUnaryOperatorNode
{

 public:

/*!
	\brief Constructor of UnaryPlusNode uses NumericUnaryOperatorNode's constructor as member initializer
	\param expression: pointer to ExpNode
	\post  A new UnaryPlusNode is created with the parameter
*/
  UnaryPlusNode(ExpNode *expression): NumericUnaryOperatorNode(expression)
	{
		// empty
	}

/*!
	\brief   Print the expression
	\return  void
	\sa		 evaluate()
*/
  void print();

/*!
	\brief   Evaluate the expression
	\return  double
	\sa		 print
*/
  double evaluateNumber();
};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!
  \class   LogicalUnaryOperatorNode
  \brief   Definition of atributes and methods of UnaryOperatorNode class
  \note    UnaryOperatorNode Class publicly inherits from UnaryOperatorNode class
  \warning Abstract class, because it does not redefine the print method of ExpNode
*/
class LogicalUnaryOperatorNode : public UnaryOperatorNode
{
 public:

/*!
	\brief Constructor of LogicalUnaryOperatorNode uses UnaryOperatorNode's constructor as member initializer
	\param expression: pointer to ExpNode
	\post  A new NumericUnaryOperatorNode is created with the parameters
	\note  Inline function
*/
  LogicalUnaryOperatorNode(ExpNode *expression): UnaryOperatorNode(expression)
	{
		// Empty
	}

	/*!
	\brief   Get the type of the child expression
	\return  int
	\sa		 print
	*/
	int getType();

};

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

/*!
  \class   NotNode
  \brief   Definition of atributes and methods of UnaryPlusNode class
  \note    NotNode Class publicly inherits from LogicalUnaryOperatorNode class
*/
class NotNode : public LogicalUnaryOperatorNode
{

 public:

/*!
	\brief Constructor of NotNode uses LogicalUnaryOperatorNode's constructor as member initializer
	\param expression: pointer to ExpNode
	\post  A new NotNode is created with the parameter
*/
  NotNode(ExpNode *expression): LogicalUnaryOperatorNode(expression)
	{
		// empty
	}

/*!
	\brief   Print the NotNode
	\return  void
	\sa		 evaluate()
*/
  void print();

/*!
	\brief   Evaluate the NotNode
	\return  bool
	\sa		 print()
*/
  bool evaluateBool();
};



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!
  \class   OperatorNode
  \brief   Definition of atributes and methods of OperatorNode class
  \note    OperatorNode Class publicly inherits from ExpNode class
  \warning Abstract class, because it does not redefine the print and getType methods of ExpNode
*/
class OperatorNode : public ExpNode
{
	protected:
		ExpNode *_left;    //!< Left expression
		ExpNode *_right;   //!< Right expression

	public:
	/*!
		\brief Constructor of OperatorNode links the node to its children,
		\param L: pointer to ExpNode
		\param R: pointer to ExpNode
		\post  A new OperatorNode is created with the parameters
	*/
    OperatorNode(ExpNode *L, ExpNode *R)
	{
	    this->_left  = L;
    	this->_right = R;
	}

};



//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!
  \class   NumericOperatorNode
  \brief   Definition of atributes and methods of NumericOperatorNode class
  \note    NumericOperatorNode Class publicly inherits from OperatorNode class
  \warning Abstract class, because it does not redefine the print method of ExpNode
*/
class NumericOperatorNode : public OperatorNode
{
	public:

	/*!
		\brief Constructor of NumericOperatorNode uses OperatorNode's constructor as members initializer
		\param L: pointer to ExpNode
		\param R: pointer to ExpNode
		\post  A new NumericOperatorNode is created with the parameters
	*/
    NumericOperatorNode(ExpNode *L, ExpNode *R): OperatorNode(L,R)
	{
		//	Empty
	}

	/*!
	\brief   Get the type of the children expressions
	\return  int
	\sa		 print()
	*/
	int getType();
};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!
  \class   PlusNode
  \brief   Definition of atributes and methods of PlusNode class
  \note    PlusNode Class publicly inherits from NumericOperatorNode class
		   and adds its own print and evaluate functions
*/
class PlusNode : public NumericOperatorNode
{
  public:
/*!
	\brief Constructor of PlusNode uses NumericOperatorNode's constructor as members initializer
	\param L: pointer to ExpNode
	\param R: pointer to ExpNode
	\post  A new PlusNode is created with the parameter
*/
  PlusNode(ExpNode *L, ExpNode *R) : NumericOperatorNode(L,R)
  {
		// Empty
  }

/*!
	\brief   Print the PlusNode
	\return  void
	\sa		 evaluate()
*/
  void print();

/*!
	\brief   Evaluate the PlusNode
	\return  double
	\sa		 print
*/
  double evaluateNumber();
};



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!
  \class   MinusNode
  \brief   Definition of atributes and methods of MinusNode class
  \note    MinusNode Class publicly inherits from NumericOperatorNode class
		   and adds its own print and evaluate functions
*/
class MinusNode : public NumericOperatorNode
{
  public:

/*!
	\brief Constructor of MinusNode uses NumericOperatorNode's constructor as members initializer
	\param L: pointer to ExpNode
	\param R: pointer to ExpNode
	\post  A new MinusNode is created with the parameter
*/
  MinusNode(ExpNode *L, ExpNode *R): NumericOperatorNode(L,R)
  {
		// Empty
  }
/*!
	\brief   Print the MinusNode
	\return  void
	\sa		 evaluate()
*/
  void print();

/*!
	\brief   Evaluate the MinusNode
	\return  double
	\sa		 print
*/
  double evaluateNumber();
};



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!
  \class   MultiplicationNode
  \brief   Definition of atributes and methods of MultiplicationNode class
  \note    MultiplicationNode Class publicly inherits from NumericOperatorNode class
		   and adds its own print and evaluate functions
*/
class MultiplicationNode : public NumericOperatorNode
{
  public:

/*!
	\brief Constructor of MultiplicationNode uses NumericOperatorNode's constructor as members initializer
	\param L: pointer to ExpNode
	\param R: pointer to ExpNode
	\post  A new MultiplicationNode is created with the parameter
*/
  MultiplicationNode(ExpNode *L, ExpNode *R): NumericOperatorNode(L,R)
  {
		// Empty
  }
/*!
	\brief   Print the MultiplicationNode
	\return  void
	\sa		 evaluate()
*/
  void print();

/*!
	\brief   Evaluate the MultiplicationNode
	\return  double
	\sa		 print
*/
  double evaluateNumber();
};

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!
  \class   DivisionNode
  \brief   Definition of atributes and methods of DivisionNode class
  \note    DivisionNode Class publicly inherits from NumericOperatorNode class
		   and adds its own print and evaluate functions
*/
class DivisionNode : public NumericOperatorNode
{
  public:
/*!
	\brief Constructor of DivisionNode uses NumericOperatorNode's constructor as members initializer
	\param L: pointer to ExpNode
	\param R: pointer to ExpNode
	\post  A new DivisionNode is created with the parameter
*/
  DivisionNode(ExpNode *L, ExpNode *R): NumericOperatorNode(L,R)
  {
		// Empty
  }
/*!
	\brief   Print the DivisionNode
	\return  void
	\sa		 evaluate()
*/
  void print();

/*!
	\brief   Evaluate the DivisionNode
	\return  double
	\sa		 print
*/
  double evaluateNumber();
};

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!
  \class   IntegerDivisionNode
  \brief   Definition of atributes and methods of IntegerDivisionNode class
  \note    IntegerDivisionNode Class publicly inherits from NumericOperatorNode class
		   and adds its own print and evaluate functions
*/
class IntegerDivisionNode : public NumericOperatorNode
{

  public:
/*!
	\brief Constructor of IntegerDivisionNode uses NumericOperatorNode's constructor as members initializer
	\param L: pointer to ExpNode
	\param R: pointer to ExpNode
	\post  A new IntegerDivisionNode is created with the parameter
*/
  IntegerDivisionNode(ExpNode *L, ExpNode *R): NumericOperatorNode(L,R)
  {
		// Empty
  }

/*!
	\brief   Print the IntegerDivisionNode
	\return  void
	\sa		 evaluate()
*/
  void print();

/*!
	\brief   Evaluate the IntegerDivisionNode
	\return  double
	\sa		 print
*/
  double evaluateNumber();
};

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!
  \class   ModuloNode
  \brief   Definition of atributes and methods of ModuloNode class
  \note    ModuloNode Class publicly inherits from NumericOperatorNode class
		   and adds its own print and evaluate functions
*/
class ModuloNode : public NumericOperatorNode
{
  public:
/*!
	\brief Constructor of ModuloNode uses NumericOperatorNode's constructor as members initializer
	\param L: pointer to ExpNode
	\param R: pointer to ExpNode
	\post  A new ModuloNode is created with the parameter
*/
  ModuloNode(ExpNode *L, ExpNode *R): NumericOperatorNode(L,R)
  {
		// Empty
  }
/*!
	\brief   Print the ModuloNode
	\return  void
	\sa		 evaluate()
*/
  void print();

/*!
	\brief   Evaluate the ModuloNode
	\return  double
	\sa		 print
*/
  double evaluateNumber();
};

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!
  \class   PowerNode
  \brief   Definition of atributes and methods of PowerNode class
  \note    PowerNode Class publicly inherits from NumericOperatorNode class
		   and adds its own print and evaluate functions
*/
class PowerNode : public NumericOperatorNode
{
  public:
/*!
	\brief Constructor of PowerNode uses NumericOperatorNode's constructor as members initializer
	\param L: pointer to ExpNode
	\param R: pointer to ExpNode
	\post  A new PowerNode is created with the parameter
*/
  PowerNode(ExpNode *L, ExpNode *R): NumericOperatorNode(L,R)
  {
		// Empty
  }

/*!
	\brief   Print the PowerNode
	\return  void
	\sa		 evaluate()
*/
  void print();

/*!
	\brief   Evaluate the PowerNode
	\return  double
	\sa		 print
*/
  double evaluateNumber();
};


//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!
  \class   StringOperatorNode
  \brief   Definition of atributes and methods of StringOperatorNode class
  \note    StringOperatorNode Class publicly inherits from OperatorNode class
  \warning Abstract class, because it does not redefine the print method of ExpNode
*/
class StringOperatorNode : public OperatorNode
{
	public:

	/*!
		\brief Constructor of StringOperatorNode uses OperatorNode's constructor as members initializer
		\param L: pointer to ExpNode
		\param R: pointer to ExpNode
		\post  A new StringOperatorNode is created with the parameters
	*/
    StringOperatorNode(ExpNode *L, ExpNode *R): OperatorNode(L,R)
	{
		//	Empty
	}

	/*!
	\brief   Get the type of the children expressions
	\return  int
	\sa		 print()
	*/
	int getType();
};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!
  \class   ConcatenateNode
  \brief   Definition of atributes and methods of ConcatenateNode class
  \note    ConcatenateNode Class publicly inherits from StringOperatorNode class
		   and adds its own print and evaluate functions
*/
class ConcatenateNode : public StringOperatorNode
{
  public:
/*!
	\brief Constructor of ConcatenateNode uses ConcatenateOperatorNode's constructor as members initializer
	\param L: pointer to ExpNode
	\param R: pointer to ExpNode
	\post  A new ConcatenateNode is created with the parameter
*/
  ConcatenateNode(ExpNode *L, ExpNode *R) : StringOperatorNode(L,R)
  {
		// Empty
  }

/*!
	\brief   Print the ConcatenateNode
	\return  void
	\sa		 evaluate()
*/
  void print();

/*!
	\brief   Evaluate the ConcatenateNode
	\return  string
	\sa		 print
*/
  std::string evaluateString();
};



//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!
  \class   RelationalOperatorNode
  \brief   Definition of atributes and methods of RelationalOperatorNode class
  \note    RelationalOperatorNode Class publicly inherits from OperatorNode class
  \warning Abstract class, because it does not redefine the print method of ExpNode
*/
class RelationalOperatorNode : public OperatorNode
{
public:
/*!
	\brief Constructor of RelationalOperatorNode uses OperatorNode's constructor as members initializer
	\param L: pointer to ExpNode
	\param R: pointer to ExpNode
	\post  A new RelationalOperatorNode is created with the parameters
*/
    RelationalOperatorNode(ExpNode *L, ExpNode *R): OperatorNode(L,R)
	{
		//	Empty
	}

	/*!
	\brief   Get the type of the children expressions
	\return  int
	\sa		 print()
	*/
	int getType();

};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!
  \class   GreaterThanNode
  \brief   Definition of atributes and methods of GreaterThanNode class
  \note    GreaterThanNode Class publicly inherits from RelationalOperatorNode class
		   and adds its own print and evaluate functions
*/
class GreaterThanNode : public RelationalOperatorNode
{
  public:

/*!
	\brief Constructor of GreaterThanNode uses RelationalOperatorNode's constructor as members initializer
	\param L: pointer to ExpNode
	\param R: pointer to ExpNode
	\post  A new GreaterThanNode is created with the parameter
*/
  GreaterThanNode(ExpNode *L, ExpNode *R): RelationalOperatorNode(L,R)
  {
		// Empty
  }


/*!
	\brief   Print the GreaterThanNode
	\return  void
	\sa		 evaluate()
*/
  void print();

/*!
	\brief   Evaluate the GreaterThanNode
	\return  bool
	\sa		 print
*/
  bool evaluateBool();
};



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!
  \class   GreaterOrEqualNode
  \brief   Definition of atributes and methods of GreaterOrEqualNode class
  \note    GreaterOrEqualNode Class publicly inherits from RelationalOperatorNode class
		   and adds its own print and evaluate functions
*/
class GreaterOrEqualNode : public RelationalOperatorNode
{
  public:

/*!
	\brief Constructor of GreaterOrEqualNode uses RelationalOperatorNode's constructor as members initializer
	\param L: pointer to ExpNode
	\param R: pointer to ExpNode
	\post  A new GreaterOrEqualNode is created with the parameter
*/
  GreaterOrEqualNode(ExpNode *L, ExpNode *R): RelationalOperatorNode(L,R)
  {
		// Empty
  }
/*!
	\brief   Print the GreaterOrEqualNode
	\return  void
	\sa		 evaluate()
*/
  void print();

/*!
	\brief   Evaluate the GreaterOrEqualNode
	\return  bool
	\sa		 print()
*/
  bool evaluateBool();
};



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!
  \class   LessThanNode
  \brief   Definition of atributes and methods of LessThanNode class
  \note    LessThanNode Class publicly inherits from RelationalOperatorNode class
		   and adds its own print and evaluate functions
*/
class LessThanNode : public RelationalOperatorNode
{
  public:

/*!
	\brief Constructor of LessThanNode uses RelationalOperatorNode's constructor as members initializer
	\param L: pointer to ExpNode
	\param R: pointer to ExpNode
	\post  A new LessThanNode is created with the parameter
*/
  LessThanNode(ExpNode *L, ExpNode *R): RelationalOperatorNode(L,R)
  {
		// Empty
  }
/*!
	\brief   Print the LessThanNode
	\return  void
	\sa		 evaluate()
*/
  void print();

/*!
	\brief   Evaluate the LessThanNode
	\return  bool
	\sa		 print()
*/
  bool evaluateBool();
};



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!
  \class   LessOrEqualNode
  \brief   Definition of atributes and methods of LessOrEqualNode class
  \note    LessThanNode Class publicly inherits from RelationalOperatorNode class
		   and adds its own print and evaluate functions
*/
class LessOrEqualNode : public RelationalOperatorNode
{
  public:

/*!
	\brief Constructor of LessOrEqualNode uses RelationalOperatorNode's constructor as members initializer
	\param L: pointer to ExpNode
	\param R: pointer to ExpNode
	\post  A new LessOrEqualNode is created with the parameter
*/
  LessOrEqualNode(ExpNode *L, ExpNode *R): RelationalOperatorNode(L,R)
  {
		// Empty
  }
/*!
	\brief   Print the LessOrEqualNode
	\return  void
	\sa		 evaluate()
*/
  void print();

/*!
	\brief   Evaluate the LessOrEqualNode
	\return  bool
	\sa		 print()
*/
  bool evaluateBool();
};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!
  \class   EqualNode
  \brief   Definition of atributes and methods of EqualNode class
  \note    EqualNode Class publicly inherits from RelationalOperatorNode class
		   and adds its own print and evaluate functions
*/
class EqualNode : public RelationalOperatorNode
{
  public:

/*!
	\brief Constructor of EqualNode uses RelationalOperatorNode's constructor as members initializer
	\param L: pointer to ExpNode
	\param R: pointer to ExpNode
	\post  A new EqualNode is created with the parameter
*/
  EqualNode(ExpNode *L, ExpNode *R): RelationalOperatorNode(L,R)
  {
		// Empty
  }
/*!
	\brief   Print the EqualNode
	\return  void
	\sa		 evaluate()
*/
  void print();

/*!
	\brief   Evaluate the EqualNode
	\return  bool
	\sa		 print()
*/
  bool evaluateBool();;
};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!
  \class   NotEqualNode
  \brief   Definition of atributes and methods of NotEqualNode class
  \note    NotEqualNode Class publicly inherits from RelationalOperatorNode class
		   and adds its own print and evaluate functions
*/
class NotEqualNode : public RelationalOperatorNode
{
  public:

/*!
	\brief Constructor of NotEqualNode uses RelationalOperatorNode's constructor as members initializer
	\param L: pointer to ExpNode
	\param R: pointer to ExpNode
	\post  A new NotEqualNode is created with the parameter
*/
  NotEqualNode(ExpNode *L, ExpNode *R): RelationalOperatorNode(L,R)
  {
		// Empty
  }

/*!
	\brief   Print the NotEqualNode
	\return  void
	\sa		 evaluate()
*/
  void print();

/*!
	\brief   Evaluate the NotEqualNode
	\return  bool
	\sa		 print()
*/
  bool evaluateBool();
};


//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!
  \class   LogicalOperatorNode
  \brief   Definition of atributes and methods of LogicalOperatorNode class
  \note    NumericOperatorNode Class publicly inherits from OperatorNode class
  \warning Abstract class, because it does not redefine the print method of ExpNode
*/
class LogicalOperatorNode : public OperatorNode
{
	public:

	/*!
		\brief Constructor of LogicalOperatorNode uses OperatorNode's constructor as members initializer
		\param L: pointer to ExpNode
		\param R: pointer to ExpNode
		\post  A new NumericOperatorNode is created with the parameters
	*/
    LogicalOperatorNode(ExpNode *L, ExpNode *R): OperatorNode(L,R)
	{
		//	Empty
	}

	/*!
	\brief   Get the type of the children expressions
	\return  int
	\sa		 print()
	*/
	int getType();
};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!
  \class   AndNode
  \brief   Definition of atributes and methods of AndNode class
  \note    AndNode Class publicly inherits from LogicalOperatorNode class
		   and adds its own print and evaluate functions
*/
class AndNode : public LogicalOperatorNode
{
  public:

/*!
	\brief Constructor of AndNode uses LogicalOperatorNode's constructor as members initializer
	\param L: pointer to ExpNode
	\param R: pointer to ExpNode
	\post  A new AndNode is created with the parameter
*/
  AndNode(ExpNode *L, ExpNode *R): LogicalOperatorNode(L,R)
  {
		// Empty
  }

/*!
	\brief   Print the AndNode
	\return  void
	\sa		 evaluate()
*/
  void print();

/*!
	\brief   Evaluate the AndNode
	\return  bool
	\sa		 print()
*/
  bool evaluateBool();
};




///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!
  \class   OrNode
  \brief   Definition of atributes and methods of OrNode class
  \note    OrNode Class publicly inherits from LogicalOperatorNode class
		   and adds its own print and evaluate functions
*/
class OrNode : public LogicalOperatorNode
{
  public:

/*!
	\brief Constructor of AndNode uses LogicalOperatorNode's constructor as members initializer
	\param L: pointer to ExpNode
	\param R: pointer to ExpNode
	\post  A new AndNode is created with the parameter
*/
  OrNode(ExpNode *L, ExpNode *R): LogicalOperatorNode(L,R)
  {
		// Empty
  }

/*!
	\brief   Print the OrNode
	\return  void
	\sa		 evaluate()
*/
  void print();

/*!
	\brief   Evaluate the OrNode
	\return  bool
	\sa		 print()
*/
  bool evaluateBool();
};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!
  \class   BuiltinFunctionNode
  \brief   Definition of atributes and methods of BuiltinFunctionNode class
  \note    BuiltinFunctionNode Class publicly inherits from ExpNode class
*/
class BuiltinFunctionNode : public ExpNode
{
  protected:
	std::string _id; //!< Name of the BuiltinFunctionNode

  public:
/*!
	\brief Constructor of BuiltinFunctionNode
	\param id: string, name of the BuiltinFunction
	\post  A new BuiltinFunctionNode is created with the parameter
*/
  BuiltinFunctionNode(std::string id)
	{
		this->_id = id;
	}

};




///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!
  \class   BuiltinFunctionNode_0
  \brief   Definition of atributes and methods of BuiltinFunctionNode_0 class
  \note    BuiltinFunctionNode_0 Class publicly inherits from BuiltinFunctionNode class
		   and adds its own print and evaluate functions
*/
class BuiltinFunctionNode_0 : public BuiltinFunctionNode
{
  public:
/*!
	\brief Constructor of BuiltinFunctionNode_0 uses BuiltinFunctionNode's constructor as member initializer
	\param id: string, name of the BuiltinFunction
	\post  A new BuiltinFunctionNode_2 is created with the parameter
*/
  BuiltinFunctionNode_0(std::string id): BuiltinFunctionNode(id)
	{
		//
	}

	/*!
		\brief   Get the type of the child expression:
		\return  int
		\sa		 print
	*/
	int getType();



	/*!
		\brief   Print the BuiltinFunctionNode_0
		\return  void
		\sa		 evaluate()
	*/
	  void print();

	/*!
		\brief   Evaluate the BuiltinFunctionNode_0
		\return  double
		\sa		 print
	*/
	  double evaluateNumber();
};



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!
  \class   BuiltinFunctionNode_1
  \brief   Definition of atributes and methods of BuiltinFunctionNode_1 class
  \note    BuiltinFunctionNode_1 Class publicly inherits from BuiltinFunctionNode class
		   and adds its own print and evaluate functions
*/
class BuiltinFunctionNode_1: public BuiltinFunctionNode
{
  private:
	ExpNode *_exp;  //!< Argument of the BuiltinFunctionNode_1

  public:
/*!
	\brief Constructor of BuiltinFunctionNode_1 uses BuiltinFunctionNode's constructor as member initializer
	\param id: string, name of the BuiltinFunction
	\param expression: pointer to ExpNode, argument of the BuiltinFunctionNode_1
	\post  A new BuiltinFunctionNode_1 is created with the parameters
*/
  BuiltinFunctionNode_1(std::string id, ExpNode *expression): BuiltinFunctionNode(id)
	{
		this->_exp = expression;
	}

	/*!
		\brief   Get the type of the child expression:
		\return  int
		\sa		 print
	*/
	int getType();

	/*!
		\brief   Print the BuiltinFunctionNode_1
		\return  void
		\sa		 evaluate()
	*/
	  void print();

	/*!
		\brief   Evaluate the BuiltinFunctionNode_1
		\return  double
		\sa		 print
	*/
	  double evaluateNumber();
};



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!
  \class   BuiltinFunctionNode_2
  \brief   Definition of atributes and methods of BuiltinFunctionNode_2 class
  \note    BuiltinFunctionNode_2 Class publicly inherits from BuiltinFunctionNode class
		   and adds its own print and evaluate functions
*/
class BuiltinFunctionNode_2 : public BuiltinFunctionNode
{
	private:
		ExpNode *_exp1; //!< First argument of the BuiltinFunction_2
		ExpNode *_exp2; //!< Second argument of the BuiltinFunction_2

	public:
	/*!
		\brief Constructor of BuiltinFunctionNode_2 uses BuiltinFunctionNode's constructor as member initializer
		\param id: string, name of the BuiltinFunction_2
		\param expression1: pointer to ExpNode, first argument of the BuiltinFunctionNode
		\param expression2: pointer to ExpNode, second argument of the BuiltinFunctionNode
		\post  A new BuiltinFunctionNode_2 is created with the parameters
	*/
	  BuiltinFunctionNode_2(std::string id,ExpNode *expression1,ExpNode *expression2): BuiltinFunctionNode(id)
	{
		this->_exp1 = expression1;
		this->_exp2 = expression2;
	}

	/*!
	\brief   Get the type of the children expressions
	\return  int
	\sa		 print
	*/
	int getType();



	/*!
		\brief   Print the BuiltinFunctionNode_2
		\return  void
		\sa		 evaluate()
	*/
	  void print();

	/*!
		\brief   Evaluate the BuiltinFunctionNode_2
		\return  double
		\sa		 print
	*/
	  double evaluateNumber();
};




///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!
  \class   Statement
  \brief   Definition of atributes and methods of Statement class
  \warning Abstract class
*/

class Statement {
 public:

/*!
	\brief   Print the Statement
	\note    Virtual function: can be redefined in the heir classes
	\return  void
	\sa		 print
*/

  virtual void print() {}

/*!
	\brief   Evaluate the Statement
	\warning Pure virtual function: must be redefined in the heir classes
	\return  void
	\sa		 print
*/
  virtual void evaluate() = 0;
};

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!
  \class   StatementList
  \brief   Definition of atributes and methods of StatementList class
*/
class StatementList {
 private:

 	std::list<Statement *> *_stmts; //!< List of statements


 public:

 /*!
	\brief Constructor of StatementList class
*/
 	StatementList(){
 		_stmts=new std::list<Statement *>();

 	}

/*!
	\brief   Print the list of Statemets
	\param   smg: Message used to print
	\return  void
	\sa		 evaluate
*/

  void print(std::string smg);

/*!
	\brief   Evaluate the list of Statemets
	\return  void
	\sa		 print
*/
  void evaluate();

 /*!
	\brief   Add new statement to the statement list
	\param   stmt: pointer to Statement
	\return  void
	\sa		 print
*/
  void addStatement(Statement* stmt);


};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!
  \class   Case
  \brief   Definition of atributes and methods of Statement class
  \warning Abstract class
*/

class Case {
 
 private:

 	StatementList* _stmts; //!< List of statements
 	double _value; //!< Value of the case

 public:


 /*!
	\brief Constructor of Case class
	\param value: double that represents the value of the case
	\param stmtList: pointer to StatementList of the case 
	\post  A new Case is created with the parameters
*/
 	Case(double value,StatementList* stmtList){

 		_value = value;
 		_stmts = stmtList;

 	}

/*!
	\brief   Print the list of statement of the case
	\param 	 msg: Message used to print
	\sa		 print
*/
  void print(std::string msg);

/*!
	\brief   Evaluate the list of statement of the case
	\sa		 print
*/
  void evaluate();

/*!
	\brief   Evaluate the value of the case
	\return  double
	\sa		 evaluate
*/
  double evaluateNumber();

};



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!
  \class   CaseList
  \brief   Definition of atributes and methods of CaseList class
*/
class CaseList {
 private:

 	std::list<Case *> *_cases; //!< List of cases

 public:


/*!
	\brief Constructor of CaseList class
*/
 	CaseList(){
 		_cases = new std::list<Case *>();
 	}

/*!
	\brief   Print the list of statement of case
	\param 	 smg: Message used to print
	\sa		 print
*/
  void print(std::string smg);

/*!
	\brief   Evaluate the list of cases
	\param 	 exp: Expresion of switch
	\return  bool: Return true if some case is evaluated
	\sa		 print
*/
  bool evaluate(ExpNode * exp);

 /*!
	\brief   Add new value to the cases list
	\param   value: pointer to Case
	\return  void
	\sa		 print
*/
  void addCase(Case* value);


};
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!
  \class   AssignmentStmt
  \brief   Definition of atributes and methods of AssignmentStmt class
  \note    AssignmentStmt Class publicly inherits from Statement class
		   and adds its own print and evaluate functions
*/
class AssignmentStmt : public Statement
{
 private:
  std::string _id;    //!< Name of the variable of the assignment statement
  ExpNode *_exp; 	 //!< Expresssion the assignment statement

  AssignmentStmt *_asgn;  //!< Allow multiple assigment -> a = b = 2

  UnaryVariableNode *_unary; //!< Allow last assignment to be an increment or a decrement-> a++

 public:

/*!
	\brief Constructor of AssignmentStmt
	\param id: string, variable of the AssignmentStmt
	\param expression: pointer to ExpNode
	\post  A new AssignmentStmt is created with the parameters
*/
  AssignmentStmt(std::string id, ExpNode *expression): _id(id), _exp(expression)
	{
		this->_asgn = NULL;
		this->_unary = NULL;
	}

/*!
	\brief Constructor of AssignmentStmt
	\param id: string, variable of the AssignmentStmt
	\param asgn: pointer to AssignmentStmt
	\post  A new AssignmentStmt is created with the parameters
	\note  Allow multiple assigment -> a = b = 2
*/

  AssignmentStmt(std::string id, AssignmentStmt *asgn): _id(id), _asgn(asgn)
	{
		this->_exp = NULL;
		this->_unary = NULL;
	}

/*!
	\brief Constructor of AssignmentStmt
	\param id: string, variable of the AssignmentStmt
	\param unary: pointer to UnaryVariableNode
	\post  A new AssignmentStmt is created with the parameters
*/

  AssignmentStmt(std::string id, UnaryVariableNode *unary): _id(id),  _unary(unary)
	{
		this->_exp = NULL;
		this->_asgn = NULL;
	}

/*!
	\brief Constructor of AssignmentStmt
	\param unary: pointer to UnaryVariableNode
	\post  A new AssignmentStmt is created with the parameters
	\note  Allow multiple assigment -> a = b = 2
*/

  AssignmentStmt(UnaryVariableNode *unary):  _unary(unary)
	{
		this->_id = "";
		this->_exp = NULL;
		this->_asgn = NULL;
	}

/*!
	\brief   Observer the name of the variable of the assignment statement
	\return  string
	\sa		 print
*/
	std::string getId(){
		return _id;
	}

/*!
	\brief   Observer the expresion of the assignment statement
	\return  string
	\sa		 print
*/	
	ExpNode * getExpression(){
		return _exp;
	}


/*!
	\brief   Print the AssignmentStmt
	\return  void
	\sa		 evaluate()
*/
   void print();

/*!
	\brief   Evaluate the AssignmentStmt
	\return  void
	\sa		 print
*/
    void evaluate();

};

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!
  \class   PlusAssignmentStmt
  \brief   Definition of atributes and methods of PlusAssignmentStmt class
  \note    PlusAssignmentStmt Class publicly inherits from AssignmentStmt class
		   and adds its own print and evaluate functions
*/
class PlusAssignmentStmt : public AssignmentStmt
{
 private:



 public:

/*!
	\brief Constructor of PlusAssignmentStmt
	\param id: string, variable of the PlusAssignmentStmt
	\param expression: pointer to ExpNode
	\post  A new PlusAssignmentStmt is created with the parameters
*/
  PlusAssignmentStmt(std::string id, ExpNode *expression): AssignmentStmt( id,expression)
	{
	}


/*!
	\brief   Print the PlusAssignmentStmt
	\return  void
	\sa		 evaluate()
*/
   void print();

/*!
	\brief   Evaluate the PlusAssignmentStmt
	\return  void
	\sa		 print
*/
    void evaluate();

};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!
  \class   MinusAssignmentStmt
  \brief   Definition of atributes and methods of MinusAssignmentStmt class
  \note    MinusAssignmentStmt Class publicly inherits from AssignmentStmt class
		   and adds its own print and evaluate functions
*/
class MinusAssignmentStmt : public AssignmentStmt
{
 private:



 public:

/*!
	\brief Constructor of MinusAssignmentStmt
	\param id: string, variable of the MinusAssignmentStmt
	\param expression: pointer to ExpNode
	\post  A new MinusAssignmentStmt is created with the parameters
*/
  MinusAssignmentStmt(std::string id, ExpNode *expression): AssignmentStmt( id,expression)
	{
	}




/*!
	\brief   Print the MinusAssignmentStmt
	\return  void
	\sa		 evaluate()
*/
   void print();

/*!
	\brief   Evaluate the MinusAssignmentStmt
	\return  void
	\sa		 print
*/
    void evaluate();

};

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!
  \class   MultiplicationAssignmentStmt
  \brief   Definition of atributes and methods of MultiplicationAssignmentStmt class
  \note    MultiplicationAssignmentStmt Class publicly inherits from AssignmentStmt class
		   and adds its own print and evaluate functions
*/
class MultiplicationAssignmentStmt : public AssignmentStmt
{
 private:



 public:

/*!
	\brief Constructor of MultiplicationAssignmentStmt
	\param id: string, variable of the MultiplicationAssignmentStmt
	\param expression: pointer to ExpNode
	\post  A new MultiplicationAssignmentStmt is created with the parameters
*/
  MultiplicationAssignmentStmt(std::string id, ExpNode *expression): AssignmentStmt( id,expression)
	{
	}




/*!
	\brief   Print the MultiplicationAssignmentStmt
	\return  void
	\sa		 evaluate()
*/
   void print();

/*!
	\brief   Evaluate the MultiplicationAssignmentStmt
	\return  void
	\sa		 print
*/
    void evaluate();

};

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!
  \class   DivisionAssignmentStmt
  \brief   Definition of atributes and methods of DivisionAssignmentStmt class
  \note    DivisionAssignmentStmt Class publicly inherits from AssignmentStmt class
		   and adds its own print and evaluate functions
*/
class DivisionAssignmentStmt : public AssignmentStmt
{
 private:



 public:

/*!
	\brief Constructor of DivisionAssignmentStmt
	\param id: string, variable of the DivisionAssignmentStmt
	\param expression: pointer to ExpNode
	\post  A new DivisionAssignmentStmt is created with the parameters
*/
  DivisionAssignmentStmt(std::string id, ExpNode *expression): AssignmentStmt( id,expression)
	{
	}




/*!
	\brief   Print the DivisionAssignmentStmt
	\return  void
	\sa		 evaluate()
*/
   void print();

/*!
	\brief   Evaluate the DivisionAssignmentStmt
	\return  void
	\sa		 print
*/
    void evaluate();

};
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!
  \class   PrintStmt
  \brief   Definition of atributes and methods of PrintStmt class
  \note    PrintStmt Class publicly inherits from Statement class
		   and adds its own print and evaluate functions
  \warning  In this class, print and evaluate functions have the same meaning.
*/
class PrintStmt: public Statement
{
 private:
  ExpNode *_exp; //!< Expresssion the print statement

 public:
/*!
	\brief Constructor of PrintStmt
	\param expression: pointer to ExpNode
	\post  A new PrintStmt is created with the parameter
*/
  PrintStmt(ExpNode *expression)
	{
		this->_exp = expression;
	}

/*!
	\brief   Print the PrintStmt
	\return  void
	\sa		 evaluate()
*/
  void print();

/*!
	\brief   Evaluate the PrintStmt
	\return  void
	\sa		 print
*/
  void evaluate();
};



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!
  \class   ReadStmt
  \brief   Definition of atributes and methods of ReadStmt class
  \note    ReadStmt Class publicly inherits from Statement class
		   and adds its own print and evaluate functions
*/
class ReadStmt : public Statement
{
  private:
	std::string _id; //!< Name of the ReadStmt


  public:
/*!
	\brief Constructor of ReadStmt
	\param id: string, name of the variable of the ReadStmt
	\post  A new ReadStmt is created with the parameter
*/
  ReadStmt(std::string id)
	{
		this->_id = id;
	}

/*!
	\brief   Print the ReadStmt
	\return  void
	\sa		 evaluate()
*/
  void print();

/*!
	\brief   Evaluate the ReadStmt
	\return  void
	\sa		 print
*/
  void evaluate();
};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!
  \class   ReadStringStmt
  \brief   Definition of atributes and methods of ReadStringStmt class
  \note    ReadStringStmt Class publicly inherits from Statement class
		   and adds its own print and evaluate functions
*/
class ReadStringStmt : public Statement
{
  private:
	std::string _id; //!< Name of the ReadStringStmt


  public:
/*!
	\brief Constructor of ReadStringStmt
	\param id: string, name of the variable of the ReadStringStmt
	\post  A new ReadStringStmt is created with the parameter
*/
  ReadStringStmt(std::string id)
	{
		this->_id = id;
	}

/*!
	\brief   Print the ReadStringStmt
	\return  void
	\sa		 evaluate()
*/
  void print();

/*!
	\brief   Evaluate the ReadStringStmt
	\return  void
	\sa		 print
*/
  void evaluate();
};



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!
  \class   EmptyStmt
  \brief   Definition of atributes and methods of EmptyStmt class
  \note    EmptyStmt Class publicly inherits from Statement class
		   and adds its own print and evaluate functions
*/
class EmptyStmt : public Statement
{
  // No attributes

  public:
/*!
	\brief Constructor of  WhileStmt
	\post  A new EmptyStmt is created
*/
  EmptyStmt()
	{
		// Empty
	}


/*!
	\brief   Print the EmptyStmt
	\return  void
	\sa		 evaluate()
*/
  void print();

/*!
	\brief   Evaluate the EmptyStmt
	\return  void
	\sa		 print
*/
  void evaluate();
};

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!
  \class   IfStmt
  \brief   Definition of atributes and methods of IfStmt class
  \note    IfStmt Class publicly inherits from Statement class
		   and adds its own print and evaluate functions
*/
class IfStmt : public Statement
{
 private:
  ExpNode *_cond; //!< Condicion of the if statement
  StatementList* _consequent; //!< StatementList of the consequent
  StatementList* _alternative; //!< StatementList of the alternative

  public:
/*!
	\brief Constructor of Single IfStmt (without alternative)
	\param condition: ExpNode of the condition
	\param consequent: StatementList of the consequent
	\post  A new IfStmt is created with the parameters
*/
  IfStmt(ExpNode *condition, StatementList* consequent)
	{
		this->_cond = condition;
		this->_consequent = consequent;
		this->_alternative = NULL;
	}


/*!
	\brief Constructor of Compound IfStmt (with alternative)
	\param condition: ExpNode of the condition
	\param consequent: StatementList of the consequent
	\param alternative: StatementList of the alternative
	\post  A new IfStmt is created with the parameters
*/
  IfStmt(ExpNode *condition, StatementList* consequent, StatementList* alternative)
	{
		this->_cond = condition;
		this->_consequent = consequent;
		this->_alternative = alternative;
	}


/*!
	\brief   Print the IfStmt
	\return  void
	\sa		 evaluate
*/
  void print();

/*!
	\brief   Evaluate the IfStmt
	\return  void
	\sa		 print
*/
  void evaluate();
};



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!
  \class   WhileStmt
  \brief   Definition of atributes and methods of WhileStmt class
  \note    WhileStmt Class publicly inherits from Statement class
		   and adds its own print and evaluate functions
*/
class WhileStmt : public Statement
{
 private:
  ExpNode *_cond; //!< Condicion of the while statement
  StatementList* _stmts; //!< Statements of the body of the while loop

  public:
/*!
	\brief Constructor of  WhileStmt
	\param condition: ExpNode of the condition
	\param statements: Statements of the body of the loop
	\post  A new WhileStmt is created with the parameters
*/
  WhileStmt(ExpNode *condition, StatementList* statements)
	{
		this->_cond = condition;
		this->_stmts = statements;
	}


/*!
	\brief   Print the WhileStmt
	\return  void
	\sa		 evaluate
*/
  void print();

/*!
	\brief   Evaluate the WhileStmt
	\return  void
	\sa		 print
*/
  void evaluate();
};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!
  \class   RepeatStmt
  \brief   Definition of atributes and methods of RepeatStmt class
  \note    RepeatStmt Class publicly inherits from Statement class
		   and adds its own print and evaluate functions
*/
class RepeatStmt : public Statement
{
 private:
 	StatementList* _stmts; //!< Statements of the body of the repeat loop
  	ExpNode *_cond; //!< Condicion of the repeat statement


  public:
/*!
	\brief Constructor of  RepeatStmt
	\param condition: ExpNode of the condition
	\param statements: Statements of the body of the loop
	\post  A new RepeatStmt is created with the parameters
*/
  RepeatStmt(StatementList* statements,ExpNode *condition )
	{
		this->_stmts = statements;
		this->_cond = condition;

	}


/*!
	\brief   Print the RepeatStmt
	\return  void
	\sa		 evaluate
*/
  void print();

/*!
	\brief   Evaluate the RepeatStmt
	\return  void
	\sa		 print
*/
  void evaluate();
};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
/*!
  \class   ForStmt
  \brief   Definition of atributes and methods of ForStmt class
  \note    ForStmt Class publicly inherits from Statement class
		   and adds its own print and evaluate functions
*/
class ForStmt : public Statement
{
 private:

	std::string _varID; //!< Name of the variable of the for statement
	ExpNode *_from; //!< From of the for statement
	ExpNode *_until; //!< Until of the for statement
	ExpNode *_step; //!< Step of the step statement
	StatementList *_stmts; //!< Statements of the body of the for loop

  public:

/*!
	\brief Constructor of ForStmt
	\param id: Name of the variable of the for statement
	\param from: ExpNode of the from expresion
	\param until: ExpNode of the until expresion
	\param step: ExpNode of the step expresion
	\param statements: Statements of the body of the loop
	\post  A new ForStmt is created with the parameters
*/
	ForStmt(std::string id,ExpNode *from,ExpNode *until,ExpNode *step,StatementList* statements)
	{
		this->_varID = id;
		this->_from = from;
		this->_until = until;
		this->_step = step;
		this->_stmts = statements;
	}

/*!
	\brief Constructor of ForStmt
	\param id: Name of the variable of the for statement
	\param from: ExpNode of the from expresion
	\param until: ExpNode of the until expresion
	\param statements: Statements of the body of the loop
	\post  A new ForStmt is created with the parameters
*/
	ForStmt(std::string id,ExpNode *from,ExpNode *until,StatementList* statements)
	{
		this->_varID = id;
		this->_from = from;
		this->_until = until;
		this->_step = NULL;
		this->_stmts = statements;
	}



/*!
	\brief   Print the ForStmt
	\return  void
	\sa		 evaluate
*/
  void print();

/*!
	\brief   Evaluate the ForStmt
	\return  void
	\sa		 print
*/
  void evaluate();
};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
/*!
  \class   SwitchStmt
  \brief   Definition of atributes and methods of SwitchStmt class
  \note    SwitchStmt Class publicly inherits from Statement class
		   and adds its own print and evaluate functions
*/
class SwitchStmt : public Statement
{
 private:

  ExpNode *_exp; //!< ExpNode of the condition
  CaseList *_cases; //!< list of cases of the statement switch

  StatementList *_default; //!< list of statement of the default case


  public:
/*!
	\brief Constructor of SwitchStmt
	\param exp: ExpNode of the condition
	\param cases: list of cases of the statement switch
	\param defecto: pointer to Statement list of the default case
	\post  A new SwitchStmt is created with the parameters
*/
  SwitchStmt(ExpNode *exp,CaseList *cases,StatementList* defecto)
	{
		this->_exp = exp;
		this->_cases = cases;
		this->_default = defecto;
	}
/*!
	\brief Constructor of SwitchStmt
	\param exp: ExpNode of the condition
	\param cases: list of cases of the statement switch
	\post  A new SwitchStmt is created with the parameters
*/
  SwitchStmt(ExpNode *exp,CaseList *cases)
	{
		this->_exp = exp;
		this->_cases = cases;
		this->_default = NULL;
	}


/*!
	\brief   Print the SwitchStmt
	\return  void
	\sa		 evaluate
*/
  void print();

/*!
	\brief   Evaluate the SwitchStmt
	\return  void
	\sa		 print
*/
  void evaluate();
};



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!
  \class   EraseStmt
  \brief   Definition of atributes and methods of EraseStmt class
  \note    EraseStmt Class publicly inherits from Statement class
		   and adds evaluate function
*/
class EraseStmt : public Statement
{
  public:

/*!
	\brief   Evaluate the EraseStmt
	\return  void
	\sa		 print
*/
  void evaluate();
};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
/*!
  \class   PlaceStmt
  \brief   Definition of atributes and methods of PlaceStmt class
  \note    PlaceStmt Class publicly inherits from Statement class
		   and adds evaluate function
*/
class PlaceStmt : public Statement
{

  private:

  	ExpNode *_x; //!< Coordinate x of the position

  	ExpNode *_y; //!< Coordinate y of the position

  public:

  	/*!
		\brief Constructor of PlaceStmt
		\param x: Coordinate x of the position
		\param y: Coordinate y of the position
		\post  A new PlaceStmt is created with the parameters
	*/
  	PlaceStmt(ExpNode * x, ExpNode * y){
  		this->_x = x;
  		this->_y = y;
  	}

/*!
	\brief   Evaluate the EraseStmt
	\return  void
	\sa		 print
*/
  void evaluate();
};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!
  \class   AST
  \brief   Definition of atributes and methods of AST class
*/
class AST {
 private:
  StatementList *stmts;  //!< List of statements

 public:

/*!
	\brief Constructor of PrintStmt
	\param stmtList: pointer to a StatementList of pointers to Statement
	\post  A new PrintStmt is created with the parameter
*/
  AST(StatementList *stmtList): stmts(stmtList)
	{
		// Empty
	}

/*!
	\brief   print the AST
	\return  void
	\sa		 evaluate()
*/
  void print();

/*!
	\brief   evaluate the AST
	\return  double
	\sa		 print
*/
  void evaluate();
};

// End of name space lp
}



// End of _AST_HPP_
#endif
