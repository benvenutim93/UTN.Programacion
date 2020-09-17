#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodoArbol
{
    char alumno [20];
    int nota;
    struct nodoArbol * izq;
    struct nodoArbol * der;
}nodoArbol;
typedef struct
{
    char materia[20];
    nodoArbol * arbol;
}celda;
nodoArbol * inicArbol ();
nodoArbol * crearNodoArbol (char [], int );
nodoArbol * agregar (nodoArbol * , nodoArbol * );
int ingresarNotas(celda [],int );
int altaMaterias(celda [],char [],char [], int , int );
int buscarPorMateria(celda [],char [], int );
int agregarMateria (celda [],char [],int );
void mostrarArreglo (celda [], int );
void mostrarArbol (nodoArbol * );

int main()
{
    celda materias [20];
    int validos=0;
    validos = ingresarNotas(materias,20);
    mostrarArreglo(materias,validos);
    return 0;
}
nodoArbol * inicArbol ()
{
    return NULL;
}
nodoArbol * crearNodoArbol (char nombre[], int nota)
{
    nodoArbol * aux = (nodoArbol*)malloc(sizeof(nodoArbol));
    aux->nota=nota;
    strcpy(aux->alumno,nombre);
    aux->izq=NULL;
    aux->der=NULL;
    return aux;
}
nodoArbol * agregar (nodoArbol * lito, nodoArbol * nn)
{
    if (lito !=NULL)
    {
        if (nn->nota<lito->nota)
            lito->izq=agregar(lito->izq,nn);
        else
            lito->der=agregar(lito->der,nn);
    }
    return lito;
}
int ingresarNotas(celda materias[],int dimension)
{
    char asignatura[20], nombre[20],seguir='s';
    int validos=0, nota=0;
    while (seguir == 's' && validos < dimension)
    {
        printf ("Ingrese una materia \n");
        fflush(stdin);
        gets(asignatura);
        printf ("Ingrese nombre del alumno \n");
        fflush(stdin);
        gets(nombre);
        printf ("Ingrese la nota del alumno %s\n",nombre);
        scanf("%d", &nota);

        validos=altaMaterias(materias,asignatura,nombre,nota,validos);
        printf ("Desea continuar cargando datos? \n");
        fflush(stdin);
        scanf("%c", &seguir);
    }
    return validos;
}

int altaMaterias(celda materias[],char asignatura[],char nombre[], int nota, int validos)
{
    nodoArbol * aux = crearNodoArbol(nombre,nota);
    int pos=buscarPorMateria(materias,asignatura,validos);
    if (pos==-1)
    {
        validos=agregarMateria(materias,asignatura,validos);
        pos=validos-1;
    }
    materias[pos].arbol=agregar(materias[pos].arbol,aux);
    return validos;
}
int buscarPorMateria(celda materias[],char asignatura[], int validos)
{
    int i=0, pos=-1;
    while (i<validos && pos==-1)
    {
        if(strcmpi(materias[i].materia,asignatura)==0)
            pos=i;
        i++;
    }
    return pos;
}

int agregarMateria (celda materias[],char asignatura[],int validos)
{
    strcpy(materias[validos].materia,asignatura);
    materias[validos].arbol=inicArbol();
    validos++;
    return validos;
}

void mostrarArreglo (celda materias[], int validos)
{
    int i=0;
    while (i<validos)
    {
        printf ("MATERIA: \n");
        puts (materias[i].materia);
        mostrarArbol(materias[i].arbol);
        i++;
    }
}
void mostrarArbol (nodoArbol * lito)
{
    if (lito !=NULL)
    {
        printf ("ALUMNO: ");
        puts (lito->alumno);
        printf ("\nNOTA: %d",lito->nota);
        mostrarArbol(lito->izq);
        mostrarArbol(lito->der);
    }
}
