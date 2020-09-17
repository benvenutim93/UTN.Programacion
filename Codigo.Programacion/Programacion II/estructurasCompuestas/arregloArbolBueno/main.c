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

int agregarMateria (celda [],char [],int );
int buscarPosMateria(celda [],int , char[] );
int alta (celda [], char [],char [],int , int );
int ingresarNotas (celda  [], int );
nodoArbol * agregarArbol (nodoArbol * , nodoArbol * );
nodoArbol * crearNodo (char  [], int );
nodoArbol * inicArbol();
void mostrarArbol (nodoArbol * );
void mostrarArreglo (celda [],int );


int main()
{
    celda materias [20];
    int validos=0;

    validos= ingresarNotas(materias,20);
    mostrarArreglo(materias,validos);

    return 0;
}

nodoArbol * inicArbol()
{
    return NULL;
}

nodoArbol * crearNodo (char nombre [], int nota)
{
    nodoArbol * aux = (nodoArbol*)malloc (sizeof(nodoArbol));
    strcpy (aux->alumno, nombre);
    aux->nota=nota;
    aux->der=NULL;
    aux->izq=NULL;
    return aux;
}
nodoArbol * agregarArbol (nodoArbol * lito, nodoArbol * nn)
{
    if (lito == NULL)
        lito = nn;
    else
    {
        if (nn->nota < lito->nota)
            lito->izq = agregarArbol(lito->izq,nn);
        else
            lito->der=agregarArbol(lito->der,nn);
    }
    return lito;
}
int ingresarNotas (celda materias [], int dimension)
{
    char nombre[20], asignatura[20], seguir='s';
    int validos=0, nota=0;

    while (seguir == 's' && validos<dimension )
    {
        printf ("Que materia desea ingresar? \n");
        fflush(stdin);
        gets(asignatura);
        printf ("Ingrese el nombre del alumno \n");
        fflush(stdin);
        gets(nombre);
        printf("Ingrese la nota del alumno \n");
        scanf("%d",&nota);

        validos = alta (materias,asignatura,nombre,nota,validos);

        printf ("Desea continuar la carga? s/n \n");
        fflush(stdin);
        scanf("%c", &seguir);
    }
    return validos;
}
int alta (celda materias[], char asignatura[],char nombre[],int nota, int validos)
{
    nodoArbol * aux = crearNodo(nombre,nota);
    int pos = buscarPosMateria(materias,validos,asignatura);
    if (pos == -1)
    {
        validos=agregarMateria(materias,asignatura,validos);
        pos=validos-1;
    }
    materias[pos].arbol=agregarArbol(materias[pos].arbol,aux);
    return validos;
}

int buscarPosMateria(celda materias[],int validos, char asignatura[])
{
    int i=0, pos=-1;
    while (i<validos)
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

void mostrarArreglo (celda materias[],int validos)
{
    int i=0;
    while (i<validos)
    {
        printf ("MATERIA:");
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
