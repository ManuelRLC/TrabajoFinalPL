

#include "funcionesAuxiliares.hpp"

#include <string>





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