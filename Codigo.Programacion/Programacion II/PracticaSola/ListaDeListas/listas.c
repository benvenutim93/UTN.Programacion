#include "listas.h"

nodo * inicLista ()
{
    return NULL;
}
nodo * crearNodo (int dato)
{
    nodo * aux = (nodo*)malloc(sizeof(nodo));
    aux->dato=dato;
    aux->sig=NULL;
    return aux;
}
nodo * agregarPpio (nodo * lista, nodo * nn)
{
    if (lista !=NULL)
        nn->sig=lista;
    lista=nn;
    return lista;
}
nodo * agregarOrdenado (nodo * lista, nodo * nn)
{
    nodo * seg = lista->sig;
    nodo * ant = lista;
    if (lista == NULL)
        lista = nn;
    else if (nn->dato < lista->dato)
        lista = agregarPpio(lista,nn);
    else
    {
        while (seg != NULL && nn->dato > seg->dato)
        {
            ant=seg;
            seg=seg->sig;
        }
        ant->sig=nn;
        if (seg != NULL)
            nn->sig=seg;
    }
    return lista;
}

void recorrerLista (nodo * lista)
{
    if(lista != NULL)
    {
        printf ("---------------------\n");
        printf ("DATO: %d\n", lista->dato);
        recorrerLista(lista->sig);
    }
}
nodo * borrarNodo (nodo * lista, int aborrar)
{
    if (lista != NULL)
    {
        if (lista->dato == aborrar)
        {
            nodo * aux = lista;
            lista=lista->sig;
            free(aux);
        }
        else
        {
            nodo * ant = lista;
            nodo * seg = lista->sig;
            while (seg != NULL && seg->dato != aborrar)
            {
                ant = seg;
                seg = seg->sig;
            }
            if (seg != NULL)
                ant->sig=seg->sig;
            free(seg);
        }
    }
    return lista;
}
nodo * buscarUltimo (nodo * lista)
{
    nodo * seg = lista;
    if(seg != NULL)
    {
        while (seg->sig != NULL)
            seg=seg->sig;
    }
    return seg;
}
nodo * agregarFinal (nodo * lista, nodo * nn)
{
    if (lista == NULL)
        lista=nn;
    else
    {
        nodo * aux = buscarUltimo(lista);
        aux->sig=nn;
    }
    return lista;
}
