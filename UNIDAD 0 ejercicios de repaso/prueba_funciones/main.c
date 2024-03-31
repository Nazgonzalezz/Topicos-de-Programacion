#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
int main()
{
    printf("El factorial de 4 es %d",obtenerFactorial(4));
    printf("\nEl calculo combinatorio de 4 tomado de 2 es: %d",calculoCombinatorio(4,2));
    printf("\nLa suma de los primeros numeros naturales de 8 es %d",LeerYsumarNaturales(8));
    printf("\nLa suma de los primeros numeros pares de 8 es %d",LeerYsumarPares(8));
    printf("\nLa suma de los primeros numeros pares menores que  8 es %d",LeerYsumarParesMenores(8));
    printf("\nEs un numero primo el 37?");
    if(EsUnNumeroPrimo(37)==1)
        printf("\nSI");
    else
        printf("\nNO");
    return 0;
}
