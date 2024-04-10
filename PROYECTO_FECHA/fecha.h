#ifndef FECHA_H_
#define FECHA_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#endif // FECHA_H_

typedef struct{
    int dia;
    int mes;
    int anio;
} T_FECHA;

T_FECHA IngresarFecha();
bool EsFechaValida(T_FECHA);
int CantDiasDelMes(int,int);
bool EsBisiesto(int);
void MostrarFecha(T_FECHA);
void SumarDiasAFecha(int, T_FECHA *);

int DiferenciaEntreFechas(T_FECHA *,T_FECHA *);
int SUMARDiaMesAnio(T_FECHA, T_FECHA);

void DiaDeLaSemana();
int DiasDelAnioAFecha();
int FechaADiaDelAnio();






