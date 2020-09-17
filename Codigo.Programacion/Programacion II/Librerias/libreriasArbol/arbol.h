#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <stdio.h>


typedef struct nodoArbol
{
    int dato;
    struct nodoArbol * izq;
    struct nodoArbol * der;
}nodoArbol;
typedef struct nodo
{
    int dato;
    struct nodo * sig;
}nodo;
nodoArbol * inicArbol ();
nodoArbol * crearNodoArbol (int );
nodoArbol * agregar (nodoArbol * , nodoArbol *);
int buscarNodoArbol (nodoArbol * , int );
void mostrarPreOrder (nodoArbol * );
int contarNodosArbol(nodoArbol * );
int esHoja(nodoArbol * );
int cuentaHojas(nodoArbol * );
int mayor (int , int );
int cantidadDeNiveles(nodoArbol* );
nodoArbol * nodoMasDerecho(nodoArbol * );
nodoArbol * nodoMasIzquierdo(nodoArbol * );
nodoArbol * borrarUnNodo(nodoArbol * , int );
nodo * pasarArbolLista (nodoArbol * , nodo * );
nodo * crearNodo (int );
nodo * agregarFinal (nodo * , nodo * );

#endif // ARBOL_H_INCLUDED
