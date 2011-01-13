/* elemento.h
 */
#if !defined(_ELEMENTO_H)
#define _ELEMENTO_H


// Tipo Elemento (un elemento de la lista) ///////////////////////
typedef struct s
{
  void *dato;          // área de datos
  struct s *anterior;  // puntero al elemento anterior
  struct s *siguiente; // puntero al elemento siguiente
} Elemento;


#endif // _ELEMENTO_H 

