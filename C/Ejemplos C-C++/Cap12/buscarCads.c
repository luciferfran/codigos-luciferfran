/* Búsqueda de subcadenas
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
  i = longCad - 1; // i es el índice dentro del texto
  while (i < longTex)
  {
    j = longCad - 1; // índice dentro de la cadena a buscar
    // Mientras haya coincidencia de caracteres
    while (cadena[j] == texto[i])
    {
      if ( j > 0 )
      {
        // Siguiente posición a la izquierda
        j--; i--;
      }
      else
      {
        // Se llegó al principio de la cadena, luego se encontró.
        return i;
      }
    }
    // Los caracteres no coinciden. Mover i lo que indique el
    // valor "delta" del carácter del texto que no coincide
    i += delta[texto[i]];
  }
  return -1;
}

void main()
{
  char *texto = "Más vale un ya que cien después se hará";
  char *cadena = "cien";
  
  if ( buscarCadena(texto, cadena) != -1 )
    printf("La cadena %s está en el texto\n", cadena);
  else
    printf("La cadena %s no está en el texto\n", cadena);
}
