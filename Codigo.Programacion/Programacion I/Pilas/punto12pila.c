#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*Suponiendo  la  existencia  de  una  pila  MODELO  (vacía  o  no),
eliminar  de  la  pila  DADA todos los elementos que existan en MODELO.*/

int main()
{
    Pila modelo, dada, aux1, aux2, aux3;
    char seguir = 's';

    inicpila (&modelo);
    inicpila (&dada);
    inicpila (&aux1);
    inicpila (&aux2);
    inicpila (&aux3);


    apilar (&modelo, 3);
    apilar (&modelo, 5);

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
        if ((tope (&dada)) == (tope (&modelo)))
        {
           apilar (&aux1, desapilar (&dada));
           apilar (&aux3, desapilar (&modelo));
        }
        else if ((tope (&dada)) != (tope (&modelo)))
        {
            apilar (&aux2, desapilar (&dada));
        }

    }

    mostrar (&aux2);




    return 0;
}
