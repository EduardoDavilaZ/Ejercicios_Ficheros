/*Programa al que se le pasa el nombre de un fichero de texto desde la línea de comandos y
lo muestra por impresora. Hacer uso de la función diseñada en el ejercicio 2.*/

#include <stdio.h>

void mostrar(void);
void introducirFichero(char[]);
void leer(FILE* fichero, char[]);
void visualizar(char[]);

int main(){
    mostrar();
    return 0;
}

void mostrar(void){
    char nombre[30];
    introducirFichero(nombre);
    FILE* fichero = fopen(nombre, "r");
    if (fichero == NULL) return;

    char cadena[30];
    while(!feof(fichero)){
        leer(fichero, cadena);
        visualizar(cadena);
    }

    fclose(fichero);
}

void introducirFichero(char nombre[]){
    printf("Introduce: ");
    scanf("%[^\n]", nombre);
}

void leer(FILE* fichero, char cadena[]){
    fscanf(fichero, "\n%[^\n]", cadena);
}

void visualizar(char cadena[]){
    printf("\n%s", cadena);
}