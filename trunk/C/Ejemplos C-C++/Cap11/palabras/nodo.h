/* nodo.h
 */
#if !defined(_NODO_H)
#define _NODO_H


// Tipo Nodo (un elemento del �rbol) ///////////////////////
typedef struct s
{
  void *datos;          // �rea de datos
  struct s *izquierdo;  // puntero al elemento anterior
  struct s *derecho;    // puntero al elemento siguiente
} Nodo;


#endif // _NODO_H 

