#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila a;
    Pila b;
    Pila iguales;
    Pila distintos;
    Pila auxAA;
    Pila c;

    inicpila(&a);
    inicpila(&b);
    inicpila(&iguales);
    inicpila(&distintos);
    inicpila(&auxAA);
    inicpila(&c);

    char seguir='s';


     while (seguir == 's')
    {
        leer (&a);
        leer (&b);
        printf ("Desea ingresar otros numeros a las pilas? \n");
        fflush (stdin);
        scanf ("%c", &seguir);
    }
    mostrar(&a);
    mostrar(&b);

    while((!pilavacia(&a))&&(!pilavacia(&b))){
    while(!pilavacia(&a))
    {

        while(!pilavacia(&b)){
        if((tope(&a))==(tope(&b))){

            apilar(&iguales,desapilar(&b));
        }
        else
        {
            apilar(&distintos,desapilar(&b));
        }
        }
        apilar(&auxAA, desapilar(&a));

        while(!pilavacia(&distintos)){

            if((tope(&a))==(tope(&distintos))){

                apilar(&iguales,desapilar(&distintos));
            }
            else
            {
                apilar(&b,desapilar(&distintos));
            }
        }
        apilar(&auxAA,desapilar(&a));
    }
    while(!pilavacia(&auxAA))
    {
        apilar(&c,desapilar(&auxAA));
    }
    while(!pilavacia(&b))
    {
        apilar(&c,desapilar(&b));
    }
    }
mostrar(&c);
    return 0;
}
