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
int __diasDeLaFecha (T_FECHA *fecha)
{
    int dias=0,anio,mes ;

    for (anio=1601; anio< fecha->anio ; anio++)
    {
        if( EsBisiesto(anio) )
            dias+=366;
        else
            dias+=365;
    }
    for ( mes=1; mes < fecha->mes; mes++)
    {
        dias+= CantDiasDelMes(mes, fecha->anio);
    }
    dias += fecha->dia;
    return dias;
}
//---------------------------------------------------------------------------------------------------

int _difEntreFechas(T_FECHA * fechaMayor,T_FECHA * fechaMenor)
{
    int dif, aux;
    aux=__diasDeLaFecha(fechaMenor);
    dif=__diasDeLaFecha(fechaMayor);
    dif -= aux;
    return dif;
}
//----------------------------------------------------------------------------------------------------
int DiferenciaEntreFechas(T_FECHA * fecha1, T_FECHA * fecha2)
{
    int diasDiferencia;
    if (fecha1->anio > fecha2->anio)
        diasDiferencia=_difEntreFechas(fecha1,fecha2);
    else if (fecha1->anio == fecha2->anio)
    {
        if (fecha1->mes > fecha2->mes)
        {
            diasDiferencia=_difEntreFechas(fecha1,fecha2);
        }
        else if (fecha1->mes == fecha2->mes)
        {
            if (fecha1->dia > fecha2->dia)
                diasDiferencia=_difEntreFechas(fecha1,fecha2);
            else if (fecha1->dia == fecha2->dia)
                diasDiferencia=0;
            else //fecha1->dia < fecha2->dia
                diasDiferencia=_difEntreFechas(fecha2,fecha1);
        }
        else //fecha1->mes < fecha2->mes
        {
            diasDiferencia=_difEntreFechas(fecha2,fecha1);
        }
    }
    else  //fecha1->anio < fecha2->anio
        diasDiferencia=_difEntreFechas(fecha2,fecha1);
    return diasDiferencia;
}


















