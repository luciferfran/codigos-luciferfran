/* nodo.h
 */
#if !defined(_NODO_H)
#define _NODO_H


// Tipo Nodo (un elemento del �rbol) ///////////////////////
typedef struct s
{
  void *datos;          // �rea de datos
  struct s *izquierdo;  // ra�z del sub�rbol izquierdo
  struct s *derecho;    // ra�z del sub�rbol derecho
} Nodo;


#endif // _NODO_H 

