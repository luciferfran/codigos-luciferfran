/* interfaz_lcde.h
 */
#if !defined(_INTERFAZ_LCSE_H)
#define _INTERFAZ_LCSE_H


// Tipo Elemento (un elemento de la lista) ///////////////////////
#include "elemento.h"

// Interfaz para manipular una lcde //////////////////////////////
//
// Par�metros de la lista
typedef struct
{
  Elemento *ultimo;      // apuntar� siempre al �ltimo elemento
  Elemento *actual;      // apuntar� siempre al elemento accedido
  int numeroDeElementos; // n�mero de elementos de la lista
  int posicion;          // �ndice del elemento apuntado por actual
} tlcde;

// Mostrar un mensaje de error y abortar el programa
void error();

// Crear un nuevo elemento
Elemento *nuevoElemento();

// Iniciar una estructura de tipo tlcde
void iniciarLcde(tlcde *lcde);

// A�adir un nuevo elemento a la lista a continuaci�n
// del elemento actual; el nuevo elemento pasa a ser el
// actual
void insertar(void *e, tlcde *lcde);

// La funci�n borrar devuelve los datos del elemento
// apuntado por actual y lo elimina de la lista.
void *borrar(tlcde *lcde);

// Avanzar la posici�n actual al siguiente elemento.
void irAlSiguiente(tlcde *lcde);

// Retrasar la posici�n actual al elemento anterior.
void irAlAnterior(tlcde *lcde);

// Hacer que la posici�n actual sea el principio de la lista.
void irAlPrincipio(tlcde *lcde);

// El final de la lista es ahora la posici�n actual.
void irAlFinal(tlcde *lcde);

// Posicionarse en el elemento i
int irAl(int i, tlcde *lcde);

// Devolver el puntero a los datos asociados
// con el elemento actual
void *obtenerActual(tlcde *lcde);

// Devolver el puntero a los datos asociados
// con el elemento de �ndice i
void *obtener(int i, tlcde *lcde);

// Establecer nuevos datos para el elemento actual
void modificar(void *pNuevosDatos, tlcde *lcde);


#endif // _INTERFAZ_LCSE_H