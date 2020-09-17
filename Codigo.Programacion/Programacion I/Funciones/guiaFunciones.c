#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
 /*Hacer una función que permita ingresar varios elementos a una Pila, tantos como quiera el usuario*/
 /*Hacer una función que pase todos los elementos de una pila a otra.*/
 /*Hacer  una  función  que  pase  todos  los  elementos  de  una  pila  a  otra,  pero  conservando  el orden.*/
//Hacer una función que encuentre el menor elemento de una pila y lo retorne
void cargarPila(Pila*);
void cambio(Pila*, Pila*);
void mismoOrden (Pila*, Pila*, Pila*);
int numMenor(Pila* );

int main()
{
    Pila a,b,c;
    inicpila (&a);
    inicpila(&b);
    inicpila (&c);

    int menor = 0;

    cargarPila (&a);
    //cambio(&a,&b);
    //mismoOrden (&a, &b, &c);

    menor = numMenor(&a);
    printf ("El numero menor de la pila A es %d", menor);
    //mostrar (&a);
    //mostrar (&b);
    //mostrar (&c);
    return 0;
}

void cargarPila(Pila* dada){

char seguir='s';

while(seguir=='s'){

    leer(dada);
    printf("Desea ingresar un nuevo numero? s/n");
    fflush(stdin);
    scanf("%c", &seguir);
   }

}
void cambio(Pila* dada, Pila * dada1){


    while(!pilavacia(dada))
    {
        apilar(dada1,desapilar(dada));

    }
}

void mismoOrden (Pila* a, Pila* b, Pila* c)
{
    while (!pilavacia (a))
    {
        apilar (b, desapilar (a));
    }
    while (!pilavacia (b))
    {
        apilar (c, desapilar (b));
    }
}

int numMenor (Pila* a)
{
    int numero=0;
    Pila descarte, menor;
    inicpila (&descarte);
    inicpila (&menor);

    apilar (&menor, desapilar (a));

    while(!pilavacia (a))
    {
        if ((tope (a)) < tope (&menor))
        {
            apilar (&descarte, desapilar (&menor));
            apilar (&menor, desapilar (a));
        }
        else
        {
            apilar (&descarte, desapilar (a));
        }
    }

    numero = tope (&menor);

    return numero;
}
