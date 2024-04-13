#ifndef FECHA_H
#define FECHA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int dia;
    int mes;
    int anio;
} T_FECHA;

#endif // FECHA_H_



T_FECHA IngresarFecha();
bool EsFechaValida(T_FECHA);
int CantDiasDelMes(int,int);
bool EsBisiesto(int);
void MostrarFecha(T_FECHA);
void SumarDiasAFecha(int, T_FECHA *);

int DiferenciaEntreFechas(T_FECHA *,T_FECHA *);
int _difEntreFechas(T_FECHA *fechaMayor,T_FECHA *fechaMenor);
int __diasDeLaFecha (T_FECHA *fecha);


void DiaDeLaSemana();
int DiasDelAnioAFecha();
int FechaADiaDelAnio();





