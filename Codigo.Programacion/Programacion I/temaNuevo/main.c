#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

int cargarPalabras (char[][15], int);
int inicializar(char[][15],char[]);
void mostrarArreglo(char [][15], char[]);
void copiarLetra (char [][15], char [], int);
int palabraRepetida(char[][15],char[],char,int);
int cargarPila (Pila*);

int main()
{
    int ejercicio =0;
    int filas = 100, palabrasValidas =0, longitud =0,devuelve=0, elementos =0;
    char p[filas][15];
    char m[15];
    char letra;
    Pila a;
    inicpila (&a);






    printf ("Que ejercicio desea realizar? \n");
    scanf("%d", &ejercicio);

    switch (ejercicio)
    {
    case 1:
        /*Hacer una función que permita ingresar tantas palabras como quiera el usuario o 100 palabras como máximo.*/
        palabrasValidas = cargarPalabras (p, filas);
        printf ("Usted cargo %d palabras \n", palabrasValidas);
        break;
    case 2:
        /*Hacer una función que teniendo en cuenta la longitud de un palabra, inicialice un segundo arreglo con elcarácter“-”.
        (Pista:primero hay que copiar la palabra en el segundo arreglo y luego modificarlo).*/
        palabrasValidas = cargarPalabras (p, filas);
        longitud = inicializar(p,m);
        mostrarArreglo(p,m);
        break;
    case 3:
        /*Hacer una función que teniendo la posición de la letra copie esa letra en
         otro arreglo inicializado con la función anterior en la misma posición que la palabra original.*/
         palabrasValidas = cargarPalabras (p, filas);
         longitud = inicializar(p,m);
         copiarLetra (p,m, longitud);
         mostrarArreglo(p,m);
         break;

    case 4:
        /*Hacer una función que reciba como parámetro el arreglo con la palabra,
        el arreglo inicializado en“-”y unaletra, por cada coincidencia de la letra en el arreglo
        con la palabra,llame la función anterior para actualizarla letra en el arreglo con-.
        Esta función debe retornar la cantidad devecesque se repite la letra o0en casoque la letra no esté en la palabra*/
        palabrasValidas = cargarPalabras (p, filas);
        longitud = inicializar(p,m);
        printf("Que letra desea buscar? \n");
        fflush(stdin);
        scanf("%c",& letra);
        devuelve =palabraRepetida(p,m,letra,longitud);
        printf("Su letra se repite %d\n",devuelve);
        mostrarArreglo(p,m);
        break;
    case 5:
        //Hacer una función que cuente y retorne la cantidad de elementos de una pila.
        elementos = cargarPila (&a);
        printf ("Su pila tiene %d elementos cargados \n", elementos);
        break;
    case 6:
        /*Hacer una función “juego” donde seleccione una palabra al azar (usando rand)
        y le permita al usuario poderjugar al ahorcado utilizando las funciones anteriores,
        el jugador tiene un total de 4 intentos, si no aciertatodas las letras pierde y se apila en
         una pila de partidas perdidas un 1, en caso de acertar todas las letras y adivinar la palabra,
         se apila en una pila de partidas ganadas un 1*/
        palabrasValidas = cargarPalabras (p, filas);
        longitud = inicializar(p,m);
        printf("Que letra desea buscar? \n");
        fflush(stdin);
        scanf("%c",& letra);
        devuelve =palabraRepetida(p,m,letra,longitud);






    }

    return 0;
}

int cargarPalabras(char p[][15], int filas)
{
    char seguir = 's';
    int i=0;

    while (seguir == 's' && i < filas)
    {
        printf ("Que palabra desea cargar? \n");
        fflush (stdin);
        scanf ("%s", p[i]);
        i++;

        printf ("Desea ingresar otra palabra? \n");
        fflush (stdin);
        scanf ("%c", &seguir);
    }
    return i;
}
int inicializar(char p[][15],char m[])
{
    int longitud=0,i=0;

    longitud = strlen(p[i]);

    strcpy(m,p[i]);

    while(i<longitud)
    {
        m[i] = '-';
        i++;

    }
    return longitud;
}
void mostrarArreglo(char p[][15],char m[])
{
    int i=0;
    printf("%s\n",p[i]);

    printf("%s\n",m);

}

void copiarLetra (char p[][15], char m[], int longitud)
{
    //int pos=0;
    //printf ("Ingrese un numero menor a %d \n", longitud);
    //scanf ("%d", &pos);

    m [longitud] = p [0][longitud];
}
int palabraRepetida(char p[][15],char m[],char letra,int longitud)
{
    int i=0,pos=0,k=0;

    while(i<longitud)
    {
        if(letra==p[0][i])
        {
            pos=i;
            k++;
            copiarLetra(p,m,pos);
        }
        i++;
    }
    return k;
}

int cargarPila (Pila* a)
{
    char seguir = 's';
    int i=0;

    while (seguir == 's')
    {
        leer(a);
        i++;

        printf ("Desea ingresar otro numero? s/n \n");
        fflush (stdin);
        scanf ("%c", &seguir);
    }
    return i;
}
