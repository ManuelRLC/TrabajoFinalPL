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

#

_borrar;

repetir 

 @ Opciones disponibles

 _lugar(10,10);
 escribir_cadena(' Calculo de los n primeros numeros primos --> 1 ');

 _lugar(11,10);
 escribir_cadena(' Factorizacion de un numero ----> 2 ');

 _lugar(12,10);
 escribir_cadena(' Finalizar ---------------> 0 ');

 _lugar(15,10);
 escribir_cadena(' Elige una opcion ');

 leer(opcion);

 _borrar;


segun (opcion)

	valor 0:

		_lugar(10,10);
	    escribir_cadena('Fin del programa\n');

	@ Calcular n primeros numeros primos
    valor 1:

	    escribir_cadena('Ingrese la cantidad de numeros primos a mostrar: ');
	    leer(cantidad_a_mostrar);
	    
	   	@el primer primo es 2, los otros son todos impares...
	   	escribir_cadena('1: 2\n');
	    cantidad_mostrados := 1;

	    n := 3;           
	    
	    Mientras (cantidad_mostrados < cantidad_a_mostrar) Hacer
	        
	        es_primo := Verdadero;

	        si (sqrt(n) > 3) entonces
	        
		        Para i desde 3 hasta sqrt(n) paso 2 Hacer
		            @Si la division es exacta entonces no es primo
		            Si (n _mod i = 0) entonces 
		                es_primo := Falso; 
		            fin_si
		        fin_para

		    fin_si
	        
	        Si (es_primo) Entonces
	            cantidad_mostrados++;
	            escribir(cantidad_mostrados);
	            escribir_cadena(': ');
	            escribir(n);
	            escribir_cadena('\n');
	        fin_si
	        
	        n := n + 2;
	        
	    fin_mientras

	    @pausa
	    _lugar(40,10);
		escribir_cadena('Pulsa una tecla para continuar');
		leer_cadena( pausa);
		_borrar;



	valor 2:

		escribir_cadena('Introducide el numero: ');

		leer(numero);

		escribir_cadena('Descomposicion en factores primos:\t');

		divisor := 2;
	     
	     mientras ( numero >= divisor ) hacer            
	          mientras ( (numero _mod divisor) = 0 ) hacer
	              escribir(divisor);
	              escribir_cadena(' x ');   
	              numero := numero / divisor;    
	          fin_mientras
	          divisor++;
	     fin_mientras
	     escribir(numero);

	    @pausa
		_lugar(40,10);
		escribir_cadena('Pulsa una tecla para continuar');
		leer_cadena( pausa);
		_borrar;


fin_segun
 
hasta (opcion = 0)             

@ Despedida final

_borrar;
_lugar(10,10);
escribir_cadena('El programa ha concluido\n');