/*Escribir un programa que genere un archivo que contiene países y sus correspondientes
capitales. Colocar ambos en una estructura. Permitir las siguientes operaciones:
a) Determinar la capital de un país determinado
b) Determinar el país cuya capital se especifica
c) Añadir un nuevo registro (país y capital)
d) Borrar un registro
e) Generar un listado de todos los países y sus capitales correspondientes
f) Acabar*/

#include <stdio.h>

typedef struct {
    char pais[30];
    char capital[30];
}rg;

int main(){
    menu();
    return 0;
}

void menu(void){
    int op;
    
    do{
        opciones();
        scanf("%d", &op);

    } while(op != 0);
}

void opciones(void){
    printf("\n1. Obtener capital");
    printf("\n2. Obtener pais");
    printf("\n3. Alta");
    printf("\n4. Borrar");
    printf("\n5. Visualizar\n");
}