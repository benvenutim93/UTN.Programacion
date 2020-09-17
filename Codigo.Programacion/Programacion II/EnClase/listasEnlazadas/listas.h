#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED
#include <stdio.h>
typedef struct
{
    int dato;
    struct nodo * sig;
} nodo;

nodo * inicLista();
nodo * crearNodo(int);
nodo * agregarPpio (nodo*, nodo*);
void mostrar(nodo*);
void recorrarListaRecursion(nodo*);
void recorrerListaIterativa(nodo*);
nodo * cargarNodo(nodo *);
nodo * agregarOrden (nodo *, nodo *);
nodo * borrarNodo (nodo*, int);
nodo * agregarFinal(nodo *, nodo*);
nodo * buscarNodo (nodo*, int);
nodo * buscarUltimo(nodo *);

#endif // LISTAS_H_INCLUDED
