#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define archAnimales "animales.dat"
#define archAves "aves.dat"
#define archMamiferos "mamiferos.dat"
#define archPeces "peces.dat"
#define archReptiles "reptiles.dat"

typedef struct
{
    char animal[30];
    int cant;
    int habitat;
    int idEspecie;
    char especie[20];
} registroArchivo;
typedef struct
{
    char nombreAnimal [30];
    int cantidad;
    int habitat; // 1 - selva, 2- savana, 3-bosque, 4-mar
} animal;
typedef struct nodoArbol
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


nodoArbol * inicArbol ();
nodoArbol * crearNodoArbol (animal a);
nodoArbol * agregar (nodoArbol * lito, nodoArbol * nn);
registroArchivo copiarDelArchivo();
animal delRegistroAlAnimal (registroArchivo a);
int agregarCelda (celdaEspecie arreglo[],int validos, registroArchivo dato);
int buscarPosEspecie (celdaEspecie arreglo[], int validos, char especie []);
int agregarEspecie (celdaEspecie arreglo [], int validos, char especie[], int idEspecie);
void mostrarArreglo (celdaEspecie arreglo[], int validos);
void mostrarArbol (nodoArbol * lito);
void mostrarAnimal (animal a);
int pasarAlArreglo (celdaEspecie arreglo [], int dimension);
registroArchivo copiarAlRegistro(animal ito, char especie[], int idEspecie);
void pasarAlArchivo (nodoArbol * lito, char especie [], int idEspecie, char archivo []);
void alArchivo (nodoArbol * lito, char especie [], int idEspecie, FILE * archi);
void pasajeAtodosLosArchivos (celdaEspecie arreglo [], int validos);
void mostrarArchivo (char []);


int main()
{
    celdaEspecie arreglo [50];
    int validos = pasarAlArreglo(arreglo,50);
    pasajeAtodosLosArchivos(arreglo,validos);
    mostrarArchivo(archMamiferos);

    return 0;
}

nodoArbol * inicArbol ()
{
    return NULL;
}
nodoArbol * crearNodoArbol (animal a)
{
    nodoArbol * aux = (nodoArbol*)malloc(sizeof(nodoArbol));
    aux->dato=a;
    aux->der=NULL;
    aux->izq=NULL;
    return aux;
}
nodoArbol * agregar (nodoArbol * lito, nodoArbol * nn)
{
    if (lito == NULL)
        lito=nn;
    else
    {
        if (nn->dato.cantidad < lito->dato.cantidad)
            lito->izq = agregar (lito->izq,nn);
        else
            lito->der = agregar (lito->der,nn);
    }
    return lito;
}
registroArchivo copiarDelArchivo()
{
    registroArchivo a;
    FILE * archi = fopen(archAnimales,"rb");
    if (archi!= NULL)
    {
        fread(&a,sizeof(registroArchivo),1,archi);
        fclose(archi);
    }
    return a;
}
animal delRegistroAlAnimal (registroArchivo a)
{
    animal aux;
    aux.cantidad=a.cant;
    aux.habitat=a.habitat;
    strcpy(aux.nombreAnimal,a.animal);
    return aux;
}
int agregarCelda (celdaEspecie arreglo[],int validos, registroArchivo dato)
{
    animal ito = delRegistroAlAnimal(dato);
    nodoArbol * aux = crearNodoArbol(ito);
    int pos = buscarPosEspecie (arreglo, validos, dato.especie);
    if (pos == -1)
    {
        validos = agregarEspecie (arreglo, validos, dato.especie, dato.idEspecie);
        pos=validos-1;
    }
    arreglo[pos].arbolDeAnimales=agregar(arreglo[pos].arbolDeAnimales,aux);
    return validos;
}

