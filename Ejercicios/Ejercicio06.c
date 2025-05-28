/*Programa que haciendo uso de un fichero de texto existente cuyo nombre se introduce por
teclado, cree otro pero con los caracteres del primero en mayúscula. Después se
renombrará el fichero obtenido con el nombre del fichero primitivo.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void convertir(void);
void introducirFichero(char[]);
void leer(FILE* fichero, char[]);
void grabar(FILE* fichero, char[]);

int main(){
    convertir();
    return 0;
}

void convertir(void){
    char cadena[30];
    introducirFichero(cadena);
    FILE* fichero = fopen(cadena, "r");
    if (fichero == NULL) {
        printf("%s no existe", cadena);
    }
    FILE* temp = fopen("temp.txt", "w");

    while(!feof(fichero)){
        leer(fichero, cadena);
        for (int i=0; i<strlen(cadena); i++){
            cadena[i] = toupper(cadena[i]);
        }
        grabar(temp, cadena);
    }

    fclose(fichero);
    fclose(temp);
}

void introducirFichero(char cadena[]){
    printf("Introduce: ");
    scanf("%[^\n]", cadena);
}

void leer(FILE* fichero, char cadena[]){
    fscanf(fichero, "\n%[^\n]", cadena);
}

void grabar(FILE* fichero, char cadena[]){
    fprintf(fichero, "\n%s", cadena);
}