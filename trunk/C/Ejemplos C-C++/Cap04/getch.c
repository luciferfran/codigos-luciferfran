/* getch.c - Funciones _getch y _getche
 */
#include <stdio.h>
#include <conio.h>

main()
{
  char byte1, byte2; 
  printf("Pulse la combinaci�n de teclas cuyo c�digo\n"
         "extendido desea conocer\n"); 
  byte1 = _getch(); byte2 = _getch(); 
  printf("%d \t %d\n", byte1, byte2);
  
  printf("Pulse una tecla para continuar ");
  _getche();
  printf("\nFin del programa\n");
}
