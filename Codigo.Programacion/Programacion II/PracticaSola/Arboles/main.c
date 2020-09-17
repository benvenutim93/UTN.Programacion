#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int dato;
    struct nodo * sig;
} nodo;

typedef struct
{
    nodo * primero;
    nodo * ultimo;
} fila;

void inicFila (fila * filita);
void agregarAlaFila (fila * filita, int dato);
int extraerDeFila (fila * filita);


int main()
{
    int lalala;
    fila filita;
    inicFila(&filita);
    //agregarAlaFila(&filita,17);
    agregarAlaFila(&filita,71);
    agregarAlaFila(&filita,6);
    agregarAlaFila(&filita,88);
    agregarAlaFila(&filita,53);
    agregarAlaFila(&filita,32);
    recorrerLista(filita.primero);
    lalala = extraerDeFila(&filita);
    printf ("DATO EXTRAIDO %d \n", lalala);
    recorrerLista(filita.primero);
    return 0;
}

void inicFila (fila * filita)
{
    filita->primero=inicLista();
    filita->ultimo=inicLista();
}

void agregarAlaFila (fila * filita, int dato)
{
    nodo * aux = crearNodo(dato);
    if (filita->primero == NULL)
    {
        filita->primero=aux;
        filita->ultimo=aux;
    }
    else
    {
        filita->primero = agregarFinal(filita->primero,aux);
        filita->ultimo=aux;
    }
}

int extraerDeFila (fila * filita)
{
    int rta=0;
    if (filita->primero != NULL)
    {
        nodo * aux = filita->primero;
        nodo * nuevoPrimero = aux->sig;
        if (filita->primero != filita->ultimo)
            filita->primero=nuevoPrimero;
        else
        {
            filita->primero=NULL;
            filita->ultimo=NULL;
        }
        rta = aux->dato;
        free(aux);
    }
    return rta;
}
