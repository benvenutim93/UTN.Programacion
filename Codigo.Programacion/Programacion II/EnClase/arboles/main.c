#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodoArbol
{
    int legajo;
    char nombre[20];
    struct nodoArbol * izquierda;
    struct nodoArbol * derecha;
} nodoArbol;

typedef struct nodo
{
    int legajo;
    char nombre[20];
    struct nodo* sig;
} nodo;



nodoArbol * inicArbol ();
nodoArbol * crearNodoArbol (int,char[]);
void mostrarPreOrder (nodoArbol*);
nodoArbol * agregar (nodoArbol*, nodoArbol*);
nodoArbol * cargarArbol (nodoArbol*);
int buscar (nodoArbol*,nodoArbol*);
int sumarArbol(nodoArbol*);
void mostrarInOrder (nodoArbol*);
void mostrarPostOrder (nodoArbol*);
void mostrarLista(nodo*);
nodo* inicLista();
nodo * pasaje(nodoArbol*, nodo*);
nodo * crearNodo (int , char  [] );
nodo* arbol_nodo(nodoArbol*);
nodo* agregarPrincipio(nodo*,nodo*);
nodoArbol * buscarLegajo (nodoArbol*, int);
void mostrarNodoArbol(nodoArbol*);
nodoArbol* buscarNombre(nodoArbol*,char[]);
int cantidadNodos(nodoArbol*);
int cantidadHojas(nodoArbol*);
int niveles(nodoArbol*);
int contarNivelesIzq (nodoArbol *);
int contarNivelesDer (nodoArbol *);
nodoArbol * nodoMasDerecho(nodoArbol * );
nodoArbol * nodoMasIzquierdo(nodoArbol * );
nodoArbol * borrarUnNodo(nodoArbol * , int );

int main()
{
    nodoArbol * arbolito = inicArbol();
    arbolito = cargarArbol(arbolito);
    nodo* lista=inicLista();
    nodoArbol * aux = inicArbol();

    int numero,suma, legajito=0;
    char nombre[20];

    printf("que ejercicio desea realizar?\n");
    scanf("%d",& numero);

    switch(numero)
    {
    case 1:
        /*Hacer una función que sume el contenido de un árbol binario de
        números enteros. Considerar que la suma del árbol será igual a la
        suma del dato de la Raíz más la suma del subárbol izquierdo más la
        suma del subárbol derecho.*/

        suma=sumarArbol(arbolito);
        printf("Su arbolito de navidad suma %d\t",suma);
        break;
    case 2:
        /*Hacer tres funciones, una función que recorra y muestre la
        información del árbol en inorder, otra en posorder y otra en
        preorder.*/
        printf ("IN ORDER \n");
        mostrarInOrder (arbolito);
       /* printf ("PRE ORDER \n");
        mostrarPreOrder(arbolito);
        printf ("POST ORDER \n");
        mostrarPostOrder (arbolito);*/
        break;
    case 3:
        /*Hacer una función que copie el contenido del árbol en una lista
        vinculada.*/
        lista = pasaje(arbolito,lista);
        mostrarLista(lista);
        break;
    case 4:
        /*Hacer una función que busque un nodo por legajo.*/
        printf ("Que legajo desea buscar? \n");
        scanf ("%d", &legajito);
        aux = buscarLegajo(arbolito,legajito);
        mostrarNodoArbol(aux);
        break;
    case 5:
        /*Hacer una función que busque un nodo por nombre. Ojo!! El árbol
        está ordenado por legajo.*/
        printf("Que nombre desea buscar?");
        fflush(stdin);
        gets(nombre);
        aux = buscarNombre(arbolito,nombre);
        mostrarNodoArbol(aux);
        break;
    case 6:
        /*Hacer una función que cuente la cantidad de nodos del árbol.*/
        suma = cantidadNodos(arbolito);
        printf("La cantidad de nodos en el arbol es %d \t",suma);
        break;
    case 7:
        /*Hacer una función que cuente la cantidad de hojas del árbol.*/
        suma=cantidadHojas(arbolito);
        printf("La cantidad de hojas del arbol es %d \t",suma);
        break;
    case 8:
        /* Hacer una función que cuente la cantidad de niveles que tiene el
        árbol (pensar bastante).*/
        suma=niveles(arbolito);
        printf("La cantidad de niveles del arbol es %d\t",suma);
        break;
    case 9: /*Borrar nodo*/
        mostrarInOrder(arbolito);
        arbolito = borrarUnNodo(arbolito,23);
        printf ("\n\n");
        mostrarInOrder(arbolito);
        break;

    }

    return 0;
}

nodoArbol * inicArbol()
{
    return NULL;
}

nodoArbol * crearNodoArbol(int numero,char nombre[])
{
    nodoArbol * aux = (nodoArbol*) malloc (sizeof(nodoArbol));
    aux->legajo=numero;
    strcpy(aux->nombre,nombre);
    aux->derecha=NULL;
    aux->izquierda=NULL;
    return aux;
}

