/* Leer el fichero de notas 
 * ejercicio02.c
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  unsigned int n_matricula;
  char nombre[40];
  char calificacion[3];
} registro;         

main(int argc, char *argv [])
{
  FILE *pf;
  registro reg;
  int ss, ap, nt, sb, total;

  ss = ap = nt = sb = 0;
  if (argc != 2)
  {
    // Se toma por defecto el fichero 'alumnos.dat'
    argv[1] = "alumnos.dat";
  }
  if ((pf = fopen(argv[1], "r")) == NULL)
  {
    perror(argv[1]);
    exit(-1);
  }
  
  fread(&reg, sizeof(reg), 1, pf);
  while (!ferror(pf) && !feof(pf))
  {
    if ( toupper(reg.calificacion[1]) == 'S')
      ss++;
    else if (toupper(reg.calificacion[0]) == 'A')
      ap++;
    else if (toupper(reg.calificacion[0]) == 'N')
      nt++;
    else if (toupper(reg.calificacion[1]) == 'B')
      sb++;
    fread(&reg, sizeof(reg), 1, pf);
  }
  if (ferror(pf))
    perror("Error durante la lectura");
  else
  {
    total = ss + ap + nt + sb;
    printf ("Suspensos:\t%d (%g%%)\nAprobados:\t%d (%g%%)\nNotables:\t%d (%g%%)\n"
      "Sobresalientes:\t%d (%g%%)\n", ss, ss*100.0/total, ap, ap*100.0/total, nt, 
      nt*100.0/total, sb, sb*100.0/total) ;
  }
  fclose(pf);
}
