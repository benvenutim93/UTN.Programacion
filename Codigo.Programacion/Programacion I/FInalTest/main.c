#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>



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
} stUsuarioadmin;
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
    char generoFav[50];
} stUsuario;
///MENU
void imprimirCabecera(char cabecera[]);
void imprimirOpcionesSubMenuAdmin();
void imprimirOpcionesMenu1();
int ingresarOpcion();
void switchSubMenu1();
int switchMenu1();
void iniciarMenu(char[], char[], char[]);
void imprimirOpcionesSubMenuAdminUsuarios();
void imprimirOpcionesSubMenuAdminCanciones();
void imprimirOpcionesSubMenuUsuario();
void switchUsuario(char[], char[], char[], int);
void switchAdminUsuarios(char[], char[], char[]);
void switchAdmin(char[], char[], char[]);
void switchAdminCanciones(char[], char[], char[]);
///ADMIN
stUsuarioadmin CrearAdmin(char[]);
void CargarAdmin(char[]);
void MostrarAdmin2(char []);
void MostrarAdmin(stUsuarioadmin);
int loguearUsuarioadmin (char []);
void BajaUsuario(char[]);
void AltaUsuario(char[]);
void mostrarArchivoUsuariosAlta(char[]);
void mostrarArchivoUsuariosBaja(char[]);
void ModificarUsuario(char []);
///CANCION
stCancion cargarCancion (char []);
void guardarCancion (char[]);
void guardarVariasCanciones (char[]);
void mostrarArchivoCanciones(char[]);
void bajaCancion (char []);
void mostrarUnaCancion(stCancion);
void mostrarCancionesEliminadas(char []);
int cargarArray (stCancion[],char[]);
int encontrarMenor (stCancion[], int, int);
void ordenarSeleccion (stCancion[], int);
void mostrarArray (stCancion[], int);
void ordenarInsercion (stCancion [], int);
void insertar (stCancion[], int, stCancion);
stCancion modificarUnaCancion (stCancion );
void modificarCancion (char[]);
void consultaCancion(char []);
void RecomendarAleatoriaCancion(char[],char [], int);
int cantidadRegistrosCancion (char[]);
void mostrarArchivoCancionesBaja (char []);
int cancionRepetida(char [],stCancion );
///USUARIO
stUsuario ingresarUnUsuario (char[]);
void mostrarTodosLosUsuarios(char[]);
void ponerEnArchivo(char[]);
int loguear(char[]);
int repetido(char[], stUsuario);
int cargarArreglo (stUsuario[],char[]);
int encontrarMenorUsuario (stUsuario[],int,int);
void ordenarSeleccionUsuario (stUsuario[],int);
void mostrarArreglo (stUsuario[],int);
void mostrarUnUsuario(stUsuario);
void ordenarArchivo(char[],stUsuario[],int);
void ConsultarUsuario(char []);
void mostrarPlaylist(char [],int,char []);
void variasCanciones(char [],char [],int );
void playlist(char [],char [],int );
stCancion ElegirCancion(char []);
void mostrarUsuarioPos (char[], int);
void ordenarPlaylist (char [],int,stCancion [],char []);
stUsuario User(char [],int);
void vectorPlaylist(stUsuario,stCancion[],char[]);
void ordenarSeleccionCancion(stCancion[],int);
void pasarAplaylist(char[],stCancion[],stUsuario,char[],int);
int encontrarMenorCancion (stCancion [], int, int );
void AltaCancion(char []);



int main()
{

    char cancion [] = "cancion.data";
    char admin [] = "admin.bin";
    char usuario [] = "usuario.data";
    system("COLOR 0A");
    iniciarMenu(admin,cancion,usuario);

    return 0;
}


///MENU
void imprimirCabecera(char cabecera[])
{
    int i;
    printf("%c", 201);
    for(i=0; i<50; i++)
    {
        printf("%c",205);
    }
    printf("%c\n", 187);
    printf("%c%32s%19c\n", 186,cabecera,186);
    printf("%c", 200);
    for(i=0; i<50; i++)
    {
        printf("%c",205);
    }
    printf("%c", 188);
}
void iniciarMenu(char admin[], char cancion[], char usuario[] )
{
    int salida;
    do
    {
        system("cls");
        imprimirCabecera("MI MENU PRINCIPAL");
        printf("\n\n");
        imprimirOpcionesMenu1();
        salida = switchMenu1(admin,cancion,usuario);
    }
    while(salida != 0);
}
void imprimirOpcionesMenu1()
{
    printf("\n1. Admin");
    printf("\n2. Usuario");
    printf("\n3. Registrarse");
    printf("\n0. Salir\n");
}
void imprimirOpcionesSubMenuAdmin()
{
    printf("\n1. Administracion de usuarios");
    printf("\n2. Administracion de canciones");
    printf("\n3. Crear administrador");
    printf("\n0. Salir\n");
}
void imprimirOpcionesSubMenuAdminUsuarios()
{
    printf("\n1. Alta de usuarios");
    printf("\n2. Baja de usuarios");
    printf("\n3. Modificacion de usuarios");
    printf("\n4. Consulta de usuarios");
    printf("\n5. Listado de usuarios");
    printf("\n0. Salir\n");
}
void imprimirOpcionesSubMenuAdminCanciones()
{
    printf("\n1. Alta de canciones");
    printf("\n2. Baja de canciones");
    printf("\n3. Modificacion de canciones");
    printf("\n4. Consulta de canciones");
    printf("\n5. Listado de canciones (por titulo)");
    printf("\n6. Listado de canciones (por genero)");
    printf("\n7. Listado de canciones (por ID)");
    printf("\n8. Ingresar cancion en sistema");
    printf("\n0. Salir\n");
}
void imprimirOpcionesSubMenuUsuario()
{
    printf("\n1. Ver perfil");
    printf("\n2. Mostrar playlist");
    printf("\n3. Escuchar cancion");
    printf("\n4. Canciones recomendadas");
    printf("\n5. Listado de canciones");
    printf("\n0. Salir\n");
}
int ingresarOpcion()
{
    int opcion;
    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%i", &opcion);
    return opcion;
}
int switchMenu1(char admin[], char cancion[], char usuario[])
{
    int op, flag, pos;
    do
    {
        op = ingresarOpcion();
        switch(op)
        {
        case 0:
            printf("Saliendo del sistema\n");
            break;
        case 1:
            system("cls");
            imprimirCabecera("ADMIN");
            printf("\n\n");
            flag = loguearUsuarioadmin(admin);
            system ("pause");
            system ("cls");
            if (flag ==1)
            {
                imprimirCabecera("ADMIN");
                imprimirOpcionesSubMenuAdmin();
                switchSubMenu1(admin,cancion,usuario);
            }
            else
            {
                imprimirCabecera("MI MENU PRINCIPAL");
                printf("\n\n");
                imprimirOpcionesMenu1();
                switchMenu1(admin, cancion, usuario);
            }
            break;
        case 2:
            system("cls");
            imprimirCabecera("USUARIO");
            printf("\n\n");
            pos =loguear(usuario);
            system("pause");
            if (pos < 0)
            {
                system("cls");
                imprimirCabecera("MI MENU PRINCIPAL");
                printf ("\n\n");
                imprimirOpcionesMenu1();
                switchMenu1(admin,cancion,usuario);
            }
            else
            {
                system("cls");
                switchUsuario(admin,cancion,usuario, pos);
            }
            break;
        case 3:
            system("cls");
            imprimirCabecera("REGISTRARSE");
            printf("\n\n");
            ponerEnArchivo(usuario);
            system ("pause");
            system("cls");
            imprimirCabecera("MI MENU PRINCIPAL");
            printf("\n\n");
            imprimirOpcionesMenu1();
            switchMenu1(admin,cancion,usuario);
            break;

        }
    }
    while(op != 0);
    return op;
}
void switchSubMenu1(char admin[], char cancion[], char usuario[])  ///Menu del admin
{
    int op;
    do
    {
        op = ingresarOpcion();
        switch(op)
        {
        case 0:
            system("cls");
            imprimirCabecera("MI MENU PRINCIPAL");
            printf ("\n\n");
            imprimirOpcionesMenu1();
            switchMenu1(admin,cancion,usuario);
            break;

        case 1:
            system("cls");
            imprimirCabecera("ADMINISTRACION DE USUARIOS");
            printf("\n\n");
            imprimirOpcionesSubMenuAdminUsuarios();
            switchAdminUsuarios(admin,cancion,usuario);
            break;
        case 2:
            system("cls");
            imprimirCabecera("ADMINISTRACION DE CANCIONES");
            printf("\n\n");
            imprimirOpcionesSubMenuAdminCanciones();
            switchAdminCanciones(admin,cancion,usuario);
            break;
        case 3:
            system("cls");
            imprimirCabecera("CREAR ADMIN");
            printf("\n\n");
            CargarAdmin(admin);
            system("pause");
            imprimirOpcionesSubMenuAdmin();
            switchSubMenu1(admin,cancion,usuario);
            break;
        default:
            printf("Opcion incorrecta\n");
        }
    }
    while(op != 0);
}

