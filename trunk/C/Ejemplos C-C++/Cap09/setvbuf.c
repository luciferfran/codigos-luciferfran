/********** Control del buffer asociado a un fichero **********/
/* setvbuf.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIBUFFER 2048

int cuenta_lineas(FILE *pf);
FILE *abrir(char *);

// BUFSIZ es una constante definida en stdio.h
char buf1[BUFSIZ], buf2[MIBUFFER];  // buffers para el fichero

int main(int argc, char *argv[])
{
  time_t t_inicial;
  FILE *pf;
  int  c;

  if (argc != 2)  // verificar el número de argumentos
  {
    printf("Sintaxis: nombre_programa nombre_fichero.\n");
    exit(1);
  }
  pf = abrir(argv[1]);
  
  /**************************************************************
            Utilizando el buffer buf1, de tamaño BUFSIZ
  **************************************************************/
  setvbuf(pf, buf1, _IOFBF, BUFSIZ);
  t_inicial = clock();
  c = cuenta_lineas(pf);
  printf("Tiempo: %5.1f\tTamaño del Buffer: %4d\n",
	   ((float)clock()-t_inicial)/CLK_TCK, BUFSIZ);

  pf = abrir(argv[1]);
  
  /**************************************************************
           Utilizando el buffer buf2, de tamaño MIBUFFER
  **************************************************************/
  setvbuf(pf, buf2, _IOFBF, sizeof(buf2));
  t_inicial = clock();
  c = cuenta_lineas(pf);
  printf("Tiempo: %5.1f\tTamaño del Buffer: %4d\t  mi buffer\n",
	   ((float)clock()-t_inicial)/CLK_TCK, MIBUFFER);

  pf = abrir(argv[1]);
  
  /**************************************************************
                      Sin utilizar un buffer
  **************************************************************/
  setvbuf(pf, NULL, _IONBF, 0);
  t_inicial = clock();
  c = cuenta_lineas(pf);
  printf("Tiempo: %5.1f\tTamaño del Buffer: %4d\n",
	    ((float)clock()-t_inicial)/CLK_TCK, 0);

  printf("\nEl fichero %s tiene %d líneas\n", argv[1], c);
  return 0;
}

/****************************************************************
              Contar líneas en un fichero de texto
****************************************************************/
int cuenta_lineas(FILE *pf)
{
  #define N 81
  char linea_buf[N];
  int c = 0;

  while (!ferror(pf) && !feof(pf))
  {
    fgets(linea_buf, N, pf);     // lee una línea
    c++;                         // contar líneas
    (c % 2) ? printf("\\\r") : printf("/\r");
  }
  if ( ferror(pf) )
  {
    printf("Ha ocurrido un error de lectura.");
    fclose(pf);
    exit(3);
  }
  putchar('\n');
  fclose(pf);
  return c;
}

/****************************************************************
              Abrir el fichero indicado por argv[1]
****************************************************************/
FILE *abrir(char *fichero)
{
  FILE *pf;
  if ((pf = fopen(fichero, "r" )) == NULL)
  {
    printf("El fichero %s no puede abrirse.\n", fichero);
    exit(2);
  }
  return pf;
}
