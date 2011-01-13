/*** Escribir datos en un fichero registro a registro ***/
/* fwrite.c
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char nombre[40];
  char direccion[40];
  long telefono;
} registro;      // tipo registro

int existe(char *nombreFichero);
void crearFichero(char *nombreFichero);

main()
{
  char nombreFichero[30]; // nombre del fichero
  char resp = 's';
  
  // Solicitar el nombre del fichero
  printf("Nombre del fichero: ");
  gets(nombreFichero);
  
  // Verificar si el fichero existe
  if (existe(nombreFichero))
  {
    printf("El fichero existe ¿desea sobrescribirlo? (s/n) ");
    resp = getchar();
    fflush(stdin);
  }
  if (resp == 's')
  {
    crearFichero(nombreFichero);
  }
}

int existe(char *nombreFichero)
{
  FILE *pf = NULL;
  // Verificar si el fichero existe
  int exis = 0; // no existe
  if ((pf = fopen(nombreFichero, "r")) != NULL)
  {
    exis = 1;   // existe
    fclose(pf);
  }
  return exis;
}

void crearFichero(char *nombreFichero)
{
  FILE *pf = NULL;   // identificador del fichero
  registro reg;      // definir un registro
  char resp;

  // Abrir el fichero nombreFichero para escribir "w"
  if ((pf = fopen(nombreFichero, "w")) == NULL)
  {
    printf("El fichero no puede abrirse.");
    exit(1);
  }

  // Leer datos de la entrada estándar y escribirlos
  // en el fichero
  do
  {
    printf("nombre:    "); gets(reg.nombre);
    printf("dirección: "); gets(reg.direccion);
    printf("teléfono:  "); scanf("%ld", &reg.telefono);
    fflush(stdin);
        
    // Almacenar un registro en el fichero
    fwrite(&reg, sizeof(reg), 1, pf);
    if (ferror(pf))
    {
      perror("Error durante la escritura");
      exit(2);
    }
    
    printf("¿desea escribir otro registro? (s/n) ");
    resp = getchar();
    fflush(stdin);
  }
  while (resp == 's');
}
