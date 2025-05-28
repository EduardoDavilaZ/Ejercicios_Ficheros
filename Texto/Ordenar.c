#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int nal;
    char nombre[30];
    int nota[3];
}rg;

void ordenar(void);
int obtenerTam(FILE*);
rg* dimensionar(int);
void obtenerDatos(FILE* , rg*);
void burbuja(rg*, int);
void guardarDatos(rg*, int);
void leer(FILE*, rg*);
void grabar(FILE*, rg);

int main(){
    ordenar();
    return 0;
}

void ordenar(void){
    FILE* fichero = fopen("alumnos.txt", "r");
    int tam = obtenerTam(fichero);
    rg* alu;
    alu = dimensionar(tam);
    obtenerDatos(fichero, alu);
    burbuja(alu, tam);
    fclose(fichero);
    guardarDatos(alu, tam);
}

int obtenerTam(FILE* fichero){
    int tam = 0;
    rg alumno;
    while(!feof(fichero)){
        leer(fichero, &alumno);
        if (alumno.nal > 0) tam++;
    }
    return tam;
}

rg* dimensionar(int tam){
    return (rg*) calloc(tam, sizeof(rg));
}

void obtenerDatos(FILE* fichero, rg* alu){
    rg alumno;
    rewind(fichero);
    for (int i=0; !feof(fichero); i++){
        leer(fichero, &alumno);
        alu[i] = alumno;
    }
}

void burbuja(rg* alu, int tam){
    for (int i=0; i<tam-1; i++){
        for (int j=0; j<tam-i-1; j++){
            if (alu[j].nal > alu[j+1].nal){
                rg aux = alu[j];
                alu[j] = alu[j+1];
                alu[j+1] = aux;
            }
        }
    }
}

void guardarDatos(rg* alu, int tam){
    FILE* temp = fopen("temp.txt", "w");
    for (int i=0; i<tam; i++){
        grabar(temp, alu[i]);
    }
    fclose(temp);
    remove("alumnos.txt");
    rename("temp.txt", "alumnos.txt");
}

void leer(FILE* fichero, rg* alumno){
    fscanf(fichero, "\n%d", &alumno->nal);
    fscanf(fichero, "\n%[^\n]", &alumno->nombre);
    for (int i=0; i<3; i++){
        fscanf(fichero, "\n%d", &alumno->nota[i]);
    }
}

void grabar(FILE* fichero, rg alumno){
    fprintf(fichero, "\n%d", alumno.nal);
    fprintf(fichero, "\n%s", alumno.nombre);
    for (int i=0; i<3; i++){
        fprintf(fichero, "\n%d", alumno.nota[i]);
    }
}