void switchUsuario (char admin[], char cancion[], char usuario[], int pos)    /// Menu del usuario
{
    int op;
    stCancion z[100];


        imprimirCabecera("USUARIO");
        printf("\n\n");
        imprimirOpcionesSubMenuUsuario();
        op = ingresarOpcion();
        switch (op)
        {
        case 0:
            system("cls");
            iniciarMenu(admin,cancion,usuario);
            break;
        case 1:
            system("cls");
            imprimirCabecera("VER PERFIL");
            printf("\n\n");
            mostrarUsuarioPos (usuario, pos);
            system ("pause");
            system("cls");
            switchUsuario(admin,cancion,usuario, pos);

            break;
        case 2:
            system("cls");
            imprimirCabecera("MOSTRAR PLAYLIST");
            printf("\n\n");
            ordenarPlaylist(usuario,pos,z,cancion);
            system ("pause");
            system("cls");
            switchUsuario(admin,cancion,usuario, pos);
            break;
        case 3:
            system("cls");
            imprimirCabecera("ESCUCHAR CANCION");
            printf("\n\n");
            printf ("Canciones disponibles \n");
            mostrarArchivoCanciones(cancion);
            playlist(usuario,cancion,pos); ///AGREGA ID DE LAS CANCIONES A LA VARIABLE PLAYLIST DE LA ESTRUCTURA Y LO ESCRIBE EN EL ARCHIVO
            system ("pause");
            system("cls");
            switchUsuario(admin,cancion,usuario,pos);
            break;
        case 4:
            system("cls");
            imprimirCabecera("CANCIONES RECOMENDADAS");
            printf("\n\n");
            RecomendarAleatoriaCancion(cancion, usuario, pos);
            system ("pause");
            system("cls");
            switchUsuario(admin,cancion,usuario, pos);
            break;
        case 5:
            system("cls");
            imprimirCabecera("LISTADO DE CANCIONES");
            printf("\n\n");
            mostrarArchivoCanciones(cancion);
            system ("pause");
            system("cls");
            switchUsuario(admin,cancion,usuario, pos);
            break;
        default:
            printf ("Opcion no valida\n");
            system ("pause");
            system("cls");
            imprimirCabecera("USUARIO");
            printf("\n\n");
            imprimirOpcionesSubMenuUsuario();
            system("cls");
            switchUsuario(admin,cancion,usuario,pos);
            break;
        }
    }


void switchAdminUsuarios (char admin[], char cancion[], char usuario[])
{
    stUsuario b[100];
    int op,v;
    op = ingresarOpcion();
    switch (op)
    {
    case 0:
        system ("cls");
        imprimirCabecera("ADMIN");
        printf ("\n\n");
        imprimirOpcionesSubMenuAdmin();
        switchSubMenu1(admin,cancion,usuario);
        break;
    case 1:
        system ("cls");
        imprimirCabecera("ALTA USUARIO");
        AltaUsuario(usuario);
        system ("pause");
        system ("cls");
        imprimirCabecera("ADMIN");
        printf ("\n\n");
        imprimirOpcionesSubMenuAdminUsuarios();
        switchAdminUsuarios(admin,cancion,usuario);
        break;
    case 2:
        system ("cls");
        imprimirCabecera("BAJA USUARIO");
        BajaUsuario(usuario);
        system ("pause");
        system ("cls");
        imprimirCabecera("ADMIN");
        printf ("\n\n");
        imprimirOpcionesSubMenuAdminUsuarios();
        switchAdminUsuarios(admin,cancion,usuario);
        break;
    case 3:
        system ("cls");
        imprimirCabecera("MODIFICAR USUARIO");
        ModificarUsuario(usuario);
        system ("pause");
        system ("cls");
        imprimirCabecera("ADMIN");
        printf ("\n\n");
        imprimirOpcionesSubMenuAdminUsuarios();
        switchAdminUsuarios(admin,cancion,usuario);
        break;
    case 4:
        system ("cls");
        imprimirCabecera("CONSULTA USUARIO");
        ConsultarUsuario(usuario);
        system ("pause");
        system ("cls");
        imprimirCabecera("ADMIN");
        printf ("\n\n");
        imprimirOpcionesSubMenuAdminUsuarios();
        switchAdminUsuarios(admin,cancion,usuario);
        break;
    case 5:
        system ("cls");
        imprimirCabecera("LISTADO DE USUARIOS");
        v = cargarArreglo(b,usuario);
        ordenarSeleccionUsuario(b,v);
        mostrarArreglo(b,v);
        system ("pause");
        system ("cls");
        imprimirCabecera("ADMIN");
        printf ("\n\n");
        imprimirOpcionesSubMenuAdminUsuarios();
        switchAdminUsuarios(admin,cancion,usuario);
        break;
    default:
        printf ("Opcion no valida\n");
        system ("pause");
        system("cls");
        imprimirCabecera("ADMIN");
        printf("\n\n");
        imprimirOpcionesSubMenuAdminUsuarios();
        switchAdminUsuarios(admin,cancion,usuario);
        system("cls");
        break;
    }
}

