#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "hash.h"

//////////////////////////////////////////////////////////////////
// Interfaz hash abierto: m�todo hash abierto.
// Para utilizar las funciones proporcionadas por esta interfaz,
// tendremos que definir en la aplicaci�n las funciones:
// fa (funci�n de acceso) y comparar.
//
// Mostrar mensaje de error y abortar el programa
void error(char *mensaje)
{
  printf("%s\n", mensaje);
  exit(1);
}
// Buscar un n�mero primo a partir de un n�mero dado ///////////
int numeroPrimo(int n)
{
  int primo = 0;
  int i, r = (int)sqrt((double)n);
  
  if (n % 2 == 0) n++;
  while (!primo)
  {
    primo = 1;
    for (i = 3; i <= r; i += 2)
      if (n % i == 0) primo = 0;
    if (!primo) n += 2; // siguiente impar
  }
  return n;
}

int existe(char *nombreFichero)
{
  FILE *pf = NULL;
  // Verificar si el fichero existe
  int exis = 0; // no existe
  if ((pf = fopen(nombreFichero, "r")) != NULL)
  {
    exis = 1;   // existe
    fclose(pf);
  }
  return exis;
}

// Iniciar el fichero �ndice y abrir el de datos
iniciarFicheros(tMatrizHash *mh)
{
  char nomFich[50], aux[50], resp = 's';
  int i = 0, n_regs = 0;
  tRegInd regI = {0, 0};

  printf("Nombre del fichero �ndice: ");
  gets(nomFich);
  strcpy(aux, nomFich); strcat(aux, ".ind");

  // Verificar si el fichero existe
  if (existe(aux))
  {
    printf("El fichero existe �desea sobrescribirlo? (s/n) ");
    resp = getchar();
    fflush(stdin);
  }
  if (resp == 's')
  {
    mh->pfInd = fopen(aux, "w+b");
    if (!mh->pfInd) error("No se puede abrir el fichero �ndice");

    printf("N�mero de registros para el fichero �ndice: ");
    if ((scanf("%d", &n_regs) == 0) || n_regs < 1) n_regs = 101;
    // Crear un fichero �ndice con n_regs registros inicialmente
    // vac�os, de los que se prev� que ser�n ocupados el 80%=n_regs
    n_regs = (int)(n_regs / 0.8);
    mh->n_regs = numeroPrimo(n_regs);

    for (i = 0; i < mh->n_regs; i++)
      fwrite(&regI, sizeof(tRegInd), 1, mh->pfInd);
    if (ferror(mh->pfInd)) error("No se puede crear el fichero �ndice");
    strcpy(aux, nomFich); strcat(aux, ".dat");
    mh->pfDat = fopen(aux, "w+b");
    if (!mh->pfDat) error("No se puede abrir el fichero de datos");
    printf("Ficheros �ndice y datos creados\n");
  }
  else
  {
    printf("Se abre el fichero existente\n");
    mh->pfInd = fopen(aux, "r+b");
    if (!mh->pfInd) error("No se puede abrir el fichero �ndice");
    strcpy(aux, nomFich); strcat(aux, ".dat");
    mh->pfDat = fopen(aux, "r+b");
    if (!mh->pfDat) error("No se puede abrir el fichero de datos");

    fseek(mh->pfInd, 0, SEEK_END);
    mh->n_regs = ftell(mh->pfInd) / sizeof(tRegInd);
    rewind(mh->pfInd);
  }
}

// A�adir un registro
int hashIn(tRegInd x, tMatrizHash mh)
{
  int i;         // �ndice para acceder a un registro
  int conta = 0; // contador
  int insertado = 0;
  tRegInd reg;
  
  i = x.clave % mh.n_regs;     // funci�n de acceso
  while (conta < mh.n_regs)
  {
    fseek(mh.pfInd, i * sizeof(tRegInd), SEEK_SET);
    fread(&reg, sizeof(tRegInd), 1, mh.pfInd);
    if (reg.clave == 0) // elemento libre
    {
      fseek(mh.pfInd, i * sizeof(tRegInd), SEEK_SET);
      fwrite(&x, sizeof(tRegInd), 1, mh.pfInd);
      insertado = 1;
      break;
    }
    else // �clave duplicada?
      if (x.clave == reg.clave)
      {
        printf("error: clave duplicada\n");
        insertado = 0;
        break;
      }
      else // colisi�n
      {
        // Siguiente registro libre
        i++; conta++;
        if (i == mh.n_regs) i = 0;
      }
  }
  if (conta == mh.n_regs)
  {
    printf("error: fichero �ndice lleno\n");
    insertado = 0;
  }
  return insertado;
}

// Buscar un registro con una clave determinada
int hashOut(tRegInd x, tMatrizHash mh)
{
  // x proporcionar� el atributo utilizado para buscar. El resto
  // de los atributos no interesan (son los que se desea conocer)

  int i;         // �ndice para acceder a un elemento
  int conta = 0; // contador
  int encontrado = 0;
  tRegInd reg;
  
  i = x.clave % mh.n_regs;     // funci�n de acceso
  while (!encontrado && conta < mh.n_regs)
  {
    fseek(mh.pfInd, i * sizeof(tRegInd), SEEK_SET);
    fread(&reg, sizeof(tRegInd), 1, mh.pfInd);
    if (reg.clave == 0) return -1;

    if (x.clave == reg.clave)
      encontrado = 1;
    else // colisi�n
    {
      // Siguiente elemento libre
      i++; conta++;
      if (i == mh.n_regs) i = 0;
    }
  }
  if (conta == mh.n_regs) // no existe
    return -1;
  else
    return reg.numReg;
}
//////////////////////////////////////////////////////////////////
