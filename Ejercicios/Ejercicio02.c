/*Crear un fichero de texto llamado SALIDA.TXT a partir del fichero creado en el ejercicio
anterior, copiando carácter a carácter los elementos del fichero PRUEBA.TXT. Hacerlo
diseñando previamente una función a la que se le pasen dos ficheros y copie uno sobre el
otro.*/

#include <stdio.h>

void copiar(void);
void mostrar(void);
void leer(FILE*, char[]); 
void grabar(FILE*, char[]); 
void visualizar(char[]);

int main(){
    copiar();
    mostrar();
    return 0;
}

void copiar(void){
    FILE* fichero = fopen("prueba.txt", "r");
    FILE* salida = fopen("salida.txt", "w");

    char cadena[30];
    while(!feof(fichero)){
        leer(fichero, cadena);
        grabar(salida, cadena);
    }

    fclose(fichero);
    fclose(salida);
}

void mostrar(void){
    FILE* salida = fopen("salida.txt", "r");
    char cadena[30];
    while(!feof(salida)){
        leer(salida, cadena);
        visualizar(cadena);
    }
    fclose(salida);
}

void leer(FILE* fichero, char cadena[]){
    fscanf(fichero, "\n%[^\n]", cadena);
}

void grabar(FILE* fichero, char cadena[]){
    fprintf(fichero, "\n%s", cadena);
}

void visualizar(char cadena[]){
    printf("\nCadena: %s", cadena);
}