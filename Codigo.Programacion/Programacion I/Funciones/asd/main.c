#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <math.h>

/*Hacer una función que reciba una pila con números de un solo dígito
 (es responsabilidad dequien usa el programa) y que transforme esos dígitos en un número decimal.*/

void cargarPila(Pila*);
void cambio(Pila*, Pila*);
void mismoOrden (Pila*, Pila*, Pila*);
int numMenor(Pila* );
void ordenar (Pila*, int);
void insertar(Pila*,Pila*);
void ordenarPila(Pila* , Pila*);
int sum (Pila);
float funcionMayor(Pila);
int sumaProm(Pila);
int contProm(Pila);
float promProm(int, int);
int numDecimal (Pila);


int main()
{
    Pila a;

    //Pila ordenada;
   // inicpila (&numero);
    inicpila (&a);
    //inicpila(&b);
    //inicpila (&c);
    //inicpila (&ordenada);

    //int menor = 0;

    //int suma=0;
   // float promedio;



   // printf("Ingrese un numero para ingresar a la pila\n");
  //  leer (&numero);
    //cambio(&a,&b);
    //mismoOrden (&a, &b, &c);

    //while(!pilavacia(&a))
    //{
    //menor = numMenor(&a);
//     ordenar (&ordenada, menor);

    //}
    //mostrar (&ordenada);


 //   while (!pilavacia (&a))
  //  {

   //     insertar(&a, &numero);
    //    ordenarPila(&a,&ordenada);

   // }

   // mostrar(&ordenada);


    //printf ("El numero menor de la pila A es %d", menor);
    //mostrar (&a);
    //mostrar (&b);
    //mostrar (&c);

   // suma = sum(a);

   // printf("La suma de sus deseados numeros es %d",suma);

 //  promedio = funcionMayor(a);

  // printf ("El promedio de la pila es %.2f", promedio);

   int pilaDecimal = 0;

    cargarPila (&a);
    mostrar(&a);

  pilaDecimal = numDecimal(a);

  printf ("El numero que forma su pila es %i", pilaDecimal);
    return 0;
}

void cargarPila(Pila* dada)
{

    char seguir='s';

    while(seguir=='s')
    {

        leer(dada);
        printf("Desea ingresar un nuevo numero? s/n");
        fflush(stdin);
        scanf("%c", &seguir);
    }

}
void cambio(Pila* dada, Pila * dada1)
{


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

    while(!pilavacia(&descarte))
    {
        apilar(a,desapilar(&descarte));
    }
    return numero;
}
void ordenar (Pila* ordenada, int numero)
{
    apilar (ordenada, numero);
}
void insertar(Pila* ordenada, Pila* numero )
{

    Pila aux;
    inicpila(&aux);

    while(!pilavacia (numero))
    {
        if((tope(ordenada))< (tope (numero)))
        {
            apilar(ordenada,desapilar (numero));
        }
        else
        {
            apilar(&aux,desapilar(ordenada));
        }
    }
    while(!pilavacia(&aux))
    {
        apilar(ordenada,desapilar(&aux));

    }

}

void ordenarPila(Pila* desordenada,Pila* ordenada)
{
    Pila auxAA;
    inicpila(&auxAA);


    apilar(ordenada,desapilar(desordenada));


    while(!pilavacia(desordenada))
    {
        if((tope(desordenada))<(tope(ordenada)))
        {
            apilar(&auxAA,desapilar(ordenada));
            apilar(ordenada,desapilar(desordenada));

        }
        else if ((tope(desordenada))>(tope(ordenada)))
        {
            apilar(ordenada,desapilar(&auxAA));
        }
        else
        {
            apilar (ordenada, desapilar (desordenada));
        }


        }
    while (!pilavacia (&auxAA))
    {
        apilar (ordenada, desapilar (&auxAA));
    }
    }

int sum(Pila dada)
{
    return (desapilar(&dada)+desapilar(&dada));
}

int sumaProm(Pila dada)
{
    int suma=0;
    while(!pilavacia(&dada))
    {
        suma+=desapilar(&dada);
    }
    return suma;
}

int contProm(Pila dada)
{
    int cont=0;
    Pila descarte;
    inicpila(&descarte);

        while(!pilavacia(&dada))
    {
        apilar(&descarte,desapilar(&dada));
        cont++;
    }
    return cont;
}

float promProm(int suma, int contador )
{
    float prom = 0;

    prom = (float)suma/(float)contador;
    return prom;
}

float funcionMayor(Pila a)
{
    float promedioProm=0;
    int sumaPromedio =0, contador =0;
    sumaPromedio = sumaProm(a);
    contador = contProm(a);
    promedioProm = promProm( sumaPromedio,  contador);

    return promedioProm;
}

int numDecimal(Pila dada)
{
    int cont=0;
    int suma=0;

   while (!pilavacia (&dada))
   {
       suma += desapilar (&dada) * pow(10,cont);
       cont++;
   }

   return suma;
}

