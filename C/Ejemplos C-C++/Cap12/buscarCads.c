/* B�squeda de subcadenas
 * buscarCads.c
 */
#include <stdio.h>
#include <string.h>

int buscarCadena(char *texto, char *cadena)
{
  // Algoritmo de Boyer y Moore.
  // Buscar una "cadena" en un "texto".
  int j, longTex = strlen(texto);
  
  // Construir la tabla "delta"
  int delta[256];
  int i, longCad = strlen(cadena);

  // Iniciar la tabla "delta"
  for (i = 0; i < 256; i++)
    delta[i] = longCad;
  // Asignar valores a la tabla
  for (i = 0; i < longCad; i++)
    delta[cadena[i]] = longCad - i - 1;
  
  // Algoritmo Boyer-Moore
  i = longCad - 1; // i es el �ndice dentro del texto
  while (i < longTex)
  {
    j = longCad - 1; // �ndice dentro de la cadena a buscar
    // Mientras haya coincidencia de caracteres
    while (cadena[j] == texto[i])
    {
      if ( j > 0 )
      {
        // Siguiente posici�n a la izquierda
        j--; i--;
      }
      else
      {
        // Se lleg� al principio de la cadena, luego se encontr�.
        return i;
      }
    }
    // Los caracteres no coinciden. Mover i lo que indique el
    // valor "delta" del car�cter del texto que no coincide
    i += delta[texto[i]];
  }
  return -1;
}

void main()
{
  char *texto = "M�s vale un ya que cien despu�s se har�";
  char *cadena = "cien";
  
  if ( buscarCadena(texto, cadena) != -1 )
    printf("La cadena %s est� en el texto\n", cadena);
  else
    printf("La cadena %s no est� en el texto\n", cadena);
}
