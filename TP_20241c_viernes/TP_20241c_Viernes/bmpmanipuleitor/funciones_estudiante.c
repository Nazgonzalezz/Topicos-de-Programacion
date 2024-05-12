/*
    Integrantes del grupo.
    Si alguno de los integrantes del grupo dejara la materia, completar de todos modos sus datos, aclarando que no entrega.
    -----------------
    Apellido: Gonzalez
    Nombre: Nazarena Araceli
    DNI: 42414940
    Entrega:
    -----------------
    Apellido: Salinas
    Nombre: Ezequiel
    DNI:
    Entrega:
    -----------------
    Apellido: Lopez
    Nombre: Uriel
    DNI:
    Entrega:
    -----------------
    Apellido: Bravo
    Nombre: Pablo
    DNI: 40258506
    Entrega:
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
void tonalidadAzul()
{
    FILE *PUNTERO_IMAGEN;
    t_metadata metadata;
    int tamano_imagen ,num_pixeles,i;
    PUNTERO_IMAGEN = fopen("imagen.png", "rb");
    if (PUNTERO_IMAGEN == NULL) {
        puts("Error al abrir el archivo");
        return 1;
    }
    tamano_imagen = _tamanioDeImagen("imagen.png");
    num_pixeles = tamano_imagen / sizeof(t_pixel);

    // Leo TODOS los registros de la imagen (sin contar el encabezado) en el VECpixeles
    t_pixel *VECpixeles = (t_pixel *)malloc(num_pixeles * sizeof(t_pixel)); //creo el vector dinamico STRUC PIXEL
    fseek(PUNTERO_IMAGEN, metadata.comienzoImagen, SEEK_SET);  //aca pongo el puntero a partir del encabezado
    fread(VECpixeles, sizeof(t_pixel), num_pixeles, PUNTERO_IMAGEN);
    
    for (i = 0; i < num_pixeles; i++)  //aumento 50% azul
    {
        if (VECpixeles[i].pixel[2] + 50 <= 255)
            VECpixeles[i].pixel[2] += 50;
        else
            VECpixeles[i].pixel[2] = 255;
    }

    // Escribir los datos de píxeles modificados de vuelta al
    fseek(PUNTERO_IMAGEN, metadata.comienzoImagen, SEEK_SET);
    fwrite(VECpixeles, sizeof(t_pixel), num_pixeles, PUNTERO_IMAGEN);

    free(VECpixeles);
    fclose(PUNTERO_IMAGEN);
}
//----------------------------------------------------------------------------------------------------------------------------
int _tamanioDeImagen(char* nombreArchi)
{
    FILE *PUNTERO_IMAGEN;
    t_metadata metadata;
    int tamano_imagen ,num_pixeles,i;

    PUNTERO_IMAGEN = fopen( *nombreArchi , "rb");
    if (PUNTERO_IMAGEN == NULL) {
        puts("Error al abrir el archivo");
        return -1;
    }
    // Leo la info del encabezado de la imagen en metadata (gracias a esto saco la info del tamanio y cantidad de pixeles)
    fread(&metadata, sizeof(t_metadata), 1, PUNTERO_IMAGEN);

    // Determinar el tamaño de los datos de píxeles en bytes
    tamano_imagen = metadata.tamArchivo - metadata.tamEncabezado;

    fclose(PUNTERO_IMAGEN);
    return tamano_imagen;
}
//----------------------------------------------------------------------------------------------------------------------------
