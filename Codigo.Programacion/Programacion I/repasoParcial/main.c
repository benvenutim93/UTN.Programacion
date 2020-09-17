#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <math.h>


void cargarPila (Pila*);
int pasarDistinto (Pila*, Pila*, int);
int cargarArreglo (int[], int);
void potencias (int [], int [], int);
void mostrarArreglo(int [], int);
void invertirArreglo(int[], int[], int);
void sumaElementos (int[], int[]);
int pasajePilas (Pila*, Pila*, int []);
void agregarBase (Pila*, int);

int main()
{
    int ejercicio =0;
    Pila a;
    Pila b;
    inicpila(&a);
    inicpila (&b);
    int numero =0, numPasados =0;
    int dimension = 20;
    int arreglo [dimension];
    int numValidos =0;
    int arregloPotencia [dimension];
    int arregloInvertido [dimension];
    int arregloSuma [5] = {1,5,6,7,8};
    int arregloSumados [5];



    printf ("Que ejercicio desea realizar? \n");
    scanf ("%d", &ejercicio);

    switch (ejercicio)
    {
    case 1:
        /*1) Hacer una función que reciba dos pilas y un número ingresado por el usuario.
        Pasar los elementos de la pila A a la B que sean distintos al número ingresado por el usuario.
        La función debe retornar cuantos elementos se pasaron. Mostrar ese número en el main.
        */
        cargarPila(&a);
        printf ("Su pila A: \n");
        mostrar (&a);
        cargarPila(&b);
        printf ("Su pila B: \n");
        mostrar (&b);

        printf ("Ingrese un numero \n");
        scanf ("%d", &numero);

        numPasados = pasarDistinto(&a, &b, numero);
        printf ("Se han pasado %d numeros de una pila a la otra \n", numPasados);

        mostrar (&a);
        break;

    case 2:
        /*2) Hacer una función que calcule el cuadrado de los elementos del arreglo Z y lo almacene en otro arreglo.*/
        numValidos = cargarArreglo(arreglo, dimension);
        mostrarArreglo(arreglo, numValidos);
        potencias(arreglo, arregloPotencia, numValidos);
        mostrarArreglo(arregloPotencia, numValidos);
        break;

    case 3:

        /*3) Escriba un programa que dado un arreglo de números enteros, genere otro en orden inverso.*/
        numValidos = cargarArreglo(arreglo, dimension);
        mostrarArreglo(arreglo, numValidos);
        invertirArreglo(arreglo, arregloInvertido, numValidos);
        mostrarArreglo(arregloInvertido, numValidos);
        break;
    case 4:
        /*4) Dado un el arreglo de enteros {1,5,6,7,8} escribir un programa que genere otro arreglo con la suma del contenido de todo los elementos anteriores al índice actual.
        El resultado final del segundo arreglo es el siguiente: {1,6,12,19,27}.*/

        sumaElementos(arregloSuma, arregloSumados);
        mostrarArreglo(arregloSumados, 5);
        break;
    case 5:
        /*5) Dadas dos pilas ordenadas y un arreglo vacío, hacer una función que pase los elementos de ambas pilas al arreglo, manteniendo el orden.*/
        printf ("Cargue dos pilas ordenadamente \n");
        cargarPila(&a);
        printf ("Su pila A: \n");
        mostrar (&a);
        cargarPila(&b);
        printf ("Su pila B: \n");
        mostrar (&b);

        numValidos = pasajePilas(&a, &b, arreglo);
        mostrarArreglo(arreglo, numValidos);
        break;
    case 6:
        /*) Hacer una función que agregue un elemento a una pila, pero debe agregarlo en la base de la misma.*/
        cargarPila(&a);
        mostrar (&a);

        printf ("Que numero desea agregar a la pila? \n");
        scanf ("%d", &numero);

        agregarBase(&a, numero);
        mostrar (&a);
        break;
    case 7:
        /*7) Hacer una función que elimine el elemento que se encuentra en la base de una pila.*/




    }

    return 0;
}



void cargarPila(Pila* a)
{
    char seguir = 's';

    while (seguir == 's')
    {
        leer(a);

        printf ("Desea cargar otro elemeto a la pila? \n");
        fflush (stdin);
        scanf (" %c", &seguir);
    }
}

int pasarDistinto(Pila* a, Pila* b, int numero)
{


    Pila aux;
    inicpila (&aux);
    int i =0;

    while (!pilavacia (a))
    {
        if (tope(a) == numero)
        {
            apilar (&aux, desapilar (a));
        }
        else
        {
            apilar (b, desapilar (a));
            i++;
        }
    }

    while (!pilavacia (&aux))
    {
        apilar (a, desapilar (&aux));
    }
    return i;
}

int cargarArreglo(int a [], int dimension)
{
    int i =0;
    char seguir = 's';

    while (seguir == 's' && i<dimension)
    {
        printf ("Ingrese un numero \n");
        scanf ("%d", &a[i]);
        i++;

        printf ("Desea cargar otro numero? s/n \n");
        fflush (stdin);
        scanf (" %c", &seguir);
    }
    return i;

}

void potencias(int z[], int a[], int validos)
{
    int i =0, aux=0;

    for (i=0; i<validos;i++)
    {
        aux = pow (z[i], 2);
        a[i] = aux;
    }
}

void mostrarArreglo (int a[], int validos)
{
    int i=0;
    printf("\n Contenido de su arreglo \n");
    while(i<validos)
    {
        printf(" %d -", a[i]);
        i++;
    }
}

void invertirArreglo (int a[], int b[], int validos)
{
    int j = validos-1;
    int i=0;

    for (i=0;i<validos;i++)
    {
        b[j] = a[i];
        j--;

    }
}
void sumaElementos(int a[5], int b[5])
{
    int i=0, suma =0;

    for (i=0; i<5;i++)
    {
        suma+= a[i];
        b[i] = suma;
    }

}

int pasajePilas(Pila* a, Pila* b, int arreglo [])
{
    int i=0;
    Pila aux;
    inicpila (&aux);

    while ((!pilavacia (a)) && (!pilavacia (b)))
    {
        if ((tope (a))> (tope (b)))
        {
            arreglo [i] = desapilar (a);
            i++;
        }
        else if ((tope (a)) < (tope (b)))
        {
            arreglo [i] = desapilar (b);
            i++;
        }
        else
        {
            arreglo [i] = desapilar (a);
            apilar (&aux, desapilar (b));
            i++;
        }

    }

    if (!pilavacia (a))
    {
        while (!pilavacia (a))
        {
             arreglo [i] = desapilar (a);
             i++;
        }

    }
    else if (!pilavacia(b))
    {
        while (!pilavacia (b))
        {
             arreglo [i] = desapilar (b);
             i++;
        }

    }

    return i;
}

void agregarBase(Pila* a, int numero)
{
    Pila aux;
    inicpila(&aux);

    while (!pilavacia (a))
    {
        apilar (&aux, desapilar (a));
    }
     apilar (a, numero);

     while (!pilavacia (&aux))
     {
         apilar (a, desapilar (&aux));
     }
}
