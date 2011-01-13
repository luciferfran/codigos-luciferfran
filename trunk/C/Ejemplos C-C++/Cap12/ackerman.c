/* ackerman.c
 */
#include <stdio.h>

int Ackerman(int m, int n)
{
  // Función recursiva de Ackerman:
  //   A(0,n) = n+1
  //   A(m,0) = A(m-1,1)               (m > 0)
  //   A(m,n) = A(m-1,A(m,n-1))        (m,n > 0)
  if (m == 0)
    return n+1;
  else if (n == 0)
    return Ackerman(m-1, 1);
  else
    return Ackerman(m-1, Ackerman(m,n-1));
}

main()
{
  int m, n, a;
  printf("Cálculo de A(m,n)=A(m-1,A(m,n-1))\n\n");
  printf("Valores de m y n : ");
  scanf("%d %d", &m, &n);
  a = Ackerman(m,n);
  printf("\n\nA(%d,%d) = %d\n",m,n,a);
}
