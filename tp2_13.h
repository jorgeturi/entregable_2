#ifndef TP2_13_H_INCLUDED
#define TP2_13_H_INCLUDED

///agregar +1 al strlen del string
///yo asignaba direcciones de memoria en los strings dentro de palabra->palabra. Tengo que copiar
typedef struct
{
    char* palabra;
    int repeticiones;
} palabra;

void liberar_palabras (palabra** p_palabras, int cantidad_palabras);

palabra** _agregar_palabra (palabra** p_palabras, char*palabra_a_agregar, int cantidad_palabras);
palabra** _eliminar_palabra (palabra** p_palabras, char*palabra_a_eliminar, int cantidad_palabras);
palabra** agregar_palabra (palabra** p_palabras, char*palabra_a_agregar, int* cantidad_palabras);
palabra** eliminar_palabra (palabra** p_palabras, char*palabra_a_eliminar, int* cantidad_palabras);
palabra** inicializar (char*palabra_a_agregar, int* cantidad_palabras);

#endif // TP2_13_H_INCLUDED
