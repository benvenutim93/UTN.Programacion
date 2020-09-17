#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*Repartir los elementos de la pila MAZO en las pilas JUGADOR1 y JUGADOR2 en forma
alternativa*/

int main()
{
    Pila mazo;
    Pila jugador1;
    Pila jugador2;

    inicpila (&mazo);
    inicpila (&jugador1);
    inicpila (&jugador2);

    leer (&mazo);
    leer (&mazo);
    leer (&mazo);
    leer (&mazo);
    leer (&mazo);
    leer (&mazo);

    mostrar (&mazo);

    apilar (&jugador1, desapilar (&mazo));
    apilar (&jugador2, desapilar (&mazo));
    apilar (&jugador1, desapilar (&mazo));
    apilar (&jugador2, desapilar (&mazo));
    apilar (&jugador1, desapilar (&mazo));
    apilar (&jugador2, desapilar (&mazo));

    mostrar (&mazo);
    mostrar(&jugador1);
    mostrar (&jugador2);

    return 0;
}
