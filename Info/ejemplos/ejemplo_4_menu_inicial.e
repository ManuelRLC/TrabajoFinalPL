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

  Fichero de ejemplo nº 4 para el intérprete de pseudocódigo en español: ipe.exe
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
leer(pausa);

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

 si (opcion = 0)        
    entonces  
	@ Fin del programa
        _lugar(10,10);
        escribir(nombre);
        escribir(': gracias por usar el intérprete ipe.exe ');

   si_no
        @ Factorial de un número
	si (opcion = 1)
   	    entonces
                _lugar(10,10);
		escribir('Ha elegido la opción de Factorial de un número  ');

	si_no  
 		@ Máximo común divisor
		si (opcion = 2)
		   entonces
			_lugar(10,10);
			escribir(' Ha elegido la opción de Máximo común divisor');

		@ Resto de opciones
		si_no  
			_lugar(15,10);
			escribir(' Ha elegido una opción incorrecta ');
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
