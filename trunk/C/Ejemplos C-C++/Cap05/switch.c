/******* D�as correspondientes a un mes de un a�o dado *******/
/* switch.c
 */
#include <stdio.h>

main()
{
  int dd = 0, mm = 0, aa = 0;

  printf("Introducir mes (##) y a�o (####): ");
  scanf("%d %d", &mm, &aa);
  switch (mm)
  {
    case 1:      // enero
    case 3:      // marzo
    case 5:      // mayo
    case 7:      // julio
    case 8:      // agosto
    case 10:     // octubre
    case 12:     // diciembre
      dd = 31;
      break;
    case 4:      // abril
    case 6:      // junio
    case 9:      // septiembre
    case 11:     // noviembre
      dd = 30;
      break;
    case 2:      // febrero
      // �Es el a�o bisiesto?
      if ((aa % 4 == 0) && (aa % 100 != 0) || (aa % 400 == 0))
        dd = 29;
      else
        dd = 28;
        break;
    default:
      printf("\nEl mes no es v�lido\n");
      break;
  }
  if (mm >= 1 && mm <= 12)
    printf("\nEl mes %d del a�o %d tiene %d d�as\n",mm,aa,dd);
}
