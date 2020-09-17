#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

int main()
{
    nodo * lista;
    nodo * aux;
    int num=0;
    lista = inicLista();
    lista = cargarNodo(lista);
    /*printf ("\n Que numero desea borrar ? \n");
    scanf ("%d", &num);
    printf ("\n");
    lista = borrarNodo(lista, num);
    recorrerListaIterativa(lista);*/
    /*nodo * nn = crearNodo(8);
    lista = agregarFinal(lista,nn);
    printf ("\n");*/
   /* printf ("\n Que numero desea buscar ? \n");
    scanf ("%d", &num);
    aux = buscarNodo(lista,num);*/
    /*aux=devolverUltimo(lista);
    if (aux == NULL)
        printf ("Su numero no esta en la lista \n");
    else
    {
        //printf ("Su dato fue encontrado \n");
        mostrar(aux);
    }*/


    return 0;
}

