#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define aAnimales "animales.dat"
#define archReptiles "reptiles.dat"
#define archAves "aves.dat"
#define archMamiferos "mamiferos.dat"
#define archPeces "peces.dat"

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

nodoArbol * inicArbol ();
nodoArbol * crearNodoArbol (animal );
nodoArbol * agregarArbol (nodoArbol *, nodoArbol * );
registroArchivo copiarDelArchivo ();
animal delRegistroAlAnimal (registroArchivo );
int agregarCelda (celdaEspecie [], int, registroArchivo );
int buscarPosEspecie (celdaEspecie [], int, char []);
int agregarEspecie (celdaEspecie [], int, char [], int );
void mostrarAnimal (animal );
void mostrarArbolAnimales (nodoArbol *);
void mostrarArchivoAVES();
void mostrarRegistroArchivo(registroArchivo);
registroArchivo copiarAlRegistro (animal, char [], int );
void avesAlArchivo (nodoArbol *, int, char[], FILE *);
void funcionMASgrande (nodoArbol *, int, char [],char[]);
void pasajeAlosArchivos (celdaEspecie arreglo [], int validos);
void mostrarArchivoAVESaux (FILE * archi);


int main()
{
    celdaEspecie arreglo [50];
    int validos=0, pos=-1;
    animal ito;
    nodoArbol * arbol;
    registroArchivo dato;

    validos=pasarAlArreglo(arreglo,50);
    mostrarArreglo(arreglo,validos);
    system("pause");
    system ("cls");
    pasajeAlosArchivos(arreglo,validos);
    printf ("AVES\n\n");
    mostrarArchivo(archAves);
    printf ("------------------------------\n");
    system("pause");
    printf ("\nMAMIFEROS \n\n");
    mostrarArchivo(archMamiferos);
    printf ("------------------------------\n");
    system("pause");
    printf ("\PECES\n\n");
    mostrarArchivo(archPeces);
    printf ("------------------------------\n");
    system("pause");
    printf ("\REPTILES\n\n");
    mostrarArchivo(archReptiles);
    printf ("------------------------------\n");
    system("pause");




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
    aux->der= NULL;
    aux->izq= NULL;
    return aux;
}
nodoArbol * agregarArbol (nodoArbol * lito, nodoArbol * nn)
{
    if (lito ==NULL)
        lito=nn;
    else
    {

        if (nn->dato.cantidad < lito->dato.cantidad)
        {
            lito->izq = agregarArbol(lito->izq,nn);
        }

        else
        {
            lito->der = agregarArbol(lito->der,nn);
        }

    }
    return lito;
}
registroArchivo copiarDelArchivo ()
{
    registroArchivo aux;
    FILE * archi = fopen (aAnimales, "rb");
    if (archi != NULL)
    {
        fread (&aux,sizeof(registroArchivo),1,archi);
        fclose(archi);
    }
    return aux;
}

animal delRegistroAlAnimal (registroArchivo a)
{
    animal ito;
    ito.cantidad = a.cant;
    ito.habitat=a.habitat;
    strcpy (ito.nombreAnimal,a.animal);
    return ito;
}

int agregarCelda (celdaEspecie a[], int validos, registroArchivo dato)
{
    int pos=0;

    animal ito = delRegistroAlAnimal(dato);
    nodoArbol * aux = crearNodoArbol(ito);
    pos = buscarPosEspecie (a,validos, dato.especie);
    if (pos==-1)
    {
        validos=agregarEspecie (a,validos,dato.especie, dato.idEspecie);
        pos=validos-1;
    }

    a[pos].arbolDeAnimales = agregarArbol(a[pos].arbolDeAnimales,aux);
    return validos;
}

int buscarPosEspecie (celdaEspecie a[], int validos, char nombreEspecie [20])
{
    int pos=-1, i=0;
    while (i<validos)
    {
        if (strcmpi (a[i].especie,nombreEspecie)==0)
            pos=i;
        i++;
    }
    return pos;
}

int agregarEspecie (celdaEspecie a[], int validos, char nombreEspecie [], int idEspecie)
{
    strcpy(a[validos].especie,nombreEspecie);
    a[validos].idEspecie=idEspecie;
    a[validos].arbolDeAnimales=inicArbol();
    validos++;
    return validos;
}

