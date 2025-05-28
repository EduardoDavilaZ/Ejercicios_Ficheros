#include <stdio.h>

typedef struct{
    int nal;
    char nombre[30];
    int nota[3];
}rg;

void buscarRegistro(void);
void introducir(char msg[], int*);
char buscar(FILE*, int);
void leer(FILE*, rg*);
void visualizar(rg);

int main(){
    buscarRegistro();
    return 0;
}

void buscarRegistro(void){
    FILE* fichero = fopen("alumnos.dat", "rb");
    if (fichero == NULL) return;

    int nal;
    introducir("Buscar: ", &nal);

    if(buscar(fichero, nal) == 's'){
        printf("\nEncontrado");
    } else {
        printf("\nNo existe");
    }
}

void introducir(char msg[], int* nal){
    printf("\n%s", msg);
    scanf("%d", nal);
}

char buscar(FILE* fichero, int nal){
    rg alumno;
    leer(fichero, &alumno);
    while(!feof(fichero) && alumno.nal != nal){
        leer(fichero, &alumno);
    }
    if (alumno.nal == nal){
        visualizar(alumno);
    }
    return alumno.nal == nal ? 's' : 'n';
}

void leer(FILE* fichero, rg* alumno){
    fread(alumno, sizeof(rg), 1, fichero);
}

void visualizar(rg alumno){
    printf("\nNumero: %d", alumno.nal);
    printf("\nNombre: %s", alumno.nombre);
    for (int i=0; i<3; i++){
        printf("\nNota[%d]: %d", i, alumno.nota[i]);
    }
}