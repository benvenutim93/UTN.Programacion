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

stUsuario registrarUnUsuario();
void guardarUsuario(char[]);
stCancion cargarCancion ();
void guardarCancion (char[]);
void guardarVariasCanciones (char[]);
void mostrarArchivoUsuarios(char[]);
void mostrarArchivoCanciones(char[]);
int loguearUsuario (char [],char[]);
void mostrarUnUsuario(char[],char[]);
void bajaCancion (char []);
void mostrarUnaCancion(stCancion);
void mostrarCancionesEliminadas(char []);
stCancion buscarCancion(char []);

int main()
{
    char usuario[] = "usuario.data";
    char cancion[] = "cancion.data";
    char admin []  = "admin.data";
    //char nombreUser [20];
    guardarCancion(cancion);
    mostrarArchivoCanciones(cancion);
    bajaCancion(cancion);
    mostrarCancionesEliminadas(cancion);


    return 0;
}
stUsuario registrarUnUsuario(char usuario [])  ///registrar un nuevo usuario
{
    int i=0;
    stUsuario a;
    FILE *archi = fopen(usuario, "rb");
    if (archi == NULL)
            i=0;
    else if (archi !=NULL)
    {
        fseek (archi, sizeof (stUsuario)*(-1), 2);
        fread(&a,sizeof(stUsuario),1,archi);
        i=a.idUsuario+1;
    }
    a.idUsuario = i;

    printf ("Nombre:  \n");
    fflush (stdin);
    gets(a.nombreUsuario);

    printf ("Contrasenia \n");
    fflush(stdin);
    gets(a.pass);

    printf ("Anio de nacimiento \n");
    scanf ("%d", &a.anioNacimiento);

    printf ("Genero f/m: \n");
    fflush(stdin);
    scanf ("%c", &a.genero);

    printf ("Pais de origen: \n");
    fflush(stdin);
    gets(a.pais);

    printf ("Eliminado: (0 = no, 1 = eliminado \n");
    scanf ("%d", &a.eliminado);

    return a;
}
void guardarUsuario(char usuario[]) ///guarda el usuario en el archivo
{
    stUsuario a;

    FILE * archi = fopen(usuario,"ab");
    a = registrarUnUsuario(usuario);
    fwrite(&a,sizeof(stUsuario),1,archi);
    fclose(archi);
}

stCancion cargarCancion(char cancion [])           ///Ingresa los datos de una cancion y lo guarda en una estructura
{
    int i=0;
    stCancion b;
    FILE *archi = fopen(cancion, "rb");
    if (archi == NULL)
            i=0;
    else if (archi !=NULL)
    {
        fseek (archi, sizeof (stCancion)*(-1), 2);
        fread(&b,sizeof(stCancion),1,archi);
        i=b.idCancion+1;
    }

    b.idCancion = i;

    printf("Titulo:\n");
    fflush(stdin);
    gets(b.titulo);

    printf("Artista:\n");
    fflush(stdin);
    gets(b.artista);

    printf("Duracion (En segundos):\n");
    scanf("%d",&b.duracion);

    printf("Album:\n");
    fflush(stdin);
    gets(b.album);

    printf("Anio de la cancion:\n");
    scanf("%d",&b.anio);

    printf("Genero:\n");
    fflush(stdin);
    gets(b.genero);

    printf ("Comentario: \n");
    gets (b.comentario);

    printf ("Eliminar : (0 = no, 1 = eliminado)\n");
    scanf("%d", &b.eliminado);

    return b;
}

void guardarCancion(char cancion [])  ///Guarda una sola cancion en el archivo
{
    stCancion c;

    FILE * archi = fopen (cancion, "ab");
    c = cargarCancion(cancion);
    fwrite(&c, sizeof(stCancion),1,archi);
    fclose(archi);
}

void guardarVariasCanciones (char cancion [])  ///Guarda varias canciones en el archivo
{
    char seguir = 's';
    while (seguir == 's')
    {
        guardarCancion(cancion);
        printf ("Desea seguir cargando canciones? \n");
        fflush(stdin);
        scanf ("%c", &seguir);
    }
}

