// crear_alumnos.c
//
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  unsigned int n_matricula;
  char nombre[40];
  char calificacion[3];
} registro;         

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
    printf("El fichero existe �desea sobrescribirlo? (s/n) ");
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
  FILE *pf = NULL;   // identifica el fichero
  registro reg;      // definir un registro
  char resp;

  // Abrir el fichero nombreFichero para escribir "w"
  if ((pf = fopen(nombreFichero, "wb")) == NULL)
  {
    printf("El fichero no puede abrirse.");
    exit(1);
  }

  // Leer datos de la entrada est�ndar y escribirlos
  // en el fichero
  do
  {
    printf("N� de matr�cula: "); scanf("%d", &reg.n_matricula);
    fflush(stdin);
    printf("Nombre:          "); gets(reg.nombre);
    printf("Calificaci�n:    "); gets(reg.calificacion);
        
    // Almacenar un registro en el fichero
    fwrite(&reg, sizeof(reg), 1, pf);
    if (ferror(pf))
    {
      perror("Error durante la escritura");
      exit(2);
    }
    
    printf("�desea escribir otro registro? (s/n) ");
    resp = getchar();
    fflush(stdin);
  }
  while (resp == 's');
}
