/* Introducci�n de datos por teclado
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
   hasta que se pulse la tecla [Entrar]. El primer car�cter, si existe, se
   asigna a 'car' y es mostrado por la pantalla, el segundo car�cter, si existe,
   se muestra por la pantalla a continuaci�n del primero.
   Si la entrada inicial es de un s�lo car�cter, no se permitir�a introducir
   un segundo car�cter. Para que esto fuera posible habr�a que limpiar el
   buffer de entrada con la funci�n fflush.
   Para leer un car�cter sin tener que pulsar [Entrar], v�ase ejercicio6b.c */