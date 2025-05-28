/*Tenemos un fichero en disco llamado alumnos, donde cada registro es de la forma:
typedef struct{
unsigned int n_matricula;
char nombre[40];
char calificación[2];
} registro;
La calificación viene dada por dos caracteres: SS (suspenso), AP (aprobado), NT
(notable) y SB (sobresaliente). Realizar un programa que nos muestre el % de
alumnos suspendidos, aprobados, notables y sobresalientes.*/

#include <stdio.h>
#include <string.h>

typedef struct{
    int nal;
    char nombre[30];
    char calificacion[3];
}rg;

void alta(void);
void introducir(int*);
char buscar(int);
void introducirDatos(rg*, int);
char validar(char[]);
void grabar(FILE*, rg);
void leer(FILE*, rg*);
void resultados(void);
void clasificar(int[], char[]);
void visualizar(int[], int);

int main(){
    alta();
    resultados();
    return 0;
}

void alta(void){
    FILE* fichero;
    rg alumno;
    int nal;
    
    do{
        introducir(&nal);
        if (buscar(nal) == 'n' && nal != 0){
            fichero = fopen("alumnos.txt", "a");
            introducirDatos(&alumno, nal);
            grabar(fichero, alumno);
            fclose(fichero);
        }
    } while(nal != 0);
}

void introducir(int* nal){
    printf("Numero: ");
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

void introducirDatos(rg* alumno, int nal){
    alumno->nal = nal;
    fflush(stdin);
    printf("Nombre: ");
    scanf("%[^\n]", &alumno->nombre);
    fflush(stdin);
    do{
        printf("Calificacion: ");
        scanf("%[^\n]", &alumno->calificacion);
    } while(validar(alumno->calificacion) == 'n');
}

char validar(char c[]){
    if (strcmp(c, "ss") == 0 || strcmp(c, "ap") == 0 || strcmp(c, "nt") == 0 || strcmp(c, "sb") == 0 ){
        return 's';
    }
    return 'n';
}

void grabar(FILE* fichero, rg alumno){
    fprintf(fichero, "\n%d", alumno.nal);
    fprintf(fichero, "\n%s", alumno.nombre);
    fprintf(fichero, "\n%s", alumno.calificacion);
}

void leer(FILE* fichero, rg* alumno){
    fscanf(fichero, "\n%d", &alumno->nal);
    fscanf(fichero, "\n%[^\n]", &alumno->nombre);
    fscanf(fichero, "\n%[^\n]", &alumno->calificacion);
}

void resultados(void){
    FILE* fichero = fopen("alumnos.txt", "r");

    int notas[4] = {0, 0, 0, 0};; // ss, ap, nt, sb
    rg alumno;
    int c=0;

    while(!feof(fichero)){
        leer(fichero, &alumno);
        clasificar(notas, alumno.calificacion);
        if (alumno.nal > 0) c++;
    }

    visualizar(notas, c);
    fclose(fichero);
}

void clasificar(int notas[], char calificacion[]){
    if (strcmp(calificacion, "ss") == 0) notas[0]++;
    else if (strcmp(calificacion, "ap") == 0) notas[1]++;
    else if (strcmp(calificacion, "nt") == 0) notas[2]++;
    else if (strcmp(calificacion, "sb") == 0) notas[3]++;
}

void visualizar(int notas[], int c){
    printf("\nSuspensos: %.2f", (float) ((notas[0] * 100) / c) );
    printf("\nAprobados: %.2f", (float) ((notas[1] * 100) / c) );
    printf("\nNotables: %.2f", (float) ((notas[2] * 100) / c) );
    printf("\nSobresalientes: %.2f", (float) ((notas[3] * 100) / c) );
}