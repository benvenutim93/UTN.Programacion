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

nodo* inicLista();
nodo* crearNodo(char[], int);
int buscarPosMateria(celda[],char[],int);
int ingresarNotas(celda[], int);
int alta(celda[], char [],char[],int,int);
int cargarMateria(celda[],char[],int);
nodo* agregarPpio(nodo*, nodo*);

int main()
{
    int dimension =20, validos=0;
    celda materias[dimension];

    validos= ingresarNotas(materias,dimension);
    mostrar(materias,validos);

    return 0;
}
int ingresarNotas(celda materias[],int dimension)
{
    char materia[20],alumno[20],seguir='s';
    int nota=0,validos=0;

    while(seguir=='s'&& validos < dimension)
    {
        printf("Ingrese la materia a cargar\n");
        fflush(stdin);
        gets(materia);
        printf("Ingrese el alumno\n");
        fflush(stdin);
        gets(alumno);
        printf("Ingrese la nota del alumno\n");
        scanf("%d",&nota);

        validos=alta(materias, materia, alumno,nota,validos);

        printf("Desea ingresar otro alumno? s/n\n");
        fflush(stdin);
        scanf("%c",&seguir);
    }
    return validos;
}
int alta(celda materias[], char materia[],char alumno[], int nota, int validos)
{
    int pos=0;

    nodo* aux=crearNodo(alumno,nota);
    pos=buscarPosMateria(materias,materia,validos);
    if (pos==-1)
    {
        validos=cargarMateria(materias,materia,validos);
        pos=validos-1;
    }
    materias[pos].lista=agregarPpio(materias[pos].lista,aux);

    return validos;
}

nodo* crearNodo(char alumno[], int nota)
{
    nodo* aux=(nodo*)malloc(sizeof(nodo));

    strcpy(aux->alumno,alumno);
    aux->nota=nota;
    aux->sig=inicLista();

    return aux;
}
int buscarPosMateria(celda materias[], char materia[],int validos)
{
    int i =0, pos=-1;

    while(i<validos)
    {
        if(strcmp(materias[i].materia,materia)==0)
            pos=i;
        i++;
    }

    return pos;
}

int cargarMateria(celda materias[],char materia[],int validos)
{
    strcpy(materias[validos].materia,materia);
    materias[validos].lista =inicLista();
    validos++;

    return validos;
}
nodo* agregarPpio(nodo* lista, nodo* nn)
{
    if (lista ==NULL)
          lista = nn;
    else
    {
        nn->sig=lista;
        lista=nn;
    }
    return lista;
}
void mostrar(celda materias[], int validos)
{
    int i=0;

    while(i< validos)
    {
        printf("MATERIA:\n");
        puts(materias[i].materia);

        mostrarLista(materias[i].lista);
        i++;

    }
}
void mostrarLista(nodo* lista)
{
    nodo* seg=lista;

    while(seg!=NULL)
    {
        printf("ALUMNO:");
        puts(seg->alumno);
        printf("NOTA: %d\n",seg->nota);
        seg=seg->sig;
    }

}
nodo* inicLista()
{
    return NULL;
}
