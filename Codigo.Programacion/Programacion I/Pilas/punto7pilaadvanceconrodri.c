#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

//Determinar si un elemento buscado está dentro de una pila
int main()
{

    Pila dada;
    Pila aux;
    Pila aux1;
    Pila auxAA;

    inicpila(&aux1);
    inicpila(&dada);
    inicpila(&aux);
    inicpila(&auxAA);

    char seguir = 's';


     while (seguir == 's')
    {
        leer (&dada);

        printf ("Desea ingresar mas numeros? s/n \n");
        fflush (stdin);
        scanf ("%c", &seguir);
    }

    printf("Que numero desea buscar?\n");
    leer(&aux);

    while(!pilavacia(&aux)){

        if((tope(&dada))==(tope(&aux))){

            apilar(&aux1,desapilar(&aux));
            mostrar (&aux1);
            printf ("Su numero se encuentra en la pila \n");
        }
        else if((tope(&dada))!=(tope(&aux))){

            apilar(&auxAA, desapilar (&dada));
        }

        if ((!pilavacia (&aux)) && (pilavacia (&dada)))
        {
            apilar (&auxAA, desapilar (&aux));
            printf ("Su numero no se encuentra en la pila \n");
        }

        }


    return 0;
}
