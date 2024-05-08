#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED

void** matrizCrear(size_t tamElem, int filas, int columnas);
void matrizDestruir(void** mat, int filas);
int matrizSumarDP(int orden,int mat[][orden]);
int matrizSumarDS(int orden,int mat[][orden]);
int matrizSumarTriangSupDS(int orden, int mat[][orden]);
int matrizSumarTriangInfDS(int orden, int mat[][orden]);
#endif // MATRICES_H_INCLUDED
