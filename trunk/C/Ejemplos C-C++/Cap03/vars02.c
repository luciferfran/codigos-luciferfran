/* vars02.c - Variables locales: clases de almacenamiento
 */
#include <stdio.h>

void funcion_1();

main()
{
  /* Declaración de var1 que se supone definida en otro sitio */
  extern int var1;

  /* Variable estática var2: es accesible solamente
     dentro de main. Su valor inicial es 0.          */
  static int var2;

  /* var3 se corresponderá con un registro si es posible */
  register int var3 = 0;

  /* var4 es declarada auto, por defecto */
  int var4 = 0;
  
  var1 += 2;

  /* Se escriben los valores 7, 0, 0, 0 */
  printf("%d  %d  %d  %d\n", var1, var2, var3, var4);
  funcion_1();
}

int var1 = 5;

void funcion_1()
{
  /* Se define la variable local var1 */
  int var1 = 15;

  /* Variable estática var2; accesible sólo en este bloque */
  static var2 = 5;

  var2 += 5;

  /* Se escriben los valores 15, 10 */
  printf("%d  %d\n", var1, var2);
}
