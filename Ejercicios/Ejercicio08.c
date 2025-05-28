/*Escribir un programa en C que codifique y decodifique varias líneas de texto usando el
procedimiento de cambiar cada carácter por el carácter siguiente en el código ASCII.
Almacenar el texto codificado en un archivo de modo que pueda ser recuperado y
decodificado en cualquier momento. El programa debe incluir las siguientes
características:
    • Introducir el texto desde teclado, codificarlo y almacenar el texto codificado en
    un archivo de datos.
    • Recuperar el texto codificado y mostrarlo en su forma codificada.
    • Recuperar el texto codificado, decodificarlo y mostrarlo en su forma
    decodificada.*/

#include <stdio.h>
#include <string.h>

void codificar(void);
void descodificar(void);
void leer(FILE*, char[]);
void grabar(FILE*, char[]);

int main(){
    codificar();
    descodificar();
    return 0;
}

void codificar(void){
    FILE* fichero = fopen("prueba.txt", "r");
    FILE* resultado = fopen("codificado.txt", "w");

    char cadena[30];

    while(!feof(fichero)){
        leer(fichero, cadena);
        for (int i=0; i<strlen(cadena); i++){
            cadena[i] = cadena[i] + 1;
        }
        grabar(resultado, cadena);
    }

    fclose(fichero);
    fclose(resultado);
}

void descodificar(void){
    FILE* fichero = fopen("codificado.txt", "r");
    FILE* resultado = fopen("descodificado.txt", "w");

    char cadena[30];

    while(!feof(fichero)){
        leer(fichero, cadena);
        for (int i=0; i<strlen(cadena); i++){
            cadena[i] = cadena[i] - 1;
        }
        grabar(resultado, cadena);
    }

    fclose(fichero);
    fclose(resultado);
}

void leer(FILE* fichero, char cadena[]){
    fscanf(fichero, "\n%[^\n]", cadena);
}

void grabar(FILE* fichero, char cadena[]){
    fprintf(fichero, "\n%s", cadena);
}