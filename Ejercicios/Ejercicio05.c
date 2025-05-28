/*Programa que cuente el número de palabras, de líneas y de caracteres de un fichero de
texto cuyo nombre se da como parámetro en la línea de comandos del DOS.*/

#include <stdio.h>
#include <string.h>

void contarPalabras(FILE*);
void contarLineas(FILE*);
void contarCaracteres(FILE*);
void leer(FILE* fichero, char[]);

int main(){
    FILE* fichero = fopen("prueba.txt", "r");
    contarPalabras(fichero);
    contarLineas(fichero);
    contarCaracteres(fichero);
    fclose(fichero);
    return 0;
}

void contarPalabras(FILE* fichero){
    char cadena[30];
    int p = 0;
    rewind(fichero);
    while(!feof(fichero)){
        leer(fichero, cadena);
        for (int i=0; i<strlen(cadena); i++){
            if (cadena[i] != ' ' && (cadena[i+1] == ' ' || cadena[i+1] == '\0') ){
                p++;
            }
        }
    }
    printf("\nPalabras: %d", p);
}

void contarLineas(FILE* fichero){
    char cadena[30];
    int l = 0;
    rewind(fichero);
    while(!feof(fichero)){
        leer(fichero, cadena);
        if (strlen(cadena) > 0){
            l++;
        }
    }
    printf("\nLineas: %d", l);
}

void contarCaracteres(FILE* fichero){
    char cadena[30];
    int c = 0;
    rewind(fichero);
    while(!feof(fichero)){
        leer(fichero, cadena);
        c += strlen(cadena);
    }
    printf("\nCaracteres: %d", c);
}

void leer(FILE* fichero, char cadena[]){
    fscanf(fichero, "\n%[^\n]", cadena);
}