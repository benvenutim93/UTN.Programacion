#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*13) Suponer un juego de cartas en el que en cada mano se reparten dos cartas por jugador.
Un jugador gana la mano cuando la suma de sus cartas es mayor que las del contrario y al hacerlo coloca todas
las cartas (las de el y las de su rival) en su pila de puntos. En caso de empate (y para simplificar)
siempre gana el jugador1. Simular la ejecución del juego de tal manera que dada una pila MAZO
(con un numero de elementos múltiplo de cuatro) distribuya las cartas en las pilas PUNTOSJUG1 y PUNTOSJUG2
 como si estos hubieran jugado. Utilizar las pilas auxiliares que crea conveniente.*/

int main()
{

    Pila jugador1, jugador2, mazo,puntosJ1,puntosJ2,J1aux,J2aux;

    inicpila(&jugador1);
    inicpila(&jugador2);
    inicpila(&mazo);
    inicpila(&puntosJ1);
    inicpila(&puntosJ2);
    inicpila(&J1aux);
    inicpila(&J2aux);

    int suma=0, suma2=0;

    char seguir='s';


    while(seguir=='s')
    {
        leer(&mazo);
        leer(&mazo);
        leer(&mazo);
        leer(&mazo);

        printf("Desea ingresar mas cartas al mazo? s/n \n");
        fflush(stdin);
        scanf("%c",&seguir);
    }

    while(!pilavacia(&mazo))
    {

        apilar(&jugador1,desapilar(&mazo));
        apilar(&jugador2,desapilar(&mazo));
        apilar(&J1aux,desapilar(&mazo));
        apilar(&J2aux,desapilar(&mazo));

        suma= (tope(&jugador1))+(tope(&J1aux));
        suma2=(tope(&jugador2))+(tope(&J2aux));

        if(suma>=suma2){

            apilar(&puntosJ1,desapilar(&jugador1));
            apilar(&puntosJ1,desapilar(&J1aux));
            apilar(&puntosJ1,desapilar(&jugador2));
            apilar(&puntosJ1,desapilar(&J2aux));
        }
        else
        {
            apilar(&puntosJ2,desapilar(&jugador1));
            apilar(&puntosJ2,desapilar(&J1aux));
            apilar(&puntosJ2,desapilar(&jugador2));
            apilar(&puntosJ2,desapilar(&J2aux));
        }


    }
    mostrar(&puntosJ1);
    mostrar(&puntosJ2);

    return 0;
}
