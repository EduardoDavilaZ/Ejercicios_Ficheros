/*Implementar un programa que permita la creación de un fichero binario denominado
PRUEBA.BIN desde teclado conteniendo un array de 10 números float. Posteriormente,
recuperar el array del fichero y mostrar su contenido en pantalla.*/

#include <stdio.h>

void alta(void);
void mostrar(void);
void introducirDatos(float[]);
void leer(FILE*, float[]);
void grabar(FILE*, float[]);
void visualizar(float[]);

int main(){
    alta();
    mostrar();
    return 0;
}

void alta(void){
    FILE* fichero = fopen("prueba.bin", "ab");
    float num[10];
    introducirDatos(num);
    grabar(fichero, num);
    fclose(fichero);
}

void mostrar(void){
    FILE* fichero = fopen("prueba.bin", "rb");
    float num[10];
    leer(fichero, num);
    while(!feof(fichero)){
        visualizar(num);
        leer(fichero, num);
    }
    fclose(fichero);
}

void introducirDatos(float num[]){
    for (int i=0; i<10; i++){
        printf("Num[%d]: ", i);
        scanf("%f", &num[i]);
    }
}

void leer(FILE* fichero, float num[]){
    fread(num, sizeof(float), 10, fichero);
}

void grabar(FILE* fichero, float num[]){
    fwrite(num, sizeof(float), 10, fichero);
}

void visualizar(float num[]){
    for (int i=0; i<10; i++){
        printf("\nNum[%d]: %.2f", i, num[i]);
    }
}