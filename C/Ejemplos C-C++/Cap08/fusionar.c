/************** Fusionar dos listas clasificadas **************/
/* fusionar.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NML 120 // número máximo de líneas
#define CPL 60  // caracteres por línea

int fusionar(char **, int,
             char **, int,
             char **, const int);
void Error(void);

main()
{
  // Iniciamos las listas a clasificar con el fin de no tener
  // que leer los datos y realizar así una prueba rápida.

  static char *listaActual[] =
          { "Ana", "Carmen", "David",
            "Francisco", "Javier", "Jesús",
            "José", "Josefina", "Luís",
            "María", "Patricia", "Sonia" };

  static char *listaNueva[] =
          { "Agustín", "Belén",
            "Daniel", "Fernando", "Manuel",
            "Pedro", "Rosa", "Susana" };

  // Calcular el número de elementos de las matrices anteriores
  const int dimA = sizeof(listaActual)/sizeof(listaActual[0]);
  const int dimN = sizeof(listaNueva)/sizeof(listaNueva[0]);
  // Definir la matriz resultante de fusionar las anteriores
  static char **listaFinal; // referencia la matriz resultante
  int ind, r;
  
  // Asignar memoria para la matriz de punteros listaFinal
  listaFinal = (char **)malloc((dimA+dimN)*sizeof(char *));
  if (listaFinal == NULL) Error();
  // Inicia la matriz de punteros. Esto evita problemas al
  // liberar memoria, en el supuesto de un error por falta de
  // memoria.
  for (ind = 0; ind < dimA+dimN; ind++)
    listaFinal[ind] = NULL;

  // Fusionar listaActual y listaNueva y almacenar el resultado en
  // listaFinal. La función "fusionar" devuelve un 0 si no se
  // pudo realizar la fusión.
  
  r = fusionar(listaActual, dimA, listaNueva, dimN, listaFinal, NML);

  // Escribir la matriz resultante
  if (r)
  {
    for (ind = 0; ind < dimA+dimN; ind++)
      printf("%s\n", listaFinal[ind]);
  }
  else
    Error();

  // Liberar la memoria ocupada por la matriz listaFinal
  for (ind = 0; ind < dimA+dimN; ind++)
    free(listaFinal[ind]);
  free(listaFinal);
  
}

/****************************************************************
                         F U S I O N A R
****************************************************************/
int fusionar(char **listaA, int dimA,
             char **listaN, int dimN,
             char **listaF, const int nml)
{
  int ind = 0, indA = 0, indN = 0, indF = 0;

  while (indA < dimA && indN < dimN)
    if (strcmp(listaA[indA], listaN[indN]) < 0)
    {
      listaF[indF] = (char *)malloc(strlen(listaA[indA]) + 1);
      if (listaF[indF] == NULL) return 0;
      strcpy(listaF[indF++], listaA[indA++]);
    }
    else
    {
      listaF[indF] = (char *)malloc(strlen(listaN[indN]) + 1);
      if (listaF[indF] == NULL) return 0;
      strcpy(listaF[indF++], listaN[indN++]);
    }

  // Los dos lazos siguientes son para prever el caso de que,
  // lógicamente una lista finalizará antes que la otra.
  
  for (ind = indA; ind < dimA; ind++)
  {
    listaF[indF] = (char *)malloc(strlen(listaA[ind]) + 1);
    if (listaF[indF] == NULL) return 0;
    strcpy(listaF[indF++], listaA[ind]);
  }

  for (ind = indN; ind < dimN; ind++)
  {
    listaF[indF] = (char *)malloc(strlen(listaN[ind]) + 1);
    if (listaF[indF] == NULL) return 0;
    strcpy(listaF[indF++], listaN[ind]);
  }

  return(1);
}

void Error(void)
{
  puts("Longitud no válida de la lista resultante");
  exit(1);
}
