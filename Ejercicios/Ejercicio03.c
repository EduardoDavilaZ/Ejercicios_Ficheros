/*Programa que permita contar el número de caracteres de un fichero de texto ya creado,
mostrando en pantalla aquellos que coincidan con el carácter 'a'. Deberá hacer una copia
del fichero en otro, pero sustituyendo ese carácter por el carácter ‘*’. Los nombres de los
dos ficheros se pasarán como parámetros en la línea de comandos.*/

#include <stdio.h>
#include <string.h>

void contar(void);
void sustituir(void);
void sustitucion(char[]);
void leer(FILE*, char[]);
void grabar(FILE*, char[]);

int main(){
    contar();
    sustituir();
    return 0;
}

void contar(void){
    FILE* fichero = fopen("prueba.txt", "r");
    char cadena[30];
    int cont = 0;

    while(!feof(fichero)){
        leer(fichero, cadena);
        cont += strlen(cadena);
    }

    printf("\nCaracteres: %d", cont);

    fclose(fichero);
}

void sustituir(void){
    FILE* fichero = fopen("prueba.txt", "r");
    FILE* temp = fopen("temp.txt", "w");

    char cadena[30];
    while(!feof(fichero)){
        leer(fichero, cadena);
        sustitucion(cadena);
        grabar(temp, cadena);
    }

    fclose(fichero);
    fclose(temp);
}

void sustitucion(char cadena[]){
    for (int i=0; i<strlen(cadena); i++){
        if (cadena[i] == 'a'){
            cadena[i] = '*';
        }
    }
}

void leer(FILE* fichero, char cadena[]){
    fscanf(fichero, "\n%[^\n]", cadena);
}

void grabar(FILE* fichero, char cadena[]){
    fprintf(fichero, "\n%s", cadena);
}