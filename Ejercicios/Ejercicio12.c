/*Escribir un programa llamado grep que permita buscar palabras en un fichero de texto.
Como resultado se visualizará el nombre del fichero y el número de línea y contenido de la
misma, para cada una de las líneas del fichero que contenga la palabra buscada. Seguir
los siguientes pasos:

• Escribir una función que busque una cadena de caracteres dentro de
otra. Esta función tendrá el siguiente prototipo:
int BuscarCadena(char cadenalf ], char cadena2[ ]);
• Escribir una función que busque una cadena de caracteres en un
fichero de texto y visualice el número y el contenido de la línea que contiene
a la cadena:
void BuscarEnFich(char nombrefichf ], char cadena[ ]);
• La forma de invocar al programa será:
grep palabra fichero*/

#include <stdio.h>
#include <string.h>

void grep(void);
void introducir(char[], char[]);
void buscarCadena(char[], char[], int*);
void leer(FILE*, char[]);

int main(){
    grep();
    return 0;
}

void grep(void){
    char nombreFichero[30];
    introducir("Fichero: ", nombreFichero);
    FILE* fichero = fopen(nombreFichero, "r");
    if (fichero == NULL) return;

    char cadena1[30];
    char cadena2[30];

    introducir("Buscar: ", cadena2);
    int l = 0;

    while(!feof(fichero)){
        leer(fichero, cadena1);
        buscarCadena(cadena1, cadena2, &l);
        l++;
    }

    fclose(fichero);
}

void introducir(char msg[], char cadena[]){
    fflush(stdin);
    printf("\n%s", msg);
    scanf("%[^\n]", cadena);
}

void buscarCadena(char cadena1[], char cadena2[], int* l){
    int i=0, j=0;
    char palabra[30];
    while(cadena1[i] != '\0'){
        if (cadena1[i] != ' '){
            palabra[j++] = cadena1[i];
        }
        if (cadena1[i] == ' ' || cadena1[i+1] == '\0'){
            palabra[j] = '\0';
            j = 0;
            if (strcmp(palabra, cadena2) == 0){
                printf("\nLinea: %d", *l);
                printf("\nCadena: %s", cadena1);
            }
        }
        i++;
    }
}

void leer(FILE* fichero, char cadena[]){
    fscanf(fichero, "\n%[^\n]", cadena);
}