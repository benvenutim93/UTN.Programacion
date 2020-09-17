#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct nodo
{
    char alumno [20];
    int nota;
    struct nodo * sig;
}nodo;

typedef struct
{
    char materia[20];
    nodo * lista;
}celda;

nodo * inicLista ();
nodo * agregarPpio (nodo*,nodo*);
nodo * crearNodo (char[],int);
int buscarPosMateria(celda[],char[],int);
int agregarMateria (celda [],char [],int );
int ingresarNotas(celda[],int);
int altaMaterias (celda  [], char [], char  [],int , int );
void mostrarPorMateria (celda  [],  char  [], int );
void mostrarLista(nodo *);

int main()
{
    celda materias [20];
    char nombre [20];
    int validos = ingresarNotas(materias,20);

    printf ("Que materia desea mostrar?");
    gets (nombre);

    mostrarPorMateria(materias,nombre,validos);






    return 0;
}

nodo * inicLista ()
{
    return NULL;
}
nodo * agregarPpio (nodo * lista, nodo * nn)
{
    if (lista == NULL)
        lista=nn;
    else
    {
        nn->sig = lista;
        lista=nn;
    }
    return lista;
}
nodo * crearNodo(char alumno[], int nota)
{
    nodo * aux = (nodo*) malloc (sizeof (nodo));
    aux->nota=nota;
    strcpy(aux->alumno,alumno);
    aux->sig=NULL;
    return aux;
}
int buscarPosMateria(celda materias[], char buscado[], int validos)
{
    int rta = -1, i=0;

    while (i<validos && rta == -1)
    {
        if (strcmpi(buscado, materias[i].materia)==0)
        {
            rta=i;
        }
        i++;
    }
    return rta;
}

int agregarMateria (celda materias[],char nombre[],int validos)
{
    strcpy (materias[validos].materia,nombre);
    materias[validos].lista = inicLista();
    validos++;
    return validos;
}

int altaMaterias (celda materias [], char nombre[], char alumno [],int nota, int validos)
{
    nodo * nn = crearNodo(alumno,nota);
    int pos = buscarPosMateria(materias,nombre,validos);
    if (pos == -1)
    {
        validos = agregarMateria(materias,nombre,validos);
        pos = validos-1;
    }
    materias[pos].lista=agregarPpio(materias[pos].lista,nn);
    return validos;
}

int ingresarNotas (celda materias [], int dimension)
{
    char alumno [20];
    char materia [20];
    int nota=0, validos =0;
    char seguir = 's';

    while (seguir == 's')
    {
        printf ("Ingrese el nombre del alumno \n");
        fflush(stdin);
        gets(alumno);
        printf ("Ingrese la materia \n");
        fflush(stdin);
        gets(materia);
        printf ("Ingrese la nota del alumno\n");
        scanf("%d", &nota);

        validos = altaMaterias(materias,materia,alumno,nota,validos);
        printf ("Desea continuar? s/n \n");
        fflush(stdin);
        scanf ("%c", &seguir);
    }
    return validos;
}

void mostrarPorMateria (celda materias [],char buscado [], int validos)
{
    int i=0;
    while(i<validos && strcmpi (buscado, materias[i].materia) != 0)
    {
        i++;
    }
    mostrarLista (materias[i].lista);
}
void mostrarLista (nodo * lista)
{
    nodo * seg = lista;
    while (seg != NULL)
    {
        printf("Alumno:");
        puts (seg->alumno);
        printf ("Nota: %d \n", seg->nota);
        printf ("----------\n");
        seg = seg->sig;
    }
}
