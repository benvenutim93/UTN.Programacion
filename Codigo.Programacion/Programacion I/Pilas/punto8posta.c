#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

//Eliminar un elemento de una pila

int main()
{
    Pila primera;
    Pila descarte;
    Pila aux;
    Pila auxAA;

    inicpila (&primera);
    inicpila (&descarte);
    inicpila (&aux);
    inicpila (&auxAA);

    char seguir = 's';


     while (seguir == 's')
    {
        leer (&primera);

        printf ("Desea ingresar mas numeros? s/n \n");
        fflush (stdin);
        scanf ("%c", &seguir);
    }

    printf("Que numero desea eliminar?\n");
    leer(&aux);

     while(!pilavacia(&aux))
        {

        if((tope(&primera))==(tope(&aux))){

            apilar(&descarte,desapilar(&primera));
            apilar (&descarte, desapilar (&aux));
            printf ("Su numero ha sido eliminado de la pila \n");
            mostrar (&primera);

        }
        else if((tope(&primera))!=(tope(&aux))){

            apilar(&auxAA, desapilar (&primera));
        }

        if ((!pilavacia (&aux)) && (pilavacia (&primera)))
        {
            apilar (&auxAA, desapilar (&aux));
            printf ("Su numero no se encuentra en la pila \n");
        }

        }
        while (!pilavacia (&auxAA))
        {
            apilar (&primera, desapilar (&auxAA));
        }
        mostrar (&primera);

    return 0;
}
