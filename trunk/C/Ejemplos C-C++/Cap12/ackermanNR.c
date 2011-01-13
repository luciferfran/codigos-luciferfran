/* ackermanNR.c
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct datos elemento;
typedef elemento * pelemento;
struct datos
{
  int m,n;
  pelemento siguiente;
};

void error(void)
{
  perror("error: no hay suficiente espacio en la pila\n\n");
  exit(1);
}

pelemento NuevoElemento()
{
  pelemento q = (pelemento)malloc(sizeof(elemento));
  if (!q) error();
  return (q);
}

int Ackerman(int, int);
void mete_pila(pelemento *, int, int);
void saca_pila(pelemento *, int *, int *);

main()
{
  int m, n, a;
  printf("Cálculo de A(m,n)=A(m-1,A(m,n-1))\n\n");
  printf("Valores de m y n : ");
  scanf("%d %d", &m, &n);
  a = Ackerman(m,n);
  printf("\n\nA(%d,%d) = %d\n",m,n,a);
}

// Función de Ackerman implementada como una función no recursiva
int Ackerman(int m, int n)
{
  pelemento pila = NULL;  // pila de elementos (m,n)
  int Ackerman_m_n = 0;

  mete_pila(&pila, m, n);
  
  while (1)
  {
    // Tomar los datos de la cima de la pila
    saca_pila(&pila, &m, &n);
    if (m == 0) // resultado para un elemento A(m,n) calculado
    {
      Ackerman_m_n = n+1;
      if (pila)
      {
        saca_pila(&pila, &m, &n);
        mete_pila(&pila, m, Ackerman_m_n);
      }
      else
        return (Ackerman_m_n);
    }
    else if (n == 0)
      mete_pila(&pila, m-1, 1);
    else
    {
      mete_pila(&pila,m-1,Ackerman_m_n); // n=Ackerman(m,n-1)
      mete_pila(&pila, m, n-1);
    }
  }
}

// Función para meter m y n en la pila
void mete_pila(pelemento *p, int m, int n)
{
  pelemento q;

  q = NuevoElemento();
  q->m = m, q->n = n;
  q->siguiente = *p;
  *p = q;
}

// Función para sacar m y n de la pila
void saca_pila(pelemento *p, int *pm, int *pn)
{
  pelemento q = *p; // cima de la pila

  if (q == NULL)
  {
    printf("\nPila vacía\n");
    exit(2);
  }
  else
  {
    *pm = q->m, *pn = q->n;
    *p = q->siguiente;
    free(q);
  }
}
