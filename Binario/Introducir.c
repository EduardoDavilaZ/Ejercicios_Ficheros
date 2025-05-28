#include <stdio.h>

typedef struct{
    int nal;
    char nombre[30];
    int nota[3];
} rg;

void alta(void);
void introducir(char msg[], int*);
char buscar(int);
void introducirDatos(rg*, int);
void leer(FILE*, rg*);
void grabar(FILE*, rg);

int main(){
    alta();
    return 0;
}

void alta(void){
    FILE* fichero;
    int nal;
    rg alumno;

    do{
        introducir("Numero: ", &nal);
        if (buscar(nal) == 'n' && nal != 0){
            fichero = fopen("alumnos.dat", "ab+");
            introducirDatos(&alumno, nal);
            grabar(fichero, alumno);
            fclose(fichero);
        }
    } while(nal != 0);
}

void introducir(char msg[], int* nal){
    printf("\n%s", msg);
    scanf("\n%d", nal);
}

char buscar(int nal){
    FILE* fichero = fopen("alumnos.dat", "rb");
    if (fichero == NULL) return 'n';
    rg alumno;
    
    rewind(fichero);
    leer(fichero, &alumno);
    while(!feof(fichero) && alumno.nal != nal){
        leer(fichero, &alumno);
    }

    fclose(fichero);
    return alumno.nal == nal ? 's' : 'n';
}

void introducirDatos(rg* alumno, int nal){
    alumno->nal = nal;
    fflush(stdin);
    printf("Nombre: ");
    scanf("\n%[^\n]", alumno->nombre); // Corregido: lee en alumno->nombre
    fflush(stdin);
    for (int i = 0; i < 3; i++){
        printf("Nota[%d]: ", i);
        scanf("\n%d", &alumno->nota[i]);
    }
}

void leer(FILE* fichero, rg* alumno){
    fread(alumno, sizeof(rg), 1, fichero);
}

void grabar(FILE* fichero, rg alumno){
    fwrite(&alumno, sizeof(rg), 1, fichero);
}