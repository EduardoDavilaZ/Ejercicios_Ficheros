/*Programa que permita crear un fichero de texto llamado PRUEBA.TXT mediante la
escritura de cadenas de caracteres, hasta que la cadena introducida sea "FIN". A
continuación mostrar el contenido del fichero por pantalla.*/

#include <stdio.h>
#include <string.h>

void alta(void);
void introducir(char[]);
void mostrar(void);
void leer(FILE*, char[]);
void grabar(FILE*, char[]);
void visualizar(char[]);

int main(){
    alta();
    mostrar();
    return 0;
}

void alta(void){
    char cadena[30];
    FILE* fichero = fopen("prueba.txt", "a");
    do{
        introducir(cadena);
        if (strcmp(cadena, "FIN") != 0){
            grabar(fichero, cadena);
        }
    } while(strcmp(cadena, "FIN") != 0);
    fclose(fichero);
}

void introducir(char cadena[]){
    fflush(stdin);
    printf("Introduce: ");
    scanf("%[^\n]", cadena);
}

void mostrar(void){
    FILE* fichero = fopen("prueba.txt", "r");
    char cadena[30];
    while(!feof(fichero)){
        leer(fichero, cadena);
        visualizar(cadena);
    }
    fclose(fichero);
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