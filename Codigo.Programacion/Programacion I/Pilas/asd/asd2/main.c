#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*Dada la pila ORIGEN ordenarla en forma ascendente por método de inserción dejando el resultado en la pila
ORIGEN. Para este ejercicio usar lo aprendido para el ejercicio 5*/

int main()
{
    Pila origen, menor, mayor, auxAA;

    inicpila (&origen);
    inicpila (&menor);
    inicpila (&mayor);
    inicpila (&auxAA);

    char seguir = 's';

    while (seguir == 's')
    {
        leer (&origen);
        printf ("Desea ingresar otro numero? s/n \n");
        fflush (stdin);
        scanf ("%c", &seguir);
    }
    mostrar (&origen);

    apilar (&menor, desapilar (&origen));

    while (!pilavacia (&origen))
    {

    while (!pilavacia (&origen))
    {
        if ((tope (&origen)) > (tope (&menor)))
        {
            apilar (&mayor, desapilar (&origen));
        }
        else
        {
            apilar (&mayor, desapilar (&menor));
            apilar (&menor, desapilar (&origen));
        }
    }

    apilar (&menor, desapilar (&mayor));

    while (!pilavacia (&mayor))
    {
        if ((tope (&mayor)) > (tope (&menor)))
        {
            apilar (&origen, desapilar (&mayor));
        }
        else
        {
            apilar (&origen, desapilar (&menor));
            apilar (&menor, desapilar (&mayor));
        }
    }

    }

    mostrar (&menor);

    return 0;
}
