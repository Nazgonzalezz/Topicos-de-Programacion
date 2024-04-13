#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fecha.h"
int main()
{
    T_FECHA fecha1,fecha2;
    int dife;

    puts("\n PRIMERA FECHA FECHA");
    fecha1=IngresarFecha(fecha1);

    puts("\n SEGUNDA FECHA");
    fecha2=IngresarFecha(fecha2);

    dife=DiferenciaEntreFechas(&fecha1,&fecha2);
    printf("\n\La diferencia entre las fechas es: %d",dife);

    return 0;
}
