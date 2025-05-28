/*Crear un programa de mantenimiento de morosos en el que se permitirán las siguientes
opciones: (A)ñadir, (B)uscar o (T)erminar. Se deben usar funciones y el fichero contendrá
como datos un nombre [40], la cantidad prestada y un número telefónico. No hacer uso de
estructuras.*/

#include <stdio.h>
#include <string.h>

typedef struct {
    char nombre[40];
    float cantidad;
    char telefono[10];
}rg;

void menu(void);
void opciones(void);
void alta(void);
void introducir(char[]);
void introducirDatos(rg*, char[]);
void grabar(FILE*, rg);
void leer(FILE*, rg*); 
void buscar(void);
char busqueda(char[]);

int main(){
    menu();
    return 0;
}

void menu(void){
    char op;
    do{
        opciones();
        fflush(stdin);
        scanf("%c", &op);
        switch (op){
            case 'a': alta(); break;
            case 'b': buscar(); break;
        }
    } while(op != 't');
}

void opciones(void){
    printf("\nMENU");
    printf("\nAlta -> a");
    printf("\nBuscar -> b");
    printf("\nTerminar -> t\n");
}

void alta(void){
    FILE* fichero;
    char nombre[30];
    rg moroso;

    do{
        introducir(nombre);
        if (strcmp(nombre, "FIN") != 0){
            fichero = fopen("morosos.bin", "ab");
            introducirDatos(&moroso, nombre);
            grabar(fichero, moroso);
            fclose(fichero);
        }
    } while(strcmp(nombre, "FIN") == 0);
}

void introducir(char nombre[]){
    fflush(stdin);
    printf("Nombre: ");
    scanf("%[^\n]", nombre);
}

void introducirDatos(rg* moroso, char nombre[]){
    strcpy(moroso->nombre, nombre);
    fflush(stdin);
    printf("Cantidad: ");
    scanf("%.2f", moroso->cantidad);
    fflush(stdin);
    printf("Telefono: ");
    scanf("%[^\n]", &moroso->telefono);
    fflush(stdin);
}

void grabar(FILE* fichero, rg moroso){
    fwrite(&moroso, sizeof(rg), 1, fichero);
}

void leer(FILE* fichero, rg* moroso){
    fread(moroso, sizeof(rg), 1, fichero);
}

void buscar(void){
    char nombre[40];
    introducir(nombre);
    if (busqueda(nombre) == 's'){
        printf("\nSi existe");
    } else {
        printf("\nNo existe");
    }
}

char busqueda(char nombre[]){
    rg moroso;
    FILE* fichero = fopen("morosos.bin", "rb");

    leer(fichero, &moroso);
    while(!feof(fichero) && strcmp(moroso.nombre, nombre) != 0){
        leer(fichero, &moroso);
    }

    return strcmp(moroso.nombre, nombre) == 0 ? 's' : 'n';
}