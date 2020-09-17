#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*Cargar desde teclado una pila DADA y pasar a la pila DISTINTOS
todos aquellos elementos distintos al valor 8.*/
int main()
{
    Pila dada;
    Pila distintos;
    Pila aux;

    inicpila(&dada);
    inicpila (&distintos);
    inicpila (&aux);

    leer (&dada);
    leer (&dada);
    leer (&dada);
    leer (&dada);
    leer (&dada);

    while (!pilavacia(&dada))
    {

    if (tope(&dada)==8)
    {
        apilar (&aux, desapilar (&dada));
    }
    else
    {
        apilar (&distintos, desapilar (&dada));
    }
    }

    mostrar (&dada);
    mostrar (&distintos);
    mostrar (&aux);

    return 0;
}
