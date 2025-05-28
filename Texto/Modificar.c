#include <stdio.h>

typedef struct{
	int nal;
	char nombre[30];
	int nota[3];
}rg;

void modificar(void);
void introducir(int*);
void introducirDatos(rg*);
void leer(FILE*, rg*);
void grabar(FILE*, rg);
char buscar(int);

int main(){
	modificar();
	return 0;
}

void modificar(void){
	int nal;
	introducir(&nal);
	if (buscar(nal) == 'n'){
		printf("No existe");
		return;
	}

	rg nuevo, alumno;
	introducirDatos(&nuevo);                             
	
	FILE* fichero = fopen("alumnos.txt", "r");
	FILE* temp = fopen("temp.txt", "w");
	
	while(!feof(fichero)){
		leer(fichero, &alumno);
		if (alumno.nal == nal){
			alumno = nuevo;
		}
		grabar(temp, alumno);
	}
	
	fclose(fichero);
	fclose(temp);

	remove("alumnos.txt");
	rename("temp.txt", "alumnos.txt");
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

void introducir(int* nal){
	printf("\nModificar: ");
	scanf("%d", nal);
}

void introducirDatos(rg* alumno){
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

void leer(FILE* fichero, rg* alumno){
	fscanf(fichero, "\n%d", &alumno->nal);
	fscanf(fichero, "\n%[^\n]", &alumno->nombre);
	for (int i=0; i<3; i++){
		fscanf(fichero, "\n%d", &alumno->nota[i]);
	}
}

void grabar(FILE* fichero, rg alumno){
	fprintf(fichero, "\n%d", alumno.nal);
	fprintf(fichero, "\n%s", alumno.nombre);
	for (int i=0; i<3; i++){
		fprintf(fichero, "\n%d", alumno.nota[i]);
	}
}