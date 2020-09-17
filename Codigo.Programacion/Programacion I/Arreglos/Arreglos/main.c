#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int numEnteros (int[], int);
void numValidos (int[],int);
int sumaValidos (int [], int);
void pasaje(int[],int,Pila*);
float sumaReales (int[], int);
int cargarCarac(char[],int);
char buscCarac(char[],int);
int alfabeto(char[],int);
void caracValidos(char[],int);
char maxCarac (char [], int);
void capicua(int[],int);
void invertir(int[],int);
void insertar (int[], int, int);
void ordenarInsertar(int[],int);
void seleccion(int[], int);
int ordenAlfabeto (char [], int, char[],int, char[],int);


int main()
{


    int cantNumeros =0;
    int numero=0;
    int suma =0;
    int dimension =0;
    int enteros [50];
    char caracter[50];
    float sumaReal =0;
    int validosCarac=0;
    char esta, letraMayor;
    int dimen=0;
    char vector[50];
    char vector2[50];
    int caracterValidos1=0;
    int caracterValidos2=0;
    int validosNuevos = 0;


    Pila dada;
    inicpila(&dada);

    printf("Ingrese numero de ejercicio\n");
    scanf("%d",&numero);

    switch(numero)
    {
    case 1:

        cantNumeros = numEnteros(enteros, dimension);
        printf ("Ud ingreso %i numeros al arreglo \n", cantNumeros);
        break;

    case 2:
        cantNumeros = numEnteros(enteros, dimension);
        numValidos (enteros, cantNumeros);
        break;
    case 3:
        /*Hacer  una  función  que  reciba  como  parámetro  un  arreglo  y  la  cantidad
        de  elementos (válidos) cargados en él y calcule la suma de sus elementos.*/
        cantNumeros = numEnteros(enteros, dimension);
        suma = sumaValidos(enteros, cantNumeros);
        printf ("La suma de los numeros de su arreglo es %i", suma);
        break;
    case 4:
        /*Hacer  una  función  que  reciba  como  parámetro  un  arreglo,
         la  cantidad  de  elementos (válidos) cargados en él y una Pila.
          La función debe copiar los elementos del arreglo en la pila*/
        cantNumeros = numEnteros(enteros,dimension);
        pasaje(enteros, cantNumeros,&dada);
        mostrar(&dada);
        break;
    case 5:
        /*Realizar una función que sume los elementos reales de un arreglo de dimensión 100*/
        cantNumeros = numEnteros(enteros, dimension);
        sumaReal = sumaReales(enteros, cantNumeros);
        printf ("La suma de los numeros reales que usted ha insertado en el arreglo es de %.2f \n", sumaReal);
        break;

    case 6:
        /*Realizar  una  función  que  indique  si  un  elemento  dado  se  encuentra  en  un  arreglo  de caracteres. */
        validosCarac = cargarCarac( caracter,dimension);
        esta = buscCarac(caracter,validosCarac);
        printf("su letra esta? s/n --> %c",esta);
        break;

    case 7:
        /*Realizar  una  función  que  inserte  un  carácter  en  un  arreglo  ordenado  alfabéticamente, conservando el orden.*/
        validosCarac = cargarCarac( caracter,dimension);
        validosCarac=alfabeto(caracter,validosCarac);
        caracValidos(caracter,validosCarac);
        break;

    case 8:
        /*Realizar una función que obtenga el máximo carácter de un arreglo dado*/

        validosCarac = cargarCarac( caracter,dimension);
        letraMayor = maxCarac(caracter,validosCarac);
        printf ("La mayor letra de su arreglo es %c\n", letraMayor);
        break;
    case 9:

        /* Realizar una función que determine si un arreglo es capicúa*/
        cantNumeros = numEnteros(enteros, dimension);
        capicua(enteros,cantNumeros);

        break;
    case 10:
        /*Realizar una función que invierta los elementos de un arreglo.*/
        cantNumeros = numEnteros(enteros, dimension);
        invertir(enteros,cantNumeros);
        numValidos(enteros,cantNumeros);
        break;
    case 11:
        /*Ordenar un arreglo según los siguientes métodos: 1. Selección. 2. Inserción.*/
        cantNumeros = numEnteros(enteros, dimension);
        ordenarInsertar(enteros, cantNumeros);
        numValidos(enteros, cantNumeros);
        break;
    case 12:
        cantNumeros = numEnteros(enteros, dimension);
        seleccion(enteros,cantNumeros);
        numValidos(enteros, cantNumeros);
        break;

    case 13:
        printf("Que dimension tiene su nuevo arreglo?");
        scanf("%d",&dimen);

        caracterValidos1 = cargarCarac(vector, dimension);
        caracterValidos2 = cargarCarac(vector2, dimension);

        validosNuevos = ordenAlfabeto(caracter,dimen,vector, caracterValidos1,vector2,caracterValidos2);
        caracValidos(caracter,validosNuevos);


    }
    return 0;
}

