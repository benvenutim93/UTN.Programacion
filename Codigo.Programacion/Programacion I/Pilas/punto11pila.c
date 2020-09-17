#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*Suponiendo la existencia de una pila MODELO que no este vacía,
eliminar de la pila DADA todos los elementos que sean iguales al tope de la pila MODELO.*/

int main()
{
    Pila modelo, dada, aux1, aux2;
    char seguir = 's';

    inicpila(&modelo);
    inicpila (&dada);
    inicpila (&aux1);
    inicpila (&aux2);

    apilar (&modelo, 3);

    while (seguir =='s')
    {
        leer (&dada);
        printf ("Desea seguir? s/n \n");
        fflush (stdin);
        scanf ("%c", &seguir);
    }

    mostrar (&dada);

    while (!pilavacia (&dada))
    {
        if (tope (&dada) == (tope (&modelo)))
             {
                 apilar (&aux1, desapilar (&dada));
             }
        else if ((tope (&dada)) != (tope (&modelo)))
            {
                apilar (&aux2, desapilar (&dada));
            }
    }

    mostrar (&aux2);

    return 0;
}
