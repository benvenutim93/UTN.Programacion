#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define archAnimales "animales.dat"

typedef struct {
   char animal[30];
   int cant;
   int habitat;
   int idEspecie;
   char especie[20];
} registroArchivo;

typedef struct {
    char nombreAnimal [30];
	int cantidad;
	int habitat; // 1 - selva, 2- savana, 3-bosque, 4-mar
} animal;

typedef struct nodo
{
   animal dato;
   struct nodo * sig;
} nodo;



typedef struct nodoLista
{
   int idEspecie;
   char especie [20];
 	 // "Mamiferos", "Aves"
       // "Reptiles", "Peces"
   nodo * listaDeAnimales;
   struct nodoLista * sig;
} nodoLista;

int main()
{
    nodoLista * listaAnimales = inicListaMaster();
    return 0;
}
nodoLista * inicListaMaster ()
{
    return NULL;
}
nodoLista * crearNodoMaster (int idEspecie, char especie[])
{
    nodoLista * a = (nodoLista*) malloc (sizeof(nodoLista));
    a->listaDeAnimales=inicLista();
    a->sig=NULL;
    a->idEspecie = idEspecie;
    strcpy(a->especie,especie);
    return a;
}
registroArchivo leerArchivo ()
{
    FILE * archi = fopen (archAnimales,"rb");
    registroArchivo a;
    fread(&a,sizeof(registroArchivo),1,archi);
    return a;
}
animal delRegistroAlAnimal(registroArchivo a)
{
    animal ito;
    ito.cantidad=a.cant;
    ito.habitat=a.habitat;
    strcpy(ito.nombreAnimal,a.animal);
    return ito;
}

nodoLista * agregarListaMaster (nodoLista * master, registroArchivo a)
{
    animal ito = delRegistroAlAnimal(a);
    nodoLista * buscado = buscarNodo(master,a.especie);
    nodoLista * ultimo;
    if (buscado == NULL)
    {
        ultimo = agregarEspecie(master,a.especie, a.idEspecie);
    }


}
nodoLista * buscarNodo (nodoLista * master, char especie [])
{
    nodo * aux=NULL;
    nodoLista * seg = master;
    while (seg != NULL)
    {
        if (strcmpi(seg->especie,especie) == 0)
            aux=seg;
        seg=seg->sig;
    }
    return aux;
}
nodoLista * buscarUltimoMaster (nodoLista * master)
{
    nodoLista * seg = lista;
    if(seg != NULL)
    {
        while (seg->sig != NULL)
            seg=seg->sig;
    }
    return seg;
}
nodoLista * agregarEspecie (nodoLista * master, char especie [], int idEspecie)
{
    nodoLista * ultimo = buscarUltimoMaster(master);
    nodoLista * aux = crearNodoMaster(idEspecie,especie);
    ultimo->sig = aux;
    aux->listaDeAnimales = inicLista();
    return aux;
}
