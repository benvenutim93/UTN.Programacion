#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO.
Pasar los
elementos de la pila ORIGEN a la pila DESTINO, pero dejándolos en el mismo orden*/
int main()
{
    Pila origen;
    Pila destino;
    Pila aux;

    inicpila(&origen);
    inicpila(&destino);
    inicpila(&aux);

    leer (&origen);
    leer (&origen);
    leer (&origen);
    leer (&origen);
    leer (&origen);

    while (!pilavacia(&origen))
    {
     apilar (&aux, desapilar (&origen));

    }


    while (!pilavacia (&aux))
    {
        apilar (&destino, desapilar (&aux));

    }

    mostrar (&origen);
    mostrar (&destino);
    mostrar (&aux);

    return 0;
}
