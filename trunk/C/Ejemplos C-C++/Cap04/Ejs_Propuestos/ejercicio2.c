/* Obtención del volumen de una esfera
 *
 * Cap4 - ejercicio2.c
 */

#include <stdio.h>

main()
{                                                                            
  double radio, volumen;

  printf("Radio de la esfera: ");
  scanf("%lf", &radio);  // Leer un valor double desde el teclado y almacenalo
                        // en la variable radio
  volumen = 4.0 / 3.0 * 3.141593 * radio * radio * radio; 
  // No es necesario usar paréntesis, aunque también se podía haber escrito:
  // volumen = (4.0 / 3.0) * 3.141593 * radio * radio * radio.
  printf("Volumen de la esfera = %.4f\n", volumen); // 4 decimales fijos    
}
