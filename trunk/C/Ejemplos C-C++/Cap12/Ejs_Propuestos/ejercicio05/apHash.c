#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

typedef struct
{
  // matricula: es la clave del fichero �ndice
  char nombre[40];
  double nota;
} tAlumno;

main()
{
  // Definici�n de variables
  int n = 0;
  tAlumno a; // registro del fichero de datos
  tRegInd x;  // registro del fichero �ndice

  // Crear una estructura de tipo tMatrizHash
  tMatrizHash mh = {NULL, NULL, 0};

  // Iniciar la estructura de tipo tMatrizHash
  // (encapsula los punteros a los ficheros �ndice y datos
  // y el n�mero de registros)
  iniciarFicheros(&mh);
  
  // Introducir datos
  printf("\nIntroducir datos. Para finalizar, matr�cula = 0\n");
  printf("\nmatr�cula:  "); scanf("%d", &x.clave);
  while (x.clave != 0)
  {

    fseek(mh.pfDat, 0, SEEK_END);
    n = ftell(mh.pfDat) / sizeof(tAlumno); // n�mero de registros
    x.numReg = n; // n�mero del siguiente registro;
                  // (el primer registros es el 0)

    if (hashIn(x, mh))
    {
      fflush(stdin);
      printf("nombre:     "); gets(a.nombre);
      printf("nota:       "); scanf("%lf", &a.nota);
      // A�adir el registro de datos al final del fichero
      fwrite(&a, sizeof(tAlumno), 1, mh.pfDat);
      if (ferror(mh.pfDat))
        error("error al escribir en el fichero de datos");
    }
    printf("\nmatr�cula:  "); scanf("%d", &x.clave);
  }

  // Buscar datos
  printf("\nBuscar datos. Para finalizar, matr�cula = 0\n");
  printf("\nmatr�cula:  "); scanf("%d", &x.clave);
  while (x.clave != 0)
  {
    n = hashOut(x, mh);
    if (n != -1)
    {
      fseek(mh.pfDat, n * sizeof(tAlumno), SEEK_SET);
      fread(&a, sizeof(tAlumno), 1, mh.pfDat);
      printf("nombre: %s\n", a.nombre);
      printf("nota:   %g\n", a.nota);
    }
    else
      printf("No existe\n");
    printf("\nmatr�cula:  "); scanf("%d", &x.clave);
  }
  fclose(mh.pfInd);
  fclose(mh.pfDat);
}

