#include <stdio.h>

typedef struct{
	int nal;
	char nombre[30];
	int nota[3];
}rg;

void mostrarRegistros(void);
void leer(FILE*, rg*);
void visualizar(rg);

main(){
	mostrarRegistros();
}

void mostrarRegistros(void){
	FILE* fichero = fopen("alumnos.txt", "r");
	
	rg alumno;
	while(!feof(fichero)){
		leer(fichero, &alumno);
		visualizar(alumno);
	}
	
	fclose(fichero);
}

void leer(FILE* fichero, rg* alumno){
	fscanf(fichero, "\n%d", &alumno->nal);
	fscanf(fichero, "\n%[^\n]", &alumno->nombre);
	for (int i=0; i<3; i++){
		fscanf(fichero, "\n%d", &alumno->nota[i]);
	}
}

void visualizar(rg alumno){
	printf("\nNumero: %d", alumno.nal);
	printf("\nNombre: %s", alumno.nombre);
	for (int i=0; i<3; i++){
		printf("\nNota[%d]: %d", i, alumno.nota[i]);
	}
	printf("\n");
}