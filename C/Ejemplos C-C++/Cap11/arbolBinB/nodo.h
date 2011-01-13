/* nodo.h
 */
#if !defined(_NODO_H)
#define _NODO_H


// Tipo Nodo (un elemento del árbol) ///////////////////////
typedef struct s
{
  void *datos;          // área de datos
  struct s *izquierdo;  // raíz del subárbol izquierdo
  struct s *derecho;    // raíz del subárbol derecho
} Nodo;


#endif // _NODO_H 

