#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{int matricula;
char nombre[30];
char sexo;}alumno;

int cargarArreglo (int [], char [][30], int);
void mostrar(int[], char [][30], int);
int buscar (int[],int,int);
void mostrarNombre (int[], char [][30], int);
int menor (char[][30],int,int);
void ordenar (int[],char[][30],int);
int cargarStruct (alumno [], int);
void mostrarStruct(alumno [], int);
int porMatricula(alumno[],int,int);
int encontrarMenor (alumno [], int, int);
void ordenarSeleccion (alumno[], int);
int varones (alumno[],int);
void mostrarVaron(alumno[],int);
alumno nuevoAlumno();
void ordenarInsercion (alumno [], int, alumno);


int main()
{
    int punto =0, filas = 20, alumnosCargados =0,numero=0,posicion=0, dimension = 20,dato=0;
    int matricula[filas];
    char nombre[filas][30];
    alumno a [dimension];
    alumno b ;

    printf ("Que ejercicio desea realizar?\n");
    scanf ("%d", &punto);

    switch (punto)
    {
        case 1: //Crear una función que los cargue, hasta que el usuario lo decida.
            alumnosCargados = cargarArreglo(matricula, nombre, filas);
            mostrar(matricula, nombre, alumnosCargados);
            break;
        case 2:
            /*Crear una función que busque dentro del arreglo de matrículas y retorne la posición de un determinado valor.*/
            alumnosCargados = cargarArreglo(matricula, nombre, filas);
            printf("Que matricula desea buscar?");
            scanf("%d",& numero);
            posicion = buscar(matricula,numero,alumnosCargados);
            printf("La posicion en la matricula es %d",posicion);
            break;
        case 3:
            /*Hacer una función que reciba como parámetro ambos arreglos y
             encuentre el nombre correspondiente a una determinada matrícula y lo
             imprima por pantalla. Se debe invocar la función 2*/
             alumnosCargados = cargarArreglo(matricula, nombre, filas);
             printf("Que matricula desea buscar?");
             scanf("%d",& numero);
             posicion = buscar(matricula,numero,alumnosCargados);
             mostrarNombre (matricula, nombre, posicion);
             break;
        case 4:
            /*Hacer una función que reciba como  parámetro ambos arreglos y ordene ambos por nombre*/
            alumnosCargados = cargarArreglo(matricula, nombre, filas);
            ordenar(matricula,nombre,alumnosCargados);
            mostrar(matricula, nombre, alumnosCargados);
            break;
        case 5:
            /*Hacer una función que cargue un arreglo de struct alumno, hasta que el usuario lo decida.*/
            numero = cargarStruct(a, dimension);
            mostrarStruct(a, numero);
            break;
        case 6:
            /*Hacer una función que escriba por pantalla el nombre de un alumno, conociendo su matricula*/
            numero = cargarStruct(a, dimension);
            printf("Que matricula desea buscar?");
            scanf("%d",&dato);
            posicion = porMatricula(a,numero,dato);
            printf("El nombre del alumno es %s ",a[posicion].nombre);
            break;
        case 7:
            /*Hacer una función que ordene el arreglo
             de struct alumno por medio del método de selección.El criterio de ordenación es el número de matrícula*/
             numero = cargarStruct(a, dimension);
             ordenarSeleccion(a, numero);
             mostrarStruct(a, numero);
             break;
        case 8:
            /*Hacer una función que muestre por pantalla el nombre y la matrícula de los varones*/
            numero = cargarStruct(a, dimension);
            dato = varones(a,numero);
            break;
        case 9:
            /*Hacer una función que inserte en un arreglo ordenado por matrícula un nuevo dato, conservando elorden.*/
            numero = cargarStruct(a, dimension);
            ordenarSeleccion(a, numero);
            mostrarStruct(a,numero);
            b=nuevoAlumno ();
            ordenarInsercion(a,numero,b);
            mostrarStruct(a, numero+1);
            break;
        case 10:
            /*Hacer una función que cuente y retorne la cantidad de varones que tiene un arreglo de struct alumno.*/
             numero = cargarStruct(a, dimension);
             dato = varones(a,numero);
             printf("La cantidad de varones que hay en su estructura es de %d",dato);
             break;
        }
        printf ("Terminamos!! \n");
    return 0;
}

