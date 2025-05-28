#include <stdio.h>

typedef struct{
    int nal;
    char nombre[30];
    int nota[3];
}rg;

void buscarRegistro(void);
void introducir(char[], int*);
char buscar(int);
void leer(FILE*, rg*);

int main(){
    buscarRegistro();
    return 0;
}

void buscarRegistro(void){
    int nal;
    introducir("Buscar: ", &nal);

    if (buscar(nal) == 's'){
        printf("\nEncontrado");
    } else{
        printf("\nNo existe");
    }
}

void introducir(char msg[], int* nal){
    printf("\n%s", msg);
    scanf("%d", nal);
}

char buscar(int nal){
    FILE* fichero = fopen("alumnos.txt", "r");
    if (fichero == NULL) return 'n';
    rg alumno;
    while(!feof(fichero) && alumno.nal != nal){
        leer(fichero, &alumno);
    }
    fclose(fichero);
    return alumno.nal == nal ? 's' : 'n';
}

void leer(FILE* fichero, rg* alumno){
    fscanf(fichero, "\n%d", &alumno->nal);
    fscanf(fichero, "\n%[^\n]", &alumno->nombre);
    for (int i=0; i<3; i++){
        fscanf(fichero, "\n%d", &alumno->nota[i]);
    }
}