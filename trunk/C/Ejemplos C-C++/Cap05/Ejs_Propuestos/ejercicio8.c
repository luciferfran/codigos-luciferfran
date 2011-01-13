/* Importe a pagar por un vehículo al circular por una autopista
 *
 * break.c
 */
#include <stdio.h>
#include <stdlib.h>

int menu(void);

typedef enum tipo_vehiculo
{
  bicicleta = 1,
  moto,
  coche,
  camion
} tvehiculo;

int main()
{
  tvehiculo vehiculo;
  int km, tm, importe;

  while (1)
  {  
    vehiculo = menu();

    switch (vehiculo)
    { 
      case bicicleta:
        importe = 100;
        break;
      case moto:
      case coche:
        printf("¿Kilómetros? ");
        scanf("%d", &km);
        importe = 30 * km;
        break;
      case camion:
        printf("¿Kilómetros y toneladas? ");
        scanf("%d %d", &km, &tm);
        importe = 30 * km + 25 * tm;
        break;
      default:
        return 0; // salir de main
    }
    // Escribir el resultado
    printf("Importe = %d\n", importe);
    // Hacer una pausa
    printf("Pulse <Entrar> para continuar ");
    // Limpiar el buffer del flujo de entrada
    fflush(stdin);
    getchar();
  }
}

int menu(void)
{
  int op;
  do
  {
    system("cls");
    printf("\t1 - bicicleta\n");
    printf("\t2 - moto\n");
    printf("\t3 - coche\n");
    printf("\t4 - camión\n");
    printf("\t5 - salir\n");
    printf("\nSeleccione la opción deseada: ");
    scanf("%d", &op);
  }
  while (op < 1 || op > 5);
  return op;
}
