/*Se tiene un fichero tipo texto conteniendo en cada línea el nombre y las calificaciones en
matemáticas e informática de uno de los alumnos de un grupo. Escribir un programa que a
partir de dichos datos escriba en otro fichero la nota media del grupo en matemáticas y la
mejor nota en informática así como el nombre del alumno que la obtuvo. Incluir la
posibilidad de borrar un alumno del fichero.*/

#include <stdio.h>

typedef struct {
    int nal;
    char nombre[30];
    float mate;
    float inform; 
}rg;

void menu(void);
void opciones(void);
void alta(void);
void resultado(void);
void leer(FILE*, rg*);
void introducir(int*);
void introducirDatos(rg*, int);
void grabar(FILE*, rg);
char buscar(int);

int main(){
    menu();
    return 0;
}

void menu(void){
    int op;
    do{
        opciones();
        printf("\nOpcion: ");
        scanf("%d", &op);
        switch (op){
            case 1: alta(); break;
            case 2: resultado(); break;
        }
    } while(op != 0);
}

void opciones(void){
    printf("\nMENU");
    printf("\n1. Introducir alumno");
    printf("\n2. Resultados");
}

void alta(void){
    int nal;
    rg alumno;
    do{
        introducir(&nal);
        if (buscar(nal) == 'n' && nal != 0){
            FILE* fichero = fopen("alumnos.txt", "a");
            introducirDatos(&alumno, nal);
            grabar(fichero, alumno);
            fclose(fichero);
        }
    } while(nal != 0);
}

void resultado(void){
    FILE* fichero = fopen("alumnos.txt", "r");
    if (fichero == NULL) return;

    rg alumno;
    int cont = 0;
    float mate;
    rg inform;
    while(!feof(fichero)){
        leer(fichero, &alumno);
        if (alumno.inform > inform.inform) inform = alumno;
        if (alumno.nal > 0) cont++;
        mate += alumno.mate;
    }

    fclose(fichero);

    printf("Mayor nota de informatica: %.2f Nombre: %s", inform.inform, inform.nombre);
    printf("Media de las notas de mate: %.2f", mate/cont);
}

void leer(FILE* fichero, rg* alumno){
    fscanf(fichero, "\n%d", &alumno->nal);
    fscanf(fichero, "\n%[^\n]", &alumno->nombre);
    fscanf(fichero, "\n%f", &alumno->mate);
    fscanf(fichero, "\n%f", &alumno->inform);
}

void introducir(int* nal){
    printf("N alumno: ");
    scanf("%d", nal);
}

void introducirDatos(rg* alumno, int nal){
    alumno->nal = nal;
    fflush(stdin);
    printf("Nombre: ");
    scanf("\n%[^\n]", &alumno->nombre);
    fflush(stdin);
    printf("Nota mate: ");
    scanf("\n%f", &alumno->mate);
    fflush(stdin);
    printf("Nota inform: ");
    scanf("\n%f", &alumno->inform);
}

void grabar(FILE* fichero, rg alumno){
    fprintf(fichero, "\n%d", alumno.nal);
    fprintf(fichero, "\n%s", alumno.nombre);
    fprintf(fichero, "\n%f", alumno.mate);
    fprintf(fichero, "\n%f", alumno.inform);
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