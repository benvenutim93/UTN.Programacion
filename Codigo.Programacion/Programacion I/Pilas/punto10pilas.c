#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

//10. Comparar las pilas A y B. Mostrar por pantalla el resultado

int main()
{
    Pila a,b, aux1, aux2;
    char seguir ='s';


    inicpila(&a);
    inicpila (&b);
    inicpila (&aux1);
    inicpila (&aux2);


    while (seguir == 's')
    {
        printf ("En que pila desea agregar un numero? a/b \n");
        fflush (stdin);
        scanf ("%c", &seguir);

        if (seguir == 'a')
        {
            leer (&a);
        }
        else if (seguir =='b')
        {
            leer (&b);
        }
        printf ("Desea ingresar un numero? s/n \n");
        fflush (stdin);
        scanf ("%c", &seguir);
    }


    mostrar (&a);
    mostrar (&b);

    while ((tope (&a)) == (tope (&b)) && (!pilavacia(&a) && (!pilavacia (&b))))
    {
        apilar (&aux1, desapilar (&a));
        apilar (&aux2, desapilar (&b));
    }

    if ((pilavacia (&a)) && (pilavacia (&b)))
    {
        printf ("Sus pilas tienen los mismos elementos \n");
    }
    else
    {
        printf ("Sus pilas tienen distintos elementos \n");
    }

    return 0;
}
