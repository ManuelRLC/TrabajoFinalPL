#
  Asignatura:    Procesadores de Lenguajes

  Titulación:    Ingeniería Informática
  Especialidad:  Computación
  Curso:         Tercero
  Cuatrimestre:  Segundo

  Departamento:  Informática y Análisis Numérico
  Centro:        Escuela Politécnica Superior de Córdoba
  Universidad de Córdoba
 
  Curso académico: 2018 - 2019

  Fichero de ejemplo nº 5 para el intérprete de pseudocódigo en español: ipe.exe
#

@ Bienvenida

_borrar;

_lugar(10,10);

escribir('Introduce tu nombre --> ');

leer(nombre);

_borrar;
_lugar(10,10);

escribir(' Bienvenido/a << ');

escribir(nombre);

escribir(' >> al intérprete de pseudocódigo en español:\'ipe.exe\'.');

_lugar(40,10);
escribir('Pulsa una tecla para continuar');
leer( pausa);


repetir 

 @ Opciones disponibles

 _borrar;

 _lugar(10,10);
 escribir(' Factorial de un número --> 1 ');

 _lugar(11,10);
 escribir(' Máximo común divisor ----> 2 ');

 _lugar(12,10);
 escribir(' Finalizar ---------------> 0 ');

 _lugar(15,10);
 escribir(' Elige una opcion ');

 leer(opcion);

 _borrar;

 si (opcion  = 0)        @ Fin del programa
    entonces  
        _lugar(10,10);
        escribir(nombre);
        escribir(': gracias por usar el intérprete ipe.exe ');

   si_no
       @ Factorial de un número
	si (opcion = 1)
   	    entonces
                _lugar(10,10);
		escribir(' Factorial de un numero  ');

                _lugar(11,10);
		escribir(' Introduce un numero entero ');
		leer(N);

        	factorial := 1;

       		para i desde 2 hasta N paso 1 hacer
	            factorial := factorial * i;
        	fin_para;

        	@ Resultado
	        _lugar(15,10);
		escribir(' El factorial de ');
		escribir(N);
		escribir(' es ');
		escribir(factorial);
    
   	@ Máximo común divisor
	si_no 
		si (opcion = 2)
			entonces
				_lugar(10,10);
				escribir(' Máximo común divisor de dos números ');

				_lugar(11,10);
                		escribir(' Algoritmo de Euclides ');

                		_lugar(12,10);
                		escribir(' Escribe el primer número ');
                		leer(a);

                  		_lugar(13,10);
                  		escribir(' Escribe el segundo número ');
                  		leer(b);

                  		@ Se ordenan los números
				si (a < b)
					entonces 
						auxiliar := a;
						a := b;
						b := auxiliar;
				fin_si;

					@ Se guardan los valores originales
					A1 := a;
					B1 := b;

					@ Se aplica el método de Euclides	
					resto  := a _mod b;

					mientras (resto <> 0) hacer
						a :=  b;
						b := resto;
						resto := a _mod b;
					fin_mientras;
         
					@ Se muestra el resultado
					_lugar(15,10);
					escribir(' Máximo común divisor de ');
					escribir(A1);
					escribir(' y ');
					escribir(B1);
					escribir(' es ---> ');
					escribir(b);

			@ Resto de opciones
 			si_no  
				_lugar(15,10);
			    	escribir(' Opcion incorrecta ');

 			fin_si;   
  	fin_si;                 

  fin_si;                          

 _lugar(40,10); 
 escribir('\n Pulse una tecla para continuar --> ');
 leer(pausa);
 
hasta (opcion = 0);             

@ Despedida final

_borrar;
_lugar(10,10);
escribir('El programa ha concluido');

