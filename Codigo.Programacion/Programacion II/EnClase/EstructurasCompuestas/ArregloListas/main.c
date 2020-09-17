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
    struct nodo * lista;
}celda;

nodo * inicLista();
nodo * crearNodo (char [],int );
nodo * agregarPpio (nodo * , nodo * );
int buscarPosMateria (celda  [],char[], int );
int cargarNotas (celda [], int );
int altaMateria(celda  [], char [],char [],int ,int );
int agregarMateria (celda [], char [], int );
void mostrarLista (nodo * );
void mostrarArreglo (celda [], int );



int main()
{
    celda materias [20];
    int validos=0;
    validos = cargarNotas(materias,20);
    mostrarArreglo(materias,validos);

    return 0;
}

nodo * inicLista()
{
    return NULL;
}
nodo * crearNodo (char nombre[],int nota)
{
    nodo * aux = (nodo*) malloc (sizeof(nodo));
    strcpy (aux->alumno, nombre);
    aux->nota=nota;
    aux->sig=NULL;
    return aux;
}
nodo * agregarPpio (nodo * lista, nodo * nn)
{
    if (lista != NULL)
        nn->sig=lista;
    lista=nn;
    return lista;
}
int buscarPosMateria (celda materias [],char asignatura[], int validos)
{
    int i =0, pos=-1;
    while (i<validos && pos ==-1)
    {
        if (strcmpi(materias[i].materia,asignatura)==0)
            pos=i;
        i++;
    }
    return pos;
}
int cargarNotas (celda materias[], int dimension)
{
    char asignatura[20], nombre[20], seguir='s';
    int nota=0, validos =0;

    while (validos < dimension && seguir == 's')
    {
        printf ("Que materia desea ingresar? \n");
        fflush(stdin);
        gets (asignatura);
        printf ("Ingrese el nombre del alumno \n");
        fflush(stdin);
        gets (nombre);
        printf ("Ingrese la nota del alumno \n");
        scanf ("%d", &nota);

        validos = altaMateria (materias,asignatura,nombre,nota,validos);
        printf ("Desea seguir cargando datos? s/n \n");
        fflush(stdin);
        scanf("%c", &seguir);
    }
    return validos;
}
int altaMateria(celda materias [], char asignatura[],char nombre[],int nota,int validos)
{
    nodo * aux = crearNodo(nombre,nota);
    int pos = buscarPosMateria(materias,asignatura,validos);
    if (pos==-1)
    {
        validos=agregarMateria (materias,asignatura,validos);
        pos=validos-1;
    }
    materias[pos].lista=agregarPpio(materias[pos].lista,aux);
    return validos;
}
int agregarMateria (celda materias[], char asignatura[], int validos)
{
    strcpy (materias[validos].materia,asignatura);
    materias[validos].lista=inicLista();
    validos++;
    return validos;
}

void mostrarArreglo (celda materias[], int validos)
{
    for(int i=0;i<validos;i++)
    {
        printf ("MATERIA:\n");
        puts (materias[i].materia);
        mostrarLista(materias[i].lista);
    }
}
void mostrarLista (nodo * lista)
{
    nodo * seg = lista;
    while (seg != NULL)
    {
        printf ("ALUMNO:");
        puts(seg->alumno);
        printf ("\nNOTA: %d", seg->nota);
        seg = seg->sig;
    }
}
