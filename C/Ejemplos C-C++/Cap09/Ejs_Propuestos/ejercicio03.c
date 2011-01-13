/* Actualizar el fichero de notas
 * ejercicio03.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LONG 61

typedef struct
{
  unsigned char nombre[LONG];
  float nota;
} alumno;

void actualizar(FILE *, FILE *, char *);
void error(char *msj);

main(int argc, char *argv [])
{
  FILE *pfa = NULL, *pfb = NULL; 

  if (argc != 3)
  { // Se toma por defecto los ficheros 'alumnos' y 'modifi'
    argv[1] = "notas";
    argv[2] = "modifi";
  }
  if ((pfa = fopen(argv[1], "rb")) == NULL)
  {
    perror(argv[1]);
    exit(-1);
  }
  if ((pfb = fopen(argv[2], "rb")) == NULL)
    exit(-1);
  
  actualizar(pfa, pfb, argv[1]);
  
  fclose(pfa);
  fclose(pfb);
}

void actualizar(FILE *pfa, FILE *pfb, char *nomfich)
{ 
  alumno regA, regB;
  int i, n = 0;
  size_t bytesreg = sizeof(alumno);

  // Crear una fichero temporal.
  FILE *pfc = tmpfile();
  if (pfc == NULL)
  {
    printf("Error: No se puede crear un fichero temporal\n");
    exit(-1);
  }

  // Si no puede leer, se habrá llegado al final del fichero.
  // Asignar a nombre el valor ASCII mayor para que el resultado
  // de la comparación regA con regB sea posible y se pueda
  // finalizar con el otro fichero.
  if (fread(&regB, bytesreg, 1, pfb) < 1)
    regB.nombre[0] = 255;
  if (fread(&regA, bytesreg, 1, pfa) < 1)
    regA.nombre[0] = 255;
  
  while (1)
  {
    if ((regB.nombre[0] == 255) && (regA.nombre[0] == 255))
      break;
    if (( i = strncmp(regA.nombre, regB.nombre, sizeof(regA.nombre)) ) == 0) 
    {
      // El mismo alumno
      if(fwrite(&regB, bytesreg, 1, pfc) < 1)
        error("Error al escribir");
      n++;
      // Leer de nuevo de ambos ficheros
      if (fread(&regB, bytesreg, 1, pfb) < 1) 
        regB.nombre[0] = 255;
      if (fread(&regA, bytesreg, 1, pfa) < 1)
        regA.nombre[0] = 255;
      continue;
    }                                                     
    else if (i > 0) // A > B
    {
      if(fwrite(&regB, bytesreg, 1, pfc) < 1)
        error("Error al escribir");
      n++;
      // Leer regB
      if (fread(&regB, bytesreg, 1, pfb) < 1)
        regB.nombre[0] = 255;
      continue;
    }
    else // B > A
    {
      if (fwrite(&regA, bytesreg, 1, pfc) < 1)
        error("Error al escribir");
      n++;
      if (fread(&regA, bytesreg, 1, pfa) < 1)
        regA.nombre[0] = 255;
      continue;                         
    }
  }
  // Copiar en el fichero notas todos los registros del temporal.
  // Para ello, creamos de nuevo el fichero notas.
  fclose(pfa);
  if ((pfa = fopen(nomfich, "wb")) == NULL)
  {
    printf("Error: No se puede crear el fichero\n");
    exit(-1);
  }
  rewind(pfc); // volver al principio del fichero temporal
  for ( i = 0; i < n; i++ )
  {
    if (fread(&regA, bytesreg, 1, pfc) < 1)
      error("Error al leer");
    if (regA.nota != -1) // si la nota es -1, no se escribe.
      if (fwrite(&regA, bytesreg, 1, pfa) < 1)
        error("Error al escribir");
  }
}

void error(char *msj)
{
  perror(msj);
  exit(-1);
}
