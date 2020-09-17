#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

typedef struct
{
    int legajo;
    char nombreYapellido [30];
    int edad;
    int anio;//año que cursa
} alumno;

void ingresarDato(int,char[]);
void leerDato(char[]);
int cantidadRegistros(char[]);
alumno ingresarEstruc();
void ingresarVEstruc(char[]);
void mostrarUnAlum(alumno);
void mostrarAlum(char[]);
void variosMas(char[]);
int legajosPila (char[],Pila*);
void mostrarEdadEntre (char[]);
alumno masViejo(char[]);
int cursada(char[],int);
int cargarArreglo (alumno[]);
void copiarEnArchivo (alumno [], char [], int );
int cantidadRegistrosAlumnos(char[]);
void mostrarArreglo(alumno [],int);
alumno mostrarRegistro(char [], int);
void invertir(char[]);

int main()
{
    int numero=0;
    printf("Que ejercicio desea realizar?\n ");
    scanf("%d",&numero);

    int dato=5, num=0;
    int registro =0;
    char nombre[]="archivito.bin";
    char alum []= "alumno.bin";
    Pila dada;
    inicpila(&dada);
    alumno a;
    alumno b[10];



    switch(numero)
    {

    case 1:
        /*Hacer una función que agregue un elemento al final de un archivo.
        2-Hacer una función que muestre por pantalla el contenido de un archivo.*/
        ingresarDato(dato,nombre);
        leerDato(nombre);
        break;
    case 2:
        /*3-Hacer una función que retorne la cantidad de registros que contiene un archivo.*/
        ingresarDato(dato,nombre);
        registro = cantidadRegistros(nombre);
        printf ("Cant registros: %i", registro);
        break;
    case 3:
        /*4-Crear  una  función  que  cargue  un  archivo de  alumnos.  Abrirlo  de  manera  tal  de
        verificar  si  el archivo ya está creado previamente. Cargar el archivo con 5 datos. Cerrarlo dentro de lafunción*/
        ingresarVEstruc(alum);
        break;
    case 4:
        /*Crear una función que muestre por pantalla los registros deun archivo de alumnos.*/
        ingresarVEstruc(alum);
        mostrarAlum (alum);
        break;
    case 5:
        /*Crear  una  función  que  permita  agregar  de  a  un  elemento  al  final  del  archivo.  O  sea,
        se  debe abrir el archivo,
         se piden los datos (se llena una variable de tipo struct alumno), se escribe en el archivo y se cierra.*/
        ingresarVEstruc(alum);
        variosMas(alum);
        mostrarAlum (alum);
        break;
    case 6:
        /*Crearuna función que pase a una pila los números de legajo de los alumnos mayores de edad.*/
        ingresarVEstruc(alum);
        registro = legajosPila(alum,&dada);
        mostrar(&dada);
        break;
    case 7:
        /*Dado un archivo de alumnos, hacer una función que cuente la cantidad de alumnos mayores de edad.*/
        ingresarVEstruc(alum);
        registro = legajosPila(alum,&dada);
        printf ("Ud tiene %d alumnos mayores de edad \n", registro);
        break;
    case 8:
        /*Dado un archivo de alumnos, mostrar por pantalla el nombre de todos los alumnos entre 17 y 25 años.*/
        ingresarVEstruc(alum);
        mostrarEdadEntre(alum);
        break;
    case 9:
        /*Dado un archivo de alumnos, mostrar el nombre del alumno de mayor edad.*/
        ingresarVEstruc(alum);
        a = masViejo(alum);
        printf("El alumno mayor es: %s",a.nombreYapellido);
        break;
    case 10:
        /*Crear una función que retorne la cantidad de alumnos que cursan un determinado año. El año buscado se pasa por parámetro*/
        ingresarVEstruc(alum);
        printf("Que anio de cursada desea buscar?\n");
        scanf("%d",&registro);
        dato = cursada(alum,registro);
        printf("La cantidad de alumnos q cursan ese anio son %d\n",dato);
        break;
    case 11:
        /*Crear  una  función  que  reciba  como  parámetro  un  arreglo  de  tipo  alumno  y  lo  copie  en  el archivo.*/
        registro = cargarArreglo(b);
        mostrarArreglo(b,registro);
        copiarEnArchivo(b,alum,registro);
        mostrarAlum(alum);
        break;
    case 12:
        /*Crear una función que retorne la cantidad de registros que tiene el archivo. Usar fseek y ftell*/
        ingresarVEstruc(alum);
        registro = cantidadRegistrosAlumnos(alum);
        printf("La cantidad de elementos de su archivo es %d",registro);
        mostrarAlum(alum);
        break;
    case 13:
        /*Dado un archivo de alumnos, que tenga al menos 10 registros,
        hacer una función que muestre el contenido de un registro, cuyo número (entre 0 y 9) se pase por parámetro.*/
        ingresarVEstruc(alum);
        printf("Que registro desea ver?\n");
        scanf ("%d", &num);
        a = mostrarRegistro (alum, num);
        mostrarUnAlum(a);
        break;
    case 14:
        /*15-Dado un archivo de alumnos, hacer una función que invierta los elementos del mismo.
         No se puede usar otro archivo auxiliar ni un arreglo auxiliar*/
        ingresarVEstruc(alum);
        invertir(alum);
        mostrarAlum(alum);

    }

    return 0;
}

