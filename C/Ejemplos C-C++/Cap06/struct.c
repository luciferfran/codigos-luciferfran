#include <stdio.h>

typedef struct ficha
{
  char nombre[40];
  char direccion[40];
  long telefono;
} tficha;

int ficha = 1;

main()
{
  tficha var1;
  char nombre[40] = "Javier";

  printf("Nombre: ");
  gets(var1.nombre);
  printf("%s\n", var1.nombre);
  printf("%s\n", nombre);
  printf("%d\n", ficha);
}

