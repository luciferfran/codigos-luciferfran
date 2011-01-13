/*********************** Campos de bits ***********************/
/* campos_de_bits.c
 */
#include <stdio.h>

struct palabra		// palabra de 32 bits: 0 a 31
{ 
  unsigned car_ascii   : 7; // bits 0 a 6 
  unsigned bit_paridad : 1; // bit 7
  unsigned operacion   : 5; // bits 8 a 12
  unsigned             :18; // bits 13 a 30 de relleno 
  unsigned bit_signo   : 1; // bit 31 
};
 
main()  //  función principal 
{ 
  struct palabra cb = { 'C', 1, 0x1E, 0 }; 

  printf("campos de bits : %x\n\n", cb); 
  printf("bit de signo   : %x\n", cb.bit_signo); 
  printf("operación      : %x\n", cb.operacion);
  printf("bit de paridad : %x\n", cb.bit_paridad); 
  printf("carácter %c     : %x\n", cb.car_ascii, cb.car_ascii);
} 
