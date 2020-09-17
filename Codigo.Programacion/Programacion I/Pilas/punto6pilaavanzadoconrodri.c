#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*6)  Usando lo resuelto en el ejercicio 4, pasar los elementos de una pila a otra de forma tal que
la segunda pila quede ordenada de mayor (tope) a menor (base). Esto se llama método de ordenación por selección.*/

int main()
{
    Pila primera;
    Pila segunda;
    Pila aux;

    inicpila (&primera);
    inicpila (&segunda);
    inicpila (&aux);

    char seguir = 's';

    while (seguir == 's')
    {
        leer (&primera);
        printf ("Desea ingresar mas numeros? s/n \n");
        fflush (stdin);
        scanf ("%c", &seguir);
    }

    mostrar (&primera);

    apilar (&segunda, desapilar (&primera));

    while ((!pilavacia (&primera)) && (pilavacia (&aux)))
    {

    while (!pilavacia (&primera))
    {
        if ((tope (&primera)) < (tope (&segunda)))
        {
            apilar (&aux, desapilar (&segunda));
            apilar (&segunda, desapilar (&primera));
        }
        else if ((tope (&primera)) > (tope (&segunda)))
        {
            apilar (&aux, desapilar (&primera));
        }
    }
    apilar (&segunda, desapilar (&aux));

    while (!pilavacia (&aux))
        if ((tope (&segunda)) < (tope (&aux)))
        {
            apilar (&primera, desapilar (&aux));
        }
        else if ((tope (&segunda)) > (tope (&aux)))
        {
            apilar (&primera, desapilar (&segunda));
            apilar (&segunda, desapilar (&aux));
        }
    apilar (&segunda, desapilar (&primera));
    }


    mostrar (&primera);
    mostrar (&segunda);
    mostrar (&aux);
    return 0;
}
