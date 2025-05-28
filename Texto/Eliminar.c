#include <stdio.h>

typedef struct{
    int nal;
    char nombre[30];
    int nota[3];
}rg;

void eliminar(void);
void introducir(int*);
void leer(FILE*, rg*);
void grabar(FILE*, rg);

int main(){
    eliminar();
    return 0;
}

void eliminar(void){
    FILE* fichero = fopen("alumnos.txt", "r");
    FILE* temp = fopen("temp.txt", "w");
    if (fichero == NULL) return;

    int nal;
    rg alumno;
    introducir(&nal);

    while(!feof(fichero)){
        leer(fichero, &alumno);
        if (alumno.nal != nal){
            grabar(temp, alumno);
        }
    }

    fclose(fichero);
    fclose(temp);

    remove("alumnos.txt");
    rename("temp.txt", "alumnos.txt");
}

void introducir(int* nal){
    printf("\nEliminar: ");
    scanf("%d", nal);
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
        fprintf(fichero, "\n%d", alumno.nal);
    }
}