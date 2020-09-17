#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

//Verificar si una pila DADA es capicúa.

int main()
{

    Pila dada;
    Pila aux;
    Pila auxAA;

    inicpila(&dada);
    inicpila(&aux);
    inicpila(&auxAA);

    int cont=0;

    char seguir ='s';

     while (seguir == 's')
    {
        leer (&dada);

        printf ("Desea ingresar mas numeros? s/n \n");
        fflush (stdin);
        scanf ("%c", &seguir);
        cont++;
    }

    while(cont>=0)
    {

        if(cont%2 == 0)
        {
            cont = cont/2;
            while(cont!=0){

            apilar(&aux, desapilar(&dada));
            cont--;
            }

        }
        else if (cont%2 != 0){

            cont--;
            cont=cont/2;
             while(cont!=0){

            apilar(&aux, desapilar(&dada));
            cont--;
            }
            apilar(&auxAA,desapilar(&dada));

        }

    }

    while((!pilavacia(&dada))&&(!pilavacia(&aux))){

        if((tope(&dada))==(tope(&aux))){

            apilar(&auxAA,desapilar(&aux));
            apilar(&auxAA, desapilar(&dada));
        }
        else{

            printf("Su pila no es capicua");
        }
    }
    if((pilavacia(&dada))&&(pilavacia(&aux)))
    {
        printf("su pila es capicua");
    }



    return 0;

}
