// mezclaNatural.c

//////////////////////////////////////////////////////////////////
// Ordenar un fichero utilizando el método de mezcla natural.
// Se trata de un fichero de texto que almacena una lista de
// nombres.
// El nombre del fichero se recibe a través de la línea de órdenes.
// La ordenación se realiza en orden alfabético ascendente.
//    Funciones:
//      mezclaNatural
//      distribuir
//      mezclar
//      main
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

void mezclaNatural(FILE *f);
int distribuir(FILE *f, FILE *fa, FILE *fb);
int mezclar(FILE *fa, FILE *fb, FILE *f);

main(int argc, char *argv[])
{
  FILE *pfichero = NULL;
  char respuesta = 0, str[MAX];

  // Análisis de los parámetros de la línea de órdenes.
  if (argc != 2)
  {
    fprintf(stderr, "Sintaxis: %s fichero", argv[0]);
    exit(-1);
  }
  // Abrir del fichero.
  if ((pfichero = fopen(argv[1], "r+")) == NULL)
  {
    perror(argv[1]);
    exit(-1);
  }
  // Ordenación.
  mezclaNatural(pfichero);

  do
  {
    printf("¿Desea visualizar el fichero? (s/n)  ");
    respuesta = getchar();
    fflush(stdin);
  }
  while (tolower(respuesta) != 's' && tolower(respuesta) != 'n');

  // Salida de datos
  if (respuesta == 's')
  {
    rewind(pfichero);
    while (fgets(str, MAX, pfichero))
      printf("%s", str);
  }
  if (ferror(pfichero))
    perror("Error durante la lectura");

  fclose(pfichero);
}

void mezclaNatural(FILE *f)
{
  // Mezcla natural
  FILE *fa = NULL, *fb = NULL;
  int nro_tramos = 0;
  do
  {
    fa = tmpfile(); // fichero temporal
    fb = tmpfile(); // fichero temporal
    rewind(f);
    // Fase de distribución
    nro_tramos = distribuir(f, fa, fb);
    if (nro_tramos <= 1)
    {
      rmtmp();
      return;
    }
    rewind(f), 	rewind(fa), rewind(fb);
    // Fase de mezcla
    nro_tramos = mezclar(fa, fb, f);
    // Eliminar los ficheros temporales
    fclose(fa);
    fclose(fb);
  }
  while (nro_tramos != 1);
} // fin de mezcla_natural

int distribuir(FILE *f, FILE *fa, FILE *fb)
{
  // Fase de distribución
  FILE *faux = fa;
  char str[MAX];
  char str_ant[MAX];
  int nro_tramos = 1;

  if (fgets(str_ant, MAX, f))
    fputs(str_ant, fa);
  else
    return 0;

  while (fgets(str, MAX, f))
  {
    if (strcmp(str, str_ant) < 0)
    {
      // Cambiar al otro fichero
      faux = (faux == fa) ? fb : fa;
      ++nro_tramos;
    }
    strcpy(str_ant, str);
    fputs(str, faux);
  }
  return (nro_tramos);
} // fin de distribuir

int mezclar(FILE *fa, FILE *fb, FILE *f)
{
  // Fase de mezcla
  char stra[256], strb[256], stra_ant[256], strb_ant[256];
  int nro_tramos = 1;

  // Leemos las dos primeras cadenas
  fgets(stra, MAX, fa); strcpy(stra_ant, stra);
  fgets(strb, MAX, fb); strcpy(strb_ant, strb);

  // Vamos leyendo y comparando hasta que se acabe alguno de los
  // ficheros. La fusión se realiza entre pares de tramos
  // ordenados. Un tramo de fa y otro de fb darán lugar a un
  // tramo ordenado sobre f.
  while (!feof(fa) && !feof(fb))
  {
    if (strcmp(stra, strb) < 0)        // 1
    {
      if (strcmp(stra, stra_ant) < 0)  // 2
      // Encontrado el final del tramo de A
      {
        strcpy(stra_ant, stra);
        // Copiamos el tramo ordenado del fichero B
        do
        {
          fputs(strb, f);
          strcpy(strb_ant, strb);
        }
        while (fgets(strb,MAX,fb) && strcmp(strb,strb_ant) > 0);
        ++nro_tramos;
      }
      else // 2
      {
        // Copiamos la cadena leída del fichero A
        strcpy(stra_ant, stra);
        fputs(stra, f);
        fgets(stra, MAX, fa);
      }
    }
    else // 1
    {
      if (strcmp(strb, strb_ant) < 0)  // 3
      // Encontrado el final del tramo de B
      {
        strcpy(strb_ant, strb);
        // Copiamos el tramo ordenado del fichero A
        do
        {
          fputs(stra, f);
          strcpy(stra_ant, stra);
        }
        while (fgets(stra,MAX,fa) && strcmp(stra,stra_ant) > 0);
        ++nro_tramos;
      }
      else // 3
      {
        // Copiamos la cadena leída del fichero B.
        strcpy(strb_ant, strb);
        fputs(strb, f);
        fgets(strb, MAX, fb);
      }
    }
  } // while

  // Caso de acabarse primero el fichero B
  if (feof(fb))
  {
    fputs(stra, f);
    while (fgets(stra, MAX, fa))
      fputs(stra, f);
  }
  // Caso de acabarse primero el fichero A
  else if (feof(fa))
  {
    fputs(strb, f);
    while (fgets(strb, MAX, fb))
      fputs(strb, f);
  }

  return (nro_tramos);
} // fin de mezclar
