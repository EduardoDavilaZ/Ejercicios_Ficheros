/*Escribir un programa que lea un fichero, indicado como parámetro en la llamada al
programa, hasta encontrar el final del archivo, buscando la palabra que contenga el mayor
número de vocales.*/

#include <stdio.h>
#include <string.h>

void buscar(void);
void analizar(char[], char[], int*);
int contarVocales(char[]);
char esVocal(char);
void leer(FILE*, char[]);

int main(){
    buscar();
    return 0;
}

void buscar(void){
    FILE* fichero = fopen("prueba.txt", "r");
    char cadena[30];
    char palabra[30];
    int max;
    while(!feof(fichero)){
        leer(fichero, cadena);
        analizar(cadena, palabra, &max);
    }
    fclose(fichero);
    printf("Palabra con mas vocales: %s", palabra);
}

void analizar(char cadena[], char palabra[], int* max){
    int i=0, j=0;
    char aux[30];
    while(cadena[i] != '\0'){
        if (cadena[i] != ' '){
            aux[j++] = cadena[i]; 
        } 
        if (cadena[i] == ' ' || cadena[i + 1] == '\0') { // Contar la última palabra
            aux[j] = '\0';
            j = 0;
            int v = contarVocales(aux);
            if (v > *max){
                *max = v;
                strcpy(palabra, aux);
            }
        }
        i++;
    }
}

int contarVocales(char palabra[]){
    int v=0;
    for (int i=0; i<strlen(palabra); i++){
        if (esVocal(palabra[i]) == 's') {
            v++;
        }
    }
    return v;
}

char esVocal(char c){
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
        return 's';
    }
    return 'n';
}

void leer(FILE* fichero, char cadena[]){
    fscanf(fichero, "\n%[^\n]", cadena);
}