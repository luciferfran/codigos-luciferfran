/************************** BIBLIOTECA ************************/
/* estr_variables.c
 */
#include <stdio.h>
#include <stdlib.h>
#define N 100 // m�ximo n�mero de elementos de la matriz

enum clase // tipo enumerado
{
  libro, revista
};

typedef struct // estructura variable
{
  unsigned numref;
  char titulo[30];
  char autor[20];
  char editorial[25];
  enum clase libro_revista;
  union
  {
    struct
    {
      unsigned edicion;
      unsigned anyo;
    } libros;
    char nomrev[30];
  } lr;
} tficha;

// Prototipos de las funciones
void escribir(tficha bibli[], int n);
int leer(tficha bibli[], int n);

main() // funci�n principal
{
  static tficha biblioteca[N]; // matriz de estructuras
  int n = 0; // n�mero actual de elementos de la matriz

  system("cls");
  printf("Introducir datos.\n");
  n = leer(biblioteca, N);
  system("cls");
  printf("Listado de libros y revistas\n");
  escribir(biblioteca, n); // listar todos los libros y revistas
}

/***************************************************************
      Funci�n para leer los datos de los libros y revistas
***************************************************************/
int leer(tficha bibli[], int NMAX)
{
  int clase;
  char resp = 's';
  int k = 0; // n�mero de elementos introducidos

  while( tolower(resp) == 's' && k < NMAX )
  {
    system("cls");
    printf("N�mero de refer. ");
    scanf("%u",&bibli[k].numref); fflush(stdin);
    printf("T�tulo           "); gets(bibli[k].titulo);
    printf("Autor            "); gets(bibli[k].autor);
    printf("Editorial        "); gets(bibli[k].editorial);
    do
    {
      printf("Libro o revista (0 = libro, 1 = revista) ");
      scanf("%d", &clase); fflush(stdin);
    }
    while (clase != 0 && clase != 1);
    if (clase == libro)
    {
      bibli[k].libro_revista = libro;
      printf("Edici�n          ");
      scanf("%u", &bibli[k].lr.libros.edicion);
      printf("A�o de public.   ");
      scanf("%u", &bibli[k].lr.libros.anyo); fflush(stdin);
    }
    else
    {
      bibli[k].libro_revista = revista;
      printf("Nombre revista   "); gets(bibli[k].lr.nomrev);
    }
    
    k++;
    
    do
    {
      printf("\n�M�s datos a introducir? s/n ");
      resp = getchar();
      fflush(stdin);
    }
    while( tolower(resp) != 's' && tolower(resp) != 'n' );
  }
  return k;
}

/***************************************************************
      Funci�n para listar todos los elementos de la matriz
***************************************************************/
void escribir(tficha bibli[], int n)
{
  int k = 0;
  for (k = 0; k < n; k++)
  {
    printf("%d  %s\n", bibli[k].numref, bibli[k].titulo);
    printf("%s - Ed. %s\n", bibli[k].autor,  bibli[k].editorial);

    switch (bibli[k].libro_revista)
    {
      case libro :
        printf("Edici�n %u - a�o %u\n",
        bibli[k].lr.libros.edicion,
        bibli[k].lr.libros.anyo);
        break;
      case revista :
        printf("%s\n", bibli[k].lr.nomrev);
    }
    printf("\nPulse <Entrar> para continuar");
    getchar();
    system("cls");
  }
}