void switchAdminCanciones (char admin[], char cancion[], char usuario[])
{
    int op, v;
    stCancion a [100];

    op = ingresarOpcion();
    switch (op)
    {
    case 0:
        system("cls");
        imprimirCabecera("ADMIN");
        printf("\n\n");
        imprimirOpcionesSubMenuAdmin();
        switchSubMenu1(admin,cancion,usuario);
        break;
    case 1:
        system("cls");
        imprimirCabecera("ALTA CANCION");
        printf("\n\n");
        AltaCancion(cancion);
        system ("pause");
        system("cls");
        imprimirCabecera("ADMIN");
        printf("\n\n");
        imprimirOpcionesSubMenuAdminCanciones();
        switchAdminCanciones(admin,cancion,usuario);
        break;
    case 2:
        system("cls");
        imprimirCabecera("BAJA CANCION");
        printf("\n\n");
        mostrarArchivoCanciones(cancion);
        bajaCancion(cancion);
        system ("pause");
        system("cls");
        imprimirCabecera("ADMIN");
        printf("\n\n");
        imprimirOpcionesSubMenuAdminCanciones();
        switchAdminCanciones(admin,cancion,usuario);
        break;
    case 3:
        system("cls");
        imprimirCabecera("MODIFICAR CANCION");
        printf("\n\n");
        modificarCancion(cancion);
        system ("pause");
        system("cls");
        imprimirCabecera("ADMIN");
        printf("\n\n");
        imprimirOpcionesSubMenuAdminCanciones();
        switchAdminCanciones(admin,cancion,usuario);
        break;
    case 4:
        system("cls");
        imprimirCabecera("CONSULTAR CANCION");
        printf("\n\n");
        consultaCancion(cancion);
        system ("pause");
        system("cls");
        imprimirCabecera("ADMIN");
        printf("\n\n");
        imprimirOpcionesSubMenuAdminCanciones();
        switchAdminCanciones(admin,cancion,usuario);
        break;
    case 5:
        system("cls");
        imprimirCabecera("LISTADO CANCIONES POR TITULO");
        printf("\n\n");
        v = cargarArray(a,cancion);
        ordenarSeleccion(a,v);
        mostrarArray(a,v);
        system("pause");
        system("cls");
        imprimirCabecera("ADMIN");
        printf("\n\n");
        imprimirOpcionesSubMenuAdminCanciones();
        switchAdminCanciones(admin,cancion,usuario);
        break;
    case 6:
        system("cls");
        imprimirCabecera("LISTADO CANCIONES POR GENERO");
        printf("\n\n");
        v = cargarArray(a,cancion);
        ordenarInsercion(a, v);
        mostrarArray(a,v);
        system("pause");
        system("cls");
        imprimirCabecera("ADMIN");
        printf("\n\n");
        imprimirOpcionesSubMenuAdminCanciones();
        switchAdminCanciones(admin,cancion,usuario);
        break;
    case 7:
        system("cls");
        imprimirCabecera("LISTADO CANCIONES POR ID");
        printf("\n\n");
        mostrarArchivoCanciones(cancion);
        system("pause");
        system("cls");
        imprimirCabecera("ADMIN");
        printf("\n\n");
        imprimirOpcionesSubMenuAdminCanciones();
        switchAdminCanciones(admin,cancion,usuario);
        break;
    case 8:
        system("cls");
        imprimirCabecera("INGRESAR CANCION EN SISTEMA");
        printf("\n\n");
        guardarCancion(cancion);
        mostrarArchivoCanciones(cancion);
        system ("pause");
        system("cls");
        imprimirCabecera("ADMIN");
        printf("\n\n");
        imprimirOpcionesSubMenuAdminCanciones();
        switchAdminCanciones(admin,cancion,usuario);
        break;

    default:
        printf ("Opcion no valida\n");
        imprimirOpcionesSubMenuAdmin();
        switchSubMenu1(admin,cancion,usuario);

    }
}

