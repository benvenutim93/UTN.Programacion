#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <stdio.h>
#include "jugador.h"
#include "entrenadores.h"
#include "admin_usuario.h"


void imprimirCabecera(char cabecera[]);
void imprimirOpcionesSubMenuADMIN();
void imprimirOpcionesMenuPrincipal();
int ingresarOpcion();
void switchSubMenuADMIN(celda[],int,int,arbolEntrenador*);
int switchMenuPrincipal(celda[],int,int,arbolEntrenador*);
void iniciarMenu(celda[], int, int,arbolEntrenador*);
void imprimirOpcionesSubMenuENTRENADOR();
int switchSubMenuENTRENADOR(celda[],int,int,arbolEntrenador*);
void imprimirOpcionesSubMenuAdminJugador ();
int switchSubMenuAdminJugador(celda[],int,int,arbolEntrenador*);
void imprimirOpcionesSubMenuAdminEntrenador();
int switchSubMenuAdminEntrenador(celda[],int,int,arbolEntrenador*);
void imprimirOpcionesSubMenuAdminEstadistica();
int switchSubMenuAdminEstadistica(celda[],int,int);
void imprimirOpcionesBuscarJugador ();
int switchOpcionesBuscarJugador(celda[],int,int);


#endif // MENU_H_INCLUDED
