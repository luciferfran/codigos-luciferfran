/* getch.c - Funciones _getch y _getche
 */
#include <stdio.h>
#include <conio.h>

main()
{
  char byte1, byte2; 
  printf("Pulse la combinación de teclas cuyo código\n"
         "extendido desea conocer\n"); 
  byte1 = _getch(); byte2 = _getch(); 
  printf("%d \t %d\n", byte1, byte2);
  
  printf("Pulse una tecla para continuar ");
  _getche();
  printf("\nFin del programa\n");
}
