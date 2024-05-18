/*
    Integrantes del grupo.
    Si alguno de los integrantes del grupo dejara la materia, completar de todos modos sus datos, aclarando que no entrega.
    -----------------
    Apellido: Gonzalez
    Nombre: Nazarena Araceli
    DNI: 42414940
    Entrega: entrega
    -----------------
    Apellido: Salinas
    Nombre: Ezequiel
    DNI:
    Entrega: no entrega
    -----------------
    Apellido: Lopez
    Nombre: Uriel
    DNI:
    Entrega: entraga
    -----------------
    Apellido: Bravo
    Nombre: Pablo
    DNI: 40258506
    Entrega: entrega
    -----------------

    Comentarios (opcionales) que deseen hacer al docente sobre el TP:

*/

#include "constantes.h"

int solucion(int argc, char* argv[])
{
/*
    Aquí deben hacer el código que solucione lo solicitado.
    Todas las funciones utilizadas deben estar declaradas en este archivo, y en su respectivo .h
*/
    return TODO_OK;
}
//----------------------------------------------------------------------------------------------------------------------------
void _tonalidadAzul()
{
    t_metadata metadata;
    int tamano_imagen, num_pixeles, i,aux;
    FILE * PUNTERO_IMAGEN, * PUNTERO_IMAGEN_MODIFICADA;
    char nombreImag[]={"unlamAzul.bmp"};
    PUNTERO_IMAGEN = fopen("unlam.bmp", "r+b");
    if (PUNTERO_IMAGEN == NULL)
    {
        puts("Error al abrir el archivo original");
        return ARCHIVO_NO_ENCONTRADO;
    }


    PUNTERO_IMAGEN_MODIFICADA = fopen("unlamAzul.bmp", "wb");
    if (PUNTERO_IMAGEN_MODIFICADA == NULL)
    {
        puts("Error al abrir el archivo modificado");
        return ARCHIVO_NO_ENCONTRADO;
    }
    _CopiarImagen (nombreImag);

    fseek(PUNTERO_IMAGEN, 2 ,SEEK_SET);
    fread(&metadata.tamArchivo, 4 , 1 , PUNTERO_IMAGEN);
    fseek(PUNTERO_IMAGEN,4,SEEK_CUR);
    fread(&metadata.comienzoImagen,4,1,PUNTERO_IMAGEN);
    fread(&metadata.tamEncabezado,4,1,PUNTERO_IMAGEN);
    fread(&metadata.ancho,4,1,PUNTERO_IMAGEN);
    fread(&metadata.alto,4,1,PUNTERO_IMAGEN);
    fseek(PUNTERO_IMAGEN,2,SEEK_CUR);
    fread(&metadata.profundidad,2,1,PUNTERO_IMAGEN);

    tamano_imagen = metadata.tamArchivo - metadata.tamEncabezado;
    num_pixeles = tamano_imagen / sizeof(t_pixel);

    t_pixel *VECpixeles = (t_pixel *)malloc(num_pixeles * sizeof(t_pixel)); 
    fseek(PUNTERO_IMAGEN, metadata.comienzoImagen, SEEK_SET);  
    fread(VECpixeles, sizeof(t_pixel), num_pixeles, PUNTERO_IMAGEN);

    for (i = 0; i < num_pixeles; i++) 
    {
        if (VECpixeles[i].pixel[0] + 50 <= 255)
            VECpixeles[i].pixel[0] += 50;

        else
            VECpixeles[i].pixel[0] = 255;
        VECpixeles[i].pixel[1] = 0;
        VECpixeles[i].pixel[2] = 0;
    }
    fseek(PUNTERO_IMAGEN_MODIFICADA, metadata.comienzoImagen, SEEK_SET);
    fwrite(VECpixeles, sizeof(t_pixel), num_pixeles, PUNTERO_IMAGEN_MODIFICADA);

    free(VECpixeles);
    fclose(PUNTERO_IMAGEN);
    fclose(PUNTERO_IMAGEN_MODIFICADA);
}
//-------------------------------------------------------------------------------------------------------------------------------
void _tonalidadRojo()
{
    t_metadata metadata;
    int tamano_imagen, num_pixeles, i,aux;
    FILE * PUNTERO_IMAGEN, * PUNTERO_IMAGEN_MODIFICADA;
    char nombreImag[]={"unlamRojo.bmp"};
    PUNTERO_IMAGEN = fopen("unlam.bmp", "r+b");
    if (PUNTERO_IMAGEN == NULL)
    {
        puts("Error al abrir el archivo original");
        return ARCHIVO_NO_ENCONTRADO;
    }


    PUNTERO_IMAGEN_MODIFICADA = fopen("unlamRojo.bmp", "wb");
    if (PUNTERO_IMAGEN_MODIFICADA == NULL)
    {
        puts("Error al abrir el archivo modificado");
        return ARCHIVO_NO_ENCONTRADO;
    }
    _CopiarImagen (nombreImag);

    fseek(PUNTERO_IMAGEN, 2 ,SEEK_SET);
    fread(&metadata.tamArchivo, 4 , 1 , PUNTERO_IMAGEN);
    fseek(PUNTERO_IMAGEN,4,SEEK_CUR);
    fread(&metadata.comienzoImagen,4,1,PUNTERO_IMAGEN);
    fread(&metadata.tamEncabezado,4,1,PUNTERO_IMAGEN);
    fread(&metadata.ancho,4,1,PUNTERO_IMAGEN);
    fread(&metadata.alto,4,1,PUNTERO_IMAGEN);
    fseek(PUNTERO_IMAGEN,2,SEEK_CUR);
    fread(&metadata.profundidad,2,1,PUNTERO_IMAGEN);

    tamano_imagen = metadata.tamArchivo - metadata.tamEncabezado;
    num_pixeles = tamano_imagen / sizeof(t_pixel);

    
    t_pixel *VECpixeles = (t_pixel *)malloc(num_pixeles * sizeof(t_pixel)); 
    fseek(PUNTERO_IMAGEN, metadata.comienzoImagen, SEEK_SET); 
    fread(VECpixeles, sizeof(t_pixel), num_pixeles, PUNTERO_IMAGEN);

    for (i = 0; i < num_pixeles; i++)  
    {
        if (VECpixeles[i].pixel[2] + 50 <= 255)
            VECpixeles[i].pixel[2] += 50;

        else
            VECpixeles[i].pixel[2] = 255;
        VECpixeles[i].pixel[1] = 0;
        VECpixeles[i].pixel[3] = 0;
    }
    fseek(PUNTERO_IMAGEN_MODIFICADA, metadata.comienzoImagen, SEEK_SET);
    fwrite(VECpixeles, sizeof(t_pixel), num_pixeles, PUNTERO_IMAGEN_MODIFICADA);

    free(VECpixeles);
    fclose(PUNTERO_IMAGEN);
    fclose(PUNTERO_IMAGEN_MODIFICADA);
}
//-------------------------------------------------------------------------------------------------------------------------------
void _tonalidadVerde()
{
    t_metadata metadata;
    int tamano_imagen, num_pixeles, i,aux;
    FILE * PUNTERO_IMAGEN, * PUNTERO_IMAGEN_MODIFICADA;
    char nombreImag[]={"unlamVerde.bmp"};
    PUNTERO_IMAGEN = fopen("unlam.bmp", "r+b");
    if (PUNTERO_IMAGEN == NULL)
    {
        puts("Error al abrir el archivo original");
        return ARCHIVO_NO_ENCONTRADO;
    }


    PUNTERO_IMAGEN_MODIFICADA = fopen("unlamVerde.bmp", "wb");
    if (PUNTERO_IMAGEN_MODIFICADA == NULL)
    {
        puts("Error al abrir el archivo modificado");
        return ARCHIVO_NO_ENCONTRADO;
    }
    _CopiarImagen (nombreImag);

    fseek(PUNTERO_IMAGEN, 2 ,SEEK_SET);
    fread(&metadata.tamArchivo, 4 , 1 , PUNTERO_IMAGEN);
    fseek(PUNTERO_IMAGEN,4,SEEK_CUR);
    fread(&metadata.comienzoImagen,4,1,PUNTERO_IMAGEN);
    fread(&metadata.tamEncabezado,4,1,PUNTERO_IMAGEN);
    fread(&metadata.ancho,4,1,PUNTERO_IMAGEN);
    fread(&metadata.alto,4,1,PUNTERO_IMAGEN);
    fseek(PUNTERO_IMAGEN,2,SEEK_CUR);
    fread(&metadata.profundidad,2,1,PUNTERO_IMAGEN);

    tamano_imagen = metadata.tamArchivo - metadata.tamEncabezado;
    num_pixeles = tamano_imagen / sizeof(t_pixel);

    t_pixel *VECpixeles = (t_pixel *)malloc(num_pixeles * sizeof(t_pixel)); 
    fseek(PUNTERO_IMAGEN, metadata.comienzoImagen, SEEK_SET); 
    fread(VECpixeles, sizeof(t_pixel), num_pixeles, PUNTERO_IMAGEN);

    for (i = 0; i < num_pixeles; i++)
    {
        if (VECpixeles[i].pixel[1] + 50 <= 255)
            VECpixeles[i].pixel[1] += 50;

        else
            VECpixeles[i].pixel[1] = 255;
        VECpixeles[i].pixel[0] = 0;
        VECpixeles[i].pixel[2] = 0;
    }
    fseek(PUNTERO_IMAGEN_MODIFICADA, metadata.comienzoImagen, SEEK_SET);
    fwrite(VECpixeles, sizeof(t_pixel), num_pixeles, PUNTERO_IMAGEN_MODIFICADA);

    free(VECpixeles);
    fclose(PUNTERO_IMAGEN);
    fclose(PUNTERO_IMAGEN_MODIFICADA);
}
//-------------------------------------------------------------------------------------------------------------------------------
void _CopiarImagen (char * nombImagen )
{
    FILE * PUNTERO_IMAGEN, * PUNTERO_IMAGEN_MODIFICADA;
    cabeceraBMP_t cabecera;
    t_metadata metadata;
    unsigned char buffer[1024];
    size_t bytesRead;
    PUNTERO_IMAGEN = fopen("unlam.bmp", "rb");
    if (PUNTERO_IMAGEN == NULL)
    {
        puts("Error al abrir el archivo original");
        return ARCHIVO_NO_ENCONTRADO;
    }

    PUNTERO_IMAGEN_MODIFICADA = fopen( nombImagen , "wb");
    if (PUNTERO_IMAGEN_MODIFICADA == NULL)
    {
        puts("Error al abrir el archivo modificado");
        return ARCHIVO_NO_ENCONTRADO;
    }

     while ((bytesRead = fread(buffer, 1, sizeof(buffer), PUNTERO_IMAGEN)) > 0)
    {
        fwrite(buffer, 1, bytesRead, PUNTERO_IMAGEN_MODIFICADA);
    }

    fclose(PUNTERO_IMAGEN);
    fclose(PUNTERO_IMAGEN_MODIFICADA);
}
//---------------------------------------------------------------------------------------------------------------------------------
