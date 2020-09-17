#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int idUsuario;
    char nombreUsuario[30];
    char pass[20];
    int anioNacimiento;
    char genero;
    char pais[20];
    int playlist[50]; //Guarda los id de las canciones.
    int cantidad; // Es el válidos de la playlist.
    int eliminado;   // indica 1 o 0 si el cliente fue eliminado
} stUsuario;

typedef struct
{
    int idCancion;
    char titulo[30];
    char artista[20];
    int duracion;
    char album[20];
    int anio;
    char genero[20];
    char comentario[100];
    int eliminado;  // indica 1 o 0 si la canción fue eliminada
} stCancion;

void carga_usuario(stUsuario[], int);
int variosUsuarios(stUsuario[]);
void cancion(stCancion[],int);
int variasCanciones(stCancion[]);
void registrarUsuario(stUsuario[]);

int main()
{

    int dimension = 100, usuariosValidos =0,cancionesValidas=0;
    stUsuario a [dimension];
    stCancion b[dimension];

    usuariosValidos = variosUsuarios(a);
    cancionesValidas = variasCanciones(b);




    return 0;
}

void carga_usuario(stUsuario a[], int i)  //Carga un usuario
{

    a[i].idUsuario = i;

    printf ("Nombre:  \n");
    fflush (stdin);
    scanf( "%s", &a[i].nombreUsuario);

    printf ("Contrasenia \n");
    fflush(stdin);
    scanf ("%s", &a[i].pass);

    printf ("Anio de nacimiento \n");
    scanf ("%d", &a[i].anioNacimiento);

    printf ("Genero f/m: \n");
    fflush(stdin);
    scanf ("%c", &a[i].genero);

    printf ("Pais de origen: \n");
    fflush(stdin);
    scanf ("%s", &a[i].pais);

}

int variosUsuarios(stUsuario a[])  //Carga varios usuarios
{
    int i=0, op = 1;


    while (op == 1)
    {
    carga_usuario(a, i);
    i++;

    scanf ("%d", &op);
    }
    return i;
}

void cancion(stCancion b[],int pos)     //Carga una cancion
{
    b[pos].idCancion = pos;

    printf("Titulo:\n");
    fflush(stdin);
    scanf("%s",&b[pos].titulo);

    printf("Artista:\n");
    fflush(stdin);
    scanf("%s",&b[pos].artista);

    printf("Duracion (En segundos):\n");
    scanf("%d",&b[pos].duracion);

    printf("Album:\n");
    fflush(stdin);
    scanf("%s",&b[pos].album);

    printf("Anio de la cancion:\n");
    scanf("%d",&b[pos].anio);

    printf("Genero:\n");
    fflush(stdin);
    scanf("%s",&b[pos].genero);

}

int variasCanciones(stCancion b[])      //Carga varias canciones
{
    int i=0,op=1;

    while(op == 1)
    {
        cancion(b,i);
        i++;

        scanf("%d",&op);
    }
    return i;
}