void mostrarPreOrder(nodoArbol * arbol)
{
    if (arbol!=NULL)
    {
        printf("NOMBRE:");
        puts(arbol->nombre);
        printf ("LEGAJO: %d \n", arbol->legajo);
        mostrarPreOrder(arbol->izquierda);
        mostrarPreOrder(arbol->derecha);
    }
}

nodoArbol * agregar(nodoArbol * arbol, nodoArbol * nn)
{
    if (arbol == NULL)
        arbol = nn;
    else if (nn->legajo < arbol->legajo)
        arbol->izquierda=agregar(arbol->izquierda,nn);
    else
        arbol->derecha = agregar (arbol->derecha,nn);
    return arbol;
}

nodoArbol * cargarArbol(nodoArbol * arbol)
{
    char seguir = 's', nombre[15];
    int num=0;

    //while (seguir == 's')
    //{
    /*printf ("Ingrese el legajo \n");
    scanf ("%d", &num);
    printf ("Ingrese el nombre \n");
    fflush (stdin);
    gets(nombre);*/
    nodoArbol *legajo1 = crearNodoArbol(17, "Mariana");
    nodoArbol *legajo2 = crearNodoArbol(33, "Rodrigo");
    nodoArbol * legajo3 = crearNodoArbol(55, "Pepe");
    nodoArbol *legajo4 = crearNodoArbol(22,"Sofia");
    nodoArbol *legajo8 = crearNodoArbol(23,"Lola");
    nodoArbol * legajo5 = crearNodoArbol(13, "Emma");
    nodoArbol * legajo6 = crearNodoArbol(5, "Lautaro");
    nodoArbol * legajo7 = crearNodoArbol(42, "Nicolas");
    arbol = agregar(arbol,legajo2);
    arbol = agregar(arbol,legajo1);
    arbol = agregar(arbol,legajo3);
    arbol = agregar(arbol,legajo4);
    arbol = agregar(arbol,legajo8);
    arbol = agregar(arbol,legajo5);
    arbol = agregar(arbol,legajo6);
    arbol = agregar(arbol,legajo7);


    //aux=crearNodoArbol(num,nombre);
    //arbol = agregar(arbol,aux);

    //  printf ("Desea cargar otro numero? \n");
    //fflush (stdin);
    //scanf("%c",&seguir);
    //}
    return arbol;
}
int buscar(nodoArbol* arbol, nodoArbol * nn)
{
    int rta=0;

    if(arbol!=NULL)
    {
        if(arbol->legajo==nn->legajo)
            rta=1;
        else if(arbol->legajo < nn->legajo)
            rta=buscar(arbol->derecha,nn);
        else
            rta=buscar(arbol->izquierda,nn);
    }
    return rta;
}
int sumarArbol(nodoArbol* arbolito)
{
    int suma=0;

    if(arbolito!=NULL)
    {
        suma= arbolito->legajo + sumarArbol(arbolito->derecha) + sumarArbol(arbolito->izquierda);
    }
    return suma;
}

void mostrarInOrder(nodoArbol * lito)
{
    if (lito != NULL)
    {
        mostrarInOrder(lito->izquierda);
        printf ("LEGAJO: %d \n", lito->legajo);
        printf ("NOMBRE:");
        puts (lito->nombre);
        mostrarInOrder(lito->derecha);
    }
}

void mostrarPostOrder(nodoArbol * lito)
{
    if (lito != NULL)
    {
        mostrarPostOrder(lito->izquierda);
        mostrarPostOrder(lito->derecha);
        printf ("LEGAJO: %d \n", lito->legajo);
        printf ("NOMBRE:");
        puts (lito->nombre);
    }
}
nodo* inicLista()
{
    return NULL;
}
void mostrarLista(nodo* lista)
{
    nodo* seg=lista;

    while(seg!=NULL)
    {
        printf("LEGAJO: %d \n",seg->legajo);
        printf("NOMBRE: ");
        puts(seg->nombre);

        seg=seg->sig;
    }
}
nodo * pasaje(nodoArbol* lito, nodo* lista)
{
    if(lito!=NULL)
    {
        nodo * aux = crearNodo(lito->legajo, lito->nombre);
        lista = agregarPrincipio(lista,aux);
        lista = pasaje (lito->izquierda, lista);
        lista= pasaje (lito->derecha, lista);
    }
    return lista;
}

nodo * crearNodo (int legajo, char nombre [] )
{
    nodo * aux = (nodo*) malloc (sizeof (nodo));
    aux->legajo=legajo;
    strcpy(aux->nombre,nombre);
    aux->sig=NULL;
    return aux;
}

