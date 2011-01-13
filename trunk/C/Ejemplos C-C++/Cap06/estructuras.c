/********** Operaciones con estructuras **********/
/* estructuras.c
 */
#include <stdio.h>

typedef struct
{
  int dia, mes, anyo;
} tfecha;

typedef struct
{
  char nombre[40];
  char direccion[40];
  long telefono;
  tfecha fecha_nacimiento;
} tficha;

main()
{
  tficha persona, otra_persona;
  
  // Introducir datos
  printf("Nombre:          ");
  gets(persona.nombre);
  printf("Direcci�n:       ");
  gets(persona.direccion);
  printf("Tel�fono:        ");
  scanf("%ld", &persona.telefono);
  printf("Fecha de nacimiento:\n");
  printf("  D�a:           ");
  scanf("%d", &persona.fecha_nacimiento.dia);
  printf("  Mes:           ");
  scanf("%d", &persona.fecha_nacimiento.mes);
  printf("  A�o:           ");
  scanf("%d", &persona.fecha_nacimiento.anyo);

  // Copiar una estructura en otra
  otra_persona = persona;
  
  // Escribir los datos de la nueva estructura
  printf("\n\n");
  printf("Nombre:      %s\n", otra_persona.nombre);
  printf("Direcci�n:   %s\n", otra_persona.direccion);
  printf("Tel�fono:    %ld\n", otra_persona.telefono);
  printf("Fecha de nacimiento:\n");
  printf("  D�a:       %d\n", otra_persona.fecha_nacimiento.dia);
  printf("  Mes:       %d\n", otra_persona.fecha_nacimiento.mes);
  printf("  A�o:       %d\n", otra_persona.fecha_nacimiento.anyo);
}
  