#include "fecha.h"

T_FECHA IngresarFecha()
{
    T_FECHA fecha;
    puts("Ingrese una fecha en el formato dd/mm/aaaa: ");
    scanf("%d/%d/%d",&fecha.dia,&fecha.mes,&fecha.anio);
    while(! EsFechaValida(fecha))
    {
        puts("Fecha invalida. Ingresa de nuevo: ");
        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
    }
    return fecha;
}
//---------
bool EsFechaValida(T_FECHA fech)
{
    if(fech.anio < 1601)
        return false;

    if(fech.mes < 1 || fech.mes > 12)
        return false;

    if(fech.dia < 1 || fech.dia > CantDiasDelMes(fech.mes, fech.anio))
        return false;

    return true;
}
//---------
int CantDiasDelMes(int mes, int anio)
{
    int DiasPorMes[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(mes == 2 && EsBisiesto(anio))
        return 29;
    return DiasPorMes[mes];
}
//---------
bool EsBisiesto(int anio)
{
    return anio % 4 == 0  && (anio % 100 != 0 || anio % 400 == 0);
}
//---------
void MostrarFecha(T_FECHA fecha)
{
    printf("\n%d/%d/%d", fecha.dia,fecha.mes,fecha.anio);
}
//----------------------------------------------------------------------------------------------------
void SumarDiasAFecha(int diasASumar,T_FECHA * fecha)
{
    int CantDeDiasMes,CantDeDiasAnio,TotalDias;
    CantDeDiasMes=CantDiasDelMes(fecha->mes,fecha->anio);

    if (diasASumar + fecha->dia <= CantDeDiasMes)
    {
        fecha->dia+=diasASumar;
    }
    else
    {
        TotalDias = diasASumar + fecha->dia;
        if( EsBisiesto(fecha->anio) )
            CantDeDiasAnio=366;
        else
            CantDeDiasAnio=365;
        while(TotalDias > CantDeDiasAnio)
        {
            TotalDias -= CantDeDiasAnio;
            fecha->anio++;
            if( EsBisiesto(fecha->anio) )
                CantDeDiasAnio=366;
            else
                CantDeDiasAnio=365;
        }
        CantDeDiasMes=CantDiasDelMes(fecha->mes,fecha->anio);
        while(TotalDias > CantDeDiasMes)
        {
            TotalDias -= CantDeDiasMes;
            fecha->mes++;
            CantDeDiasMes=CantDiasDelMes(fecha->mes,fecha->anio);
        }
        fecha->dia=TotalDias;
    }
}
//----------------------------------------------------------------------------------------------------
int SUMARDiaMesAnio(T_FECHA fechaMayor, T_FECHA fechaMenor)
{
    int CantDeDiasMes,SumaDeDias=0,CantDeDiasAnio;
    while(fechaMenor.anio < fechaMayor.anio)
    {
        if( EsBisiesto(fechaMenor.anio) )
            CantDeDiasAnio=366;
        else
            CantDeDiasAnio=365;
        SumaDeDias+=CantDeDiasAnio;
        fechaMenor.anio++;
    }
    while(fechaMenor.mes < fechaMayor.mes)
    {
        CantDeDiasMes=CantDiasDelMes(fechaMenor.mes,fechaMenor.anio);
        SumaDeDias+= CantDeDiasMes;
        fechaMenor.mes ++;
    }
    SumaDeDias+=fechaMenor.dia;
    while(fechaMenor.dia < fechaMayor.dia)
    {
        SumaDeDias++;
        fechaMenor.dia++;
    }
    return SumaDeDias;
}
//----------------------------------------------------------------------------------------------------
int SUMARDiaMesMesAnio(T_FECHA fechaMayor, T_FECHA fechaMenor)
{
    int CantDeDiasMes,SumaDeDias=0,CantDeDiasAnio,aux=1;
    while(fechaMenor.anio < fechaMayor.anio)
    {
        if( EsBisiesto(fechaMenor.anio) )
            CantDeDiasAnio=366;
        else
            CantDeDiasAnio=365;
        SumaDeDias+=CantDeDiasAnio;
        fechaMenor.anio++;
    }
    CantDeDiasMes=CantDiasDelMes(fechaMayor.mes,fechaMayor.anio);
    SumaDeDias += CantDeDiasMes - fechaMayor.dia;
    fechaMayor.mes++;
    while(fechaMayor.mes <= 12)
    {
        CantDeDiasMes=CantDiasDelMes(fechaMayor.mes,fechaMayor.anio);
        SumaDeDias+= CantDeDiasMes;
        fechaMenor.mes ++;
    }
        while(aux < fechaMenor.mes)
    {
        CantDeDiasMes=CantDiasDelMes(aux,fechaMayor.anio);
        SumaDeDias+= CantDeDiasMes;
        fechaMenor.mes ++;
    }
    SumaDeDias += fechaMenor.dia;
    return SumaDeDias;
}
//----------------------------------------------------------------------------------------------------
int DiferenciaEntreFechas(T_FECHA * fecha1, T_FECHA * fecha2)
{
    int totalDias=0;
    switch(true)
    {
    case fecha1->anio > fecha2->anio:
        switch(true)
        {
        case (fecha1->mes) > (fecha2->mes):
            switch(true)
            {
            case (fecha1->dia) > (fecha2->dia):
                totalDias= SUMARDiaMesAnio(*fecha1,*fecha2);
                break;
            case fecha1->dia == fecha2->dia:
                totalDias = SUMARDiaMesAnio(*fecha1,*fecha2);
                break;
            case fecha1->dia < fecha2->dia:
                totalDias = SUMARDiaMesMesAnio(*fecha1,*fecha2);
                break;
            }
            break;
        case fecha1->mes == fecha2->mes:
            switch(true)
            {
            case fecha1->dia > fecha2->dia:
                totalDias = SUMARDiaMesAnio(*fecha1,*fecha2);
                break;
            case fecha1->dia == fecha2->dia:
                totalDias = SUMARDiaMesAnio(*fecha1,*fecha2);
                break;
            case fecha1->dia < fecha2->dia:
                totalDias = SUMARDiaMesMesAnio(*fecha1,*fecha2);
                break;
            }
            break;
        case fecha1->mes < fecha2->mes:
            switch(true)
            {
            case fecha1->dia > fecha2->dia:
                totalDias = SUMARDiaMesMesAnio(*fecha1,*fecha2);
                break;
            case fecha1->dia == fecha2->dia:
                totalDias = SUMARDiaMesMesAnio(*fecha1,*fecha2);
                break;
            case fecha1->dia < fecha2->dia:
                totalDias = SUMARDiaMesMesAnio(*fecha1,*fecha2);
                break;
            }
            break;
        }
        break;
    case fecha1->anio == fecha2->anio:
        switch(true)
        {
        case fecha1->mes > fecha2->mes:
            switch(true)
            {
            case fecha1->dia > fecha2->dia:
                totalDias = SUMARDiaMesAnio(*fecha1,*fecha2);
                break;
            case fecha1.->dia == fecha2->dia:
                totalDias = SUMARDiaMesAnio(*fecha1,*fecha2);
                break;
            case fecha1->dia < fecha2->dia:
                totalDias = SUMARDiaMesMesAnio(*fecha2,*fecha1);
                break;
            }
            break;
        case fecha1->mes == fecha2->mes:
            switch(true)
            {
            case fecha1->dia > fecha2->dia:
                totalDias = SUMARDiaMesAnio(*fecha1,*fecha2);
                break;
            case fecha1->dia == fecha2->dia:
                totalDias = 0;
                break;
            case fecha1->dia < fecha2->dia:
                totalDias = SUMARDiaMesAnio(*fecha2,*fecha1);
                break;
            }
            break;
        case fecha1->mes < fecha2->mes:
            switch(true)
            {
            case fecha1->dia > fecha2->dia:
                totalDias = SUMARDiaMesMesAnio(*fecha2,*fecha1);
                break;
            case fecha1->dia == fecha2->dia:
                totalDias = SUMARDiaMesAnio(*fecha2,*fecha1);
                break;
            case fecha1->dia < fecha2->dia:
                totalDias = SUMARDiaMesAnio(*fecha2,*fecha1);
                break;
            }
            break;
        }
        break;
    case fecha1->anio < fecha2->anio:
        switch(true)
        {
        case fecha1->mes > fecha2->mes:
            switch(true)
            {
            case fecha1->dia > fecha2->dia:
                totalDias = SUMARDiaMesMesAnio(*fecha2,*fecha1);
                break;
            case fecha1->dia == fecha2->dia:
                break;
            case fecha1->dia < fecha2->dia:
                totalDias = SUMARDiaMesMesAnio(*fecha2,*fecha1);
                break;
            }
            break;
        case fecha1->mes == fecha2->mes:
            switch(true)
            {
            case fecha1->dia > fecha2->dia:
                totalDias = SUMARDiaMesMesAnio(*fecha2,*fecha1);
                break;
            case fecha1->dia == fecha2->dia:
                totalDias = SUMARDiaMesAnio(*fecha2,*fecha1);
                break;
            case fecha1->dia < fecha2->dia:
                totalDias = SUMARDiaMesAnio(*fecha2,*fecha1);
                break;
            }
            break;
        case fecha1->mes < fecha2->mes:
            switch(true)
            {
            case fecha1->dia > fecha2->dia:
                totalDias = SUMARDiaMesMesAnio(*fecha2,*fecha1);
                break;
            case fecha1->dia == fecha2->dia:
                totalDias = SUMARDiaMesAnio(*fecha2,*fecha1);
                break;
            case fecha1->dia < fecha2->dia:
                totalDias = SUMARDiaMesAnio(*fecha2,*fecha1);
                break;
            }
            break;
        }
        break;
    }
    return totalDias;
}
//---------

















