#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*Pasar el primer elemento (tope) de la pila DADA a su última posición
(base), dejando los
restantes elementos en el mismo orden.*/
int main()
{
    Pila dada;
    Pila aux;
    Pila base;

    inicpila (&dada);
    inicpila (&aux);
    inicpila (&base);

    leer (&dada);
    leer (&dada);
    leer (&dada);
    leer (&dada);
    leer (&dada);

    mostrar (&dada);

    apilar (&base, desapilar (&dada));

    while (!pilavacia (&dada))
    {
        apilar (&aux, desapilar (&dada));
    }

    apilar (&dada, desapilar (&base));

    while (!pilavacia (&aux))
    {
        apilar (&dada, desapilar (&aux));
    }

    mostrar (&dada);

    return 0;
}
