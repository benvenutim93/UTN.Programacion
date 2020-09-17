#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	int habitat;
// 1 - selva, 2- savana, 3-bosque, 4-mar
} animal;
typedef struct
{
   animal dato;
   struct nodoArbol * izq;
   struct nodoArbol * der;
} nodoArbol;


typedef struct
{
   int idEspecie;
   char especie [20];
 	 // "Mamiferos", "Aves"
       // "Reptiles", "Peces"
   nodoArbol * arbolDeAnimales;
} celdaEspecie;


int main()
{
    return 0;
}

nodoArbol * inicArbol ()
{
    return NULL;
}
nodoArbol * agregar (nodoArbol * lito, nodoArbol * nn)
{
    if (lito == NULL)
        lito=nn;
    else
    {
        if (nn->dato.cantidad < lito->dato.cantidad)
            lito->izq = agregar (lito->izq, nn);
        else
            lito->der = agregar (lito->der,nn);
    }
    return lito;
}
