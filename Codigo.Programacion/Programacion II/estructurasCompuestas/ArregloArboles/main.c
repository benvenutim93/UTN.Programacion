#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodoArbol
{
    char alumno [20];
    int nota;
    struct nodoArbol * izq;
    struct nodoArbol * der;
} nodoArbol;

typedef struct
{
    char materia [20];
    nodoArbol * arbol;
} celda;

nodoArbol * inicArbol();
nodoArbol * crearArbol(char[],int);
int agregarMateria (celda [], int );
void ingresarNotas (celda [], int );
nodoArbol * agregarArbol (nodoArbol *, nodoArbol * );
void mostrarArreglo (celda[], int);
void mostrarArbol (nodoArbol *);


int main()
{
    celda materias [20];
    int validos =0;

    validos = agregarMateria(materias,20);
    ingresarNotas(materias,validos);
    mostrarArreglo(materias,validos);

    return 0;
}

nodoArbol * inicArbol()
{
    return NULL;
}

nodoArbol * crearArbol (char nombre[], int nota)
{
    nodoArbol * aux = (nodoArbol*) malloc (sizeof (nodoArbol));
    strcpy(aux->alumno,nombre);
    aux->nota=nota;
    aux->der=NULL;
    aux->izq=NULL;
    return aux;
}

int agregarMateria (celda materias[], int dimension)
{
    char asignatura [20], seguir = 's';
    int validos=0;
    while (seguir == 's' && validos<dimension)
    {
        printf ("Que materia desea agregar? \n");
        fflush(stdin);
        gets (asignatura);
        strcpy(materias[validos].materia,asignatura);
        materias[validos].arbol=inicArbol();
        validos++;

        printf ("Desea ingresar otra materia? \n");
        fflush(stdin);
        scanf("%c", &seguir);
    }

    return validos;
}

void ingresarNotas (celda materias[], int validos)
{
    int i=0, nota=0;
    char asignatura[20], nombre[20], seguir = 's';
    nodoArbol * aux;
    printf ("De que materia desea ingresar notas? \n");
    fflush(stdin);
    gets(asignatura);

    while (strcmpi(materias[i].materia, asignatura)!=0)
    {
        i++;
    }
    while (seguir == 's')
    {
        printf ("Ingrese el nombre del alumno \n");
        fflush(stdin);
        gets(nombre);
        printf ("Ingrese la nota del alumno \n");
        scanf ("%d", &nota);
        aux=crearArbol(nombre,nota);
        materias[i].arbol=agregarArbol(materias[i].arbol,aux);
        printf ("Desea cargar otra nota de alumno? \n");
        fflush(stdin);
        scanf("%c", &seguir);
    }

}

nodoArbol * agregarArbol (nodoArbol * lito, nodoArbol * nn)
{
    if (lito == NULL)
        lito=nn;
    else
    {
        if (nn->nota<lito->nota)
            lito->izq=agregarArbol(lito->izq,nn);
        else
            lito->der=agregarArbol(lito->der,nn);
    }
    return lito;

}

void mostrarArreglo (celda materias[], int validos)
{
    int i=0;
    while (i<validos)
    {
        printf ("MATERIA: ");
        puts (materias[i].materia);
        mostrarArbol(materias[i].arbol);
        i++;
    }

}
void mostrarArbol (nodoArbol * lito)
{
    if (lito!=NULL)
    {
        printf ("ALUMNO:");
        puts (lito->alumno);
        printf ("NOTA: %d \n", lito->nota);
        mostrarArbol(lito->izq);
        mostrarArbol(lito->der);
    }
}
