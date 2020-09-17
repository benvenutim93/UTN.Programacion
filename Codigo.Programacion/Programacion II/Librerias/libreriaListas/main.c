#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

int main()
{
    nodo * lista = inicLista();
    nodo * aux = crearNodo(17);
    lista = agregarPpio(lista,aux);
    recorrerLista(lista);
    return 0;
}