void mostrarArchivoUsuarios (char usuario [])
{
    stUsuario a;
    FILE * archi = fopen (usuario, "rb");
    while (fread (&a, sizeof(stUsuario),1,archi)>0)
    {
        printf ("\nNombre:");
        puts(a.nombreUsuario);
        printf ("Contrasenia: %s\n", a.pass);
        printf ("Anio de nacimiento: %d\n", a.anioNacimiento);
        printf ("Genero: %c\n", a.genero);
        printf ("Pais: %s\n", a.pais);

    }
    fclose(archi);
}

void mostrarArchivoCanciones (char cancion [])
{
    stCancion c;
    FILE * archi = fopen (cancion, "rb");
    while (fread (&c, sizeof(stCancion),1,archi)>0)
    {
        printf ("ID Cancion %d", c.idCancion);
        printf("\nTitulo:");
        puts (c.titulo);
        printf("Artista:");
        puts (c.artista);
        printf ("Duracion en segundos: %d \n", c.duracion);
        printf ("Album:");
        puts (c.album);
        printf ("Anio: %d \n", c.anio);
        printf ("Genero:");
        puts(c.genero);
        printf ("Comentario:");
        puts (c.comentario);
    }
}

int loguearUsuario (char usuario [], char nombreUser [])   ///loguea un usuario
{
    FILE * archi = fopen(usuario,"rb");
    stUsuario b;
    char contrasenia[20];
    int flag=0;

    printf("Nombre de usuario:\n");
    fflush(stdin);
    gets(nombreUser);
    printf("Contrasenia\n");
    fflush(stdin);
    gets(contrasenia);

    if (archi!=NULL)
    {
        while(fread(&b,sizeof(stUsuario),1,archi)>0 && flag== 0)
        {
            if(strcmp(b.pass,contrasenia)==0 && strcmp(b.nombreUsuario,nombreUser)==0)
            {
                printf("Bienvenido %s\n",b.nombreUsuario);
                flag=1;
            }
            else if(strcmp(b.nombreUsuario,nombreUser)==0 && strcmp(b.pass,contrasenia)!=0)
            {
                printf("La contrasenia es incorrecta \n");
                flag=2;
            }

        }
        if (flag == 0)
        {
            printf("Los datos ingresados son invalidos\n");
        }
        fclose(archi);
    }
    return flag;
}

void mostrarUnUsuario (char usuario[],char nombreUser[])
{
    stUsuario a;

    FILE * archi = fopen(usuario,"rb");

    if(archi!=NULL)
    {
        while((fread(&a,sizeof(stUsuario),1,archi))>0)
        {
            if(strcmp(a.nombreUsuario,nombreUser)==0)
            {
                printf ("ID Usuario %d", a.idUsuario);
                printf ("\nNombre:");
                puts(a.nombreUsuario);
                printf ("Contrasenia: %s\n", a.pass);
                printf ("Anio de nacimiento: %d\n", a.anioNacimiento);
                printf ("Genero: %c\n", a.genero);
                printf ("Pais: %s\n", a.pais);
            }
        }
        fclose(archi);
    }
}
stCancion buscarCancion (char cancion []) ///MARI
{
    char titulo [20];
    stCancion a;
    FILE * archi = fopen (cancion, "rb");

    printf ("Cual es el titulo de la canción a eliminar? \n");
    fflush (stdin);
    scanf (" %s", titulo);

    while (fread(&a,sizeof(stCancion),1,archi)>0 && strcmp(a.titulo,titulo)!=0)
    {
    }

    fclose (archi);
    return a;


}

void bajaCancion(char cancion[]) ///MARI
{
    stCancion a;
    FILE * archi = fopen (cancion, "a+b");

    a = buscarCancion(cancion);
    a.eliminado = 1;
}
void mostrarUnaCancion (stCancion a)
{
    printf ("idCancion: \t", a.idCancion);
    printf ("\nTitulo: \t", a.titulo);
    printf ("\nArtista: \t", a.artista);
    printf ("\nDuracion: \t", a.duracion);
    printf ("\nAlbum: \t", a.album);
    printf ("\nAnio: \t", a.anio);
    printf ("\nGenero: \t", a.genero);
    printf ("\nComentario: \t", a.comentario);
}
void mostrarCancionesEliminadas (char cancion []) ///MARI
{
    FILE * archi = fopen (cancion, "rb");
    stCancion a;
    while (fread(&a, sizeof(stCancion),1,archi)>0 && a.eliminado == 1)
    {
        mostrarUnaCancion(a);
    }
    fclose(archi);

}
