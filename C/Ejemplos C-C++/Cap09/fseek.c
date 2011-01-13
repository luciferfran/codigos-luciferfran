/**************** Acceso aleatorio a un fichero ****************/
/* fseek.c
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char nombre[40];
  char direccion[40];
  long telefono;
} registro;      // tipo registro

void mostrarReg(FILE *pf, int nreg);
void modificarReg(FILE *pf, int nreg);

main()
{
  FILE *pf = NULL;            // puntero a un flujo
  int totalreg = 0;           // número total de registros
  int nreg = 0;               // número de registro
  char nombreFichero[30];     // nombre del fichero
  int c = 0, respuesta = 0;
  
  // Solicitar el nombre del fichero
  printf("Nombre del fichero: ");
  gets(nombreFichero);
  
  // Abrir el fichero para leer y escribir "r+"
  if ((pf = fopen(nombreFichero, "r+b")) == NULL)
  {
    printf("Error: no se puede abrir el fichero\n");
    exit(1);
  }

  // Calcular el nº total de registros del fichero
  fseek(pf, 0L, SEEK_END);
  totalreg = (int)ftell(pf)/sizeof(registro);

  // Presentar un registro en pantalla y modificarlo si procede
  do
  {
    printf("Nº registro entre 1 y %d (0 para salir): ", totalreg);
    c = scanf("%d", &nreg);
    fflush(stdin);
    if (c && (nreg >= 1) && (nreg <= totalreg))
    {
      mostrarReg(pf, nreg);
      // Preguntar si se desea modificar el registro seleccionado
      do
      {
        printf ("¿Desea modificar este registro? (s/n)  ");
        respuesta = getchar();
        fflush(stdin);
      }
      while (tolower(respuesta != 's') && tolower(respuesta) != 'n');

      if (respuesta == 's')
        modificarReg(pf, nreg);
    }
  }
  while (nreg);
  fclose(pf);
}

void mostrarReg(FILE *pf, int nreg)
{
  long desp = 0; // desplazamiento en bytes
  registro reg;  // variable de tipo registro
  int bytesPorReg = sizeof(registro);

  // Visualizar un registro
  desp = (long)(nreg - 1) * bytesPorReg;
  fseek(pf, desp, SEEK_SET);
  fread(&reg, bytesPorReg, 1, pf);
  if (ferror(pf))
  {
    printf("Error al leer un registro del fichero.\n");
    return;
  }
  printf("Nombre:    %s\n", reg.nombre);
  printf("Dirección: %s\n", reg.direccion);
  printf("Teléfono:  %ld\n\n", reg.telefono);
}

void modificarReg(FILE *pf, int nreg)
{
  long desp = 0; // desplazamiento en bytes
  registro reg;  // variable de tipo registro
  int bytesPorReg = sizeof(registro);

  printf("Nombre:    "); gets(reg.nombre);
  printf("Dirección: "); gets(reg.direccion);
  printf("Teléfono:  "); scanf("%ld", &reg.telefono);
  fflush(stdin);
  // Escribir un registro en el fichero
  fseek(pf, -bytesPorReg, SEEK_CUR);
  fwrite (&reg, bytesPorReg, 1, pf);
  if (ferror(pf))
  {
    printf("Error al escribir un registro en el fichero.\n");
    return;
  }
}
