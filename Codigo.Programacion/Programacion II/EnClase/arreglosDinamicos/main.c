#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nombre[30];
    char genero;
    int edad;
} persona;

typedef struct
{
    int valores[100];
    int posTope; //posición de nuevo tope, lugar en donde se almacenará el nuevo valor
} Pila;


int cargarPersonas (persona[], int);
int contarVarones (persona[],int);
persona * pasarVarones(persona[], int, int);
void mostrarArreglo(persona[],int);
int posMenor(persona*,int,int);
void ordenarSeleccion(persona*, int);
void apilar(Pila *, int);
void inicPila(Pila *);
void mostrar(Pila * p);
void cargarPila(Pila *);
int desapilar(Pila*);
int tope(Pila*);
int pilavacia(Pila*);


int main()
{
    int ejercicio =0;
    int dim =5, validos=0, varones=0,num=0,dato=0;
    persona a[dim];
    persona * p;
    Pila  dada;

    printf ("Que ejercicio desea realizar? \n");
    scanf ("%d", &ejercicio);
    switch (ejercicio)
    {
    case 1: /*a. Crear un arreglo de 30 elementos de esta estructura y cargarlo mediante una función.
            b. Hacer una función que cuente la cantidad de varones o mujeres que hay.
c. Hacer una función que copie los datos de todos los varones del arreglo anterior en otro arreglo del tamaño justo.
 Usar malloc dentro de la función y retornarlo o usar dos parámetros de tipo arreglo y crear el arreglo dinámico antes
  de la invocación.
*/
        validos = cargarPersonas(a,dim);
        mostrarArreglo(a,validos);
        varones = contarVarones(a,validos);
        printf ("En el arreglo hay %d varones\n", varones);
        p = pasarVarones(a,validos,varones);
        mostrarArreglo(p,varones);
        break;
    case 2:
        ///codificar el algoritmo de ordenamiento por selección, sobre la estructura anterior teniendo en cuenta la edad
        validos = cargarPersonas(a,dim);
        mostrarArreglo(a,validos);
        varones = contarVarones(a,validos);
        p = pasarVarones(a,validos,varones);
        ordenarSeleccion(p,varones);
        printf ("\n Su arreglo ordenado:\n\n");
        mostrarArreglo(p,varones);
        break;
    case 3:
        inicPila(&dada);
        cargarPila(&dada);
        mostrar(&dada);
        num = tope(&dada);
        printf("%d",num);
        dato = desapilar(&dada);
        printf("%d\n",dato);
        mostrar(&dada);



    }
    return 0;
}

int cargarPersonas(persona a[], int dim)
{
    int i=0;
    char seguir ='s';
    while (seguir == 's' && i<dim)
    {
        printf("Ingrese nombre de la persona \n");
        fflush (stdin);
        gets (a[i].nombre);
        printf ("Ingrese edad de la persona \n");
        scanf("%d", &a[i].edad);
        printf ("Ingrese genero de la persona f/m \n");
        fflush(stdin);
        scanf("%c", &a[i].genero);
        i++;

        printf ("Desea cargar otra persona? \n");
        fflush (stdin);
        scanf("%c", &seguir);
    }

    return i;
}

int contarVarones(persona a[], int validos)
{
    int i=0, j=0;
    for (i=0; i<validos; i++)
    {
        if(a[i].genero == 'm')
            j++;
    }
    return j;
}
persona * pasarVarones (persona a[], int validos, int varones)
{

    persona * p = (persona *)malloc (varones*sizeof(persona));
    int i=0, j=0;

    while (i<validos)
    {
        if(a[i].genero == 'm')
        {
            p[j]=a[i];
            j++;
        }
        i++;
    }
    return p;
}

void mostrarArreglo (persona a[], int validos)
{
    for (int i=0; i<validos; i++)
    {
        printf("\nNombre persona: %s \n", a[i].nombre);
        printf ("Edad persona: %d\n", a[i].edad);
        printf ("Genero persona: %c\n\n", a[i].genero);
    }
}
int posMenor(persona * p,int validos,int pos)
{
    int i=pos,menor= p[pos].edad,menorPos=i;

    while(i<validos)
    {
        if(menor> p[i].edad)
        {
            menor = p[i].edad;
            menorPos = i;
        }
        i++;
    }
    return menorPos;
}
void ordenarSeleccion(persona * p, int validos)
{
    int i=0,pos=0;
    persona aux;

    while(i<validos)
    {
        pos = posMenor(p,validos,i);
        aux=p[i];
        p[i]=p[pos];
        p[pos]=aux;
        i++;
    }
}

void inicPila(Pila * p)
{
    (*p).posTope=0;
}

void apilar(Pila * p, int dato)
{
    (*p).valores[(*p).posTope]=dato;
    (*p).posTope=(*p).posTope+1;
}

void mostrar(Pila * p)
{
    int i=0;
    while (i<(*p).posTope)
    {
        printf ("%d -", (*p).valores[i]);
        i++;
    }
}
void cargarPila(Pila * dada)
{
    char seguir='s';
    int num=0;

    while (seguir=='s')
    {
        printf ("Que valor desea agregar a la pila? \n");
        scanf("%d",&num);
        apilar(dada,num);

        printf("Desea ingresar otro numero? s/n\n");
        fflush(stdin);
        scanf("%c",&seguir);
    }
}
int tope(Pila * p)
{
    int i=(*p).valores[(*p).posTope-1];
    return i;
}
int desapilar(Pila * p)
{
    int i=tope(p);
    (*p).posTope = (*p).posTope-1;
    return i;
}
int pilavacia(Pila * p)
{
    if((*p).valores[0]=)
}
