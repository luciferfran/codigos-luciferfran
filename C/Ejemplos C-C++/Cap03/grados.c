/* Paso de grados Cent�grados a Fahrenheit (F=9/5*C+32)
 *
 * grados.c
 */
/* Directrices para el preprocesador */
#include <stdio.h> /* declaraciones de las funciones est�ndar
                    * de entrada salida (E/S) de C.
                    */
/* Definici�n de constantes */
#define INF -30    /* l�mite inferior del intervalo de �C */
#define SUP 100    /* l�mite superior */

/* Declaraci�n de funciones */
float convertir(int c);  /* prototipo de la funci�n convertir */

main()             /* funci�n principal - comienzo del programa */
{
  /* Declaraci�n de variables locales */
  int nGradosCentigrados = 0;
  int incremento = 6; /* iniciar incremento con el valor 6 */
  float GradosFahrenheit = 0;

  nGradosCentigrados = INF;  /* sentencia de asignaci�n */
  while (nGradosCentigrados <= SUP)
  {
    /* Se llama a la funci�n convertir */
    GradosFahrenheit = convertir(nGradosCentigrados);
    /* Se escribe la siguiente l�nea de la tabla */
    printf("%10d C %10.2f F\n", nGradosCentigrados, GradosFahrenheit);
    /* Siguiente valor a convertir */
    nGradosCentigrados += incremento;
  }
}   /* fin de la funci�n principal y del programa */

/************** Definici�n de la funci�n convertir **************/
float convertir(int gcent)
{
  float gfahr; /* variable local accesible solamente aqu�,
                  en la funci�n */
  /* los operandos son convertidos al tipo del operando de
     precisi�n m�s alta (float) */
  gfahr = (float)9 / (float)5 * gcent + 32;
  return (gfahr);  /* valor que retorna la funci�n convertir */
} /* Fin de la funci�n de convertir */
