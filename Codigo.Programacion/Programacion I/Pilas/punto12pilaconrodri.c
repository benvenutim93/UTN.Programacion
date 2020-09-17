#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*Suponiendo  la  existencia  de  una  pila  MODELO  (vacía  o  no),
 eliminar  de  la  pila  DADA todos los elementos que existan en MODELO.*/
int main()
{
    Pila modelo;
    Pila dada;
    Pila dadaDistinto;
    Pila dadaIgual;
    Pila modeloFinal;

    char seguir = 's';

    inicpila (&modelo);
    inicpila (&dada);
    inicpila (&dadaDistinto);
    inicpila (&dadaIgual);
    inicpila (&modeloFinal);


    apilar (&modelo, 10);
    apilar (&modelo, 33);
    apilar (&modelo, 40);

    while(seguir == 's'){

        leer(&dada);

        printf("Desea ingresar otro numero? s/n \n");
        fflush(stdin);
        scanf("%c", &seguir);
    }

    mostrar (&dada);
    while ((!pilavacia(&modelo))){
    while ((!pilavacia(&dada)))
    {
        if ((tope (&dada)) == (tope (&modelo)))
        {
            apilar (&dadaIgual, desapilar (&dada));
        }
        else if ((tope (&dada)) != (tope (&modelo)))
        {
            apilar (&dadaDistinto, desapilar (&dada));
        }

    }
    while(!pilavacia(&dadaDistinto)){

            apilar(&dada, desapilar (&dadaDistinto));
    }

    apilar(&modeloFinal,desapilar (&modelo));
    }

    mostrar (&dada);
    mostrar (&modeloFinal);

    return 0;
}
