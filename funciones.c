#include "funciones.h"

/**
*   recibe el nombre de un archivo y otro para crear una copia
*   QUEDA UNA COPIA EN EL DIRECTORIO. A ELIMINAR CUANDO SE CONSIDERE NECESARIO
**/
void generar_copia(char* nombre_archivo_original, char* nombre_archivo_copia)
{

    FILE *archivo_original;
    FILE *archivo_copiado;
    char caracter = 'a';

    archivo_original = fopen(nombre_archivo_original, "r");
    if (archivo_original == NULL)
    {
        perror("error al abrir el archivo original\n");
        exit (1);
    }

    archivo_copiado = fopen(nombre_archivo_copia, "w");
    if (archivo_copiado == NULL)
    {
        perror("error al abrir el archivo para copiar\n");
        fclose(archivo_original);
    }

    while ((caracter = fgetc(archivo_original)) != EOF)     ///mientra no llege a fin de linea tomo caracter por caracter
    {
        fputc(caracter, archivo_copiado);                   ///lo pongo en el archivo que copio
    }

    fclose(archivo_original);
    fclose(archivo_copiado);

}


/**
*   Devuelve un conjunto de caracteres con los deseados
*   estos si los veo en el archivo me los quiero quedar
**/
charset* conjunto_caracteres_deseados()
{

    charset *caracteres = charset_init();
    charset_add_range(caracteres,'A','Z');
    charset_add_range(caracteres,'a','z');
    charset_add_str(caracteres,"αινσϊ");    ///por que las vocales con acento me las toma asi?

    return caracteres;

}


/**
*   Carga palabras, tomando como referencia los caracteres que me quiero quedar
*   Por referencia recibe la cantidad de palabras, así tambien se devuelve la cantidad nueva
*
*   Crea un puntero temporal de caracteres, guarda una seguidilla de caracteres deseados hasta encontrar uno que no lo sea
*   Guarda ese caracter en palabras
*   Se repite hasta recorrer toda la copia Y LA ELIMINA AL TERMINAR
**/
palabra** cargar_palabras_texto(char* nombre_copia, charset* caracteres, int* cantidad_palabras)
{

    palabra** palabras = NULL;
    char caracter = 'a';
    char* palabra;
    int largo_palabra = 0;

    FILE* archivo_copiado = fopen(nombre_copia, "r");               ///abro la copia

    palabras = inicializar("a", cantidad_palabras);                 ///inicializo palabras
    palabras = eliminar_palabra(palabras,"a",cantidad_palabras);    ///borro la que puse, no me interesa

    while ((caracter=fgetc(archivo_copiado)) != EOF)
    {

        while (charset_in(caracteres,caracter) == 1 && caracter != EOF)     ///si el caracter que leo me interesa
        {
            largo_palabra = largo_palabra + 1;                              ///aumento longitud
            caracter = fgetc(archivo_copiado);                              ///sigo leyendo
        }

        palabra = malloc(sizeof(char)*largo_palabra+1);                     ///por el fin de linea +1

        fseek(archivo_copiado, -largo_palabra-1, SEEK_CUR);                 ///voy para atras la palabra +1 por la que no interesaba y lei

        palabra = fgets(palabra, largo_palabra+1, archivo_copiado);         ///me quedo con las palabras que me interesan
        ///no entendi por que tuve que poner ese +1
        if (strlen(palabra)>0)  ///ya que lo que agarro puede ser un espacio*********** POR QUE??? no me di cuenta hasta probar
        {
            palabras = agregar_palabra (palabras, palabra, cantidad_palabras);  ///agrego la palabra a las palabras
        }

        fseek(archivo_copiado, 1, SEEK_CUR); ///salteo el espacio

        largo_palabra = 0;  ///reseteo para una nueva palabra auxiliar
        free(palabra);
    }

    fclose(archivo_copiado);    ///terminado, cierro la copia y la borro
    remove(nombre_copia);    ///ya que no se usa mas.. pero si otra funcion la necesitara ,donde me conviene ponerlo?

    return palabras;
}



void imprimir_palabras(palabra** palabras, int cantidad_palabras){

    for(int i=0; i<cantidad_palabras ; i++){

        printf("%s. Se encuentra repetida %d veces\n", palabras[i]->palabra, palabras[i]->repeticiones);

    }

}


///********************************************* ORDENAMIENTO NO SE COMO HACER
int comparador( const void *a, const void *b )
{

    struct palabra* palabra1 = (struct palabra*)a;
    struct palabra* palabra2 = (struct palabra*)b;

    //(struct palabra*)palabra1->palabra;
    ///quiero comparar los strings pero me tira un error al intentar obtener el puntero a la palabra y mandarlo a strcmp

    return 0;
}



/*palabra** _preordenar(palabra** palabras, int cantidad_palabras )
{
    palabra** p_nuevo = NULL;
    int* posiciones;
    posiciones = calloc (cantidad_palabras, sizeof(int));

    int a ;
    p_nuevo = palabras;


    for(int i=0; i<cantidad_palabras-1 ; i++){
/// -1 la primera es menor
    a = strcmp(palabras[i]->palabra, palabras[i+1]->palabra);
        posiciones[i] = a;
    }

    palabra* aux = NULL;
    aux = malloc(sizeof(palabras));
     for(int i=0; i<cantidad_palabras-1 ; i=i+2){
            if (posiciones[i] == 1)
            aux->palabra = malloc(sizeof(palabras[i]->palabra));
            aux->palabra = strcpy(aux->palabra,palabras[i]->palabra);

            palabras[i] = palabras[i+1];

            if(posiciones[i] == -1)
            palabras[i] = palabras[i-1];

            if(posiciones[i] == 0)
            palabras[i] = palabras[i];
    }

    printf("el vector de posiciones\n");
    for(int i=0; i<cantidad_palabras-1 ; i++){
            printf("%d",posiciones[i]);}
    printf("\n");



    return p_nuevo;
}
*/
