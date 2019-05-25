/*!
	\file    funcionesAuxiliares.cpp
	\brief   Code of funcitons of funcionesAuxiliares.hpp
	\version 1.0
*/
#include "funcionesAuxiliares.hpp"

#include <string>

#include "../ast/ast.hpp"

/*  interpreter.tab.h contains the numeric values of the tokens produced by the parser */
#include "interpreter.tab.h"



std::string parseSlash(char * str,int leng){

	std::string aux;
	bool check=false;

	for(int i =0; i<leng;i++){

		if(!check){
			if(str[i]!='\\'){
				aux.push_back(str[i]);
			}
			else{
				check=true;
			}
			
		}
		else{
			check=false;
			if(str[i]=='n'){
				aux.push_back('\n');
			}
			else if(str[i]=='t'){
				aux.push_back('\t');
			}
			else{
				aux.push_back(str[i]);
			}


		}
		
		
	}

	return aux;

}


void changeStringToLower(char* identifier){
	for(int i=0; identifier[i]!='\0';i++){
		identifier[i] = tolower(identifier[i]);
	}
}


bool isSentenciaControl(int token){

	switch (token){
		case IF:
			return true;
		break;
		case WHILE:
			return true;
		break;
		case FOR:
			return true;
		break;
		case REPEAT:
			return true;
		break;
		case SWITCH:
			return true;
		break;
	}
	return false;
}

bool isFinSentenciaControl(int token){

	switch (token){
		case ENDIF:
			return true;
		break;
		case ENDWHILE:
			return true;
		break;
		case ENDFOR:
			return true;
		break;
		case UNTIL:
			return true;
		break;
		case ENDSWITCH:
			return true;
		break;
	}
	return false;	
}