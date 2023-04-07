#ifndef CHARSET_H_INCLUDED
#define CHARSET_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 256

/**
 * @brief Estructura para administrar conjuntos de caracteres
 * (versión 2)
 */
typedef struct {
    char v[MAX_CHARS];
} charset;

typedef charset* pcharset;


charset* charset_init();
void charset_free(charset *cs);
void charset_add(charset *cs, unsigned char c);
void charset_remove(charset *cs, unsigned char c);
int charset_in(charset *cs, unsigned char c);
void charset_add_str (charset *cs, char *s);
void charset_add_range (charset *cs,unsigned char from, unsigned char to);
void charset_print(charset *cs);

#endif // CHARSET_H_INCLUDED