void ingresarDato(int dato,char nombre[])
{
    FILE * archivo = fopen( nombre,"ab");
    fwrite(&dato,sizeof(int),1,archivo);
    fclose(archivo);
}
void leerDato(char nombre[])
{
    int dato=0;
    FILE * archivo = fopen( nombre,"rb");
    if (archivo != NULL)
    {
        while(fread(&dato,sizeof(int),1,archivo)>0)
            printf("\nDato: %d",dato);
    }
    fclose(archivo);
}
int cantidadRegistros (char nombre[])
{
    int i=0;
    FILE * archivo = fopen(nombre,"rb");
    fseek (archivo, sizeof(int),2);
    i = ftell (archivo)/sizeof (int);
    fclose (archivo);
    return i;
}

alumno ingresarEstruc()
{
    alumno a;
    printf("Nombre y apellido del alumno:\n");
    fflush(stdin);
    gets(a.nombreYapellido);
    printf("Legajo:\n");
    scanf("%d",&a.legajo);
    printf("Ingrese la edad del alumno:\n");
    scanf("%d",&a.edad);
    printf("Anio cursada:\n");
    scanf("%d",&a.anio);
    return a;
}
void ingresarVEstruc(char alum[])
{
    alumno a;
    FILE * archi = fopen(alum, "wb");
    if(archi!=NULL)
    {
        for(int i=0; i<10; i++)
        {
            a=ingresarEstruc();
            fwrite(&a,sizeof(alumno),1,archi);
        }
        fclose(archi);
    }
}

void mostrarUnAlum (alumno a)
{
    printf ("\nNombre y apellido: ");
    puts(a.nombreYapellido);
    printf("Legajo: %d\n", a.legajo);
    printf ("Edad: %d\n", a.edad);
    printf ("Anio de cursada: %d \n", a.anio);
}
void mostrarAlum(char alum[])
{
    alumno a;
    FILE * archi = fopen (alum, "rb");
    if (archi !=NULL)
    {
        while (fread (&a, sizeof(alumno),1,archi)>0)
            mostrarUnAlum(a);
        fclose(archi);
    }
}
void variosMas(char alum[])
{
    alumno a;
    char seguir='s';
    FILE * archi = fopen(alum,"ab");
    if(archi!=NULL)
    {
        while(seguir=='s')
        {
            a=ingresarEstruc();
            fwrite(&a,sizeof(alumno),1,archi);
            printf("Desea ingresar otro alumno?\n");
            fflush(stdin);
            scanf("%c",&seguir);
        }
        fclose(archi);
    }
}
int legajosPila(char alum[],Pila * dada)
{
    int i=0;
    alumno a;
    FILE * archi=fopen(alum,"rb");
    if(archi!=NULL)
    {
        while(fread(&a,sizeof(alumno),1,archi)>0)
        {
            if(a.edad>=18)
            {
                apilar(dada,a.legajo);
                i++;
            }

        }
        fclose(archi);
    }
    return i;
}

