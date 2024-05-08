#include <stddef.h>
#include "matrices.h"

void** matrizCrear(size_t tamElem, int filas, int columnas)
{
  void** mat = malloc(sizeof(void*) * filas);
  if(!mat)
    return NULL;
  void** ult = mat + filas -1;
  for(void** i = mat; i <= ult ; i++)
  {
    *i= malloc(tamElem * columnas);
    if(!*i)
      matrizDestruir(mat, i-mat);
      return NULL;
  }
  return mat;
}
void matrizDestruir(void** mat, int filas)
{
  void** ult = mat + filas -1;
  for(void** i = mat; i <= ult ; i++)
  {
    free(*i);
  }
  free(mat);
}
int matrizSumarDP(int orden,int mat[][orden])
{
  int suma = 0;
  for(int i=0; i < orden; i++)
  {
    suma += mat[i][i];
  }
  return suma;
}
int matrizSumarDS(int orden,int mat[][orden])
{
  int suma = 0;
  for(int i=0, j= orden -1; i < orden; i++, j--)
  {
    suma += mat[i][j];
  }
  return suma;
}
int matrizSumarTriangSupDS(int orden, int mat[][orden])
{
  int suma = 0;
  for(int i=0, limJ= orden -2; i <= orden - 2; i++, limJ--)
  {
    for(int j=0; j <= limJ; j++)
    {
        suma += mat[i][j];
    }
  }
  return suma;
}
