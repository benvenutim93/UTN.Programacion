#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int const dimC=5;

void cargarMatriz(int[][dimC], int);
void mostrarMatriz(int[][dimC], int);
void cargaAleatoria(int[][dimC],int);
int sumaMatriz (int [][dimC], int);
float promedio (int [][dimC],int,int*);
float promedio_2(int[][dimC],int,int);
int buscarElemento (int[][dimC], int, int);
int cargarMPalabras(char [][11],int);
void mostrarCarac(char [][dimC],int);
int buscarPalabra (char [][dimC], char[], int);
void alfabeto(char[][dimC],int);
int menorPalabra(char[][11],int,int);
int determinante (int [][2]);
void mostrarMatriz2x2 (int [][2], int);
void cargaAleatoria2x2 (int [][2], int);
void inversa (int);
void cargaAleatoria2x10 (int [][10], int);
void mostrarMatriz2x10 (int [][10], int);
void productoMatriz (int [2][2], int [2][10], int [2][10]);
int sumaVotos(int [][dimC],int,int);
void ganador(int[][dimC],int, int, char[][11], int);
int masVot(int[][dimC],int,int,int);
int votosTotal(int, int[][dimC] , int);

int main()
{
    int ejercicio =0;
    int filas =5, suma =0, bandera=0, dato=0,i=0, j=1,total=0, gano=0;
    float prom=0;
    int m [filas][dimC];
    char p [filas][11];
    char palabra [15];
    int d [2][2];
    int r [2][10];
    int prod [2][10];


    printf ("Ejercicio numero ..? \n");
    scanf ("%d", &ejercicio);


    switch (ejercicio)
    {
    case 1:
        /*1.Hacer una función que reciba como parámetro una matriz de números enteros y permita que el usuario
        ingrese valores al mismo por teclado. La función debe cargar la matriz por completo.*/
        cargarMatriz(m, filas);
        mostrarMatriz(m, filas);
        break;
    case 2:
        /*Hacer una función que reciba como parámetro una matriz de números enteros y que cargue la misma con números
         aleatorios (sin intervención del usuario). La función debe cargar la matriz por completo*/
        cargaAleatoria(m,filas);
        mostrarMatriz(m, filas);
        break;
    case 3:
        /*Hacer una función tipo int que sume el contenido total de una matriz de números enteros.*/
        cargaAleatoria(m,filas);
        mostrarMatriz(m, filas);
        suma = sumaMatriz(m, filas);
        printf ("\n\nLa suma de los elementos de la matriz es %i", suma);
        break;
    case 4:
        /*5. Hacer una función tipo int que calcule el promedio de una matriz de números enteros.*/
        cargaAleatoria(m,filas);
        mostrarMatriz(m, filas);
        suma = sumaMatriz(m, filas);
        //prom = promedio(m,filas,&suma);
        prom = promedio_2(m,filas,suma);
        printf("\n\nEl promedio de su matriz es %.2f ",prom);
        break;
    case 5:
        /*Hacerunafunciónquedeterminesiunelementoseencuentradentrodeunamatrizdenúmerosenteros.
         La función recibe la matriz y el dato a buscar.*/
        cargaAleatoria(m,filas);
        mostrarMatriz(m, filas);
        printf("\n\nQue elemento busca en la matriz? \n");
        scanf ("%d", &dato);
        bandera = buscarElemento(m,filas,dato);

        if (bandera ==1)
        {
            printf ("\nSu elemento se encuentra en la matriz \n");
        }
        else
            printf ("\nSu elemento no esta en la matriz \n");
        break;
    case 6:
        /*7.Hacer unafunciónquecargueunarreglodepalabras(strings).Lafuncióndeberetornarcuantaspalabras se cargaron*/
        dato = cargarMPalabras(p,filas);
        mostrarCarac(p,dato);
        printf("Se cargaron %d palabras ",dato);
        break;
    case 7:
        /*Hacer una función que determine si una palabra se encuentra dentro de un arreglo de palabras.
        Lafunción recibe el arreglo, la cantidad de palabras que contiene y la palabra a buscar*/
        dato = cargarMPalabras(p, filas);
        printf ("Que palabra desea buscar? \n");
        fflush (stdin);
        scanf ("%s", palabra);
        bandera = buscarPalabra(p, palabra, dato);

        if (bandera == 0)
        {
            printf ("La palabra buscada se encuentra en la matriz\n");
        }
        else
            printf ("La palabra no se ha encontrado \n");
        break;
    case 8:
        /*10.Hacer una función(o varias)que ordene un arreglo de palabras por orden alfabético.
        (Por seleccióno inserción, el que más te guste)*/
        dato = cargarMPalabras(p, filas);
        mostrarCarac(p,dato);
        alfabeto(p,dato);
        mostrarCarac(p,dato);
        break;
    case 9:
        /*Hacer una función que retorne el determinante de una matriz de 2x2.*/
        cargaAleatoria2x2(d,2);
        mostrarMatriz2x2(d, 2);
        dato = determinante (d);
        printf ("\nEl determinante de su matriz es %d", dato);
        break;
    case 10:
        /*12. Función que verifique si una matriz de 2x2 tiene inversa*/
        cargaAleatoria2x2(d,2);
        mostrarMatriz2x2(d, 2);
        dato = determinante (d);
        inversa(dato);
        break;
    case 11:
        /* Hacer una función que multiplique una matriz de 2x2 por una matriz de 2x10.*/
        cargaAleatoria2x2(d,2);
        mostrarMatriz2x2(d,2);
        cargaAleatoria2x10 (r,2);
        mostrarMatriz2x10(r,2);
        productoMatriz (d, r, prod);
        mostrarMatriz (prod, 2);
        break;
    case 12:
        printf ("Ingrese la planilla de votacion \n");
        bandera = cargarMPalabras(p, filas);
        cargarMatriz(m, filas);

        mostrarCarac(p,bandera);
        mostrarMatriz(m,filas);

        while(j<5)
        {
            suma = sumaVotos(m,filas,j);
            printf ("La suma de votos del candidato %s es de %d \n", p[j], suma);
            j++;
        }
        j=1;

        total= votosTotal(j,m,filas);
        printf("La cantidad de votos emitidos fue de %d \n",total);
        gano = masVot(m,filas,j,dato);
        printf("El que mas votos recibio fue %s \n",p[gano]);
        ganador(m, filas, j, p, total);










    }
    return 0;
}

