#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
///Porcentaje de deudores en mes "x".
///buscar jugador por ID en arbol.
///pasar todos a un arbol, y despues dividirlo en el arreglo de listas.

typedef struct
{
    int id;
    char nombreYapellido[30];
    char dni[9];
    char direccion[20];
    char telefono[20];
    char deporte[15]; ///que ocupa jugando al deporte
    char categoria[5]; ///anio de nacimiento
    char cuota[15]; /// ultimo mes pago
    int eliminado; ///1 eliminado, 0 listo para usar.
} jugador;

typedef struct nodo
{
    jugador player;
    struct nodo * sig;
} nodo;

typedef struct
{
    char deporte [20];
    struct nodo * lista;
} celda;

nodo * jugInicLista(); ///inicializa la lista en NULO
nodo * jugAgregarPpio(nodo*,nodo*); ///Agrega al principio de la lista un nodo
jugador jugCrearJugador (char[]); ///Pregunta los datos del jugador y devuelve un jugador
nodo * jugCrearNodoNuevo (char []); ///crea al jugador, lo guarda en el archivo y crea el nodo con la estructura
int jugID(char []); ///Abre el archivo y devuelve el id que le corresponde al nuevo jugador
void jugCargarArchivo (char [], nodo*); ///carga al archivo toda una lista de jugadores
int jugAgregarDeporte (celda [], char [],int ); ///agrega al final del arreglo el nuevo deporte
int jugPosDeporte (celda [], char [], int ) ;///busca en el arreglo la posicion del deporte deseado
int jugAltaDeporte (celda [], char [], char [],int );///agrega un deporte al arreglo de celdas, devuelve validos del arreglo
void mostrarJugador (jugador); ///muestra UN jugador
void jugMostrarArchivo(char[]); ///muestra los jugadores guardados en el archivo
void jugAlArchivo (char[],jugador); ///carga al archivo UN unico jugador
void jugMesCuota (char[]); ///devuelve el mes que paga el jugador
void mostrarArreglo (celda [], int );
void mostrarLista (nodo * );
void mostrarJugEliminados (celda [], int);
void mostrarListaEliminados(nodo*);
jugador buscarJugadorNombreArreglo (celda  [],int, char  []);
jugador buscarJugadorNombreLista (nodo *, char  []);
void jugadorAlta (celda  [],int);
void mostrarListaHabilitados (nodo * );
void mostrarJugadoresHabilitados (celda  [], int );
void jugadorBaja (celda  [], int );
int inicioProgramaJugadores (celda  [], int, char []);
int inicioProgramaDeportes (celda [],char []);
void mostrarArchivo(char[]);
nodo * crearNodoJugador (jugador);
int deporteRepetido(char [], char []); ///Que si existe una celda con el deporte del nuevo jugador




int main()
{
    char jugadores[] = "jugadores.bin";
    int validosDeporte=0, validos=0;
    //char deporte[20];
    celda deportes[30];
    agregarJugadoresArchivo(jugadores);  ///NO FUNCIONA
    mostrarArchivo(jugadores);
    validosDeporte = inicioProgramaDeportes(deportes,jugadores);
    validos=inicioProgramaJugadores(deportes,validosDeporte,jugadores);
    printf ("------------------------\n");
    system("pause");
    system("cls");
    mostrarArreglo(deportes,validos);


    return 0;
}

nodo * jugInicLista ()
{
    return NULL;
}
nodo * jugAgregarPpio(nodo * lista, nodo * nn)
{
    if (lista != NULL)
        nn->sig=lista;
    lista=nn;
    return lista;
}
int jugID(char archivo[])
{
    jugador a;
    int id;
    FILE * archi = fopen (archivo,"rb");
    if (archi == NULL)
        id=0;
    else
    {
        fseek(archi,sizeof(jugador)*(-1),2);
        fread(&a,sizeof(jugador),1,archi);
        id=a.id+1;
    }
    fclose(archi);
    return id;
}
jugador jugCrearJugador(char archivo[])
{
    jugador a;
    char pago = 's';
    a.id = jugID(archivo);
    printf ("Nombre y apellido del jugador \n");
    fflush(stdin);
    gets(a.nombreYapellido);
    printf ("Direccion \n");
    fflush(stdin);
    gets (a.direccion);
    printf ("Telefono de contacto \n");
    fflush(stdin);
    gets(a.telefono);
    printf ("DNI \n");
    fflush(stdin);
    gets(a.dni);
    printf ("Categoria:\n");
    fflush(stdin);
    gets(a.categoria);
    printf ("Deporte \n");
    fflush(stdin);
    gets(a.deporte);
    printf ("Paga la cuota ahora? S/N \n");
    scanf("%c", &pago);
    if (pago == 's')
    {
        jugMesCuota(a.cuota);
    }
    else
        strcpy(a.cuota,"Sin Pagar");
    a.eliminado=0;

    return a;
}

