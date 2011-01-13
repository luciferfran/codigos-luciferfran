/********************** Programa alumnos **********************/
/* alumnos.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100  // n�mero m�ximo de alumnos

typedef struct
{
  char matricula[10];
  char apellidos[30];
  char nombre[20];
  char direccion[30];
} ficha;

int leer(ficha *, const int);
void buscar(ficha *, char *, int, int);
int menu(void);

main()
{    
  static ficha lista[N];
  char dato[30];  // dato a buscar
  int opcion;     // opci�n elegida en el men�
  int n = 0;      // n�mero de alumnos le�dos

  while (1)       // bucle infinito. Se sale con break.
  {
    opcion = menu();
    if (opcion != 4)
    {
      switch (opcion)
      {
        case 1:    // entrada de los datos de los alumnos
          n = leer(lista, N);
          break;
        case 2:    // b�squeda por el n�mero de matr�cula
          system("cls");
          printf("N�mero de matr�cula "); gets(dato);
          buscar(lista, dato, n, opcion);
          break;
        case 3:    // B�squeda por los apellidos
          system("cls");
          printf("Apellidos.......... "); gets(dato);
          buscar(lista, dato, n, opcion);
          break;
      }
    }
    else
      break;
  }
}

/****************************************************************
               Funci�n para visualizar el men�
****************************************************************/

int menu(void)
{
  int op;
  
  do
  {
    system("cls");
    printf("\t1. Entrada de datos de alumnos\n");
    printf("\t2. B�squeda por nro. de matr�cula\n");
    printf("\t3. B�squeda por apellidos\n");
    printf("\t4. Fin\n");
    printf("\nTeclee la opci�n deseada  ");
    scanf("%d", &op);
    fflush(stdin);
  }
  while (op < 1 || op > 4);
  
  return (op);
}

/****************************************************************
     Funci�n para leer los datos correspondientes a un alumno
****************************************************************/

int leer(ficha *lista, const int NMAX)
{
  int n = 0;
  char resp = 's';
  while (tolower(resp) == 's' && n < NMAX)
  {
    do
    {
      system("cls");
      printf("Alumno n�mero %d\n\n", n+1);
      printf("N�mero de matr�cula "); gets(lista[n].matricula);
      printf("Apellidos.......... "); gets(lista[n].apellidos);
      printf("Nombre............. "); gets(lista[n].nombre);
      printf("Direcci�n.......... "); gets(lista[n].direccion);
      printf("\n\n� Datos correctos ? s/n ");
      resp = getchar();
      fflush(stdin);
    }
    while (tolower(resp) != 's');
    n++;

    printf("\n� M�s datos a introducir ? s/n ");
    resp = getchar();
    fflush(stdin);
  }
  return (n);
}

/****************************************************************
       Funci�n para buscar si existe o no un dato
****************************************************************/

void buscar(ficha *lista, char *x, int alumnos, int opcion)
{
  const int NO = 0;
  const int SI = 1;
  int existe = NO, i = 0;
  char resp;

  switch (opcion)
  {
    case 2: // b�squeda por n�mero de matr�cula
      while (!existe && i < alumnos)
     if (strcmp(lista[i++].matricula, x) == 0)
       existe = SI;
     break;
    case 3: // b�squeda por apellidos
      while (!existe && i < alumnos)
     if (strcmp(lista[i++].apellidos, x) == 0)
       existe = SI;
     break;
  }
  if (existe)
    printf("\n%s\n%s %s\n%s\n", lista[i-1].matricula,
                                lista[i-1].apellidos,
                                lista[i-1].nombre,
                                lista[i-1].direccion);
  else
    printf("\n%s no existe", x);

  printf("\n\nPulse <Entrar> para continuar ");
  resp = getchar();
  fflush(stdin);
}
