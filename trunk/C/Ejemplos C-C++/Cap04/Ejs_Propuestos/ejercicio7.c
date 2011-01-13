/* Uso de constantes numéricas
 *
 * Cap4\ej6.c
 */

#include <stdio.h>        

/* Con este programa, se obtiene un número ASCII y su letra correspondiente;
   en este caso "97 a" en ambos printf  */                

main()
{                 
	char car1 = 'A', car2 = 65, car3 = 0;	  // el valor ASCII de 'A' es 65
	car3 = car1 + 'a' - 'A';                // car3 = 'A' + 'a' - 'A' = 'a'
	printf("%d %c\n", car3, car3);          // 'A' dista de 'a' 32 caracteres, luego:
	car3 = car2 + 32;                       // car3 = 'A' + 32 = 'a'
	printf("%d %c\n", car3, car3);
}
