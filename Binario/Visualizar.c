#include <stdio.h>

typedef struct{
    int nal;
    char nombre[30];
    int nota[3];
} rg;

void mostrarRegistros(void);
void leer(FILE*, rg*);
void visualizar(rg);

int main(){
    mostrarRegistros();
    return 0;
}

void mostrarRegistros(void){
    FILE* fichero = fopen("alumnos.dat", "rb");
    rg alumno;

    leer(fichero, &alumno);
    while(!feof(fichero)){
        visualizar(alumno);
        leer(fichero, &alumno);
    }
    fclose(fichero);
}

void leer(FILE* fichero, rg* alumno){
    fread(alumno, sizeof(rg), 1, fichero);
}

void visualizar(rg alumno){
    printf("\nNumero: %d", alumno.nal);
    printf("\nNombre: %s", alumno.nombre);
    for (int i = 0; i < 3; i++){
        printf("\nNota[%d]: %d", i, alumno.nota[i]);
    }
}