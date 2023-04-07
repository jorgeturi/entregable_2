#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "charset.h"
#include "tp2_13.h"

palabra** cargar_palabras_texto(char* nombre_copia, charset* caracteres, int* cantidad_palabras);
void generar_copia(char* nombre_archivo_original, char* nombre_archivo_copia);
charset* conjunto_caracteres_deseados();
void imprimir_palabras(palabra** palabras, int cantidad_palabras);



#endif // FUNCIONES_H_INCLUDED
