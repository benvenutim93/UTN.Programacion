#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/* Determinar  si  la  cantidad  de  elementos  de  la  pila  DADA  es  par.
Si  es  par,  pasar  el elemento del tope de la pila AUX a la pila PAR y si es impar pasar el tope a la pila IMPAR*/

int main()
{
    Pila dada;
    Pila par;
    Pila impar;
    Pila aux;

    inicpila (&dada);
    inicpila (&par);
    inicpila (&impar);
    inicpila (&aux);

    char seguir = 's';

    while(seguir == 's')
        {

        leer(&dada);

        printf("Desea ingresar un numero? s/n \n");
        fflush(stdin);
        scanf("%c", &seguir);
        }

    mostrar (&dada);

    while (!pilavacia (&dada))
    {
        apilar (&impar, desapilar (&dada));
        if (!pilavacia (&dada))
        {
            apilar (&par, desapilar (&dada));
        }
    }

    while ((!pilavacia (&impar)) && (!pilavacia (&par)))
    {
        apilar (&aux, desapilar (&par));
        apilar (&aux, desapilar (&impar));
    }

    if ((pilavacia (&par)) && (pilavacia (&impar)))
    {
        printf ("La cantidad de elementos de la pila es par \n");
    }
    else if ((pilavacia (&par)) && (!pilavacia (&impar)))
    {
        printf ("La cantidad de elementos de la pila es impar \n");
    }
    else
    {
        printf ("La cantidad de elementos de la pila es par \n");
    }


    return 0;
}
