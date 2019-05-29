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

_lugar(10,10);

escribir_cadena('Ingrese un numero(en radianes): ');

@leer angulo
leer (angulo);


@este es el resultado de cada iteracion de la sumatoria
iteracion := 0; 

@este es el total de la sumatoria
sumatoria := 0; 

@la presicion con la que se calcula el coseno
precision := 0.0001; 

@numero de iteracion n = 0 , n -> iteracion < precicion
n := 0; 

repetir
    @calcular el factorial
    factorial := 1; 
    num := n * 2;
    mientras (num <> 0) hacer 
        factorial *:= num; 
        num--; 
    fin_mientras 

    @calcular la sumatoria principal
    iteracion := ((-1) ** n) / factorial * (angulo ** (2 * n)); 
    sumatoria +:= iteracion;

    @aumentar n de la sumatoria
    n++;

    si (iteracion < 0) entonces
        iteracion := -iteracion;
    fin_si

Hasta (iteracion < precision); 

_lugar(13,15);

escribir_cadena('Resultado algoritmo: ');
escribir(sumatoria);
escribir_cadena('\n');

_lugar(15,15);

escribir_cadena('Resultado funcion predefinida: ');
escribir(cos(angulo));
escribir_cadena('\n');

_lugar(40,10); 
escribir_cadena('\n Pulse una tecla para finalizar --> ');
leer_cadena(pausa);
