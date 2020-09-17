#include "arbol.h"

nodoArbol * inicArbol ()
{
    return NULL;
}
nodoArbol * crearNodoArbol (int dato)
{
    nodoArbol * aux = (nodoArbol*) malloc (sizeof(nodoArbol));
    aux->dato = dato;
    aux->der=NULL;
    aux->izq=NULL;
    return aux;
}
nodoArbol * agregar (nodoArbol * lito, nodoArbol * nn)
{
    if (lito == NULL)
        lito = nn;
    else
    {
        if (nn->dato < lito->dato)
            lito->izq = agregar (lito->izq, nn);
        else
            lito->der = agregar (lito->der, nn);
    }
    return lito;
}
int buscarNodoArbol (nodoArbol * lito, int buscado)
{
    int rta =0;
    if (lito != NULL)
    {
        if (lito->dato == buscado)
            rta = 1;
        else if (buscado < lito->dato)
            rta = buscarNodoArbol (lito->izq, buscado);
        else
            rta = buscarNodoArbol (lito->der, buscado);
    }
    return rta;
}
void mostrarPreOrder (nodoArbol * lito)
{
    if (lito != NULL)
    {
        printf ("DATO: %d\n", lito->dato);
        mostrarPreOrder (lito->izq);
        mostrarPreOrder(lito->der);
    }
}
int contarNodosArbol(nodoArbol * arbol)
{
    int rta;
    if(arbol==NULL)
    {
        rta=0;
    }
    else
    {
        rta=1+contarNodosArbol(arbol->izq)+contarNodosArbol(arbol->der);
    }
    return rta;
}
int esHoja(nodoArbol * arbol)
{
    int rta=0;
    if(arbol)
    {
        if(arbol->izq==NULL&&arbol->der==NULL)
        {
            rta=1;
        }
    }
    return rta;
}
int cuentaHojas(nodoArbol * arbol)
{
    int rta;
    if(arbol==NULL)
    {
        rta=0; // st
    }
    else
    {
        if(esHoja(arbol))
        {
            rta=1; //st
        }
        else
        {
            rta=cuentaHojas(arbol->izq)+cuentaHojas(arbol->der);
        }
    }
    return rta;
}
int mayor (int izquierdo, int derecho)
{
    int rta =0;
    if (izquierdo>derecho)
    {
        rta = izquierdo;
    }
    else
    {
        rta=derecho;
    }
    return rta;
}

int cantidadDeNiveles(nodoArbol* arbol)
{
    int resp;
    if(arbol==NULL)
    {
        resp=0;
    }
    else
    {
        if(arbol->der==NULL && arbol->izq==NULL) /// esto podemos evaluarlo con la fn esHoja
        {
            resp=1;
        }
        else
        {
            resp=1 + mayor(cantidadDeNiveles(arbol->izq), cantidadDeNiveles(arbol->der));
        }
    }
    return resp;
}
nodoArbol * nodoMasDerecho(nodoArbol * arbol)
{
    nodoArbol * aux;
    if(arbol->der==NULL)
    {
        aux=arbol;
    }
    else
    {
        aux=nodoMasDerecho(arbol->der);
    }
    return aux;
}

nodoArbol * nodoMasIzquierdo(nodoArbol * arbol)
{
    nodoArbol * aux;
    if(arbol->izq==NULL)
    {
        aux=arbol;
    }
    else
    {
        aux=nodoMasIzquierdo(arbol->izq);
    }
    return aux;
}


nodoArbol * borrarUnNodo(nodoArbol * arbol, int dato)
{
    if(arbol!=NULL)
    {
        if(dato > arbol->dato)
        {
            arbol->der=borrarUnNodo(arbol->der, dato);
        }
        else if (dato< arbol->dato)
        {
            arbol->izq=borrarUnNodo(arbol->izq, dato);
        }
        else
        {
            if(arbol->izq!=NULL)
            {
                arbol->dato= (nodoMasDerecho(arbol->izq))->dato;
                arbol->izq=borrarUnNodo(arbol->izq, arbol->dato);
            }
            else if(arbol->der!=NULL)
            {
                arbol->dato=(nodoMasIzquierdo(arbol->der))->dato;
                arbol->der=borrarUnNodo(arbol->der, arbol->dato);
            }
            else
            {
                free(arbol);
                arbol=NULL;
            }
        }
    }
    return arbol;
}
nodo * pasarArbolLista (nodoArbol * arbol, nodo * lista)
{
    nodo * aux=NULL;
    if(arbol!=NULL)
    {

        lista=pasarArbolLista(arbol->izq, lista);

        aux=crearNodo(arbol->dato);
        lista=agregarFinal(lista, aux);

        lista=pasarArbolLista(arbol->der, lista);
    }
    return lista;
}

nodo * crearNodo (int dato)
{
    nodo * aux = (nodo*)malloc(sizeof(nodo));
    aux->dato=dato;
    aux->sig=NULL;
    return aux;
}

nodo * agregarFinal (nodo * lista, nodo * nn)
{
    nodo * seg = lista;
    while (seg->sig != NULL)
    {
        seg=seg->sig;
    }
    seg->sig=nn;
    return lista;
}
