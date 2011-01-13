/************************* Polinomios *************************/
/* polinom.c
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int grado;   // grado del polinomio
  float *coef; // coeficientes del polinomio
} tpolinomio;

tpolinomio LeerPol(void)
{
  tpolinomio pol = {0, NULL};
  int i = 0;
  
  printf("Grado del polinomio: ");
  scanf("%d", &pol.grado);
  // Asignar memoria para la matriz de coeficientes
  pol.coef = (float *)malloc((pol.grado + 1) * sizeof(float));
  if ( pol.coef != NULL )
  {
    // Leer los coeficientes de mayor a menor grado
    printf("Coeficientes de mayor a menor grado: ");
    for ( i = pol.grado; i >= 0; i-- )
      scanf("%g", &pol.coef[i]);
  }

  return pol;
}

void VisualizarPol(tpolinomio pol)
{
  int i = 0;
  
  // Escribir los términos de pol de mayor a menor grado
  for ( i = pol.grado; i > 0; i-- )
    if ( pol.coef[i] ) printf("%+gx^%d ", pol.coef[i], i);
  // Escribir el término independiente
  if ( pol.coef[i] ) printf("%+g\n", pol.coef[i]);
}

tpolinomio SumarPols(tpolinomio polA, tpolinomio polB)
{
  int i = 0;
  tpolinomio polresu = {0, NULL}, polaux = {0, NULL};

  // Hacer que polA sea el de mayor grado
  if ( polA.grado < polB.grado)
  {
    polaux = polA;
    polA = polB;
    polB = polaux;
  }
  
  // El polinomio resultante tendrá como grado, el mayor
  polresu.grado = polA.grado;
  
  // Asignar memoria para la matriz de coeficientes de polresu
  polresu.coef = (float *)malloc((polresu.grado + 1) * sizeof(float));
  if ( polresu.coef != NULL )
  {
    // Sumar polB con los coeficientes correspondientes de polA
    for ( i = 0; i <= polB.grado; i++ )
      polresu.coef[i] = polB.coef[i] + polA.coef[i];
    // A partir del valor actual de i, copiar
    // los coeficientes restantes de polA
    for ( ; i <= polA.grado; i++ )
      polresu.coef[i] = polA.coef[i];
  }
  
  return polresu;
}

main(void)
{
  tpolinomio polA, polB, polR;
  
  polA = LeerPol();
  if (polA.coef != NULL)
  {
    polB = LeerPol();
    if (polB.coef != NULL)
    {
      polR = SumarPols(polA, polB);
      if (polR.coef != NULL)
      {
        VisualizarPol(polR);
      }
    }
  }

  if ((polA.coef == NULL) || (polB.coef == NULL) || (polR.coef == NULL))
    printf("Insuficiente memoria\n");

  // Liberar la memoria asignada
  free(polA.coef);
  free(polB.coef);
  free(polR.coef);
}
