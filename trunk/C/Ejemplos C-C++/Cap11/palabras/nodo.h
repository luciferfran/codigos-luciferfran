/* nodo.h
 */
#if !defined(_NODO_H)
#define _NODO_H


// Tipo Nodo (un elemento del árbol) ///////////////////////
typedef struct s
{
  void *datos;          // área de datos
  struct s *izquierdo;  // puntero al elemento anterior
  struct s *derecho;    // puntero al elemento siguiente
} Nodo;


#endif // _NODO_H 

