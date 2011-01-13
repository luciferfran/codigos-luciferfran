//////////////////////////////////////////////////////////////////
// Utilizar una pila para simular una calculadora capaz de
// realizar las operaciones +, -, * y /, utilizando la
// notación postfija.
//
// calculadora.c
//
#include <stdio.h>
#include <stdlib.h>
#include "interfaz_pila_cola.h"

void liberarMemoria(Elemento **pila)
{
  // Borrar todos los elementos de la pila
  double *pdouble = NULL;
  // borrar: borra siempre el primer elemento
  pdouble = borrar(pila);
  while (pdouble)
  {
    free(pdouble); // borrar el área de datos
    pdouble = borrar(pila); // borrar elemento
  }
}

void *nuevoDouble(double d)
{
  // Reservar memoria para un double
  double *p = (double *)malloc(sizeof(double));
  if (!p) error();
  *p = d;
  return p;
}

int obtenerOperandos(double operando[], Elemento **pila)
{
  // Obtener los dos operandos de la cima de la pila
  double *pdouble = NULL;

  if (tamanyo(*pila) < 2)
  {
    printf("Error: teclee %d operando(s) más\n", 2 - tamanyo(*pila));
    return 0;
  }
  pdouble = (double *)sacarDePila(pila);
  operando[0] = *pdouble;
  free(pdouble);
  pdouble = (double *)sacarDePila(pila);
  operando[1] = *pdouble;
  free(pdouble);
  return 1;
}

main()
{
  // Pila vacía
  Elemento *pila = NULL;

  // oper almacena la entrada realizada desde el teclado
  char oper[20];
  // operando almacena los dos operandos
  double operando[2];

  printf("Operaciones: + - * /\n\n");
  printf("Forma de introducir los datos:\n");
  printf(">operando 0 [Entrar]\n");
  printf(">operando 1 [Entrar]\n");
  printf(">operador [Entrar]\n\n");
  printf("Para salir pulse q\n\n");

  do
  {
    printf("> ");
    gets(oper);       // leer un operando o un operador
    switch (oper[0])  // verificar el primer carácter
    {
      case '+':
        if (!obtenerOperandos(operando, &pila)) break;
        printf("%g\n", operando[0] + operando[1]);
        meterEnPila(nuevoDouble(operando[0]+operando[1]), &pila);
        break;
      case '-':
        if (!obtenerOperandos(operando, &pila)) break;
        printf("%g\n", operando[0] - operando[1]);
        meterEnPila(nuevoDouble(operando[0]-operando[1]), &pila);
        break;
      case '*':
        if (!obtenerOperandos(operando, &pila)) break;
        printf("%g\n", operando[0] * operando[1]);
        meterEnPila(nuevoDouble(operando[0]*operando[1]), &pila);
        break;
      case '/':
        if (!obtenerOperandos(operando, &pila)) break;
        if (operando[1] == 0)
        {
          printf("\nError: división por cero");
          break;
        }
        printf("%g\n", operando[0] / operando[1]);
        meterEnPila(nuevoDouble(operando[0]/operando[1]), &pila);
        break;
      case 'q':
        // salir
        break;
      default :  // es un operando
        meterEnPila(nuevoDouble(atof(oper)), &pila);
    }
  }
  while (oper[0] != 'q');

  // Borrar la pila
  liberarMemoria(&pila);
}
