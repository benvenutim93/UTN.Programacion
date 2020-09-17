#include <stdio.h>
#include <stdlib.h>

int cargar(int[]);
void insertar (int[],int,int);
void mostrar(int[],int);
void insertarDesordenado(int[],int);
int posMenor(int[],int);
void seleccion(int [], int, int);

int main()
{
    int numero=0;
    int vector [100];
    int validos=0;
    int dato=0;
    int posicion =0;
//    int nuevosValidos =0;

    printf ("Que ejercicio desea realizar? \n");
    scanf ("%d", &numero);

    switch(numero)
    {
    case 1:

        validos = cargar(vector);

        printf("Que numero desea ingresar al vector?");
        scanf("%d", &dato);

        insertar(vector,validos, dato);
        mostrar(vector,validos+1);
        break;
    case 2:
        validos = cargar(vector);

        mostrar(vector,validos);
        insertarDesordenado(vector,validos);
        mostrar(vector,validos);
        break;
    case 3:
        validos = cargar(vector);
        mostrar(vector,validos);
        seleccion(vector, posicion, validos);
        mostrar(vector,validos);
    }

return 0;
}

int cargar(int vector[])
{
    char seguir='s';
    int i =0;
    while(seguir=='s')
    {
        printf ("Que numero desea cargar? \n");
        scanf ("%i", &vector [i]);
        i++;

        printf ("Desea cargar otro numero? s/n \n");
        fflush (stdin);
        scanf ("%c", &seguir);
    }
    return i;
}
void mostrar (int vector[], int validos)
{
    int i=0;
    printf ("El contenido de su arreglo es: \n");

    while (i<validos)
    {
        printf ("-%d-", vector [i]);
        i++;
    }
}
void insertar(int vector[], int validos, int dato)
{
    int cont=validos;
    //int aux =0;
    while(cont>=0 && vector[cont] > dato )
    {
        vector[cont+1] = vector[cont];
        cont--;
    }
    vector [cont+1] = dato;
}
void insertarDesordenado(int vector[],int validos)
{
    int i=0;

    while(i < validos-1)
    {
        insertar (vector, i, vector[i+1]);
        i++;
    }
}
int posMenor(int vector[],int validos)
{
   int menor = vector [validos-1];
   int posicionMenor = validos-1;
   int i=0;

   while (i<validos)
   {
       if(menor > vector[i])
       {
           menor = vector[i];
           posicionMenor = i;
       }
       i++;
   }
   return posicionMenor;
}

void seleccion (int vector[], int posicion, int validos)
{
    int aux=0, i=0;

    while (i<validos)
    {
    posicion = posMenor (vector, validos);

    aux = vector [posicion];
    vector[posicion] = vector [i];
    vector [i] = aux;
    i++;
    }
}
