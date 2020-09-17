#include <stdio.h>
#include <stdlib.h>
#include "pila.h"


int cantidadYprecios (float*);
float montoTotal (int, float);
float totalConDescuento (float, int, float*);
void factura (int, float, float, float, float);
float venta(int);
float ventasDia();

int main()
{

    int cantidadProductos =0;
    //float precioUnidad=0, precioParcial =0, precioFinal =0, descuento =0;
    float sumaDia=0;

    sumaDia = venta (cantidadProductos);
    //sumaDia = ventasDia();
    printf ("La venta es %f \n", sumaDia);


    /*cantidadProductos = cantidadYprecios(&precioUnidad);
    printf ("Ud ha comprado %i productos con un valor unitario de %.2f \n \n", cantidadProductos, precioUnidad);

    precioParcial = montoTotal(cantidadProductos, precioUnidad);
    printf ("El valor total de su compra es de %.2f \n \n", precioParcial);

    precioFinal = totalConDescuento( precioParcial, cantidadProductos, &descuento);
    printf ("Su compra con descuento es de %.2f \n \n", precioFinal);

    factura (cantidadProductos, precioUnidad, precioParcial, descuento, precioFinal);*/
}

int cantidadYprecios(float* precio)
{
    int cantidad =0;

    printf ("Cuantos productos ha comprado? \n");
    scanf ("%i", &cantidad);
    printf ("Que valor tiene el producto? \n");
    scanf ("%f", precio);

    return cantidad;
}

float montoTotal( int cantidad, float precio)
{
    float total =0;
    total = cantidad * precio;
    return total;
}

float totalConDescuento(float totalCompra, int cantidadProductos, float* dcto)
{
    float porcentajeDescuento =0, nuevoValor =0;

    if ((totalCompra > 1000) && (cantidadProductos >10))
    {
        porcentajeDescuento = 0.15;
        (*dcto) = totalCompra * porcentajeDescuento;
        nuevoValor = totalCompra - (*dcto);
    }
    else if ((totalCompra >2000) && (cantidadProductos >= 25))
    {
        porcentajeDescuento = 0.25;
        (*dcto)= totalCompra * porcentajeDescuento;
        nuevoValor = totalCompra - (*dcto);
    }
    else
    {
        nuevoValor = totalCompra;
    }
    return nuevoValor;
}

void factura (int productos, float precioUnitario, float totalParcial, float dcto, float totalFinal)
{
    printf ("................Empresa PIRULO .................\n");
    printf ("Cantidad de productos ................ %i un. \n", productos);
    printf ("Precio por producto ...................$ %.2f \n", precioUnitario);
    printf ("Total parcial .........................$ %.2f \n", totalParcial);
    printf ("Descuento aplicado....................$ %.2f \n", dcto);
    printf ("Monto a pagar.........................$ %.2f \n", totalFinal);
}

float venta (int cantidadProductos)
{
    //int cantidadProductos =0;
    float precioUnidad=0, precioParcial =0, precioFinal =0, descuento =0;

    cantidadProductos = cantidadYprecios(&precioUnidad);
    printf ("Ud ha comprado %i productos con un valor unitario de %.2f \n \n", cantidadProductos, precioUnidad);

    precioParcial = montoTotal(cantidadProductos, precioUnidad);
    printf ("El valor total de su compra es de %.2f \n \n", precioParcial);

    precioFinal = totalConDescuento( precioParcial, cantidadProductos, &descuento);
    printf ("Su compra con descuento es de %.2f \n \n", precioFinal);

    factura (cantidadProductos, precioUnidad, precioParcial, descuento, precioFinal);

    return precioFinal;
}

/*float ventasDia()
{
    float suma=0;
    int productosVendidos=0;

    {
    suma = venta();


    return suma;
} */
