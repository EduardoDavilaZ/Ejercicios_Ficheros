#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int nal;
    char nombre[30];
    int nota[3];
} rg;

void ordenar(void);
void leer(FILE* fichero, rg*);
void grabar(FILE* fichero, rg);
void posicionarAtras(FILE*);

int main(){
    ordenar();
    return 0;
}

void ordenar(void){
    FILE* fichero = fopen("alumnos.dat", "rb+");
    rg alu, alu2, aux;

    int sw = 0;
    do{
        sw = 0;
        rewind(fichero);
        leer(fichero, &alu);
        leer(fichero, &alu2);

        while(!feof(fichero)){
            if (alu.nal > alu2.nal){
                rg aux = alu;
                alu = alu2;
                alu2 = aux;

                posicionarAtras(fichero);
                posicionarAtras(fichero);

                grabar(fichero, alu);
                grabar(fichero, alu2);

                posicionarAtras(fichero);
                sw = 1;
            } else {
                alu = alu2;
            }
            leer(fichero, &alu2);
        }
    } while(sw == 1);
}

void leer(FILE* fichero, rg* alumno){
    fread(alumno, sizeof(rg), 1, fichero);
}

void grabar(FILE* fichero, rg alumno){
    fwrite(&alumno, sizeof(rg), 1, fichero);
}

void posicionarAtras(FILE* fichero){
    fseek(fichero, -sizeof(rg), SEEK_CUR);
}