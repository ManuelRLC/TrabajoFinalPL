/*!
	\file    funcionesAuxiliares.hpp
	\brief   Definitions of the auxiliary functions
	\version 1.0
*/
#ifndef _FUNCIONES_AUXILIARES_HPP
#define _FUNCIONES_AUXILIARES_HPP

#include <string>

/*!
	\brief   Function that converts '\\n' and '\\t' into a unique character
	\param 	 str: char*
	\param 	 leng: int
	\return  string
*/
std::string parseSlash(char * str,int leng);

/*!
	\brief Function that convert a string to lowercase 
	\param identifier: char*
*/
void changeStringToLower(char* identifier);

/*!
	\brief   Function that checks if a control statement has started
	\param 	 token: int
	\return  bool
	\sa		 isFinSentenciaControl
*/
bool isSentenciaControl(int token);

/*!
	\brief   Function that checks if a control statement has finished
	\param 	 token: int
	\return  bool
	\sa		 isSentenciaControl
*/
bool isFinSentenciaControl(int token);



#endif