void cargarMatriz (int m[][dimC], int filas)
{
    int i=0;
    int j=0;
    for (i=0; i<filas; i++)
    {
        for(j=0; j<dimC; j++)
        {
            printf ("Ingrese un valor \n");
            scanf ("%i", &m[i][j]);
        }
    }
}

void mostrarMatriz (int m[][dimC], int filas)
{
    int i=0;
    int j=0;

    for (i=0; i<filas; i++)
    {
        printf ("\n");
        for (j=0; j<dimC; j++)
        {
            printf ("|\t %d \t", m[i][j]);
        }
    }
    printf ("\n");
}
void cargaAleatoria(int m[][dimC],int filas)
{
    srand(time(NULL));

    int i=0,j=0;

    for(i=0; i<filas; i++)
    {
        for(j=0; j<dimC; j++)
        {
            m[i][j]=rand()%100+1;
        }
    }
}

int sumaMatriz(int m[][dimC], int filas)
{
    int i=0, j=0, suma=0;

    for (i=0; i<filas; i++)
    {
        for(j=0; j<dimC; j++)
        {
            suma+=m[i][j];
        }
    }
    return suma;
}
float promedio(int m[][dimC],int filas, int* suma)
{
    int i=0, j=0, c=0;

    for (i=0; i<filas; i++)
    {
        for(j=0; j<dimC; j++)
        {
            *suma+=m[i][j];
            c++;
        }
    }
    return (float)*suma/c;
}
float promedio_2 (int m[][dimC],int filas,int suma)
{
    int cant=dimC * filas;
    return suma/cant;
}

int buscarElemento(int m[][dimC], int filas, int dato)
{
    int i=0, j=0, flag=0;

    for (i=0; i<filas; i++)
    {
        for (j=0; j<dimC; j++)
        {
            if (dato == m[i][j])
            {
                flag=1;
            }

        }
    }
    return flag;
}
int cargarMPalabras(char p[][11],int filas)
{
    int i=0;
    char seguir='s';

    while(seguir=='s' && i<filas)
    {
        printf("Ingrese  la palabra para su matriz (maximo 10 carac)\n");
        scanf("%s",p[i]);
        printf("Desea ingresar otra palabra\n");
        fflush(stdin);
        scanf("%c",&seguir);
        i++;
    }
    return i;
}
void mostrarCarac (char p[][11],int bandera)
{
    int i=0;

    while(i<bandera)
    {
        printf("| %s \t",p[i]);
        i++;
    }

}

