#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombre[20];
    int articulos;
    int prioridad; /// 1 o 2
} persona;

typedef struct
{
    persona p;
    struct nodo * sig;
} nodo;

typedef struct
{
    persona p;
    struct nodo2 * anterior;
    struct nodo2 * siguiente;
} nodo2;

typedef struct
{
    nodo2 * primero;
    nodo2 * ultimo;
    int prioridad;
} fila;

nodo * inicLista();
nodo * crearNodo(char[],int, int);
nodo * agregarFinal(nodo*, nodo*);
nodo * buscarUltimo(nodo*);
void mostrarLista (nodo *);
void mostrarPersona(persona);
fila inicFilaP1(fila);
fila inicFilaP2(fila);
void pasajeFilas(fila,fila,fila[]);
nodo2 * crearNodo2(persona);
void agregarFila(fila, nodo2*);
nodo * agregarFinalNodo2(nodo*, nodo2*);

int main()
{

    nodo * lista = inicLista();
    fila  filita0;
    fila  filita2;
    fila super[2];

    inicFilaP1(filita0);
    inicFilaP2(filita2);


    nodo * p1 = crearNodo("juan",15,1);
    lista = agregarFinal(lista, p1);
    printf("a\n");
    nodo * p2 = crearNodo("mariana",99,2);
    lista = agregarFinal(lista, p2);
    printf("a\n");
    nodo * p3 = crearNodo("rodrigo",1,1);
    lista = agregarFinal(lista, p3);
    printf("a\n");
    nodo * p4 = crearNodo("lautaro",17,2);
    lista = agregarFinal(lista, p4);
    printf("a\n");
    nodo * p5 = crearNodo("sofia",13,2);
    lista = agregarFinal(lista, p5);
    printf("a\n");
    nodo * p6 = crearNodo("nico",33,1);
    lista = agregarFinal(lista, p6);
    printf("a\n");

    mostrarLista(lista);



    return 0;
}
nodo * crearNodo(char nombre[20], int cantidad, int prioridad)
{
    nodo * nn = (nodo*)malloc(sizeof(nodo));

    persona a;
    strcpy(a.nombre,nombre);
    a.articulos=cantidad;
    a.prioridad=prioridad;

    nn->p=a;
    nn->sig =NULL;

    return nn;
}
nodo * inicLista()
{
    return NULL;
}

nodo * agregarFinal (nodo * lista, nodo * nn)
{
    if (lista == NULL)
        lista=nn;
    else
    {
        nodo * aux = buscarUltimo(lista);
        aux->sig = nn;
    }
    return lista;
}
nodo * buscarUltimo(nodo * lista)
{
    nodo * aux = lista;
        printf("8\n ");
    while (aux->sig != NULL)
    {
        printf(".");
        aux=aux->sig;
    }
    return aux;
}

void mostrarLista(nodo * lista)
{
    printf ("-");
    nodo * aux = lista;
    while(aux!=NULL)
    {
        mostrarPersona(aux->p);
        aux = aux->sig;
    }
}

void mostrarPersona (persona p)
{
    printf ("NOMBRE: ");
    puts (p.nombre);
    printf("CANTIDAD DE ARTICULOS: %d \n", p.articulos);
    printf ("PRIORIDAD: %d\n", p.prioridad);
    printf ("-------------------------------\n\n");
}
fila inicFilaP1(fila  filita)
{
    filita.primero=inicLista();
    filita.ultimo=inicLista();
    filita.prioridad=1;
    return filita;
}
fila inicFilaP2(fila  filita)
{
    filita.primero=inicLista();
    filita.ultimo=inicLista();
    filita.prioridad=2;
    return filita;
}
void pasajeFilas(fila  filita0, fila  filita2,fila super[])
{
    super[0]=filita0;
    super[1]=filita2;
}
nodo2 * crearNodo2 (persona a)
{
    nodo2 * nn =(nodo2*)malloc(sizeof(nodo2*));

    nn->p=a;
    nn->anterior=NULL;
    nn->siguiente=NULL;

    return nn;
}
void agregarFila(fila  filita, nodo2 * nn)
{
    if(filita.primero==NULL)
    {
        filita.primero=nn;
        filita.ultimo=nn;
    }
    else
    {
        filita.primero=agregarFinalNodo2(filita.primero,nn);
        filita.ultimo=nn;
    }
}
fila * encolar(fila super[],nodo * lista)
{
    nodo * seg = lista;
    persona a;
    nodo2 * aux;
    while(seg!=NULL)
    {
        a=seg->p;
        for(int i=0; i<2; i++)
        {
            if(a.prioridad==super[i].prioridad)
            {
                aux=crearNodo2(a);
                agregarFila(super[i],aux);
            }
        }
        seg=seg->sig;
    }
    return super;
}

nodo * agregarFinalNodo2 (nodo * lista, nodo2 * nn)
{
    if (lista == NULL)
        lista=nn;
    else
    {
        nodo * aux = buscarUltimo(lista);
        aux->sig = nn;
    }
    return lista;
}
