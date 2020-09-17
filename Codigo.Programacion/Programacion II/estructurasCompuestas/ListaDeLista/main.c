#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo
{
    char alumno[20];
    int nota;
    struct nodo* sig;
}nodo;

typedef struct
{
    char materia[20];
    struct master* sig;
    struct nodo* lista;

}master;


int main()
{
    master listaMaterias=inicLista();

    listaMaterias=cargarDatos(listaMaterias);

    return 0;
}
nodo* inicLista()
{
    return NULL;
}
nodo* crearNodo(char alumno[], int nota)
{
    nodo* nn=(nodo*) malloc(sizeof(nodo));

    strcpy(nn->alumno,alumno);
    nn->nota=nota;
    nn->sig=NULL;

    return nn;
}
master cargarDatos(master listaMaterias)
{
    int nota=0;
    char seguir='s', asignatura[20], alumno[20];

    printf("INGRESE MATERIA:");
    fflush(stdin);
    gets(asignatura);
    printf("Ingrese el alumno\n");
    fflush(stdin);
    gets(alumno);
    printf("ingrese la nota\n");
    scanf("%d",&nota);

    listaMaterias=alta(listaMaterias, asignatura, nota, alumno);

}
master alta(master listaMaterias,char asignatura[], int nota, char alumno[])
{
    nodo* nn =crearNodo(alumuno, nota);
    listaMaterias=agregarLista(listaMaterias,asignatura,nn);


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
    return nn;
}
