/*************************** Veh�culos ***************************/
// Cap2\ejercicio03.c

#include <stdio.h>

typedef enum coches
{
  volvo, renault, seat, fiat, lancia, lada, audi ,peugeot, ford, mercedes
} vehiculos; 
	
main()
{
  vehiculos MiCoche, MiPreferido, MiVecino;
  long Precio[9]; // en euros
  /* Obs�rvese c�mo el trabajar con palabras en lugar de n�meros, hace m�s f�cil y 
     agradable la lectura y comprensi�n del programa */
  Precio[volvo]=25178;
  Precio[renault]=18912;
  Precio[seat]=12797;
  Precio[fiat]=14174;
  Precio[lancia]=26885;
  Precio[lada]=6698;
  Precio[audi]=39228;
  Precio[peugeot]=20140;
  Precio[ford]=20066;
  Precio[mercedes]=31450;
	
  MiCoche = volvo;
  MiPreferido = audi;
  MiVecino = seat;

  printf("El precio de mi coche es: %ld euros.\n", Precio[MiCoche] );
  printf("El precio del coche que me gusta es: %ld euros.\n", Precio[MiPreferido] );
  printf("El precio del coche de mi vecino es: %ld euros.\n", Precio[MiVecino] );
}
