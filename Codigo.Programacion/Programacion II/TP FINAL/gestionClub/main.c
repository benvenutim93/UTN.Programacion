#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char nombre [20];
    char dni [9];
    char posicion [20];
    int eliminado; /// 0 activo - 1 eliminado
}jugador;

typedef struct nodo
{
    jugador player;
    struct nodo * sig;
}nodo;

typedef struct
{
    char deporte [20];
    struct nodo * lista;
}celda;
///LISTA
nodo * inicLista ();
nodo * agregarDni (nodo * , nodo * );
void mostrarLista (nodo * );

///JUGADOR
jugador cargarJugador(int, char[],char[],char[]);
jugador buscarJugador (nodo * , char []);
jugador eliminarJugador (jugador );
void mostrarJugador (jugador );

///CELDAS
int ingresarDatos (celda [], int);
void mostrarArreglo (celda [], int );


int main()
{
    char jugadores[] = "jugadores.bin";
    char deportes[] = "deportes.bin";
    return 0;
}
///----------------------------------- L I S T A S --------------------------------------------------
nodo * inicLista()
{
    return NULL;
}
nodo * agregarDni (nodo * lista, nodo * nn)
{
    if (lista != NULL)
        nn->sig=lista;
    lista=nn;
    return lista;
}
void mostrarLista (nodo * lista)
{
    nodo * seg = lista;
    while (seg != NULL)
    {
        mostrarJugador(seg->player);
        seg=seg->sig;
    }
}

/// ----------------------------- J U G A D O R -------------------------------------------------------
jugador cargarJugador(int id, char nombre[], char dni [], char posicion [])
{
    jugador a;
    a.id=id;
    strcpy(a.nombre,nombre);
    strcpy(a.dni,dni);
    strcpy (a.posicion,posicion);
    a.eliminado=0;
    return a;
}
jugador buscarJugador (nodo * lista, char nombre [])
{
    jugador a;
    nodo * seg = lista;
    while (seg != NULL)
    {
        if (strcmpi (nombre, lista->player.nombre)==0)
            a=lista->player;
        seg=seg->sig;
    }
    return a;
}
jugador eliminarJugador (jugador borrar)
{
    borrar.eliminado=1;
    return borrar;
}

void mostrarJugador (jugador a)
{
    printf ("ID JUGADOR: %d\n", a.id);
    printf ("NOMBRE JUGADOR:");
    puts(a.nombre);
    printf ("POSICION JUGADOR:");
    puts (a.posicion);
    printf ("DNI JUGADOR:");
    puts(a.dni);
}
///------------------------------------------- C E L D A S -----------------------------------------------
void mostrarArreglo (celda deportes[], int validos)
{
    int i=0;
    while (i<validos)
    {
        printf ("DEPORTE");
        puts (deportes->deporte);
        mostrarLista(deportes->lista);
        i++;
    }
}
int ingresarDatos(celda deportes[], int dimension)
{

}