int numEnteros (int arreglo[], int dimension)
{
    char seguir = 's';
    int i=0;
    printf ("Cual es la dimension del arreglo? \n");
    scanf ("%i", &dimension);

    while ((seguir == 's') && i<dimension)
    {
        printf ("Ingrese el numero \n");
        scanf ("%i", &arreglo [i]);
        i++;

        printf ("Desea ingresar un numero? s/n \n");
        fflush (stdin);
        scanf ("%c", &seguir);
    }
    return i;
}
void numValidos(int arreglo[],int numeros)
{
    int i=0;
    printf("\n Contenido de su arreglo \n");
    while(i<numeros)
    {
        printf("%d", arreglo[i]);
        i++;
    }
}
void caracValidos(char arreglo[],int numeros )
{
    int i=0;
    printf("\n Contenido de su arreglo \n");
    while(i<numeros)
    {
        printf("%c", arreglo[i]);
        i++;
    }
}
int sumaValidos(int arreglo [], int cantidad)
{
    int i=0, suma =0;

    for (i=0; i<cantidad; i++)
    {
        suma= suma + arreglo[i];
    }
    return suma;
}
void pasaje (int arreglo[], int numeros, Pila* dada)
{
    int cont=0;

    for(cont=0; cont<numeros; cont++)
    {
        apilar(dada, arreglo[cont]);
    }
}
float sumaReales(int arreglo [], int validos)
{
    int i=0;
    float suma=0;
    while (i<validos)
    {
        suma = suma + (float) arreglo[i];
        i++;
    }
    return suma;
}
int cargarCarac(char caracter[],int dimension)
{
    char seguir='s';
    int  i=0;


    printf("Que dimension tiene su arreglo?\n");
    scanf("%d",&dimension);


    while(i<dimension && seguir=='s')
    {
        printf("Ingrese un caracter\n");
        fflush(stdin);
        scanf("%c",&caracter[i]);

        printf("Desea ingresar otro caracter? s/n \n");
        fflush(stdin);
        scanf("%c",&seguir);
        i++;

    }
    return i;
}
char buscCarac(char caracter[], int dimension)
{
    char otrachar;
    char esta;
    int i=0;

    printf("Que caracter desea buscar?\n");
    fflush(stdin);
    scanf("%c", &otrachar);

    while(esta!='s' && i<dimension)
    {

        if(otrachar==caracter[i])
        {
            esta = 's';

        }
        else
        {
            esta = 'n';
        }
        i++;
    }
    return esta;
}
int alfabeto(char caracter[],int dimension)
{
    char letra;
    int i=dimension-1;

    printf("Que caracter desea ingresar? \n");
    fflush(stdin);
    scanf("%c",&letra);

    while(i>=0&&letra<caracter[i])
    {
        caracter [i+1]=caracter [i];
        i--;vector[cont+1] = vector[cont] ;
    }
    caracter[i+1]=letra;
    return dimension+1;

}

char maxCarac(char caracter[], int dimension)
{
    int i=dimension-1;
    char letra;
    letra = caracter [dimension-1];

    while (i>=0)
    {
        if (letra < caracter[i])
        {
            letra = caracter [i];
        }
        i--;
    }
    return letra;
}
void capicua(int vector[],int dimension)
{
    int i=dimension-1;
    int j=0;

    if(dimension%2 == 0)
    {
        while(vector[j]==vector[i])
        {
            j = j+1;
            i = i-1;
        }
    }
    else if(dimension%2 != 0)
    {
        while(vector[j]==vector[i])
        {
            j = j+1;
            i = i-1;
        }
    }
    if(j>i)
    {
        printf("su numero es capicua");
    }
    else
    {
        printf("su numero no es capicua");
    }



}
void invertir(int vector[],int validos)
{
    int aux=0,i=0,j=validos-1;

    for(i=0; i<j; i++)
    {
        aux=vector[j];
        vector[j]=vector[i];
        vector[i]=aux;
        j--;
    }
}

void insertar (int vector [], int validos, int nuevo)
{
    int i=validos;
    while (i>=0 && nuevo<vector[i])
    {
        vector [i+1] = vector [i];
        i--;
    }
    vector [i+1] = nuevo;

}
void ordenarInsertar(int vector[],  int validos)
{
    int i = 0;
    while (i < validos-1)
    {
        insertar (vector, i, vector [i + 1]);
        i++;

    }
}
int menor(int vector[], int validos, int pos)
{
    int posmenor= pos;
    int menor = vector [pos];
    int i = pos + 1;


    while(i<validos)
    {
        if(menor>vector[i])
        {
            menor=vector[i];
            posmenor=i;
        }
        i++;
    }
    return posmenor;
}
void seleccion(int vector[], int validos)
{
    int aux=0;
    int i=0;
    int posmenor=0;

    while(i < validos)
    {
        posmenor = menor(vector,validos,i);

        aux = vector[posmenor];
        vector[posmenor]=vector[i];
        vector[i]=aux;

        i++;
    }
}
int ordenAlfabeto(char arreglo [],int dimension, char vector[],int validos1, char vector2[],int validos2)
{
    int cont1 =0;
    int cont2=0;
    int m=0;


    while ((cont1 < validos1) && (cont2 < validos2)&& (m<dimension))
    {
        if (vector [cont1] < vector2 [cont2])
        {
            arreglo [m] = vector [cont1];
            cont1++;
        }
        else
        {
            arreglo[m] = vector2[cont2];
            cont2 ++;
        }
        m++;

    }
    return m;
}