nodo * jugCrearNodoNuevo(char archivo [])
{
    jugador a = jugCrearJugador(archivo);
    jugAlArchivo(archivo,a);
    nodo * nn = (nodo*)malloc (sizeof(nodo));
    nn->player=a;
    nn->sig = NULL;
    return nn;
}

void jugCargarArchivo(char archivo[], nodo * lista)
{
    jugador a;
    nodo * seg=lista;
    FILE * archi = fopen(archivo,"ab");
    while(seg!=NULL)
    {
        a=seg->player;
        fwrite(&a,sizeof(jugador),1,archi);
        seg=seg->sig;
    }
    fclose(archi);
}

int jugAltaDeporte (celda deportes[], char archivo[], char deporte[],int validos)
{
    int pos;

    nodo * aux = jugCrearNodoNuevo(archivo);
    pos=jugPosDeporte (deportes, deporte, validos);
    if (pos==-1)
    {
        validos=jugAgregarDeporte (deportes,deporte,validos);
        pos=validos-1;
    }
    deportes[pos].lista=jugAgregarPpio(deportes[pos].lista,aux);
    return validos;
}
int jugPosDeporte (celda deportes[], char deporte[], int validos)
{
    int pos=-1, i=0;
    while (i<validos)
    {
        if (strcmpi(deportes[i].deporte,deporte)==0)
            pos=i;
        i++;
    }
    return pos;
}
int jugAgregarDeporte (celda deportes[], char deporte[],int validos)
{
    strcpy(deportes[validos].deporte,deporte);
    deportes[validos].lista=jugInicLista();
    validos++;
    return validos;
}
void mostrarJugador(jugador a)
{
    printf ("\nID JUGADOR: %d\n",a.id);
    printf ("NOMBRE Y APELLIDO:");
    puts(a.nombreYapellido);
    printf ("DNI:");
    puts(a.dni);
    printf ("CATEGORIA:");
    puts(a.categoria);
    printf ("DIRECCION:");
    puts(a.direccion);
    printf ("TELEFONO:");
    puts(a.telefono);
    printf("DEPORTE:");
    puts(a.deporte);
    printf("ULTIMO MES PAGO:");
    puts(a.cuota);
}
void jugMostrarArchivo(char archivo[])
{
    FILE * archi = fopen(archivo,"rb");
    jugador a;

    if (archi!=NULL)
    {
        while (fread(&a,sizeof(jugador),1,archi)>0)
        {
            mostrarJugador(a);
        }
    }
}

void jugAlArchivo(char archivo[], jugador a)
{
    FILE * archi = fopen (archivo,"ab");
    fwrite(&a,sizeof(jugador),1,archi);
    fclose(archi);
}

void jugMesCuota (char mesCuota[])
{
    time_t sisTime;
    struct tm * tiempo;
    int mes;

    time(&sisTime);
    tiempo=localtime(&sisTime);
    mes=tiempo->tm_mon;

    switch (mes)
    {
    case 0:
        strcpy(mesCuota,"Enero");
        break;
    case 1:
        strcpy(mesCuota,"Febrero");
        break;
    case 2:
        strcpy(mesCuota,"Marzo");
        break;
    case 3:
        strcpy(mesCuota,"Abril");
        break;
    case 4:
        strcpy(mesCuota,"Mayo");
        break;
    case 5:
        strcpy(mesCuota,"Junio");
        break;
    case 6:
        strcpy(mesCuota,"Julio");
        break;
    case 7:
        strcpy(mesCuota,"Agosto");
        break;
    case 8:
        strcpy(mesCuota,"Septiembre");
        break;
    case 9:
        strcpy(mesCuota,"Octubre");
        break;
    case 10:
        strcpy(mesCuota,"Noviembre");
        break;
    case 11:
        strcpy(mesCuota,"Diciembre");
        break;
    }
}