void mostrarEdadEntre(char alum [])
{
    alumno a;
    FILE * archi = fopen (alum, "rb");
    if (archi!=NULL)
    {
        while (fread (&a, sizeof(alumno), 1, archi)>0)
        {
            if (a.edad >=17 && a.edad <=25)
                printf ("Nombre alumno: %s \n", a.nombreYapellido);
        }
        fclose(archi);
    }
}
alumno masViejo (char alum[])
{
    alumno mayor;
    alumno b;
    FILE * archi= fopen(alum,"rb");
    if(archi!=NULL)
    {
        fread(&mayor,sizeof(alumno),1,archi);

        while(fread(&b,sizeof(alumno),1,archi)>0)
            if(mayor.edad<b.edad)
            {
                mayor=b;
            }
        fclose(archi);
    }
    return mayor;
}
int cursada(char alum[],int dato)
{
    alumno a;
    int i=0;

    FILE * archi= fopen(alum,"rb");
    if(archi!=NULL)
    {
        while(fread(&a,sizeof(alumno),1,archi)>0)
        {
            if(dato==a.anio)
            {
                i++;
            }

        }
        fclose(archi);
    }
    return i;
}

int cargarArreglo (alumno b[])
{
    int i=0;
    char seguir = 's';

    while (seguir == 's')
    {
        b[i] = ingresarEstruc();
        i++;

        printf ("Desea ingresar otro alumno? \n");
        fflush(stdin);
        scanf ("%c", &seguir);
    }
    return i;
}

void mostrarArreglo (alumno a[],int validos)
{
    for (int i=0; i<validos; i++)
        mostrarUnAlum(a[i]);
}

void copiarEnArchivo (alumno b[], char alum [], int validos)
{
    FILE * archi = fopen(alum, "wb");
    fwrite (b, sizeof (alumno),validos,archi);
    fclose(archi);

}
int cantidadRegistrosAlumnos (char nombre[])
{
    int i=0;
    FILE * archivo = fopen(nombre,"rb");
    fseek (archivo,0,2);
    i = ftell (archivo)/sizeof (alumno);
    fclose (archivo);
    return i;
}

alumno mostrarRegistro (char alum [], int numero)
{
    alumno a;
    FILE * archi = fopen(alum, "rb");
    if (archi !=NULL)
    {
        fseek (archi,0,2);
        fseek (archi,numero*sizeof(alumno),0);
        fread (&a, sizeof (alumno),1, archi);
        fclose (archi);
    }
    return a;
}
void invertir(char alum[])
{
    alumno a, b;
    int i=0, k=0;

    FILE * archi = fopen(alum, "r+b");

    if(archi!=NULL)
    {

        fseek (archi,0,2);
        i = ftell(archi)/sizeof(alumno);
        fseek (archi,0,0);
        while( i>k)
        {

            fseek (archi,sizeof(alumno)*k,0);
            fread(&a,sizeof(alumno),1,archi);
            fseek (archi,sizeof(alumno)*(i-1),0);
            fread (&b, sizeof(alumno),1,archi);
            fseek (archi,sizeof(alumno)*(i-1),0);
            fwrite(&a,sizeof(alumno),1,archi);
            fseek (archi,k*sizeof (alumno),0);
            fwrite (&b, sizeof (alumno),1,archi);
            i--;
            k++;
        }
        fclose(archi);
    }
}
