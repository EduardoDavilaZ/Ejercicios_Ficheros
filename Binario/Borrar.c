#include <stdio.h>

typedef struct{
    int nal;
    char nombre[30];
    int nota[3];
}rg;

void eliminar(void);
void introducir(char[], int*);
char buscar(FILE*, int);
void posicionarAtras(FILE*);
void grabar(FILE*, rg);
void leer(FILE*, rg*);

int main(){
    eliminar();
    return 0;
}

void eliminar(void){
    int nal;
    introducir("Eliminar: ", &nal);
    FILE* fichero = fopen("alumnos.dat", "rb+");
    if (fichero == NULL || buscar(fichero, nal) == 'n'){
        printf("\nError");
        fclose(fichero);
        return;
    }
    rg alumno = {0};
    posicionarAtras(fichero);
    grabar(fichero, alumno);
    fclose(fichero);
}

void introducir(char msg[], int* nal){
    printf("%s", msg);
    scanf("%d", nal);
}

char buscar(FILE* fichero, int nal){
    rg alumno;
    leer(fichero, &alumno);
    while(!feof(fichero) && alumno.nal != nal){
        leer(fichero, &alumno);
    }
    return alumno.nal == nal ? 's' : 'n';
}

void posicionarAtras(FILE* fichero){
    fseek(fichero, -sizeof(rg), SEEK_CUR);
}

void leer(FILE* fichero, rg* alumno){
    fread(alumno, sizeof(rg), 1, fichero);
}

void grabar(FILE* fichero, rg alumno){
    fwrite(&alumno, sizeof(rg), 1, fichero);
}