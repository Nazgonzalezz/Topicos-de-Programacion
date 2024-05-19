#ifndef FUNCIONES_ESTUDIANTE_H_INCLUDED
#define FUNCIONES_ESTUDIANTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "constantes.h"
#include "estructuras.h"
int solucion(int argc, char* argv[]);

void _escalaDeGrises(char argv[]);
void _aumentarContraste( char argv[]);
void _CopiarImagen (const char nombImagen[],char argv[]);
void _tonalidadAzul(char argv[]);
void _tonalidadRojo(char argv[]);
void _tonalidadVerde(char argv[]);
void _reducirContraste(char argv[]);


#endif // FUNCIONES_ESTUDIANTE_H_INCLUDED
