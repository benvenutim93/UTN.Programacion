#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>


typedef struct nodo
{
    int dato;
    struct nodo * sig;
} nodo;

nodo * inicLista ();
nodo * crearNodo (int );
nodo * agregarPpio (nodo * , nodo * );
nodo * agregarOrdenado (nodo * , nodo * );
void recorrerLista (nodo * );
nodo * borrarNodo (nodo * , int );
nodo * agregarFinal (nodo *, nodo *);
nodo * buscarUltimo (nodo * lista);

#endif // LISTAS_H_INCLUDED
