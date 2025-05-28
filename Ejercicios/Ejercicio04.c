/*Programa que abre un fichero de texto cuyo nombre se introduce por teclado, y permite
añadirle cadenas de caracteres hasta que la cadena introducida sea "FIN".*/

#include <stdio.h>
#include <string.h>

void alta(void);
void introducir(char[], char[]);
void grabar(FILE*, char[]);

int main(){
    alta();
    return 0;
}

void alta(void){
    char nomFichero[30];
    introducir("Nombre del fichero: ", nomFichero);
    FILE* fichero = fopen(nomFichero , "a");
    if (fichero == NULL) {
        printf("\nEl fichero introducido no existe");
        return;
    }

    char cadena[30];
    do{
        introducir("Introduce: ", cadena);
        if (strcmp(cadena, "FIN") != 0){
            grabar(fichero, cadena);
        }
    } while(strcmp(cadena, "FIN") != 0);
}

void introducir(char msg[], char cadena[]){
    fflush(stdin);
    printf("%s", msg);
    scanf("%[^\n]", cadena);
}

void grabar(FILE* fichero, char cadena[]){
    fprintf(fichero, "\n%s", cadena);
}