/*A partir del fichero AYUNTAMIENTO.TXT (que se te proporcionará si lo pides) diseña un
programa que pida el nombre de un pueblo y devuelva su código postal, y la provincia a la
que pertenece. El fichero AYUNTAMIENTO.TXT es un fichero de texto con la siguiente
estructura: Cada línea está formada por un código postal de 5 dígitos, un carácter ‘
\t', y el nombre de un pueblo.
Ejemplo:
06000 BADAJOZ El nombre de la provincia aparece siempre precedido de 1 dígito o dos,
06001 BADAJOZ correspondientes a esa provincia, seguidos por tres ceros. Ejemplo: 1000
06800 MÉRIDA CÁCERES.
06300 ZAFRA*/

#include <stdio.h>
#include <string.h>

typedef struct{
    char provincia[3];
    char nombre[30];
}pv; // provincia

typedef struct{
    char cpostal[7];
    char nombre[30];
}pb; // pueblo

void menu(void);
void opciones(void);
void altaProvincia(void);
void altaPueblo(void);
void introducirProv(pv*);
void introducirPue(pb*);
void consultarProvincia(void);
void introducirNombre(char[]);
char buscar(char[]);
void leer1(FILE*, pb*);
void grabar1(FILE*, pb);
void leer2(FILE*, pv*);
void grabar2(FILE*, pv);

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
            case 1: altaProvincia(); break;
            case 2: altaPueblo(); break;
            case 3: consultarProvincia(); break;
        }
    } while(op != 0);
}

void opciones(void){
    printf("\nMENU");
    printf("\n1. Introducir provincia");
    printf("\n2. Introducir pueblo");
    printf("\n3. Consultar provincia");
}

void altaProvincia(void){
    FILE* fichero = fopen("provincias.txt", "a");
    pv provincia;
    introducirProv(&provincia);
    grabar2(fichero, provincia);
    fclose(fichero);
}

void altaPueblo(void){
    FILE* fichero = fopen("pueblos.txt", "a");
    pb pueblo;
    introducirPue(&pueblo);
    grabar1(fichero, pueblo);
    fclose(fichero);
}

void introducirProv(pv* provincia){
    fflush(stdin);
    printf("Nombre: ");
    scanf("%[^\n]", &provincia->nombre);
    fflush(stdin);
    printf("Codigo: ");
    scanf("%[^\n]", &provincia->provincia);
}

void introducirPue(pb* pueblo){
    fflush(stdin);
    printf("Nombre: ");
    scanf("%[^\n]", &pueblo->nombre);
    fflush(stdin);
    printf("Codigo postal: ");
    scanf("%[^\n]", &pueblo->cpostal);
}

void consultarProvincia(void){
    char nombrePueblo[30];
    introducirNombre(nombrePueblo);

    if (buscar(nombrePueblo) == 'n'){
        printf("\nNo existe");
        return;
    }

    FILE* provincias = fopen("provincias.txt", "r");
    FILE* pueblos = fopen("pueblos.txt", "r");

    pb pueblo;
    int sw = 0;
    while (!feof(pueblos) && sw == 0){
        leer1(pueblos, &pueblo);
        if (strcmp(pueblo.nombre, nombrePueblo) == 0) {
            sw == 1;
        }
    }

    pv provincia;
    sw = 0;
    while (!feof(provincias) && sw == 0){
        leer2(provincias, &provincia);
        if (provincia.provincia[0] == pueblo.cpostal[0] && provincia.provincia[1] == pueblo.cpostal[1]) {
            sw = 1;
        }
    }

    if (sw == 1){
        printf("\nNombre de la provincia: %s", provincia.nombre);
    } else {
        printf("\nLa provincia no ha sido registrada");
    }

    fclose(provincias);
    fclose(pueblos);
}

void introducirNombre(char nombre[]){
    fflush(stdin);
    printf("Buscar: ");
    scanf("%[^\n]", nombre);
}

char buscar(char nombre[]){
    FILE* fichero = fopen("pueblos.txt", "r");

    pb pueblo;
    while(!feof(fichero) && strcmp(pueblo.nombre, nombre) != 0){
        leer1(fichero, &pueblo);
    }

    fclose(fichero);
    return strcmp(pueblo.nombre, nombre) == 0 ? 's' : 'n';
}

void leer1(FILE* fichero, pb* pueblo){
    fscanf(fichero, "\n%[^\n]", pueblo->cpostal);
    fscanf(fichero, "\n%[^\n]", pueblo->nombre);
}

void grabar1(FILE* fichero, pb pueblo){
    fprintf(fichero, "\n%s", pueblo.cpostal);
    fprintf(fichero, "\n%s", pueblo.nombre);
}

void leer2(FILE* fichero, pv* provincia){
    fscanf(fichero, "\n%[^\n]", provincia->provincia);
    fscanf(fichero, "\n%[^\n]", provincia->nombre);
}

void grabar2(FILE* fichero, pv provincia){
    fprintf(fichero, "\n%s", provincia.provincia);
    fprintf(fichero, "\n%s", provincia.nombre);
}