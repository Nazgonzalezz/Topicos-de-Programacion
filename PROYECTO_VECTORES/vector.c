#include "vector.h"
bool vectorCrear(T_VECTOR * vectorr)
{
    (*vectorr).ce -0 ;
    return true;
}
int vectorOrdInsertar(T_VECTOR * vectorr, int elem)
{

}
/*
int vectorOrdBuscar(T_VECTOR * vectorr, int elem)
{
    int i=0;
    while(i < vectorr->ce && elem > vectorr->vec[i])
    {
        i++;
    }
    if(i == vector->ce || elem != vectorr->vec[i])
        return -1;
    return i;
}
*/
int vectorOrdBuscar(T_VECTOR * vectorr, int elem)
{
    int pos;
    return _vectorOrdBuscarInt(vectorr,elem,&pos) ? pos : -1;
}
bool _vectorOrdBuscarInt(T_VECTOR * vectorr, int elem, int * pos)
{
    int i=0;
    while(i < vectorr->ce && elem > vectorr->vec[i])
    {
        i++;
    }
    * pos=i;
    if(i == vector->ce || elem != vectorr->vec[i])
        return false;
    return true;
}

bool vectorEliminarElem(T_VECTOR * vectorr, int elem)
{
    int posElim= vectorOrdBuscar(vectorr,elem);
    if(posElim == -1)
        return false;
    for(i=posElim;i<=vectorr->ce-2;i++)
    {
        vectorr->vec[i]=vectorr->vec[i-1];
    }
    vectorr->ce--;
    return true;
}
void vectorVaciar(T_VECTOR * vectorr,)
{
    vectorr->ce=0;
}
void vectorEliminar(T_VECTOR * vectorr)
{

}
int eliminarOrdEliminarDupli(T_VECTOR * vectorr)
{

}
int eliminarDesordEliminarDupli(T_VECTOR * vectorr)
{

}
int vectorOrdenarInsertar(T_VECTOR* vector, int elem)
{
    if(vector->ce == TAM)
        return VEC_LLENO;
    int posIns;
    bool existe= _vectorOrdBuscarInt(vector,elem,&posIns);
    if(existe)
        return DUPLICADO;
    for(int i=vector->ce-1;i>=posIns;i--)
    {
        vector->vec[i+1] = vector->vec[i];
    }
    vector->vec[posIns]=elem;
    vector->ce++;
    return TODO_OK;
}
















