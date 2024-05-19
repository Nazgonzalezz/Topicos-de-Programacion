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
    DNI: 41798196
    Entrega: entrega
    -----------------
    Apellido: Bravo
    Nombre: Pablo
    DNI: 40258506
    Entrega: entrega
    -----------------


    Comentarios (opcionales) que deseen hacer al docente sobre el TP:

*/
#include "funciones_estudiante.h"
#include "constantes.h"

int solucion(int argc, char* argv[])
{
    char vec [11][30] = {"--escala-de-grises","--aumentar-contraste","--reducir-contraste","--tonalidad-azul","--tonalidad-verde","--tonalidad-roja","--recortar","--rotar-derecha","--rotar-izquierda","--achicar","--monocromo"};
    int numArch = argc;
    bool band;

    argc--;
    while (argc>1)
    {
        band=false;
        for (int i=0;i<11;i++)
        {
            if (!band && strcmpi (argv [argc-1],vec [i]) == 0 )

                switch (i)
                {
                    case 0:
                        //--escala-de-grises
                        _escalaDeGrises(argv[numArch]);
                        band=true;
                        break;
                    case 1:
                        //--aumentar-contraste
                        _aumentarContraste( argv[numArch] );
                        band=true;
                        break;
                    case 2:
                        //--reducir-contraste
                        _reducirContraste(argv[numArch]);
                        band=true;
                        break;
                    case 3:
                        //--tonalidad-azul
                        _tonalidadAzul(argv[numArch]);
                        band=true;
                        break;
                    case 4:
                        //--tonalidad-verde
                        _tonalidadVerde(argv[numArch]);
                        band=true;
                        break;
                    case 5:
                        //--tonalidad-roja
                        _tonalidadRojo(argv[numArch]);
                        band=true;
                        break;
                    case 6:
                        //--recortar
                        band=true;
                        break;
                    case 7:
                        //--rotar-derecha
                        band=true;
                        break;
                    case 8:
                        //--rotar-izquierda
                        band=true;
                        break;
                    case 9:
                        //--achicar
                        band=true;
                        break;
                    case 10:
                        //--monocromo
                        band=true;
                        break;
                }
        }
        argc--;
    }
   // Aquí deben hacer el código que solucione lo solicitado.
 //   Todas las funciones utilizadas deben estar declaradas en este archivo, y en su respectivo .h

    return TODO_OK;
}
//----------------------------------------------------------------------------------------------------------------------------
void _tonalidadAzul(char argv[])
{
    t_metadata metadata;
    int tamano_imagen, num_pixeles, i,aux;
    FILE * PUNTERO_IMAGEN;
    FILE * PUNTERO_IMAGEN_MODIFICADA;
    char nombreImag[]={"unlamAzul.bmp"};

    PUNTERO_IMAGEN = fopen(argv, "r+b");
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

    _CopiarImagen (nombreImag,argv);

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
    fseek(PUNTERO_IMAGEN_MODIFICADA, metadata.comienzoImagen, SEEK_SET);
    fread(VECpixeles, sizeof(t_pixel), num_pixeles, PUNTERO_IMAGEN_MODIFICADA);

    for (i = 0; i < num_pixeles ; i++)
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
void _tonalidadRojo(char argv[])
{
    t_metadata metadata;
    int tamano_imagen, num_pixeles, i,aux;
    FILE * PUNTERO_IMAGEN, * PUNTERO_IMAGEN_MODIFICADA;
    char nombreImag[]={"unlamRojo.bmp"};
    PUNTERO_IMAGEN = fopen(argv, "r+b");
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
    _CopiarImagen (nombreImag,argv);

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
void _tonalidadVerde(char argv[])
{
    t_metadata metadata;
    int tamano_imagen, num_pixeles, i,aux;
    FILE * PUNTERO_IMAGEN, * PUNTERO_IMAGEN_MODIFICADA;
    char nombreImag[]={"unlamVerde.bmp"};
    PUNTERO_IMAGEN = fopen(argv, "r+b");
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
    _CopiarImagen (nombreImag,argv);

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
void _escalaDeGrises(char argv[])
{
    t_metadata metadata;
    int tamano_imagen, num_pixeles, i;
    FILE * PUNTERO_IMAGEN, * PUNTERO_IMAGEN_MODIFICADA;
    char nombreImag[]={"unlamEscalaGris.bmp"};

    PUNTERO_IMAGEN = fopen(argv, "r+b");
    if (PUNTERO_IMAGEN == NULL)
    {
        puts("Error al abrir el archivo original");
        return ARCHIVO_NO_ENCONTRADO;
    }

    PUNTERO_IMAGEN_MODIFICADA = fopen("unlamEscalaGris.bmp", "wb");
    if (PUNTERO_IMAGEN_MODIFICADA == NULL)
    {
        puts("Error al abrir el archivo modificado");
        return ARCHIVO_NO_ENCONTRADO;
    }
    _CopiarImagen (nombreImag,argv);

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
        VECpixeles[i].pixel[0] = ( VECpixeles[i].pixel[0] + VECpixeles[i].pixel[1] + VECpixeles[i].pixel[2] ) / 3;
        VECpixeles[i].pixel[1] = ( VECpixeles[i].pixel[0] + VECpixeles[i].pixel[1] + VECpixeles[i].pixel[2] ) / 3 ;
        VECpixeles[i].pixel[2] = ( VECpixeles[i].pixel[0] + VECpixeles[i].pixel[1] + VECpixeles[i].pixel[2] ) / 3 ;
    }

    fseek(PUNTERO_IMAGEN_MODIFICADA, metadata.comienzoImagen, SEEK_SET);
    fwrite(VECpixeles, sizeof(t_pixel), num_pixeles, PUNTERO_IMAGEN_MODIFICADA);

    free(VECpixeles);
    fclose(PUNTERO_IMAGEN);
    fclose(PUNTERO_IMAGEN_MODIFICADA);
}
//-------------------------------------------------------------------------------------------------------------------------------
void _aumentarContraste(char argv[])
{

    t_metadata metadata;
    int tamano_imagen, num_pixeles, i, j;
    FILE * PUNTERO_IMAGEN, * PUNTERO_IMAGEN_MODIFICADA;
    char nombreImag[]={"unlamAumContraste.bmp"};

    PUNTERO_IMAGEN = fopen(argv, "r+b");
    if (PUNTERO_IMAGEN == NULL)
    {
        puts("Error al abrir el archivo original");
        return ARCHIVO_NO_ENCONTRADO;
    }

    PUNTERO_IMAGEN_MODIFICADA = fopen("unlamAumContraste.bmp", "wb");
    if (PUNTERO_IMAGEN_MODIFICADA == NULL)
    {
        puts("Error al abrir el archivo modificado");
        return ARCHIVO_NO_ENCONTRADO;
    }
    _CopiarImagen (nombreImag,argv);

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

    for(i = 0; i < num_pixeles; i++)
    {
        for(j = 0; j< 3; j++)
        {
            float nuevoPixel = ( VECpixeles[i].pixel[j] - 127.5 ) * 25 + 127.5 ;
            if (nuevoPixel < 0)
                nuevoPixel = 0;
            else if (nuevoPixel > 255)
                nuevoPixel = 255;
            VECpixeles[i].pixel[j]=(unsigned char )nuevoPixel;
        }
    }

    fseek(PUNTERO_IMAGEN_MODIFICADA, metadata.comienzoImagen, SEEK_SET);
    fwrite(VECpixeles, sizeof(t_pixel), num_pixeles, PUNTERO_IMAGEN_MODIFICADA);

    free(VECpixeles);
    fclose(PUNTERO_IMAGEN);
    fclose(PUNTERO_IMAGEN_MODIFICADA);
}
//-------------------------------------------------------------------------------------------------------------------------------
void _reducirContraste(char argv[])
{

    t_metadata metadata;
    int tamano_imagen, num_pixeles, i, j;
    FILE * PUNTERO_IMAGEN, * PUNTERO_IMAGEN_MODIFICADA;
    char nombreImag[]={"unlamReduContraste.bmp"};

    PUNTERO_IMAGEN = fopen(argv, "r+b");
    if (PUNTERO_IMAGEN == NULL)
    {
        puts("Error al abrir el archivo original");
        return ARCHIVO_NO_ENCONTRADO;
    }

    PUNTERO_IMAGEN_MODIFICADA = fopen("unlamReduContraste.bmp", "wb");
    if (PUNTERO_IMAGEN_MODIFICADA == NULL)
    {
        puts("Error al abrir el archivo modificado");
        return ARCHIVO_NO_ENCONTRADO;
    }
    _CopiarImagen (nombreImag,argv);

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

    for(i = 0; i < num_pixeles; i++)
    {
        for(j = 0; j< 3; j++)
        {
            float nuevoPixel = ( VECpixeles[i].pixel[j] - 127.5 ) * 0.25 + 127.5 ;
            if (nuevoPixel < 0)
                nuevoPixel = 0;
            else if (nuevoPixel > 255)
                nuevoPixel = 255;
            VECpixeles[i].pixel[j]=(unsigned char )nuevoPixel;
        }
    }

    fseek(PUNTERO_IMAGEN_MODIFICADA, metadata.comienzoImagen, SEEK_SET);
    fwrite(VECpixeles, sizeof(t_pixel), num_pixeles, PUNTERO_IMAGEN_MODIFICADA);

    free(VECpixeles);
    fclose(PUNTERO_IMAGEN);
    fclose(PUNTERO_IMAGEN_MODIFICADA);
}
//-------------------------------------------------------------------------------------------------------------------------------
void _CopiarImagen (const char *nombImagen, char argv[])
{
    FILE *PUNTERO_IMAGEN = fopen(argv, "rb");
    if (PUNTERO_IMAGEN == NULL) {
        puts("Error al abrir el archivo original");
        return ARCHIVO_NO_ENCONTRADO;
    }

    FILE *PUNTERO_IMAGEN_MODIFICADA = fopen(nombImagen, "wb");
    if (PUNTERO_IMAGEN_MODIFICADA == NULL) {
        puts("Error al abrir el archivo modificado");
        return ARCHIVO_NO_ENCONTRADO;
    }

    fseek(PUNTERO_IMAGEN, 0, SEEK_END);
    int tamnArch = ftell(PUNTERO_IMAGEN);
    fseek(PUNTERO_IMAGEN, 0, SEEK_SET);


    unsigned char *memoTempo = (unsigned char *)malloc(tamnArch);
    if (memoTempo == NULL)
    {
        puts("No se pudo asignar memoria");
        fclose(PUNTERO_IMAGEN);
        fclose(PUNTERO_IMAGEN_MODIFICADA);
        return NO_SE_PUEDE_CREAR_ARCHIVO;
    }
    fread(memoTempo,1,tamnArch, PUNTERO_IMAGEN);
    fwrite(memoTempo,1, tamnArch, PUNTERO_IMAGEN_MODIFICADA);

    free(memoTempo);
    fclose(PUNTERO_IMAGEN);
    fclose(PUNTERO_IMAGEN_MODIFICADA);
}
//--------------------------------------------------------------------------------------------------------------------------