///------------------------------------------------------------ADMIN
stUsuarioadmin CrearAdmin(char admin[]) ///Crea una cuenta de un usuario administrador
{
    int i=0,flag=0,anio=1900;
    char gen;
    stUsuarioadmin a;
    FILE *archi=fopen(admin,"rb");
    if (archi == NULL  )
        i=0;
    else if (archi !=NULL)
    {
        fseek (archi, sizeof (stUsuarioadmin)*(-1), 2);
        fread(&a,sizeof(stUsuarioadmin),1,archi);
        i=a.idUsuario+1;
    }
    a.idUsuario = i;
    printf("ingrese datos del admin");
    printf("\nNombre Usuario:");
    fflush(stdin);
    gets(a.nombreUsuario);
    printf("Contrasenia:");
    fflush(stdin);
    gets(a.pass);
    while(anio<=1900 || anio>=2020) /// crea una restriccion de anio de nacimiento
    {
        if(flag==0)
        {
            printf("Anio Nacimiento:\n");
            scanf("%d",&anio);
            flag=1;
        }
        else
        {
            printf("Ingrese un año adecuado(mayor a 1900 y menor a 2019):\n");
            scanf("%d",&anio);
        }
    }
    a.anioNacimiento=anio;
    flag=0;
    while(gen=='m' && gen=='f' && gen=='i')
    {
        if(flag==0)
        {
            printf("Genero(m/f/i):");
            fflush(stdin);
            scanf("%c",&gen);
            flag=1;
        }
        else
        {
            printf("Genero invalido,ingrese otro:");
            fflush(stdin);
            scanf("%c",&gen);
        }
        a.genero=gen;
    }
    printf("Nacionalidad:");
    fflush(stdin);
    gets(a.pais);
    return a;
}
void  CargarAdmin(char admin[]) /// el admin creado se carga al archivo admin.bin
{
    stUsuarioadmin a;
    FILE *archi=fopen(admin,"ab");
    if(archi==NULL)
    {
        printf("ERROR");
    }
    if(archi!=NULL)
    {
        a=CrearAdmin(admin);
        fwrite(&a,sizeof(stUsuarioadmin),1,archi);
    }
    fclose(archi);
}
void MostrarAdmin2(char archivo[]) ///muestra todos los usuarios administradores cargados en el archivo admin.bin
{
    FILE * archi=fopen(archivo,"rb");
    stUsuarioadmin a;
    if (archi!=NULL)
    {
        while(!feof(archi))
        {
            fread(&a,sizeof(stUsuarioadmin),1,archi);
            if(!feof(archi))
            {
                MostrarAdmin(a);
            }
        }
        fclose(archi);
    }
}
void MostrarAdmin(stUsuarioadmin a) ///muestra UN administrador
{
    printf("\nID:%d",a.idUsuario);
    printf("\nNombre Usuario:%s",a.nombreUsuario);
    printf("\nContraseña:%s",a.pass);
    printf("\nAnioNacimiento:%d",a.anioNacimiento);
    printf("\nGenero:%c",a.genero);
    printf("\nPais:%s",a.pais);
    printf("\n");
}
int loguearUsuarioadmin (char admin[])///loguea un administrador
{
    FILE * archi = fopen(admin,"rb");
    stUsuarioadmin b;
    char nombreUseradmin [30];
    char contrasenia[20];
    int flag=0;
    printf("\n---------------------");
    printf("\nADMINISTRADOR\n");
    printf("---------------------");
    printf("\nNombre de administrador:");
    fflush(stdin);
    gets(nombreUseradmin);
    printf("Contrasenia:");
    fflush(stdin);
    gets(contrasenia);
    system("cls");

    if (archi!=NULL)
    {
        while(fread(&b,sizeof(stUsuarioadmin),1,archi)>0 && flag== 0)
        {
            if(strcmp(b.pass,contrasenia)==0 && strcmp(b.nombreUsuario,nombreUseradmin)==0)
            {
                printf("-----------------------");
                printf("\nBIENVENIDO %s\n",b.nombreUsuario);
                printf("-----------------------\n");
                flag=1;
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
void mostrarArchivoUsuariosAlta (char usuario1 [])///muestra los usuarios de alta
{
    stUsuario a;
    FILE * archi = fopen (usuario1, "rb");
    while (fread (&a, sizeof(stUsuario),1,archi)>0)
    {
        if(a.eliminado!=1)///muestra todos los usuarios que no estan eliminados
        {
            printf ("\nID usuario: %d", a.idUsuario);
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
void BajaUsuario(char usuario1[])///elimina el usuario
{
    stUsuario a;
    int i=0, flag =0, titulo =0;
    printf("\n\nUsuarios dados de alta: \n\n");
    mostrarArchivoUsuariosAlta(usuario1);
    FILE * archi = fopen (usuario1, "r+b");
    printf ("Cual es el ID del usuario  a eliminar? \n");
    scanf ("%d", &titulo);
    fseek(archi,0,0);

    while (flag == 0 &&fread(&a,sizeof(stUsuario),1,archi)>0)
    {
        if (titulo != a.idUsuario)
            i++;
        else
            flag=1;

    }
    if (flag ==1)
    {
        a.eliminado = 1;
        fseek(archi,sizeof(stUsuario)*i,SEEK_SET);
        fwrite (&a,sizeof(stUsuario),1,archi);
        printf ("\nEl usuario %s ha sido eliminado con exito \n", a.nombreUsuario);
    }
    fclose(archi);
}
void AltaUsuario(char usuario1[])///elimina el usuario
{
    stUsuario a;

    int i=0, flag =0, titulo=0;
    FILE * archi = fopen (usuario1, "r+b");
    printf ("\n\nUsuarios dados de baja : \n\n");
    mostrarArchivoUsuariosBaja(usuario1);
    printf ("Cual es el ID del usuario  a dar de alta? \n");
    scanf ("%d", &titulo);
    fseek(archi,0,0);

    while (flag == 0 &&fread(&a,sizeof(stUsuario),1,archi)>0)
    {
        if (titulo != a.idUsuario)
            i++;
        else
            flag=1;

    }
    if (flag ==1)
    {
        a.eliminado = 0;
        fseek(archi,sizeof(stUsuario)*i,SEEK_SET);
        fwrite (&a,sizeof(stUsuario),1,archi);
        printf ("\nEl usuario %s ha sido dado de alta con exito \n\n", a.nombreUsuario);
    }
    fclose(archi);
}
void mostrarArchivoUsuariosBaja (char usuario1 [])///muestra los usuarios dados de baja
{
    stUsuario a;
    FILE * archi = fopen (usuario1, "rb");
    while (fread (&a, sizeof(stUsuario),1,archi)>0)
    {
        if(a.eliminado==1)///muestra todos los usuarios que no estan eliminados
        {
            printf ("\nID usuario %d: \n", a.idUsuario);
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
void ModificarUsuario(char usuario1[])///modifica campos de un usuario
{
    stUsuario a;
    int respuesta,campo,anio=1900,flag=0;
    char nombre[30];
    char contrasenia[30];
    char pais[30];
    char gen='q';
    FILE * archi = fopen (usuario1, "r+b");
    printf("\nIngrese numero de ID a modificar:");
    scanf("%d",&respuesta);
    while(flag==0 && fread(&a,sizeof(stUsuario),1,archi)>0)
    {
        if(a.idUsuario==respuesta && a.eliminado==0)///compara todos los usuarios menos los eliminados
        {
            flag=1;
            mostrarUnUsuario(a);///muestra usuario a modificar
            printf("\nQue campo desea cambiar:");
            printf("\n1:Nombre");
            printf("\n2:Contraseña");
            printf("\n3:Anio de Nacimiento");
            printf("\n4:Genero");
            printf("\n5:Pais\n");
            scanf("%d",&campo);
            if(campo==1)
            {
                printf("\nQue nombre desea poner\n");
                fflush(stdin);
                gets(nombre);
                int pos=ftell(archi)-sizeof(stUsuario);
                fseek(archi,pos,SEEK_SET);
                strcpy(a.nombreUsuario,nombre);
                fwrite(&a,sizeof(stUsuario),1,archi);
                printf("\nEl usuario cambio de nombre a %s\n",nombre);///cambia nombre de usuario
            }
            else if(campo==2)
            {
                printf("\nQue contraseña desea poner\n");
                fflush(stdin);
                gets(contrasenia);
                int pos=ftell(archi)-sizeof(stUsuario);
                fseek(archi,pos,SEEK_SET);
                strcpy(a.pass,contrasenia);
                fwrite(&a,sizeof(stUsuario),1,archi);
                printf("\nLa nueva contraseña es %s\n",contrasenia);///cambia contraseña
            }
            else if(campo==3)
            {
                while(anio<=1900 || anio>=2020)
                {
                    if(flag==0)
                    {
                        printf("ANIO DE NACIMIENTO: \n");
                        scanf("%d",&anio);
                        flag=1;
                    }
                    else
                    {
                        printf("Ingrese un anio valido(mayor a 1900 y menor a 2019):\n");
                        scanf("%d",&anio);
                    }
                }
                a.anioNacimiento=anio;
                int pos=ftell(archi)-sizeof(stUsuario);
                fseek(archi,pos,SEEK_SET);
                a.anioNacimiento=anio;
                fwrite(&a,sizeof(stUsuario),1,archi);
                printf("\nEl cambio de anio se realizo a %d\n",anio);
            }
            else if(campo==4)
            {
                flag=0;
                while(gen!='m'&& gen!='f'&& gen!='i')
                {
                    if(flag==0)
                    {
                        printf("GENERO(m/f/i):\n");
                        fflush(stdin);
                        scanf("%c",&gen);
                        flag=1;
                    }
                    else
                    {
                        printf("genero invalido,ingrese otro:\n");
                        fflush(stdin);
                        scanf("%c",&gen);
                    }
                }
                int pos=ftell(archi)-sizeof(stUsuario);
                fseek(archi,pos,SEEK_SET);
                a.genero=gen;
                fwrite(&a,sizeof(stUsuario),1,archi);
                printf("\nEl genero a sido modificado a %c\n",gen);
            }

            else if(campo==5)
            {
                printf("\nIngrese pais a modificar");
                fflush(stdin);
                gets(pais);
                int pos=ftell(archi)-sizeof(stUsuario);
                fseek(archi,pos,SEEK_SET);
                strcpy(a.pais,pais);
                fwrite(&a,sizeof(stUsuario),1,archi);
                printf("\nEl pais a sido cambiado a %s",pais);
            }

        }
    }

    if(flag==0)
    {
        printf("\nEl numero de usuario no existe\n");
    }
    fclose(archi);
}

///-------------------------------------------CANCIONES--------------------------------------------------------
stCancion cargarCancion(char cancion [])           ///Ingresa los datos de una cancion y lo guarda en una estructura
{
    int i=0;
    stCancion c;

    FILE *archi = fopen(cancion, "rb");

    if (archi == NULL)
        i=0;
    else
    {
        fseek (archi, sizeof (stCancion)*(-1), 2);
        fread(&c,sizeof(stCancion),1,archi);
        i=c.idCancion+1;
    }

    c.idCancion = i;

    printf("Titulo:\n");
    fflush(stdin);
    gets(c.titulo);

    printf("Artista:\n");
    fflush(stdin);
    gets(c.artista);

    printf("Duracion (En segundos):\n");
    scanf("%d",&c.duracion);

    printf("Album:\n");
    fflush(stdin);
    gets(c.album);

    printf("Anio de la cancion:\n");
    scanf("%d",&c.anio);

    printf("Genero:\n");
    fflush(stdin);
    gets(c.genero);

    printf ("Comentario: \n");
    gets (c.comentario);
    c.eliminado=0;

    fclose(archi);
    return c;
}
void guardarCancion(char cancion [])  ///Guarda una sola cancion en el archivo
{
    stCancion c;
    int i=0;

    c = cargarCancion(cancion);
    i = cancionRepetida(cancion, c);
    if (i==0)
    {
        FILE * archi = fopen (cancion, "ab");
        fwrite(&c, sizeof(stCancion),1,archi);
        fclose(archi);
    }
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
void mostrarArchivoCanciones (char cancion []) ///Muestra todas las canciones que esten dadas de alta
{
    stCancion c;
    FILE * archi = fopen (cancion, "rb");
    while (fread (&c, sizeof(stCancion),1,archi)>0)
    {
        if (c.eliminado==0)
            mostrarUnaCancion(c);
    }
}
void bajaCancion(char cancion[]) ///Elimina logicamente una cancion del archivo
{
    stCancion a;
    int i=0, flag =0,dato=0;
    FILE * archi = fopen (cancion, "r+b");
    printf ("\nCual es el ID de la cancion a eliminar? \n");
    scanf ("%d", &dato);

    while (flag == 0 && fread(&a,sizeof(stCancion),1,archi)>0)
    {
        if (dato != a.idCancion)
            i++;
        else
            flag =1;
    }

    if (flag ==1)
    {
        if (a.eliminado==1)
            printf("\nSu cancion ya ha sido eliminada del programa\n");
        else
        {
            a.eliminado = 1;
            fseek(archi, sizeof(stCancion)*(i),0);
            fwrite (&a,sizeof(stCancion),1,archi);
            printf ("\nLa cancion %s ha sido eliminada con exito \n", a.titulo);
        }
    }

    fclose(archi);

}
void mostrarUnaCancion (stCancion a) ///Muestra una cancion que se pase por parametro
{
    printf ("\n\nidCancion: %d\t", a.idCancion);
    printf ("\nTitulo: \t");
    puts (a.titulo);
    printf ("Artista: \t");
    puts (a.artista);
    printf ("Duracion: %d\t", a.duracion);
    printf ("\nAlbum: \t");
    puts (a.album);
    printf ("Anio: %d\t", a.anio);
    printf ("\nGenero: %s\t", a.genero);
    printf ("\nComentario: \t");
    puts (a.comentario);
    //printf ("\nEliminado: %d", a.eliminado);
    printf ("\n\n");
}
void mostrarCancionesEliminadas (char cancion []) ///Muestra las canciones que esten eliminadas logicamente en su estructura
{
    FILE * archi = fopen (cancion, "rb");
    stCancion a;
    int flag=0;

    while (fread(&a, sizeof(stCancion),1,archi)>0)
    {
        if (a.eliminado == 1)
        {
            mostrarUnaCancion(a);
            flag = 1;
        }
    }
    if (flag ==0)
        printf ("\n\nNo hay canciones eliminadas en el programa \n\n");
    fclose(archi);
}
int cargarArray (stCancion b[], char cancion [])  ///carga en un arreglo todas las canciones del archivo
{
    FILE * archi = fopen (cancion, "rb");
    stCancion c;
    int i=0;
    if (archi != NULL)
    {
        while (fread(&c,sizeof(stCancion),1,archi)>0)
        {
            if (c.eliminado == 0)
            {
                b[i] = c;
                i++;
            }
        }
        fclose(archi);
    }
    return i;
}
int encontrarMenor (stCancion b[], int pos, int validos) ///encuentra en el arreglo, la cancion menor (alfabeticamente hablando)
{
    stCancion menor = b[pos];
    int posMenor = pos;
    int i = pos+1;

    while (i<validos)
    {
        if (strcmp (menor.titulo,b[i].titulo)>0)
        {
            menor = b[i];
            posMenor = i;
        }
        i++;
    }
    return posMenor;

}
void ordenarSeleccion (stCancion b[], int validos )  ///ordena alfabeticamente las canciones (titulo)
{
    int posMenor;
    int i = 0;
    stCancion aux;

    while (i<validos-1)
    {
        posMenor = encontrarMenor (b,i, validos);
        aux = b[posMenor];
        b[posMenor] = b[i];
        b[i]=aux;
        i++;
    }
}
void mostrarArray (stCancion b [], int validos) ///Muestra un arreglo de canciones
{
    for (int i=0; i<validos; i++)
    {
        mostrarUnaCancion(b[i]);
    }
}
void insertar (stCancion b[], int ultimaPos, stCancion dato)
{
    int i = ultimaPos;
    while (i>=0 && (strcmp (dato.genero,b[i].genero)<0))
    {
        b[i+1] = b[i];
        i--;
    }
    b[i+1] = dato;
}
void ordenarInsercion (stCancion b[], int validos) ///ordena un arreglo de canciones por genero
{
    int i=0;
    while (i<validos-1)
    {
        insertar (b,i,b[i+1]);
        i++;
    }

}
void modificarCancion (char cancion[]) ///Modifica uno de los campos de la estructura de la cancion
{
    stCancion a;
    stCancion b;
    int i=0, flag=0;
    FILE * archi = fopen (cancion, "r+b");
    int num =0;
    if (archi!=NULL)
    {
        printf ("Ingrese el numero de ID de la cancion a modificar \n");
        scanf("%d", &num);

        while (fread(&a,sizeof(stCancion),1,archi)>0 && flag==0)
        {

            if (a.idCancion == num)
            {
                mostrarUnaCancion(a);
                b = modificarUnaCancion(a);
                flag=1;
            }
            i++;
        }
        if (flag==1)
        {
            fseek (archi,sizeof(stCancion)*(i-1),0);
            fwrite (&b,sizeof(stCancion),1,archi);
            printf ("Su cancion modificada: \n");
            mostrarUnaCancion(b);
        }
        else
            printf ("\nSu cancion no se encuentra en los datos del programa\n");
        fclose (archi);
    }
}
stCancion modificarUnaCancion (stCancion a) ///modifica un campo de una cancion
{
    int opcion =0;
    printf ("\nIngrese el numero del campo a modificar\n\n");
    printf ("1- Titulo\n ");
    printf ("2- Artista\n");
    printf ("3- Duracion\n");
    printf ("4- Album\n ");
    printf ("5- Anio\n");
    printf ("6- Genero\n" );
    printf ("7- Comentario\n");
    scanf ("%d", &opcion);

    switch (opcion)
    {
    case 1:
        printf ("Nuevo titulo de cancion:\n");
        fflush(stdin);
        gets(a.titulo);
        break;
    case 2:
        printf ("Nuevo artista de cancion:\n");
        fflush(stdin);
        gets(a.artista);
        break;
    case 3:
        printf ("Nueva duracion de cancion: \n");
        scanf ("%d", &a.duracion);
        break;
    case 4:
        printf ("Nuevo album de cancion: \n");
        fflush(stdin);
        gets(a.album);
        break;
    case 5:
        printf ("Nuevo anio de cancion:\n");
        scanf("%d", &a.anio);
        break;
    case 6:
        printf ("Nuevo genero de cancion:\n");
        fflush(stdin);
        gets (a.genero);
        break;
    case 7:
        printf ("Nuevo comentario de cancion: \n");
        fflush(stdin);
        gets(a.comentario);
        break;
    default:
        printf ("Ha ingresado una opcion invalida \n");
        break;
    }
    return a;
}
void consultaCancion(char cancion []) ///Se ingresa el titulo de la cancion y la busca en el archivo.
{
    char nombre[50];
    int flag =0;
    stCancion a;
    FILE * archi = fopen(cancion,"rb");
    printf ("Ingrese el titulo de la cancion que desea buscar \n");
    fflush(stdin);
    gets(nombre);

    while (fread(&a,sizeof(stCancion),1,archi)>0 && flag == 0)
    {
        if (strcmp (a.titulo,nombre)==0)
        {
            mostrarUnaCancion(a);
            flag=1;
            if(a.eliminado==1)
                printf ("Su cancion esta eliminada del sistema \n");
            else
                printf ("Su cancion esta disponible en sistema\n");
        }
    }
    if (flag == 0)
    {
        printf ("\nSu cancion no se encuentra en los datos del programa\n");
    }
    fclose (archi);
}

void RecomendarAleatoriaCancion(char cancion[],char usuario[],int pos) ///recomienda una cancion en relacion a tu genero  favorito
{
    int i=0,tema=0;
    srand(time(NULL));
    stCancion random[20];
    stCancion a;
    stUsuario b;
    FILE*archi=fopen(cancion,"rb");
    FILE*archivo=fopen(usuario,"rb");
        fseek(archivo,sizeof(stUsuario)*pos,0);
        fseek(archi,0,0);
        fread(&b,sizeof(stUsuario),1,archivo);
        while(fread(&a,sizeof(stCancion),1,archi)>0)
        {
            if(strcmpi(a.genero,b.generoFav)==0)
            {
                random[i]=a;
                i++;
            }
        }
        if(i==0)
        {
            printf("No hay canciones para recomendar\n");
        }
        else
        {
            tema=rand()%i;
            printf("CANCION RECOMENDADA:\n");
            printf("%d\n",random[tema].idCancion);
            printf("%s\n",&random[tema].titulo);
            printf("%s\n",&random[tema].genero);
            printf("%d\n",random[tema].anio);
            printf("%s\n",&random[tema].artista);
            printf("%d\n",random[tema].duracion);
            printf("%s\n",&random[tema].comentario);
        }
        fclose(archi);
        fclose(archivo);

}
void ordenarPlaylist (char Usuario[],int pos,stCancion c[],char cancion[]) ///ordena la playlist que creaste en tu usuario y la muestra
{
    stUsuario a;

    a = User(Usuario,pos);
    vectorPlaylist(a,c,cancion);
    ordenarSeleccionCancion(c,a.cantidad);
    pasarAplaylist(Usuario,c,a,cancion,pos);

}


///--------------------------------------------------USUARIO--------------------------------------------------------
stUsuario ingresarUnUsuario(char Usuario[]) ///crea un usuario
{
    int i =0,byte=0,anio=1900,flag=0;
    char gen='q';
    stUsuario a;

    FILE * archi = fopen(Usuario,"rb");
    if(archi != NULL)
    {
        fseek(archi,0,2);
        byte = ftell(archi);
        if(byte == 0)
        {
            i=0;
        }
        else
        {
            fseek(archi,sizeof(stUsuario) * -1,2);
            fread(&a,sizeof(stUsuario),1,archi);

            i = a.idUsuario + 1;
        }
        a.idUsuario = i;
        printf("NOMBRE:\n");
        fflush(stdin);
        gets(a.nombreUsuario);
        printf("CONTRASENIA: \n");
        fflush(stdin);
        gets(a.pass);
        while(anio<=1900 || anio>=2020)
        {
            if(flag==0)
            {
                printf("ANIO DE NACIMIENTO: \n");
                scanf("%d",&anio);
                flag=1;
            }
            else
            {
                printf("INGRESE UN ANIO VALIDO(mayor a 1900 y menor a 2019):\n");
                scanf("%d",&anio);
            }
        }

        a.anioNacimiento=anio;
        flag=0;
        while(gen!='m'&& gen!='f'&& gen!='i')
        {
            if(flag==0)
            {
                printf("GENERO(m/f/i):\n");
                fflush(stdin);
                scanf("%c",&gen);
                flag=1;
            }
            else
            {
                printf("genero invalido,ingrese otro:\n");
                fflush(stdin);
                scanf("%c",&gen);
            }
        }
        a.genero=gen;
        printf("PAIS DE ORIGEN:\n");
        fflush(stdin);
        gets(a.pais);
        a.eliminado=0;
        a.cantidad=0;
        do
        {
            printf("INGRESE SU GENERO FAVORITO\n");
            printf("pop\n");
            printf("rock\n");
            printf("cumbia\n");
            printf("rap\n");
            fflush(stdin);
            gets(a.generoFav);
            if((strcmpi(a.generoFav,"pop")!=0)&& (strcmpi(a.generoFav,"rock")!=0)&&(strcmpi(a.generoFav,"cumbia")!=0)&&(strcmpi(a.generoFav,"rap")!=0))
            {
                printf("EL GENERO INGRESADO NO EXISTE\n");
            }
        }
        while((strcmpi(a.generoFav,"pop")!=0)&& (strcmpi(a.generoFav,"rock")!=0)&&(strcmpi(a.generoFav,"cumbia")!=0)&&(strcmpi(a.generoFav,"rap")!=0));
    }
    fclose(archi);
    return a;
}
void mostrarUnUsuario(stUsuario a) ///muestra un usuario
{
    printf("\n\nID:%d\n",a.idUsuario);
    printf("NOMBRE: %s\n",a.nombreUsuario);
    printf("CONTRASENIA: %s\n",a.pass);
    printf("ANIO DE NACIMIENTO: %d \n",a.anioNacimiento);
    printf("GENERO: %c\n",a.genero);
    printf("PAIS DE ORIGEN: %s\n",a.pais);
    printf("GENERO FAVORITO: %s\n",a.generoFav);
    //printf("Eliminado %d\n",a.eliminado);
}
void ponerEnArchivo (char Usuario[]) /// guarda los usuarios en el archivo
{
    stUsuario a;
    int i=0;

    FILE * archi = fopen(Usuario,"ab");

    a = ingresarUnUsuario(Usuario);
    i = repetido(Usuario,a);
    if(i==0)
    {
        fwrite(&a,sizeof(stUsuario),1,archi);
        fclose(archi);
    }

}
void mostrarTodosLosUsuarios(char Usuario[]) ///muestra todos los usuarios
{
    stUsuario a;

    FILE * archi =fopen(Usuario,"rb");
    fseek(archi,0,0);
    while(fread(&a,sizeof(stUsuario),1,archi)>0)
    {
        mostrarUnUsuario(a);

    }
    fclose(archi);
}
int loguear(char Usuario[]) ///loguea un usuario, devuelve la posicion de dicho usuario.
{
    stUsuario b;
    char nombre[50];
    char contra[20];
    int flag=0;
    int k=0;

    FILE * archi= fopen(Usuario,"rb");
    printf ("Log in Usuario \n");
    printf("Nombre:\n");
    fflush(stdin);
    gets(nombre);
    printf("Contrasenia:\n");
    fflush(stdin);
    gets(contra);
    flag=0;
    if(archi!=NULL)
    {
        while(fread(&b,sizeof(stUsuario),1,archi) > 0 && flag == 0 )
        {
            if(strcmp(nombre,b.nombreUsuario)==0 && (strcmp(contra,b.pass))==0)
            {
                if (b.eliminado ==0)
                {
                printf("Bienvenido: %s \n",b.nombreUsuario);
                k = ftell(archi)/sizeof(stUsuario);
                k=k-1;
                flag = 1;
                }
                else printf ("Su cuenta esta dada de baja\n");

            }
            else k=-1;

        }
        if(flag==0)
            printf("Los datos ingresados son invalidos\n");

    }
    fclose(archi);
    return k;
}

int repetido(char Usuario[],stUsuario a) ///Verifica que los nombres de usuarios no esten repetidos
{
    stUsuario b;
    int i=0;
    FILE * archi =fopen(Usuario,"rb");
    while(fread(&b,sizeof(stUsuario),1,archi) >0 && i==0)
    {
        if(strcmp(b.nombreUsuario,a.nombreUsuario)==0)
        {
            printf("El nombre q ingreso ya esta en uso\n");
            i=1;
        }
    }
    fclose(archi);
    return i;
}
int cargarArreglo (stUsuario b[], char Usuario [])///Carga una arreglo con todos los usuarios
{
    FILE * archi = fopen (Usuario, "rb");
    stUsuario c;
    int i=0;
    if (archi != NULL)
    {
        while (fread(&c,sizeof(stUsuario),1,archi)>0)
        {
            b[i] = c;
            i++;
        }
        fclose(archi);
    }
    return i;
}
int encontrarMenorUsuario (stUsuario b[], int pos, int validos)///encuentra el menor usuario (alfabeticamente hablando)
{
    stUsuario menor = b[pos];
    int posMenor = pos;
    int i = pos+1;

    while (i<validos)
    {
        if (strcmp (menor.nombreUsuario,b[i].nombreUsuario)>0)
        {
            menor = b[i];
            posMenor = i;
        }
        i++;
    }
    return posMenor;

}
void ordenarSeleccionUsuario (stUsuario b[], int validos )///ordena el arreglo de usuarios
{
    int posMenor;
    int i = 0;
    stUsuario aux;

    while (i<validos-1)
    {
        posMenor = encontrarMenorUsuario (b,i, validos);
        aux = b[posMenor];
        b[posMenor] = b[i];
        b[i]=aux;
        i++;
    }
}
void mostrarArreglo (stUsuario b [], int validos)///muestra el arreglo de usuarios
{
    for (int i=0; i<validos; i++)
    {
        mostrarUnUsuario(b[i]);
    }
}
void ordenarArchivo(char Usuario[],stUsuario b[],int validos)///ordena el archivo de usuarios
{
    int i=0;

    FILE * archi = fopen(Usuario,"ab");
    fseek(archi,0,0);
    while(i<validos)
    {
        fwrite(&b[i],sizeof(stUsuario),1,archi);
        i++;
    }
    printf("Los usuario estan ordenados por orden alfabetico\n");
    mostrarTodosLosUsuarios(Usuario);
    fclose(archi);
}

void playlist(char Usuario[],char cancion[],int cant) ///carga las ID de las canciones a la playlist
{

    stUsuario a;
    stCancion b;

    int i=0;

    FILE * archi =fopen(Usuario,"r+b");

    b = ElegirCancion(cancion);
    fseek(archi,sizeof(stUsuario)*(cant),0);
    fread(&a,sizeof(stUsuario),1,archi);
    i=a.cantidad;
    a.playlist[i] = b.idCancion;
    i++;
    fseek(archi,sizeof(stUsuario)*(cant),0);
    fwrite(&a,sizeof(stUsuario),1,archi);
    a.cantidad = a.cantidad+1;
    fseek(archi,sizeof(stUsuario)*(cant),0);
    fwrite(&a,sizeof(stUsuario),1,archi);
    fclose(archi);
}
void variasCanciones(char Usuario[],char cancion[],int cant) ///guarda varias canciones en el archivo
{
    char seguir='s';
    while(seguir=='s')
    {
        playlist(Usuario,cancion,cant);
        printf("Desea ingresar otra cancion a su playlist? s/n\n");
        fflush(stdin);
        scanf("%c",&seguir);
    }
}
void mostrarPlaylist(char Usuario[],int pos,char cancion[]) /// muestra playlist
{
    stUsuario a;
    int i=0;
    stCancion b;

    FILE * archi = fopen(Usuario,"rb");
    FILE * archivo = fopen(cancion,"rb");

    fseek(archi,sizeof(stUsuario)*pos,0);
    fread(&a,sizeof(stUsuario),1,archi);

    while(i < a.cantidad && fread(&b,sizeof(stCancion),1,archivo)>0)
    {

        if(a.playlist[i]==b.idCancion)
        {
            mostrarUnaCancion(b);
            i++;
            fseek(archivo,0,0);
        }
    }
    fclose(archi);
    fclose(archivo);
}

void ConsultarUsuario(char usuario[]) ///consulta la existencia de un usuario por el NOMBRE
{
    stUsuario a;
    int flag=0;
    char nom[30];
    FILE * archi = fopen (usuario, "rb");
    printf("\nQue usuario desea consultar?\n");
    fflush(stdin);
    gets (nom);
    while (fread (&a, sizeof(stUsuario),1,archi)>0)
    {
        if(flag==0 && a.eliminado==0 && strcmp(nom,a.nombreUsuario)==0)///muestra todos los usuarios que no estan eliminados
        {
            printf("\n----USUARIO------\n");
            mostrarUnUsuario(a);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("\nEl usuario no esta en el sistema");
    }
}
stCancion ElegirCancion(char cancion[]) ///Elige una cancion por ID y la devuelve
{
    int k=0,flag=0;
    stCancion i;
    int dato=0;
    stCancion a;
    FILE *archi = fopen(cancion,"rb");
    do
    {
        printf("Ingrese el ID de la cancion que desea agregar a la playlis\n");
        fflush(stdin);
        scanf ("%d", &dato);

        fseek(archi,0,0);

        while(flag==0 && fread(&a,sizeof(stCancion),1,archi)>0)
        {
            if(dato == a.idCancion)
            {
                i = a;
                k++;
                flag=1;
            }
        }
        if(k==0)
        {
            printf("La cancion que desea buscar no existe\n");
        }
    }
    while(k==0);
    printf("%d",i.idCancion);

    fclose(archi);

    return i;
}

int cantidadRegistrosCancion(char a[]) ///devuelve la cantidad de registros hechos en el archivo cancion.data
{
    FILE * archi = fopen (a,"rb");
    int i=0;
    if (archi!=NULL)
    {
        fseek(archi,0,2);
        i = ftell(archi)/sizeof(stCancion);
        fclose(archi);
    }
    return i;
}
void mostrarUsuarioPos (char usuario [], int pos) ///muestra los usuarios por la posicion
{
    stUsuario a;
    FILE * archi = fopen (usuario,"rb");
    if (archi !=NULL)
    {
        fseek (archi, sizeof(stUsuario)*pos,0);
        fread(&a,sizeof(stUsuario),1,archi);
        mostrarUnUsuario(a);
        fclose(archi);
    }
}
stUsuario User(char Usuario[],int pos) ///devuelve el usuario logueado
{
    stUsuario a;
    FILE * archi = fopen(Usuario,"rb");

    fseek(archi,(sizeof(stUsuario)*pos),0);

    fread(&a,sizeof(stUsuario),1,archi);
    fclose(archi);
    return a;
}
void vectorPlaylist (stUsuario a,stCancion c[],char cancion []) ///crea un vector con los ID cargados en la playlist
{
    stCancion b;
    int i=0;

    FILE * archi = fopen(cancion,"rb");

    while(i<a.cantidad && fread(&b,sizeof(stCancion),1,archi)>0)
    {

        if(a.playlist[i]==b.idCancion)
        {
            c[i]=b;
            i++;
            fseek(archi,0,0);
        }
    }
    fclose(archi);

}
void ordenarSeleccionCancion (stCancion c[], int validos )///Ordena el vector de las canciones
{
    int posMenor;
    int i = 0;
    stCancion aux;

    while (i<validos-1)
    {
        posMenor = encontrarMenorCancion(c,i, validos);
        aux = c[posMenor];
        c[posMenor] = c[i];
        c[i]=aux;
        i++;
    }
}
void pasarAplaylist(char Usuario[],stCancion c[],stUsuario a,char cancion[],int pos)///Pasa el vector ordenado devuelta al usuario
{
    int i=0;

    FILE * archi = fopen(Usuario,"r+b");

    while(i<a.cantidad)
    {
        a.playlist[i]=c[i].idCancion;
        fseek(archi,(sizeof(stUsuario)*pos),0);
        fwrite(&a,sizeof(stUsuario),1,archi);
        i++;
    }

    printf("Las canciones estan ordenadas alfabeticamente\n");
    mostrarPlaylist(Usuario,pos,cancion);
    fclose(archi);
}
int encontrarMenorCancion (stCancion c[], int pos, int validos)///encuentra en un vector la cancion menor, alfabeticamente hablando.
{
    stCancion menor = c[pos];
    int posMenor = pos;
    int i = pos+1;

    while (i<validos)
    {
        if (strcmpi (menor.titulo,c[i].titulo)>0)
        {
            menor = c[i];
            posMenor = i;
        }
        i++;
    }
    return posMenor;
}


void mostrarArchivoCancionesBaja (char cancion []) ///muestra todas las canciones dadas de baja
{
    stCancion a;
    FILE * archi = fopen (cancion, "rb");
    while (fread (&a, sizeof(stCancion),1,archi)>0)
    {
        if(a.eliminado==1)
        {
            mostrarUnaCancion(a);
        }
    }
    fclose(archi);
}

int cancionRepetida(char cancion[],stCancion a) ///si una cancion que queres ingresar esta repetida, te lo avisa y no se guarda en el archivo
{
    stCancion b;
    int i=0;
    FILE * archi =fopen(cancion,"rb");

    while(fread(&b,sizeof(stCancion),1,archi) >0 && i==0)
    {
        if(strcmp(b.titulo,a.titulo)==0)
        {
            printf("\n\n\nLa cancion ya se encuentra en sistema\n\n\n");
            printf ("-----------------------------------------------\n\n\n");
            i=1;
        }
    }
    fclose(archi);
    return i;
}
void AltaCancion(char cancion[]) ///Da de alta una cancion que anteriormente estaba eliminada.
{
    stCancion a;
    int i=0, flag =0, dato=0;
    FILE * archi = fopen (cancion, "r+b");
    printf ("Canciones dadas de baja: \n\n");
    mostrarCancionesEliminadas(cancion);
    printf ("\nCual es el ID de la cancion a dar de alta? \n");
    scanf ("%d", &dato);
    fseek(archi,0,0);

    while (flag == 0 && fread(&a,sizeof(stCancion),1,archi)>0)
    {
        if (dato != a.idCancion)
            i++;
        else
            flag=1;

    }
    if (flag ==1)
    {
        if (a.eliminado ==1)
        {
            a.eliminado=0;
            fseek(archi,sizeof(stCancion)*i,0);
            fwrite (&a,sizeof(stCancion),1,archi);
            printf ("\nLa cancion %s ha sido dada de alta con exito \n", a.titulo);
        }
        else
            printf("\nSu cancion no necesita ser dada de alta\n");
    }
    fclose(archi);
}
