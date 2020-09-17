#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*1. Cargar desde el teclado una pila DADA con 5 elementos. Pasar los tres
primeros elementosa la pila AUX1 y los dos restantes a la pila AUX2,
 ambas pilas inicializadas en vacío.
*/
int main()
{
    Pila dada;
    Pila aux1;
    Pila aux2;

    inicpila(&dada);
    inicpila (&aux1);
    inicpila (&aux2);

    leer (&dada);
    leer (&dada);
    leer (&dada);
    leer (&dada);
    leer (&dada);

    apilar (&aux1, desapilar (&dada));
    apilar (&aux1, desapilar (&dada));
    apilar (&aux1, desapilar (&dada));

    apilar (&aux2, desapilar (&dada));
    apilar (&aux2, desapilar (&dada));

    mostrar (&dada);
    mostrar (&aux1);
    mostrar (&aux2);

    return 0;
}
