// ferror.c
//
#include <stdio.h>
#include <stdlib.h>
 
main() 
{ 
  FILE *pf; 
  char *cadena = "Esta cadena nunca será escrita";

  if ((pf = fopen("datos", "r")) == NULL)
  {
    printf("Error: no se puede abrir el fichero\n");
    exit(1);
  } 
  fprintf(pf, "%s\n", cadena); 
  if (ferror(pf)) 
  { 
    printf("Error al escribir en el fichero\n"); 
    clearerr(pf); 
  } 
  fclose(pf);
}
