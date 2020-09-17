#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*Comparar la cantidad de elementos de las pilas A y B. Mostrar por pantalla el resultado*/

int main()
{
    Pila a;
    Pila b;
    Pila aux1;
    Pila aux2;

    char control;

    inicpila (&a);
    inicpila (&b);
    inicpila (&aux1);
    inicpila (&aux2);

    printf ("Desea ingresar un numero? s/n \n");
    fflush (stdin);
    scanf ("%c", &control);

    while (control == 's')
    {
        printf ("En que pila desea agregar un numero? a/b \n");
        fflush (stdin);
        scanf ("%c", &control);

        if (control == 'a')
        {
            leer (&a);
        }
        else if (control =='b')
        {
            leer (&b);
        }
        printf ("Desea ingresar un numero? s/n \n");
        fflush (stdin);
        scanf ("%c", &control);
    }

    mostrar (&a);
    mostrar (&b);

    while ((!pilavacia (&a)) && (!pilavacia (&b)))
    {
        apilar (&aux1, desapilar (&a));
        apilar (&aux2, desapilar (&b));
    }

    if ((pilavacia(&a)) && (pilavacia (&b)))
    {
        printf ("Las pilas tienen la misma cantidad de elementos \n");
    }
    else if (pilavacia (&b))
    {
        printf ("La pila A tiene mas elementos que la pila B \n");
    }
    else
    {
        printf ("La pila B tiene mas elementos que la pila A \n");
    }



    return 0;
}
