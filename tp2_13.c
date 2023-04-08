#include "tp2_13.h"
#include <stdlib.h>

void liberar_palabras (palabra** p_palabras, int cantidad_palabras)
{

    for (int i=0 ; i<cantidad_palabras ; i++)
    {
        free (p_palabras[i]->palabra);
        free (p_palabras[i]);
    }
    free(p_palabras);

}



/**
*   ESTA FUNCION SE LLAMA SI LA PALABRA NO SE ENCONTRABA
*   Recibe:
*   puntero con palabras, palabra a agregar, cantidad de palabras al momento
***
*   Devuelve:
*   puntero con palabras nuevo con la palabra nueva
*
**/
palabra** _agregar_palabra (palabra** p_palabras, char*palabra_a_agregar, int cantidad_palabras)
{
    ///creo puntero nuevo y asigno lugar para un puntero mas del que traia
    palabra** p_nuevo = NULL;
    p_nuevo = (palabra**) malloc (sizeof(palabra*)*(cantidad_palabras+1));

    int longitud_palabra = 0;

    for (int i=0 ; i<cantidad_palabras ; i++)  ///por cada palabra que traia
    {
        p_nuevo[i] =(palabra*) malloc (sizeof(palabra));   ///reservo lugar del tipo palabra para cada palabra
        longitud_palabra = strlen( p_palabras[i]->palabra);///veo la longitud previa de la palabra que venia en el puntero viejo
        p_nuevo[i]->palabra = malloc(sizeof(char)*longitud_palabra+1);///reservo lugar para cada palabra segun largo de palabra

        p_nuevo[i]->palabra = strcpy(p_nuevo[i]->palabra, p_palabras[i]->palabra);           ///la palabra vieja la copio
        p_nuevo[i]->repeticiones = p_palabras[i]->repeticiones; ///igual que las repeticiones que traia
    }

    longitud_palabra = strlen(palabra_a_agregar);   ///IDEM ANTERIOR con la palabra nueva
    p_nuevo[cantidad_palabras] =(palabra*) malloc (sizeof(palabra));
    p_nuevo[cantidad_palabras]->palabra = malloc(sizeof(char)*longitud_palabra+1);
    p_nuevo[cantidad_palabras]->palabra = strcpy(p_nuevo[cantidad_palabras]->palabra, palabra_a_agregar);
    p_nuevo[cantidad_palabras]->repeticiones = 0;

    return p_nuevo;
}

palabra** _eliminar_palabra (palabra** p_palabras, char*palabra_a_eliminar, int cantidad_palabras)
{
    ///creo puntero nuevo y asigno lugar para un puntero mas del que traia
    palabra** p_nuevo = NULL;
    p_nuevo = (palabra**) malloc (sizeof(palabra*)*(cantidad_palabras-1));

    int longitud_palabra = 0;
    int n=0;
    for (int i=0 ; i<cantidad_palabras ; i++)  ///por cada palabra que traia
    {

        if (p_palabras[i]->palabra != palabra_a_eliminar){
        p_nuevo[n] =(palabra*) malloc (sizeof(palabra));   ///reservo lugar del tipo palabra para cada palabra
        longitud_palabra = strlen( p_palabras[i]->palabra);///veo la longitud previa de la palabra que venia en el puntero viejo
        p_nuevo[n]->palabra = malloc(sizeof(char)*longitud_palabra);///reservo lugar para cada palabra segun largo de palabra

        p_nuevo[n]->palabra = p_palabras[i]->palabra;           ///la palabra vieja la copio
        p_nuevo[n]->repeticiones = p_palabras[i]->repeticiones; ///igual que las repeticiones que traia
        n = n + 1 ;
        }
    }

    return p_nuevo;
}






palabra** agregar_palabra (palabra** p_palabras, char*palabra_a_agregar, int* cantidad_palabras)
{
    palabra** p_a_devolver = NULL;
    int existia = 0;

    for (int i=0 ; i<*cantidad_palabras ; i++)  ///veo si alguna palabra coincide
    {
        if (strcmp(palabra_a_agregar,p_palabras[i]->palabra) == 0)   ///si es igual a 0 es que eran iguales
        {
            p_palabras[i]->repeticiones =  p_palabras[i]->repeticiones + 1;
            existia = 1;
            return p_palabras;  ///una vez que encontre que existia devuelvo el puntero incrementado en la repeticion
        }
    }

    if (existia == 0)
    {
        p_a_devolver = _agregar_palabra(p_palabras, palabra_a_agregar, *cantidad_palabras);
        liberar_palabras(p_palabras, *cantidad_palabras); /// libero puntero viejo
        *cantidad_palabras = *cantidad_palabras + 1;
    }

    return p_a_devolver;
}


palabra** eliminar_palabra (palabra** p_palabras, char*palabra_a_eliminar, int* cantidad_palabras)
{
    palabra** p_a_devolver = NULL;
    int existia = 0;

    for (int i=0 ; i<*cantidad_palabras ; i++)  ///veo si existe
    {
        if (strcmp(palabra_a_eliminar,p_palabras[i]->palabra) == 0)   ///si es igual a 0 es que eran iguales
        {
            if (p_palabras[i]->repeticiones >= 1)
            {
                p_palabras[i]->repeticiones =  p_palabras[i]->repeticiones - 1;
                return p_palabras;  ///una vez que encontre que existia devuelvo el puntero incrementado en la repeticion

            }else{
                p_a_devolver = _eliminar_palabra(p_palabras,palabra_a_eliminar,*cantidad_palabras);
                *cantidad_palabras = *cantidad_palabras - 1;
                return p_a_devolver;
            }

        }
    }

    if (existia == 0)
    {
        return p_palabras;
    }

    return p_palabras;///NUNCA LLEGA ACA PERO PONGO PARA QUE NO MOLESTE LA FUNCION
}



palabra** inicializar (char*palabra_a_agregar, int* cantidad_palabras)
{
    palabra ** resultado = NULL;
    ///guardo lugar para puntero del tipo palabra
    resultado =(palabra**) malloc (sizeof(palabra*));

    ///a donde apuntan esos punteros guardo lugar para que en cada uno entre lo que ocupa palabra
    resultado[0] =(palabra*) malloc (sizeof(palabra));
    ///casteo porque lo vi

    int longitud_palabra = strlen(palabra_a_agregar) + 1; ///+1 por fin de linea

    ///en la primer posicion, reservo lugar para ponerle una palabra
    resultado[0]->palabra = malloc(longitud_palabra*sizeof(char));

    resultado[0]->palabra = palabra_a_agregar;
    resultado[0]->repeticiones = 0;

    *cantidad_palabras = 1;

    return resultado;
}
