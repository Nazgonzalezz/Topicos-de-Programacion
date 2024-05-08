#include <stdio.h>
#include <stdlib.h>
#include "matrices.h"

#define SIN_MEM 1

int main()
{
    //int matriz[4][4]=
    //{
     // {1,  2,  3,  4},
     // {5,  6,  7,  8},
     // {9,  10, 11, 12},
     //{13, 14, 15, 16}
    //};
    orden = 4
    int(*matriz)[4]= malloc(sizeof(int)* orden * orden);

    if(!matriz)
    {
      return SIN_MEM;
    }
    int cont= 1;
    for(int i=0; i<orden; i++)
    {
      for(int j=0;j <orden; j++)
      {
        matriz[i][j]=cont;
      }
    }

    printf("Suma DP: %d\n",matrizSumarDP(orden,matriz));
    printf("Suma DS: %d\n",matrizSumarDS(orden,matriz));
    printf("Suma TriSupDS: %d\n", matrizSumarTriangSupDS(orden,matriz));

    free(matriz);

    return 0;
}
