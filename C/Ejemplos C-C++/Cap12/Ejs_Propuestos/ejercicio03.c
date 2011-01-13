/* Fusionar dos registros ordenados en un tercero también ordenado
 *
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
                                            
void fusionar(FILE *pfa, FILE *pfb, FILE *pfc);

main(int argc, char *argv [])
{
  char respuesta = 0;
  FILE *pfa, *pfb, *pfc;
  alumno reg;

  if (argc != 4)
  {
    // Se toma por defecto los ficheros 'a', 'b' y 'c'
    argv[1] = "a";
    argv[2] = "b";
    argv[3] = "c";
  }
  if ((pfa = fopen(argv[1], "rb")) == NULL)
  {
    perror(argv[1]);
    exit(-1);
  }
  if ((pfb = fopen(argv[2], "rb")) == NULL)
    exit(-1);
  if ((pfc = fopen(argv[3], "w+b")) == NULL)
  {
    perror("No puedo crear fichero destino.");
    exit(-1);
  }
  
  fusionar(pfa, pfb, pfc);
  printf("Ficheros fusionados\n");

  do
  {
    printf("¿Desea visualizar el fichero resultante? (s/n)  ");
    respuesta = getchar();
    fflush(stdin);
  }
  while (tolower(respuesta) != 's' && tolower(respuesta) != 'n');

  // Salida de datos
  if (respuesta == 's')
  {
    rewind(pfc);
    // Leer el primer registro del fichero
    fread(&reg, sizeof(alumno), 1, pfc);
    while (!ferror(pfc) && !feof(pfc))
    {
      printf("Nombre:    %s\n", reg.nombre);
      printf("Nota:      %g\n\n", reg.nota);

      // Leer el siguiente registro del fichero
      fread(&reg, sizeof(alumno), 1, pfc);
    }
  }
  if (ferror(pfc))
    perror("Error durante la lectura");

  fclose(pfa);
  fclose(pfb);
  fclose(pfc);
}

void fusionar(FILE *pfa, FILE *pfb, FILE *pfc)
{ 
  alumno regA, regB;
  int orden = 0, wA = 0, wB = 0;

  if (fread(&regA, sizeof(alumno), 1, pfa) != 1)
    regA.nombre[0] = 255; // Si no puede leer, inutiliza el registro
  if (fread(&regB, sizeof(alumno), 1, pfb) != 1)
    regB.nombre[0] = 255;
  
  while (1)
  {
    if ((regB.nombre[0] == 255) && (regA.nombre[0] == 255))
      return; // fin de los dos ficheros
    if ((orden = strncmp(regA.nombre, regB.nombre, LONG) ) == 0) 
    {
      wA = fwrite(&regA, sizeof(alumno), 1, pfc);
      wB = fwrite(&regB, sizeof(alumno), 1, pfc);
      if ((wA != 1) && (wB != 1))
      {
        perror("No puedo escribir en el fichero destino.");
        fclose(pfa), fclose(pfb), fclose(pfc);
        exit(-1);
      }
      if (fread(&regA, sizeof(alumno), 1, pfa) != 1) // Lee de nuevo de
        regA.nombre[0] = 255;                        // ambos ficheros
      if (fread(&regB, sizeof(alumno), 1, pfb) != 1)
        regB.nombre[0] = 255;
      continue;
    }                                                     
    else if (orden > 0) // A > B
    {
      // Escribe el registro B
      if(fwrite(&regB, sizeof(alumno), 1, pfc) != 1)
      {
        perror("No puedo escribir en el fichero destino.");
        fclose(pfa), fclose(pfb), fclose(pfc);
        exit(-1);
      }
      if (fread(&regB, sizeof(alumno), 1, pfb) != 1)// Lee 'regB'
        regB.nombre[0] = 255;
      continue;
    }
    else // B > A
    {
      // Escribe el registro A
      if (fwrite(&regA, sizeof(alumno), 1, pfc) != 1)
      {
        perror("No puedo escribir en el fichero destino.");
        fclose(pfa), fclose(pfb), fclose(pfc);
        exit(-1);
      }
      if(fread(&regA, sizeof(alumno), 1, pfa) != 1)
        regA.nombre[0] = 255;
      continue;                         
    }
  }
}