int buscarPalabra(char p[][dimC], char palabra[dimC], int bandera)
{
    int i=0, flag=1;

    while (i < bandera)
    {
        if (flag == 1)
        {
            flag = strcmp (p[i], palabra);
        }
        i++;
    }
    return flag;
}

int menorPalabra(char p[][dimC],int dato, int pos)
{
    int i=pos,posMenor=pos;

    for(i=pos; i<dato; i++)
        if (strcmp(p[posMenor],p[i])>0)
            posMenor=i;
    return posMenor;
}
void alfabeto(char p[][dimC],int dato)
{
    int i=0,menorPos=0;
    char aux[dimC];

    for(i=0; i<dato; i++)
    {
        menorPos=menorPalabra(p,dato,i);
        strcpy (&aux[i],p[menorPos]);
        strcpy (p[menorPos],p[i]);
        strcpy (p[i],&aux[i]);

    }
}

int determinante (int d [2][2])
{
    return ((d[0][0]*d[1][1])-(d[0][1]*d[1][0]));
}

void mostrarMatriz2x2 (int m[][2], int filas)
{
    int i=0;
    int j=0;

    for (i=0; i<filas; i++)
    {
        printf ("\n");
        for (j=0; j<2; j++)
        {
            printf ("| %d\t |", m[i][j]);
        }
    }
    printf ("\n");
}
void cargaAleatoria2x2(int m[][2],int filas)
{
    srand(time(NULL));

    int i=0,j=0;

    for(i=0; i<filas; i++)
    {
        for(j=0; j<2; j++)
        {
            m[i][j]=rand()%100+1;
        }
    }
}
void inversa(int dato)
{
    if(dato==0)
        printf("\nSu matriz no tiene inversa");
    else
        printf("\nSu matriz tiene inversa");
}
void cargaAleatoria2x10(int m[][10], int filas)
{
    srand(time(NULL));

    int i=0,j=0;

    for(i=0; i<filas; i++)
    {
        for(j=0; j<10; j++)
        {
            m[i][j]=rand()%100+1;
        }
    }
}

void mostrarMatriz2x10 (int m[][10], int filas)
{
    int i=0;
    int j=0;

    for (i=0; i<filas; i++)
    {
        printf ("\n");
        for (j=0; j<10; j++)
        {
            printf ("| %d\t |", m[i][j]);
        }
    }
    printf ("\n");
}

void productoMatriz (int d[2][2], int r[2][10], int prod [2][10])
{
    int i=0, j=0;
    for (i=0; i<2; i++)
    {
        for (j=0; j<10; j++)
        {
            prod [i][j] = d[i][0]*r[0][j]+d[i][1]*r[1][j];
        }
    }
}

int sumaVotos(int m[][dimC],int filas,int j)
{
    int i=0,suma=0;

    for(i=0; i<filas; i++)
    {
        suma+=m[i][j];
    }
    return suma;

}
int masVot(int m[][dimC],int filas,int j,int dato)
{
    int jota=0, suma=0;

    while(j<5)
    {
    suma=sumaVotos(m,filas,j);

    if(dato<suma)
    {
        dato=suma;
        jota=j;
    }
    j++;
    }
    return jota;
}
int votosTotal(int j,int m[][dimC],int  filas)
{
    int total=0,suma=0;

    while(j<5)
    {
        suma = sumaVotos(m,filas,j);
        total+=suma;
        j++;
    }
    return total;
}
void ganador(int m [][dimC],int filas, int j, char p[][11],int total)
{
    int suma=0 flag =0;
    float porcen=0;

    while(j<5)
    {
    suma = sumaVotos(m,filas,j);

    porcen= ((float)suma*100)/(float)total;

    if(porcen >50)
    {
        printf("El ganador es %s",p[j]);

    }
    j++;
    }

}

void segundaRonda(int m[][dimC],int filas, int j)
{
        int suma=0, masvotado2=0,masvotado=0;

            suma = sumaVotos(m,filas,j);
            if (suma > masvotado)
            {
                masvotado2=masvotado;
                masvotado = suma;
            }
            else if (suma < masVotado) && (suma > masvotado2)
            {
                masvotado2=suma;
            }
}
