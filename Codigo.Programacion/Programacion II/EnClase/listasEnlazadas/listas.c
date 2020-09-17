#include "listas.h"
nodo * inicLista ()
{
    return NULL;
}

nodo * crearNodo (int num)
{
    nodo * a = (nodo*) malloc (sizeof(nodo));
    a->dato=num;
    a->sig=NULL;
    return a;
}
nodo * agregarPpio(nodo * lista, nodo * nn)
{
    if (lista==NULL)
        lista=nn;
    else
    {
        nn->sig=lista;
        lista=nn;
    }
    return lista;
}

void mostrar (nodo * a)
{
    printf (" %d -", a->dato);
}

void recorrerListaIterativa (nodo * lista)
{
    nodo * aux = lista;
    while (aux != NULL)
    {
        mostrar (aux);
        aux=aux->sig;
    }
}

void recorrarListaRecursion (nodo * lista)
{
    nodo * aux = lista;
    if (aux != NULL)
    {
        mostrar (aux);
        recorrarListaRecursion(aux->sig);
    }
}

nodo * cargarNodo (nodo * lista)
{
    nodo * aux;
    int num;
    char seguir = 's';
    while (seguir == 's')
    {
        printf ("Que numero quiere cargar al nodo? \n");
        scanf ("%d", &num);
        aux = crearNodo(num);
        lista = agregarPpio(lista, aux);


        printf ("Quiere cargar otro nodo?\n");
        fflush (stdin);
        scanf ("%c", &seguir);
    }

    recorrarListaRecursion(lista);

    return lista;
}

nodo * agregarOrden(nodo * lista, nodo * nn)
{
    nodo * ant = lista;
    nodo * seg = lista ->sig;
    if (lista == NULL)
        lista = nn;
    else if (lista->dato > nn->dato)
        lista = agregarPpio(lista,nn);
    else
    {
        nodo * ant = lista;
        nodo * seg = lista ->sig;
        while (seg != NULL && seg->dato < nn->dato)
        {
            ant = seg;
            seg = seg->sig;
        }
    }
    if (seg != NULL)
    {
        ant->sig = nn;
        nn->sig=seg;
    }
    else
        ant ->sig = nn;
    return lista;
}

nodo * borrarNodo(nodo * lista, int num)
{
    nodo * seg=lista->sig;
    nodo * ant=lista;

    if(lista!=NULL)
    {
        if(lista ->dato == num)
        {
            nodo * aborrar = lista;
            lista = lista->sig;
            free(aborrar);
        }
        else
        {
            while(seg!=NULL && seg->dato != num)
            {
                ant= seg;
                seg = seg->sig;
            }
            if(seg!=NULL)
            {
                ant ->sig = seg ->sig;
                free(seg);
            }
        }
    }
    return lista;
}
nodo * agregarFinal(nodo * listado, nodo * nn)
{
    nodo * seg = listado->sig;
    nodo * ant = listado;
    if (listado == NULL)
        listado = nn;
    else
    {
        while (seg != NULL)
        {
            ant=seg;
            seg=seg->sig;
        }
        ant ->sig = nn;
    }

    return listado;
}

nodo * buscarNodo(nodo * lista, int dato)
{
    nodo * aux = lista;
    nodo * encontrado;
    if (aux == NULL)
        encontrado = NULL;
    else if (aux != NULL)
    {
        while (aux != NULL && aux->dato != dato)
        {
            aux=aux->sig;
        }
        if (aux == NULL)
            encontrado = NULL;
        else
            encontrado = aux;
    }
    return encontrado;
}
nodo * buscarUltimo(nodo * listado)
{
    nodo * aux = listado->sig;
    nodo * ultimo;

    if(listado==NULL)
       ultimo=NULL;
    else
    {
        while(aux -> sig!=NULL)
        {
            aux= aux->sig;
        }
        ultimo= aux;
    }
    return ultimo;
}