void mostrarArreglo (celda deportes[], int validos)
{
    for (int i=0; i<validos; i++)
    {
        printf ("DEPORTE: \t");
        puts(deportes[i].deporte);
        mostrarLista(deportes[i].lista);
        printf ("---------------------------\n");
    }
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

void mostrarJugEliminados(celda deportes [], int validos)
{
    printf ("JUGADORES ELIMINADOS\n\n");
    for (int i=0; i<validos; i++)
    {
        mostrarListaEliminados(deportes[i].lista);
    }
}
void mostrarListaEliminados(nodo * lista)
{
    nodo * seg = lista;
    while (seg != NULL)
    {
        if (seg->player.eliminado == 1)
            mostrarJugador(seg->player);
        seg=seg->sig;
    }
}
void jugadorAlta (celda deportes [],int validos)
{
    char nombre [20];
    jugador a;
    mostrarJugEliminados(deportes,validos);
    printf ("Ingrese nombre de jugador a dar de alta\n");
    fflush(stdin);
    gets(nombre);
    a = buscarJugadorNombreArreglo (deportes,validos, nombre);
    a.eliminado=0;
    printf ("El jugador %s ha sido dado de alta \n", a.nombreYapellido);

}

jugador buscarJugadorNombreArreglo (celda deportes[],int validos, char buscado [])
{
    jugador a;
    int i=0,flag=0;
    while (i<validos && flag == 0)
        a=buscarJugadorNombreLista(deportes[i].lista,buscado);
    return a;

}

jugador buscarJugadorNombreLista (nodo * lista, char buscado [])
{
    nodo * seg = lista;
    jugador a;
    while (seg != NULL)
    {
        if (strcmpi (seg->player.nombreYapellido,buscado)==0)
            a=seg->player;
        seg = seg->sig;
    }
    return a;
}

void jugadorBaja (celda deportes [], int validos)
{
    char nombre [20];
    jugador a;
    mostrarJugadoresHabilitados(deportes,validos);
    printf ("Ingrese nombre de jugador a dar de baja\n");
    fflush(stdin);
    gets(nombre);
    a = buscarJugadorNombreArreglo (deportes,validos, nombre);
    a.eliminado=1;
    printf ("El jugador %s ha sido dado de baja \n", a.nombreYapellido);


}

void mostrarJugadoresHabilitados (celda deportes [], int validos)
{
    printf ("JUGADORES HABILITADOS\n\n");
    for (int i=0; i<validos; i++)
    {
        mostrarListaHabilitados(deportes[i].lista);
    }
}
void mostrarListaHabilitados (nodo * lista)
{
    nodo * seg = lista;
    while (seg != NULL)
    {
        if (seg->player.eliminado == 0)
            mostrarJugador(seg->player);
        seg=seg->sig;
    }
}

int inicioProgramaDeportes (celda deportes[],char archivo[])
{
    FILE * archi = fopen (archivo,"rb");
    jugador a;
    int i=0, flag=0;
    while (fread(&a,sizeof(char[20]),1,archi)>0)
    {
        flag = deporteRepetido(archivo,a.deporte);
        if (flag == 0)
        {
            strcpy(deportes[i].deporte,a.deporte);
            i++;
        }
    }
    fclose(archi);
    return i;
}
int inicioProgramaJugadores (celda deportes [], int validosDeporte, char archivo[])
{
    jugador a;
    int pos=0;
    nodo * jug;
    FILE * archi = fopen (archivo,"rb");
    while (fread(&a,sizeof(jugador),1,archi)>0)
    {
        pos = jugPosDeporte(deportes,a.deporte,validosDeporte);
        jug = crearNodoJugador(a);
        deportes[pos].lista=jugAgregarPpio(deportes[pos].lista,jug);

    }
    fclose(archi);
    return validosDeporte;
}
void mostrarArchivo (char jugadores [])
{
    FILE * archi = fopen (jugadores,"rb");
    jugador a;
    while (fread(&a,sizeof(jugador),1,archi)>0)
    {
        mostrarJugador(a);
    }
}
nodo * crearNodoJugador (jugador a)
{
    nodo * nn = (nodo*)malloc(sizeof(nodo));
    nn->player=a;
    nn->sig=NULL;
    return nn;
}
int deporteRepetido(char archivo[], char deporte[]) ///Que si existe una celda con el deporte del nuevo jugador
{

    jugador a;
    int i=0;
    FILE * archi =fopen(archivo,"rb");
    while(fread(&a,sizeof(jugador),1,archi) >0 && i==0)
    {
        if(strcmp(a.deporte,deporte)==0)
        {
            i=1;
        }
    }
    fclose(archi);
    return i;
}

void agregarJugadoresArchivo (char archivo [])
{
    FILE * archi = fopen(archivo,"ab");
    jugador a;
    char seguir = 's';
    while (seguir == 's')
    {
        a=jugCrearJugador(archivo);
        fwrite(&a,sizeof(jugador),1,archi);

        printf ("Ingresa otro jugador? \n");
        fflush(stdin);
        scanf("%c",&seguir);
    }
    fclose(archi);
}
