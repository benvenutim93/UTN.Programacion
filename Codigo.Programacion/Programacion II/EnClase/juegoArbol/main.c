#include <stdio.h>
#include <stdlib.h>

typedef struct nodoArbol
{
    int numero;
    struct nodoArbol * der;
    struct nodoArbol * izq;
} nodoArbol;

typedef struct
{
    int cantidadNodosDerecha;
    int cantidadNodosIzquierda;
    float promedio;
} estadistica;

typedef struct nodo
{
    estadistica jugada;
    struct nodo * sig;
} nodo;

nodoArbol * inicArbol ();
int contarNodos (nodoArbol *);
nodoArbol * agregar (nodoArbol *, nodoArbol*);
nodoArbol * crearNodoArbol (int);
nodoArbol * cargarArbol (nodoArbol*);
float promedioHijos (nodoArbol*, int);
int contarUnHijo (nodoArbol*);
float contarDosHijos (nodoArbol*);
int contarHojas (nodoArbol*);
nodo* iniclista();
estadistica crearEstadistica(nodoArbol*);
nodo* crearNodo(estadistica):
    nodo* agregarFinal(nodo*,nodo*);



    int main()
{
    int rta=0;
    float prom =0;
    nodo* jugador1=iniclista();
    nodo* jugador2=iniclista();
    nodoArbol * arbolito = inicArbol();
    arbolito = cargarArbol(arbolito);
    jugador1=cargarLista(jugador1,arbolito);
    jugador2=cargarLista(jugador2,arbolito);



    return 0;
}
nodo* iniclista()
{
    return NULL;
}
nodoArbol * inicArbol ()
{
    return NULL;
}
int contarNodos (nodoArbol * lito)
{
    int rta =0;
    if (lito != NULL)
    {
        rta= 1 + contarNodos(lito->izq) + contarNodos(lito->der);
    }
    return rta;
}
nodoArbol * agregar(nodoArbol * lito, nodoArbol * nn)
{
    if (lito == NULL)
        lito=nn;
    else
    {
        if (nn->numero > lito->numero)
            lito->der=agregar(lito->der,nn);
        else
            lito->izq=agregar(lito->izq,nn);
    }
    return lito;
}
nodoArbol * crearNodoArbol(int dato)
{
    nodoArbol * aux = (nodoArbol*)malloc (sizeof (nodoArbol));
    aux->numero = dato;
    aux->der = NULL;
    aux->izq = NULL;
    return aux;
}
nodoArbol * cargarArbol (nodoArbol* lito)
{
    nodoArbol * a = crearNodoArbol(33);
    nodoArbol * b = crearNodoArbol(17);
    nodoArbol * c = crearNodoArbol(23);
    nodoArbol * d = crearNodoArbol(66);
    nodoArbol * e = crearNodoArbol(51);
    nodoArbol * f = crearNodoArbol(5);
    nodoArbol * g = crearNodoArbol(44);
    nodoArbol * h = crearNodoArbol(27);
    nodoArbol * i = crearNodoArbol(10);
    nodoArbol * j = crearNodoArbol(88);
    nodoArbol * k = crearNodoArbol(93);
    nodoArbol * l = crearNodoArbol(56);
    nodoArbol * m = crearNodoArbol(71);

    lito = agregar(lito,a);
    lito = agregar(lito,b);
    lito = agregar(lito,c);
    lito = agregar(lito,d);
    lito = agregar(lito,e);
    lito = agregar(lito,f);
    lito = agregar(lito,g);
    lito = agregar(lito,h);
    lito = agregar(lito,i);
    lito = agregar(lito,j);
    lito = agregar(lito,k);
    lito = agregar(lito,l);
    lito = agregar(lito,m);
    return lito;
}
float promedioHijos(nodoArbol * lito, int total)
{
    int cant0 =0, cant1=0, cant2=0;
    float prom=0;
    cant0 = contarHojas (lito);
    cant1 = contarUnHijo (lito);
    cant2 = contarDosHijos (lito);

    prom = (cant0+cant1+cant2)/total;
    return prom;
}

int contarHojas (nodoArbol * lito)
{
    int rta =0;
    if (lito != NULL)
    {
        if(lito->der == NULL && lito->izq == NULL)
            rta = 1;
        else
            rta = rta + contarHojas(lito->der) + contarHojas(lito->izq);
    }
    return rta;
}

int contarUnHijo (nodoArbol * lito)
{
    int rta=0;
    if (lito != NULL)
    {
        if (lito->der == NULL && lito ->izq != NULL)
            rta=1;
        else if (lito ->izq == NULL && lito->der != NULL  )
            rta =1;
        else
            rta = rta + contarUnHijo(lito->der) + contarUnHijo(lito->izq);
    }
    return rta;
}

float contarDosHijos (nodoArbol * lito)
{
    float rta =0;
    if (lito != NULL)
    {
        if (lito ->izq != NULL && lito->der != NULL)
            rta +=1;

        rta += contarDosHijos(lito->der) + contarDosHijos(lito->izq);
    }
    return rta;
}
estadistica crearEstadistica(nodoArbol* lito)
{
    int der=0, izq=0;
    float prom=0;
    estadistica a;

    der = contarNodos(arbolito->der);
    izq = contarNodos(arbolito->izq);
    prom = contarDosHijos(arbolito);

    a.cantidadNodosDerecha=der;
    a.cantidadNodosIzquierda=izq;
    a.promedio=prom;

    return a;
}
nodo* crearNodo(estadistica a)
{
    nodo* aux = (nodo*)malloc(sizeof(nodo));

    aux->jugada=a;
    aux->sig=NULL;

    return aux;
}

nodo* cargarLista(nodo* lista,nodoArbol* lito)///el arbol se genera random
{
    estadistica a;
    for(int i=0; i<5; i++)
    {
        a=crearEstadistica(lito);
        nodo* aux= crearNodo(a);
        lista=agregarFinal(lista,aux);
    }
    return lista;
}
nodo* agregarFinal(nodo* lista,nodo*nn)
{
    nodo* seg=lista;

    if(lista==NULL)
        lista=nn;
    else
    {
        while(seg->sig!=NULL)
        {
            seg=seg->sig;
        }
        seg->sig=nn;
    }
    return lista;
}
