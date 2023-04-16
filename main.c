#include "tp2_13.h"
#include "charset.h"
#include "funciones.h"

int main()
{
/// VARIABLES
    palabra** palabras = NULL;
    int cantidad_palabras = 0;

    charset* caracteres;

    char nombre_copia[] = "copia.txt";
    char nombre_original[] = "archivo.txt";

/// INICIO

    generar_copia(nombre_original,nombre_copia); ///copio el archivo original para manejarme con una copia

    caracteres = conjunto_caracteres_deseados(); ///genero un conjunto con caracteres que me interesan obtener

    palabras = cargar_palabras_texto(nombre_copia, caracteres, &cantidad_palabras); ///cargo palabras, segun el conjunto deseado
         //printf("en la dir %x, apunto a %x que es la primer palabra y tiene%s\n",palabras, palabras[0] ,palabras[0]->palabra);
    qsort(palabras, cantidad_palabras, sizeof(palabras), comparador);
         //palabras = _preordenar(palabras, cantidad_palabras);

    imprimir_palabras(palabras, cantidad_palabras);

    return 0;
}