nodo* agregarPrincipio(nodo* lista, nodo* nn)
{
    if(lista==NULL)
        lista=nn;
    else
    {
        nn->sig=lista;
        lista=nn;
    }
    return lista;
}
nodo* arbol_nodo(nodoArbol* lito)
{
    nodo* aux=(nodo*)malloc(sizeof(nodo));

    aux->legajo=lito->legajo;
    strcpy(aux->nombre,lito->nombre);
    aux->sig=NULL;

    return aux;
}

nodoArbol * buscarLegajo (nodoArbol* lito, int buscado)
{
    nodo * aux;
    if (lito != NULL)
    {
        if (buscado == lito->legajo)
            aux = lito;
        else if (buscado < lito->legajo)
            aux = buscarLegajo (lito->izquierda,buscado);
        else
            aux = buscarLegajo (lito->derecha, buscado);
    }
    return aux;
}

void mostrarNodoArbol (nodoArbol * a)
{
    printf("LEGAJO: %d \n",a->legajo);
    printf("NOMBRE: ");
    puts(a->nombre);
}
nodoArbol* buscarNombre(nodoArbol* lito, char nombre[])
{
    nodoArbol* aux;

    if(lito!=NULL)
    {
        if(strcmpi(lito->nombre,nombre)==0)
            aux=lito;
        else
        {
            aux=buscarNombre(lito->derecha,nombre);
            if(strcmpi(aux->nombre,nombre)!=0)
                aux=buscarNombre(lito->izquierda,nombre);
        }
    }
    return aux;
}
int cantidadNodos(nodoArbol* lito)
{
    int cantidad=0;

    if(lito!=NULL)
    {
        cantidad = cantidadNodos(lito->derecha) + cantidad;
        cantidad++;
        cantidad = cantidadNodos(lito->izquierda)+cantidad;
    }
    return cantidad;
}
int cantidadHojas(nodoArbol* lito)
{
    int cantidad=0;

    if(lito!=NULL)
    {
        cantidad = cantidadHojas(lito->izquierda) +cantidadHojas(lito->derecha);

        if(lito->derecha==NULL && lito->izquierda==NULL)
            cantidad++;
    }
    return cantidad;
}
/*int niveles(nodoArbol* lito) ///version nuestra, bien precaria
{
    int izq=0, der =0, cantidad =0;

    if(lito!=NULL)
    {
        izq = contarNivelesIzq (lito->izquierda);
        der = contarNivelesDer(lito->derecha);

        if (izq < der)
            cantidad =  der;
        else
            cantidad = izq;
    }
    return cantidad;
}*/

int niveles(nodoArbol* lito) ///version emma
{
    int izq=0, der =0, cantidad =-1;

    if(lito!=NULL)
    {
        izq=niveles(lito->izquierda);
        der=niveles(lito->derecha);
        if (der>izq)
            cantidad=1+der;
        else
            cantidad=1+izq;
    }

    return cantidad;
}

int contarNivelesIzq (nodoArbol * lito)
{
    int cantidad=0;
    if (lito !=NULL)
    {
        cantidad += contarNivelesIzq(lito->izquierda);
        cantidad++;
    }
    return cantidad;
}


int contarNivelesDer (nodoArbol * lito)
{
    int cantidad=0;
    if (lito !=NULL)
    {
        cantidad += contarNivelesDer(lito->derecha);
        cantidad++;
    }
    return cantidad;
}

nodoArbol * nodoMasDerecho(nodoArbol * arbol)
{
    nodoArbol * aux;
    if(arbol->derecha==NULL)
    {
        aux=arbol;
    }
    else
    {
        aux=nodoMasDerecho(arbol->derecha);
    }
    return aux;
}

nodoArbol * nodoMasIzquierdo(nodoArbol * arbol)
{
    nodoArbol * aux;
    if(arbol->izquierda==NULL)
    {
        aux=arbol;
    }
    else
    {
        aux=nodoMasIzquierdo(arbol->izquierda);
    }
    return aux;
}
nodoArbol * borrarUnNodo(nodoArbol * arbol, int dato)
{
    if(arbol!=NULL)
    {
        if(dato > arbol->legajo)
        {
            arbol->derecha=borrarUnNodo(arbol->derecha, dato);
        }
        else if (dato< arbol->legajo)
        {
            arbol->izquierda=borrarUnNodo(arbol->izquierda, dato);
        }
        else
        {
            if(arbol->izquierda!=NULL)
            {
                arbol->legajo= (nodoMasDerecho(arbol->izquierda))->legajo;
                arbol->izquierda=borrarUnNodo(arbol->izquierda, arbol->legajo);
            }
            else if(arbol->derecha!=NULL)
            {
                arbol->legajo=(nodoMasIzquierdo(arbol->derecha))->legajo;
                arbol->derecha=borrarUnNodo(arbol->derecha, arbol->legajo);
            }
            else
            {
                free(arbol);
                arbol=NULL;
            }
        }
    }
    return arbol;
}