int cargarArreglo(int matricula [], char nombre [][30], int filas)
{
    int i =0;
    char seguir = 's';

    while (i<filas && seguir == 's')
    {
        printf ("Ingrese el nombre del alumno \n");
        fflush (stdin);
        scanf ("%s", nombre [i]);

        printf ("Ingrese el numero de matricula del alumno %s \n", nombre[i]);
        scanf ("%d", &matricula[i]);

        printf ("Desea cargar otro alumno? \n");
        fflush (stdin);
        scanf ("%c", &seguir);

        i++;
    }
    return i;
}

void mostrar (int matricula [], char nombre [][30], int validos)
{
    int i=0;

    for (i=0;i<validos;i++)
    {
        printf ("Alumno:\t%s\t-\tMatricula:\t%d \n", nombre[i], matricula [i]);
    }
}
int buscar(int matricula[],int numero, int validos)
{
    int pos =-2,i=0;

    while(i<validos && pos<-1)
    {
        if(numero==matricula[i])
        {
            pos=i;
        }
        i++;
    }
    return pos;
}

void mostrarNombre (int matricula [], char nombre [][30], int posicion)
{
    printf ("El nombre correspondiente a la matricula %d es %s\n", matricula [posicion], nombre [posicion]);
}
int menor (char nombre[][30],int validos, int posicion)
{
    int i=posicion+1,posM=posicion;

    while(i<validos)
    {
        if( strcmp(nombre[posM],nombre[i])>0)
        {
            posM = i;
        }
        i++;
    }
    return posM;
}
void ordenar (int matricula[],char nombre[][30],int validos)
{
    int i=0,posMenor=0,auxA=0;
    char aux[20];

    while(i<validos)
    {
        posMenor = menor(nombre,validos , i);
        strcpy(aux,nombre[i]);
        strcpy(nombre[i],nombre[posMenor]);
        strcpy(nombre[posMenor],aux);

        auxA=matricula[i];
        matricula[i]=matricula[posMenor];
        matricula[posMenor]=auxA;
        i++;
    }
}

int cargarStruct(alumno a[], int dimension)
{
    int i=0;
    char seguir = 's';

    while (seguir == 's' && i< dimension)
    {
        a[i]=nuevoAlumno();

    printf ("Desea cargar otro alumno? \n");
    fflush (stdin);
    scanf ("%c", &seguir);
    i++;
    }
    return i;
}

void mostrarStruct (alumno a [], int validos)
{
    int i =0;
    while (i<validos)
    {
    printf ("Matricula n: %d\n", a[i].matricula);
    printf ("Nombre: %s\n", a[i].nombre);
    printf ("Sexo: %c\n\n", a[i].sexo);
    i++;
    }
}
int porMatricula(alumno a[] ,int validos,int numero)
{
    int i=0, pos=0;

    while(i<validos)
    {
        if(numero==a[i].matricula)
            {
            pos=i;
            }
            i++;
    }
    return pos;
}

int encontrarMenor(alumno a [], int validos, int pos)
{
    int i=pos, posicion=pos;
    int matricula = a[pos].matricula;

    while (i<validos)
    {
        if (matricula>a[i].matricula)
        {
            matricula = a[i].matricula;
            posicion = i;
        }
        i++;
    }
    return posicion;
}

void ordenarSeleccion(alumno a[], int validos)
{
    int i=0, pos=0;
    alumno aux;

    while (i<validos)
    {
        pos = encontrarMenor(a, validos, i);
        aux = a[i];
        a[i] = a[pos];
        a[pos]= aux;
        i++;
    }

}
int varones(alumno a[],int validos)
{
    int i=0,k=0;

    while(i<validos)
    {
        if(a[i].sexo == 'm')
        {

        mostrarVaron(a,i);
        k++;

        }
        i++;
    }
    return k;
}
void mostrarVaron(alumno a[],int pos)
{
    printf("Nombre: %s\n",a[pos].nombre);
    printf("Matricula: %d\n",a[pos].matricula);
}

alumno nuevoAlumno()
{
    alumno b;
    printf ("\n\nDATOS DEL NUEVO ALUMNO\n\n");
    printf ("Numero de matricula del nuevo alumno \n");
    scanf ("%d", &b.matricula);

    printf ("Nombre del nuevo alumno \n");
    fflush (stdin);
    scanf ("%s", &b.nombre);

    printf ("Sexo del nuevo alumno f/m \n");
    fflush (stdin);
    scanf ("%c", &b.sexo);
    return b;

}
void ordenarInsercion(alumno a[], int validos, alumno b)
{
    int i=validos-1;
    while (i>=0 && a[i].matricula > b.matricula )
    {
        a[i+1] = a[i];
        i--;
    }
    a[i+1]= b;
}


