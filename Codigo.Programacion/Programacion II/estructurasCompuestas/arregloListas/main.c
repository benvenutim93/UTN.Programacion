#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char materia[20];
    struct nodo* lista;
} celda;

typedef struct
{
    char alumno[20];
    int nota;
    struct nodo* sig;
} nodo;

int cargarMaterias(celda[]);
int cargarNotas(celda[], int);
nodo* crearNodo(char[], int);
void agregarLista(celda[],nodo*,char[],int);
nodo* agregarPpio(nodo*,nodo*);
void mostrarLista(nodo*);
void mostrarMateria(celda[],int);
nodo* inicLista();

int main()
{
    celda materias[10];
    int validos=0,cantidad;

    validos = cargarMaterias(materias);

    cantidad = cargarNotas(materias, validos);
    mostrarMateria(materias,validos);


    return 0;
}
nodo* inicLista()
{
    return NULL;
}
int cargarMaterias(celda materias[])
{
    char asignatura [20];

    char seguir='s';
    int validos=0;

    while(seguir=='s'&& validos<10)
    {
        printf("Ingrese la materia para su arreglo\n");
        fflush(stdin);
        gets(asignatura);

        strcpy (materias[validos].materia,asignatura);
        materias[validos].lista=inicLista();
        validos++;

        printf("Desea ingresar otra materia? s/n\n");
        fflush(stdin);
        scanf("%c",&seguir);
    }
    return validos;
}
int cargarNotas(celda materias[], int validos)
{
    char alumno[20],asignatura[20];
    int nota;
    nodo* nn;
    char seguir='s';

    while(seguir=='s')
    {
        printf("Ingrese el nombre del alumno\n");
        fflush(stdin);
        gets(alumno);

        printf("Ingrese la nota del alumno\n");
        scanf("%d",&nota);

        nn=crearNodo(alumno, nota);
        printf("A que materia pertenece el alumno?\n");
        fflush(stdin);
        gets(asignatura);

        agregarLista(materias,nn,asignatura, validos);

        printf("Desea agregar otro alumno? s/n\n");
        fflush(stdin);
        scanf("%c",&seguir);
    }



}
nodo* crearNodo(char marianas[], int nota)
{
    nodo* aux= (nodo*)malloc(sizeof(nodo));

    strcpy(aux->alumno,marianas);
    aux->nota =nota;
    aux->sig=NULL;

    return aux;
}
void agregarLista(celda materias[], nodo* nn, char asignatura[],int validos)
{
    int i=0,flag=0;
    while(flag==0)
    {

        while(strcmp(materias[i].materia,asignatura)!=0 && i<validos)
        {
            i++;
        }
        if((strcmp(materias[i].materia,asignatura)==0))
        {
            materias[i].lista=agregarPpio(materias[i].lista, nn);
            flag=1;
        }
        else
        {
            printf("Su materia no existe\n");
            printf("ingrese una materia valida\n");
            gets(asignatura);
            i=0;
        }
    }
}
nodo* agregarPpio(nodo* lista, nodo*nn)
{
    if(lista==NULL)
        lista=nn;
    else
    {
        nn->sig=lista;
        lista=nn;
    }
    return lista;
}
void mostrarMateria(celda materias[],int validos)
{
    for(int i=0; i<validos; i++)
    {
        printf("Materia:\n");
        puts(materias[i].materia);

        mostrarLista(materias[i].lista);
    }
}
void mostrarLista(nodo* lista)
{
    nodo* seg=lista;

    while(seg!=NULL)
    {
        printf("\nAlumno:");
        puts (seg->alumno);
        printf("Nota: %d",seg->nota);

        seg=seg->sig;
    }
}
