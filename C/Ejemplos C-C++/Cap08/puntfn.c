// puntfn.c
//
#include <stdio.h>
#include <math.h>

double cuadrado(double);
double pot(double, double);
int menu(void);

main()
{ 
  double (*pfn[2])();  // pfn es una matriz de punteros a funciones
  double x = 0, y = 0, r = 0;
  int op = 0;

  pfn[0] = cuadrado;   // pfn[0] apunta a la función cuadrado
  pfn[1] = pot;        // pfn[1] apunta a la función pot

  do
  {
    op = menu();
    switch(op)
    {
      case 1:
        printf("Introducir x: ");
        scanf("%lf", &x);
        r = pfn[0](x);    // llamada a la función cuadrado
        break;
      case 2:
        printf("Introducir x e y: ");
        scanf("%lf %lf", &x, &y);
        r = pfn[1](x, y); // llamada a la función potenciación
        break;
    }
    printf("%g\n", r);
  }
  while(op != 3);
}

double cuadrado(double a)
{
  return (a * a);
}

double pot(double x, double y)
{
  return exp(y * log(x));
}

int menu(void)
{
  int op;
  do
  {
    printf("\t1. cuadrado\n");
    printf("\t2. potenciación\n");
    printf("\t3. salir\n");
    printf("\n\tSeleccione una opción: ");
    scanf("%d", &op);
  }
  while (op < 1 || op > 3);
  return op;
}
