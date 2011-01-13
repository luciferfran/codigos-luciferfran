/*********** Entrada/salida de cadenas de caracteres ***********/
/* fgets.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 81

main()
{
  FILE *pf = NULL;
  char buffer[N], nomfi[13];

  printf("Nombre del fichero: ");
  fgets(nomfi, 13, stdin);
  fflush(stdin); // eliminar posibles caracteres escritos demás
  if (nomfi[strlen(nomfi)-1] == '\n')
    nomfi[strlen(nomfi)-1] = 0; // eliminar \n

  // Abrir el fichero nomfi para escribir y leer
  if ((pf = fopen(nomfi, "w+")) == NULL)
  {
    printf("El fichero %s no puede abrirse.", nomfi);
    exit(1);
  }

  printf("Fichero %s abierto\n", nomfi);
  printf("Introducir datos. Finalizar cada línea con <Entrar>\n");
  printf("Para terminar introduzca la marca eof\n\n");
  while (fgets(buffer, N, stdin) != NULL)
  {
    // Escribir la cadena en el fichero seguida de \n
    fputs(buffer, pf);
    if (ferror(pf))
    {
      perror("Error al escribir");
      exit(2);
    }
  }

  // Visualizar el contenido del fichero
  rewind(pf);  // situarse al principio del fichero

  // leer hasta un '\n' o hasta N-1 caracteres
  //  while (fgets(buffer, N, pf) != NULL)
  //    printf("%s", buffer);

  fgets(buffer, N, pf);
  while (!ferror(pf) && !feof(pf))
  {
    printf("%s", buffer);
    fgets(buffer, N, pf);
  }

  if (ferror(pf))
    perror("Error durante la lectura");

  fclose(pf);
}
