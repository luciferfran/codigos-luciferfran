/* Transformación de texto
 *
 * Cap5 - ejercicio7.c
 */

#include <stdio.h>
#include <conio.h>

#define DESPL 'K' - 'A'

main()
{                         
  unsigned char CarIn, CarOut;

  printf("Escribe un texto finalizado con un punto:\n");
  CarIn = getchar();
  printf("Resultado de la conversión:\n");
  while( CarIn != '.' )
  {
    if(CarIn >= 'A' && CarIn <= 'Z')
    {
      CarOut = CarIn + DESPL;
      if((CarIn + DESPL) > 'Z') CarOut -= 'Z' - 'A' + 1;
    }
    else if(CarIn >= 'a' && CarIn <= 'z')
    {
      CarOut = CarIn + DESPL;
      if((CarIn + DESPL) > 'z') CarOut -= 'z' - 'a' + 1;
    }                                                     
    else CarOut = CarIn;
    if(CarIn == 0) break;
    putchar( CarOut );
    CarIn = getchar();
  }                        
}
