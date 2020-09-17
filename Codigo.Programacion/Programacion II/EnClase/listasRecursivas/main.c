#include <stdio.h>
#include <stdlib.h>
typedef struct nodo
{
    int dato;
    struct nodo * sig;
}nodo;

nodo * inicLista();
nodo * crearNodo (int);
nodo * cargarLista (nodo *);
void recorrerYmostrarRecursivo (nodo *);
void mostrarNodo (nodo *);
nodo * agregarPpio(nodo*, nodo*);
int sumaListaRecursiva (nodo*);
void mostrarNodosPares (nodo*, int);

int main()
{
    /**1. Recorrer una lista y mostrarla en forma invertida.
2. Sumar los elementos de una lista.
3. Mostrar los elementos de una lista ubicados en un lugar par.
4. Invertir una lista cambiando los vínculos.
5. Borrar un nodo de una lista.
6. Insertar un nodo en una lista en forma recursiva (manteniendo el orden de forma creciente).
*/
    int suma =0, pos=0;
    nodo * lista = inicLista();
    lista = cargarLista(lista);
    /*recorrerYmostrarRecursivo(lista);
    suma = sumaListaRecursiva(lista);
    printf ("La suma de los numeros de la lista es: %d", suma);*/
    mostrarNodosPares(lista,pos);
    return 0;
}

nodo * inicLista()
{
    return NULL;
}
nodo * crearNodo(int dato)
{
    nodo * aux = (nodo*) malloc (sizeof(nodo));
    aux->dato=dato;
    aux->sig= NULL;
    return aux;
}

nodo * cargarLista(nodo * lista)
{
    char seguir ='s';
    int numero;

    while (seguir == 's')
    {
        printf ("Que dato desea ingresar? \n");
        scanf ("%d", &numero);
        nodo * aux = crearNodo(numero);
        lista = agregarPpio(lista, aux);

        printf ("Desea cargar otro dato? \n");
        fflush(stdin);
        scanf ("%c", &seguir);
    }
    return lista;
}

nodo * agregarPpio (nodo * lista, nodo * nn)
{
    if (lista == NULL)
        lista = nn;
    else
    {
        nn->sig=lista;
        lista=nn;
    }
    return lista;
}

void mostrarNodo(nodo * a)
{
    printf ("DATO: %d \n", a->dato);
}
void recorrerYmostrarRecursivo(nodo * lista)
{
    if (lista!=NULL)
    {
        recorrerYmostrarRecursivo(lista->sig);
        mostrarNodo(lista);
    }
}

int sumaListaRecursiva(nodo * lista)
{
    int suma;
    nodo * seg = lista;
    if (seg != NULL)
    {
        suma = seg->dato + sumaListaRecursiva(seg->sig);
    }
    else
        suma=0;

    return suma;
}

void mostrarNodosPares(nodo * lista, int posicion)
{
    nodo * seg = lista;
    if (seg!=NULL)
    {
        if (posicion%2==0)
        {
            mostrarNodo(seg);
        }
        mostrarNodosPares(seg->sig,posicion+1);
    }
}
