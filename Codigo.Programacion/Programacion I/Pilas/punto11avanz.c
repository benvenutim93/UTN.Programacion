#include <stdio.h>
#include <stdlib.h>
#include "pila.h"


int main()
{
    Pila ordenada1;
    Pila ordenada2;
    Pila mayor;
    Pila aux;
    Pila ordenadaF;

    inicpila(&ordenada1);
    inicpila(&ordenada2);
    inicpila(&mayor);
    inicpila(&aux);
    inicpila(&ordenadaF);

    char seguir='s';

    printf ("Ingrese numeros ordenados de manera creciente \n");
    while (seguir == 's')
    {
        leer (&ordenada1);
        printf ("Desea ingresar otro numero? s/n \n");
        fflush (stdin);
        scanf ("%c", &seguir);
    }

    seguir = 's';

    printf ("Ingrese numeros ordenados de manera creciente para otra pila \n");
    while (seguir == 's')
    {
        leer (&ordenada2);
        printf ("Desea ingresar otro numero? s/n \n");
        fflush (stdin);
        scanf ("%c", &seguir);
    }


    while((!pilavacia(&ordenada1))&&(!pilavacia(&ordenada2)))
    {

        if((tope(&ordenada1))>(tope(&ordenada2)))
        {
            apilar(&mayor,desapilar(&ordenada1));
        }
        else if((tope(&ordenada2))>(tope(&ordenada1)))
        {
            apilar(&mayor,desapilar(&ordenada2));
        }
        else if((tope(&ordenada2))==(tope(&ordenada1)))
        {
        apilar(&mayor,desapilar(&ordenada1));
        apilar(&aux,desapilar(&ordenada2));
        }

    }
    while(!pilavacia(&ordenada1)){

        apilar(&mayor,desapilar(&ordenada1));
    }
    while(!pilavacia(&ordenada2))
    {
        apilar(&mayor,desapilar(&ordenada2));
    }

    while(!pilavacia(&mayor))
    {
        apilar(&ordenadaF,desapilar(&mayor));
    }
    mostrar(&ordenadaF);
    return 0;
}
