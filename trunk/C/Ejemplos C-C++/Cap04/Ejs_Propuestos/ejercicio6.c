/* Introducción de datos por teclado
 *
 * Cap4 - ejercicio6.c
 */

#include <stdio.h>
                 
main()
{                 
  int car = 0;
  car = getchar();
  putchar(car);
  // fflush(stdin);
  car = getchar();
  putchar(car); 
}
/* El programa espera a que el usuario introduzca caracteres por el teclado
   hasta que se pulse la tecla [Entrar]. El primer carácter, si existe, se
   asigna a 'car' y es mostrado por la pantalla, el segundo carácter, si existe,
   se muestra por la pantalla a continuación del primero.
   Si la entrada inicial es de un sólo carácter, no se permitiría introducir
   un segundo carácter. Para que esto fuera posible habría que limpiar el
   buffer de entrada con la función fflush.
   Para leer un carácter sin tener que pulsar [Entrar], véase ejercicio6b.c */