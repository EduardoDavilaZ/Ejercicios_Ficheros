#include <stdio.h>

typedef struct {
    int nal;
    char nombre[30];
    int nota[3];
}rg;

void modificar(void);
void introducir(int*);
char buscar(FILE*, int);
void introducirDatos(FILE*, rg*);
void posicionarAtras(FILE*);
void leer(FILE*, rg*);
void grabar(FILE*, rg);

int main(){
    modificar();
    return 0;
}

void modificar(void){
    int nal;
    introducir(&nal);
    FILE* fichero = fopen("alumnos.dat", "rb+");
    rg alumno;
    buscar(fichero, nal);
    introducirDatos(fichero, &alumno);
    posicionarAtras(fichero);
    grabar(fichero, alumno);
    fclose(fichero);
}

void introducir(int* nal){
    printf("Numero: ");
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

void introducirDatos(FILE* fichero, rg* alumno){
    printf("Numero: ");
    scanf("%d", &alumno->nal);
    fflush(stdin);
    printf("Nombre: ");
    scanf("%[^\n]", &alumno->nombre);
    fflush(stdin);
    for (int i=0; i<3; i++){
        printf("Nota[%d]: ", i);
        scanf("%d", &alumno->nota[i]);
    }
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