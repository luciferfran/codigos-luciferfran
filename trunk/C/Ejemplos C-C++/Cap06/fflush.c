/************* Limpiar el buffer asociado con stdin ************/
/* fflush.c
 */
#include <stdio.h>

main()
{
  int entero;
  double real;
  char respuesta = 's', cadena[81];

  // Introducir números
  printf("Introducir un nº entero y un nº real:\n");
  scanf("%d %lf", &entero, &real);
  printf("%d + %f = %f\n\n", entero, real, entero + real);

  // Limpiar el buffer de entrada y leer una cadena con gets
  fflush(stdin);

  printf("Introducir cadenas para gets.\n");
  while (respuesta == 's' && gets(cadena) != NULL)
  {
    printf("%s\n", cadena);
    do
    {
      printf("¿Desea continuar? (s/n) ");
      respuesta = getchar();
      // Limpiar el buffer de entrada
      fflush( stdin );
    }
    while ((respuesta != 's') && (respuesta != 'n'));
  }
}
