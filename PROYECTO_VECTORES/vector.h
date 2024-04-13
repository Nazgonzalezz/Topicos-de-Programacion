#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdbool.h>

#define TAM 100
#define DUPLICADO 1
#define TODO_OK 0
#define VEC_LLENO 2

typedef struct
{
    int vec[TAM];
    size_t ce;
} T_VECTOR;

bool vectorCrear(T_VECTOR * vectorr);
int vectorOrdInsertar(T_VECTOR * vectorr, int elem);
int vectorOrdBuscar(T_VECTOR * vectorr, int elem);
bool _vectorOrdBuscarInt(T_VECTOR * vectorr, int elem, int * pos);
bool vectorEliminarElem(T_VECTOR * vectorr, int elem);
void vectorVaciar(T_VECTOR * vectorr,);
void vectorEliminar(T_VECTOR * vectorr);
int eliminarOrdEliminarDupli(T_VECTOR * vectorr);
int eliminarDesordEliminarDupli(T_VECTOR * vectorr);
#endif

