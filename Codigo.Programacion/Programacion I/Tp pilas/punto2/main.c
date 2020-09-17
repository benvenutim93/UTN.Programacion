#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO.
Pasar todos
los elementos de la pila ORIGEN a la pila DESTINO.*/

int main()
{
    Pila origen;
    Pila destino;

    inicpila(&origen);
    inicpila (&destino);

    leer (&origen);
    leer (&origen);
    leer (&origen);

    apilar (&destino, desapilar (&origen));
    apilar (&destino, desapilar (&origen));
    apilar (&destino, desapilar (&origen));

    mostrar (&origen);
    mostrar (&destino);
    return 0;
}