int buscarPosEspecie (celdaEspecie arreglo[], int validos, char especie [])
{
    int pos = -1, i=0;
    while (i<validos)
    {
        if (strcmpi(arreglo[i].especie,especie)==0)
            pos=i;
        i++;
    }
    return pos;
}
int agregarEspecie (celdaEspecie arreglo [], int validos, char especie[], int idEspecie)
{
    arreglo[validos].idEspecie=idEspecie;
    strcpy(arreglo[validos].especie,especie);
    arreglo[validos].arbolDeAnimales = inicArbol();
    validos ++;
    return validos;
}
void mostrarArreglo (celdaEspecie arreglo[], int validos)
{
    for (int i=0; i<validos; i++)
    {
        printf ("--------------------------------\n");
        printf ("ESPECIE:");
        puts(arreglo[i].especie);
        printf("ID ESPECIE: %d\n\n", arreglo[i].idEspecie);
        mostrarArbol(arreglo[i].arbolDeAnimales);
        printf ("--------------------------------\n");
    }
}
void mostrarArbol (nodoArbol * lito)
{
    if (lito !=NULL)
    {
        mostrarAnimal (lito->dato);
        mostrarArbol(lito->izq);
        mostrarArbol(lito->der);
    }
}
void mostrarAnimal (animal a)
{
    printf ("\nNOMBRE:");
    puts (a.nombreAnimal);
    printf ("CANTIDAD: %d\n", a.cantidad);
    switch (a.habitat)
    {
    case 1:
        printf ("HABITAT: SELVA\n");
        break;
    case 2:
        printf ("HABITAT: SAVANA\n");
        break;
    case 3:
        printf ("HABITAT: BOSQUE\n");
        break;
    case 4:
        printf ("HABITAT: MAR\n");
        break;
    }
}

int pasarAlArreglo (celdaEspecie arreglo [], int dimension)
{
    registroArchivo a;
    int validos=0;
    FILE * archi = fopen (archAnimales, "rb");
    if (archi != NULL)
    {
        while (fread (&a,sizeof(registroArchivo),1,archi)>0)
            validos=agregarCelda(arreglo,validos,a);
        fclose (archi);
    }
    return validos;
}

registroArchivo copiarAlRegistro(animal ito, char especie[], int idEspecie)
{
    registroArchivo aux;
    strcpy(aux.especie,especie);
    aux.idEspecie=idEspecie;
    aux.cant=ito.cantidad;
    aux.habitat=ito.habitat;
    strcpy(aux.animal,ito.nombreAnimal);
    return aux;
}
void pasarAlArchivo (nodoArbol * lito, char especie [], int idEspecie, char archivo [])
{
    int i=0;
    FILE * archi = fopen (archivo, "w+b");
    if (archi != NULL)
    {
        alArchivo(lito,especie,idEspecie,archi);
        fclose(archi);
    }
}
void alArchivo (nodoArbol * lito, char especie [], int idEspecie, FILE * archi)
{
    registroArchivo a;
    if (lito != NULL)
    {
        alArchivo(lito->izq,especie,idEspecie,archi);
        alArchivo(lito->der,especie,idEspecie,archi);
        a=copiarAlRegistro(lito->dato,especie,idEspecie);
        fwrite(&a,sizeof(registroArchivo),1,archi);
    }
}

void pasajeAtodosLosArchivos (celdaEspecie arreglo [], int validos)
{
    int pos;
    pos=buscarPosEspecie(arreglo,validos,"aves");
    pasarAlArchivo(arreglo[pos].arbolDeAnimales,arreglo[pos].especie,arreglo[pos].idEspecie,archAves);
    pos=buscarPosEspecie(arreglo,validos,"reptiles");
    pasarAlArchivo(arreglo[pos].arbolDeAnimales,arreglo[pos].especie,arreglo[pos].idEspecie,archReptiles);
    pos=buscarPosEspecie(arreglo,validos,"mamiferos");
    pasarAlArchivo(arreglo[pos].arbolDeAnimales,arreglo[pos].especie,arreglo[pos].idEspecie,archMamiferos);
    pos=buscarPosEspecie(arreglo,validos,"peces");
    pasarAlArchivo(arreglo[pos].arbolDeAnimales,arreglo[pos].especie,arreglo[pos].idEspecie,archPeces);
}

void mostrarArchivo (char archivo [])
{
    registroArchivo a;
    FILE * archi = fopen (archivo,"rb");
    while (fread(&a,sizeof(registroArchivo),1,archi)>0)
    {
        mostrarRegistro(a);
    }
}
void mostrarRegistro (registroArchivo a)
{
    printf ("ESPECIE:");
    puts (a.especie);
    printf ("ID ESPECIE: %d\n", a.idEspecie);
    printf ("NOMBRE ANIMAL:");
    puts(a.animal);
    switch (a.habitat)
    {
    case 1:
        printf ("HABITAT: Selva\n");
        break;
    case 2:
        printf ("HABITAT: Savana\n");
        break;
    case 3:
        printf ("HABITAT: Bosque\n");
        break;
    case 4:
        printf ("HABITAT: Mar\n");
        break;
    }
    printf ("CANTIDAD: %d\n",a.cant);
    printf ("------------------------------\n\n");
}
