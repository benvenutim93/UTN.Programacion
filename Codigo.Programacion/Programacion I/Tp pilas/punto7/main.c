#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/* Pasar el último elemento (base) de la pila DADA a su primera posición
(tope), dejando los
restantes elementos en el mismo orden.
*/
int main()
{
    Pila dada;
    Pila aux;
    Pila tope;

    inicpila (&dada);
    inicpila (&aux);
    inicpila (&tope);

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

    apilar (&tope, desapilar (&aux));

    while (!pilavacia(&aux))
    {
    apilar (&dada, desapilar (&aux));
    }

    apilar (&dada, desapilar (&tope));

    mostrar (&dada);

    return 0;
}
