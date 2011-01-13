/* Paso de grados Centígrados a Fahrenheit (F=9/5*C+32)
 *
 * grados.c
 */
/* Directrices para el preprocesador */
#include <stdio.h> /* declaraciones de las funciones estándar
                    * de entrada salida (E/S) de C.
                    */
/* Definición de constantes */
#define INF -30    /* límite inferior del intervalo de ºC */
#define SUP 100    /* límite superior */

/* Declaración de funciones */
float convertir(int c);  /* prototipo de la función convertir */

main()             /* función principal - comienzo del programa */
{
  /* Declaración de variables locales */
  int nGradosCentigrados = 0;
  int incremento = 6; /* iniciar incremento con el valor 6 */
  float GradosFahrenheit = 0;

  nGradosCentigrados = INF;  /* sentencia de asignación */
  while (nGradosCentigrados <= SUP)
  {
    /* Se llama a la función convertir */
    GradosFahrenheit = convertir(nGradosCentigrados);
    /* Se escribe la siguiente línea de la tabla */
    printf("%10d C %10.2f F\n", nGradosCentigrados, GradosFahrenheit);
    /* Siguiente valor a convertir */
    nGradosCentigrados += incremento;
  }
}   /* fin de la función principal y del programa */

/************** Definición de la función convertir **************/
float convertir(int gcent)
{
  float gfahr; /* variable local accesible solamente aquí,
                  en la función */
  /* los operandos son convertidos al tipo del operando de
     precisión más alta (float) */
  gfahr = (float)9 / (float)5 * gcent + 32;
  return (gfahr);  /* valor que retorna la función convertir */
} /* Fin de la función de convertir */
