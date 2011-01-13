/****************** Punteros como parámetros ******************/
/* pparam01.c
*/
#include <stdio.h>
#include <stdlib.h>

struct fecha
{
  unsigned int dd;
  unsigned int mm;
  unsigned int aa;
};

void escribir(struct fecha *f);
void asigmem(struct fecha **p);

int main()
{
  struct fecha *hoy = NULL; // hoy es un puntero a una estructura

  // Asignación de memoria para la estructura
  asigmem(&hoy);
  if (hoy == NULL) return -1;

  printf("Introducir fecha (dd-mm-aa): ");
  scanf("%u-%u-%u", &hoy->dd, &hoy->mm, &hoy->aa);
  escribir(hoy);

  free(hoy);
  return 0;
}

void escribir(struct fecha *f)
{
  printf("Día %u del mes %u del año %u\n", f->dd, f->mm, f->aa);
}

void asigmem(struct fecha **p)
{
  *p = (struct fecha *)malloc(sizeof(struct fecha));
}