void mostrarAnimal (animal a)
{
    printf ("\nNOMBRE:");
    puts(a.nombreAnimal);
    printf ("CANTIDAD: %d\n", a.cantidad);
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
}

void mostrarArbolAnimales (nodoArbol * lito)
{
    if (lito != NULL)
    {
        mostrarAnimal(lito->dato);
        mostrarArbolAnimales(lito->izq);
        mostrarArbolAnimales(lito->der);
    }
}
void mostrarArreglo (celdaEspecie a [], int validos)
{
    for (int i=0; i<validos; i++)
    {
        printf ("\n-----------------------------------\n");
        printf ("\n-----------------------------------\n");
        printf ("ID ESPECIE: %d\n", a[i].idEspecie);
        printf ("ESPECIE:");
        puts(a[i].especie);
        mostrarArbolAnimales(a[i].arbolDeAnimales);
        printf ("\n-----------------------------------\n");
    }
}

int pasarAlArreglo (celdaEspecie arreglo [], int dimension)
{
    FILE * archi = fopen (aAnimales, "rb");
    registroArchivo a;
    int validos=0;
    fseek (archi,0,0);
    while (fread(&a,sizeof(registroArchivo),1,archi)>0)
    {
        validos = agregarCelda(arreglo,validos,a);
    }
    return validos;
}

void AlArchivo (nodoArbol * lito, int idEspecie, char nombreEspecie [], FILE * archi)
{
    registroArchivo a;
    if (lito != NULL)
    {
        AlArchivo(lito->der, idEspecie,nombreEspecie, archi);
        AlArchivo(lito->izq,idEspecie,nombreEspecie,archi);
        a = copiarAlRegistro(lito->dato,nombreEspecie,idEspecie);
        fwrite(&a,sizeof(registroArchivo),1,archi);
    }
}
void funcionMASgrande (nodoArbol * lito, int idEspecie, char nombreEspecie [], char archivo[])
{
    FILE * archi = fopen (archivo,"w+b");
    if(archi!=NULL)
    {
        AlArchivo(lito,idEspecie,nombreEspecie,archi);
        fclose(archi);
    }
    mostrarArchivo(archivo);

}
registroArchivo copiarAlRegistro (animal ito, char nombreEspecie [], int idEspecie)
{

    registroArchivo a;
    strcpy(a.especie,nombreEspecie);
    a.idEspecie=idEspecie;
    strcpy(a.animal,ito.nombreAnimal);
    a.cant=ito.cantidad;
    a.habitat = ito.habitat;
    return a;
}

void mostrarArchivo (char archivo [])
{
    FILE * archi = fopen (archivo,"rb");
    registroArchivo a;
    if(archi!=NULL)
    {
        while (fread (&a,sizeof(registroArchivo),1,archi)>0)
            mostrarRegistroArchivo (a);
        fclose(archi);
    }
}
void mostrarRegistroArchivo (registroArchivo a)
{
    printf ("ESPECIE:");
    puts (a.especie);
    printf ("ID ESPECIE: %d", a.idEspecie);
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
}

void pasajeAlosArchivos (celdaEspecie arreglo [], int validos)
{
    int pos;
    pos=buscarPosEspecie(arreglo,validos,"aves");
    funcionMASgrande(arreglo[pos].arbolDeAnimales, arreglo[pos].idEspecie,arreglo[pos].especie,archAves);
    pos=buscarPosEspecie(arreglo,validos,"peces");
    funcionMASgrande(arreglo[pos].arbolDeAnimales, arreglo[pos].idEspecie,arreglo[pos].especie,archPeces);
    pos=buscarPosEspecie(arreglo,validos,"mamiferos");
    funcionMASgrande(arreglo[pos].arbolDeAnimales, arreglo[pos].idEspecie,arreglo[pos].especie,archMamiferos);
    pos=buscarPosEspecie(arreglo,validos,"reptiles");
    funcionMASgrande(arreglo[pos].arbolDeAnimales, arreglo[pos].idEspecie,arreglo[pos].especie,archReptiles);
}
