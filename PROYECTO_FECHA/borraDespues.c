int DiferenciaEntreFechas(T_FECHA * fecha1,T_FECHA * fecha2)
{
    int SumaDeDias=0;
    T_FECHA fechaMayor,fechaMenor;
    switch(true)
    {
    case fecha1->anio > fecha2.anio:
        switch(true)
        {
        case fecha1.mes > fecha2.mes:
            switch(true)
            {
            case fecha1.dia > fecha2.dia:
                //todo lo de fecha1 es mayor a fecha2, sumo todo
                break;
            case fecha1.dia == fecha2.dia:
                //
                break;
            case fecha1.dia < fecha2.dia:
                break;
            }
            break;
        case fecha1.mes == fecha2.mes:
            switch(true)
            {
            case fecha1.dia > fecha2.dia:
                break;
            case fecha1.dia == fecha2.dia:
                break;
            case fecha1.dia < fecha2.dia:
                break;
            }
            break;
        case fecha1.mes < fecha2.mes:
            switch(true)
            {
            case fecha1.dia > fecha2.dia:
                break;
            case fecha1.dia == fecha2.dia:
                break;
            case fecha1.dia < fecha2.dia:
                break;
            }
            break;
        }
        break;
    case fecha1.anio == fecha2.anio:
        switch(true)
        {
        case fecha1.mes > fecha2.mes:
            switch(true)
            {
            case fecha1.dia > fecha2.dia:
                break;
            case fecha1.dia == fecha2.dia:
                //sumar diferencia entre meses nomas
                break;
            case fecha1.dia < fecha2.dia:
                break;
            }
            break;
        case fecha1.mes == fecha2.mes:
            switch(true)
            {
            case fecha1.dia > fecha2.dia:
                //sumo las direncia entre dias:
                break;
            case fecha1.dia == fecha2.dia:
                //no sumo nada, las fechas son iguales
                break;
            case fecha1.dia < fecha2.dia:
                //sumo las direncia entre dias:
                break;
            }
            break;
        case fecha1.mes < fecha2.mes:
            switch(true)
            {
            case fecha1.dia > fecha2.dia:
                break;
            case fecha1.dia == fecha2.dia:
                break;
            case fecha1.dia < fecha2.dia:
                break;
            }
            break;
        }
        break;
    case fecha1.anio < fecha2.anio:
        switch(true)
        {
        case fecha1.mes > fecha2.mes:
            switch(true)
            {
            case fecha1.dia > fecha2.dia:
                break;
            case fecha1.dia == fecha2.dia:
                break;
            case fecha1.dia < fecha2.dia:
                break;
            }
            break;
        case fecha1.mes == fecha2.mes:
            switch(true)
            {
            case fecha1.dia > fecha2.dia:
                break;
            case fecha1.dia == fecha2.dia:
                //aca solo sumo los anios que le faltan a fecha1 para llegar a fecha2
                break;
            case fecha1.dia < fecha2.dia:
                break;
            }
            break;
        case fecha1.mes < fecha2.mes:
            switch(true)
            {
            case fecha1.dia > fecha2.dia:
                break;
            case fecha1.dia == fecha2.dia:
                break;
            case fecha1.dia < fecha2.dia:
                break;
            }
            break;
        }
        break;
    }
    return SumaDeDias;
}
