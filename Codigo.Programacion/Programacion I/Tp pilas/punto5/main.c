#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*  Cargar desde el teclado la pila DADA. Invertir la pila de manera
que DADA contenga los
elementos cargados originalmente en ella, pero en orden inverso*/
int main()
{
    Pila dada;
    Pila aux;
    Pila aux1;

    inicpila (&dada);
    inicpila (&aux);
    inicpila (&aux1);

    leer (&dada);
    leer (&dada);
    leer (&dada);
    leer (&dada);
    leer (&dada);

    mostrar (&dada);

    while (!pilavacia(&dada))
    {
        apilar (&aux, desapilar (&dada));
    }

    while (!pilavacia (&aux))
    {
        apilar (&aux1, desapilar (&aux));
    }

    while (!pilavacia (&aux1))
    {
        apilar (&dada, desapilar (&aux1));
    }

    mostrar (&dada);

    return 0;
}
