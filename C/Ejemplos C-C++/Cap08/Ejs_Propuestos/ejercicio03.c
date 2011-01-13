/* Comparación de cadenas
 * ejercicio03.c
 */
#include <stdio.h>
#include <string.h>

int compcads(char *cadena1, char *cadena2, int n);                 
                          
main()
{                         
	char Cadena1[50], Cadena2[50];
	int n, temp;
	printf("Cadena 1: "); gets(Cadena1);
	printf("Cadena 2: "); gets(Cadena2);
	printf("Número de caracteres que desea comparar: ");
	scanf("%d", &n);
	temp = compcads(Cadena1, Cadena2, n);
	if (temp >= 1)
		printf("%s", Cadena2); 
	else
		printf("%s", Cadena1);
}

int compcads(char *cadena1, char *cadena2, int n)
{
 	int res = 0, i = 0, lonmin = 0, loncad1 = 0, loncad2 = 0, m = 0;
  loncad1 = strlen(cadena1);
  loncad2 = strlen(cadena2);
  lonmin =  loncad1 < loncad2 ? loncad1 : loncad2;
  if (n >= 1 && n <= lonmin)
    m = n;
  else
    m = lonmin;

  for (i = 0; i < m; i++)
  {
    if (cadena1[i] == cadena2[i]) continue;
    if (cadena1[i] < cadena2[i])
    {
      res = -1;
      break;
    }
    if (cadena1[i] > cadena2[i])
    {
      res = 1;
      break;
    }
  }

  if (res) return res;
  // Si res = 0 y las cadenas son de diferente longitud ...
  if (m == lonmin)
    if (loncad1 < loncad2)
      return -1;
    else if (loncad1 > loncad2)
      return 1;
  return res;
}