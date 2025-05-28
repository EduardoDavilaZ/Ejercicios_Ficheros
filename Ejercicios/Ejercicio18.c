/*Modifica el ejercicio anterior, permitiendo que se puedan añadir nuevos registros, borrar
registros antiguos y modificar registros existentes y manteniendo siempre los registros en
orden alfabético. Para llevar a cabo estas operaciones, se deberá hacer uso de un fichero
auxiliar, que después se renombrará con el nombre del fichero original (se supone que se
trata de ficheros secuenciales).*/

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
char busqueda(FILE*, char[]);
void eliminar(void);
void modificar(void);
void posicionarAtras(FILE*);
void introducirNuevo(rg*);

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
            case 'e': eliminar(); break;
            case 'm': modificar(); break;
        }
    } while(op != 't');
}

void opciones(void){
    printf("\nMENU");
    printf("\nAlta -> a");
    printf("\nBuscar -> b");
    printf("\nEliminar -> e");
    printf("\nModificar -> m");
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
    FILE* fichero = fopen("morosos.bin", "rb");
    introducir(nombre);
    if (busqueda(fichero, nombre) == 's'){
        printf("\nSi existe");
    } else {
        printf("\nNo existe");
    }
    fclose(fichero);
}

char busqueda(FILE* fichero, char nombre[]){
    rg moroso;
    rewind(fichero);
    leer(fichero, &moroso);
    while(!feof(fichero) && strcmp(moroso.nombre, nombre) != 0){
        leer(fichero, &moroso);
    }
    return strcmp(moroso.nombre, nombre) == 0 ? 's' : 'n';
}

void eliminar(void){
    FILE* fichero = fopen("morosos.bin", "rb+");
    char nombre[40];
    introducir(nombre);
    if (busqueda(fichero, nombre) == 'n') return;
    rg moroso = {0};
    posicionarAtras(fichero);
    grabar(fichero, moroso);
    fclose(fichero);
}

void modificar(void){
    FILE* fichero = fopen("morosos.bin", "rb+");
    char nombre[40];
    introducir(nombre);
    if (busqueda(fichero, nombre) == 'n') return;
    rg moroso;
    introducirNuevo(&moroso);
    posicionarAtras(fichero);
    grabar(fichero, moroso);
    fclose(fichero);
}

void posicionarAtras(FILE* fichero){
    fseek(fichero, -sizeof(rg), SEEK_CUR);
}

void introducirNuevo(rg* moroso){
    fflush(stdin);
    printf("Nombre: ");
    scanf("%[^\n]", &moroso->nombre);
    fflush(stdin);
    printf("Cantidad: ");
    scanf("%.2f", moroso->cantidad);
    fflush(stdin);
    printf("Telefono: ");
    scanf("%[^\n]", &moroso->telefono);
    fflush(stdin);
}