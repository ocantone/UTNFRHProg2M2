/*
    CREA EL ARCHIVO DATOS.DAT Y LO CARGA CON 40 REGISTROS
*/
#include<stdio.h>
#define CANTIDAD 40
#define ruta "DATOS.DAT"

struct ALUMNO{
	char NOM[15];
	char SEX;
	int NOTA;
};

struct ALUMNO LISTA[CANTIDAD] = {
	{"JUAN", 'm', 8},{"ISMAEL", 'm', 7},{"ROSENDO", 'm', 7},
	{"JULIAN", 'm', 10},{"ALFREDO", 'm', 8},{"CARLA", 'f', 7},
	{"CAROLA", 'f', 9},{"AMBAR", 'f', 9},{"FEDERICO", 'm', 6},
	{"PEDRO", 'm', 5},{"RITA", 'f', 10},{"MANUEL", 'm', 8},
	{"LISA", 'f', 7},{"MARIELA", 'f', 9},{"GIMENA", 'f', 6},
	{"ARIEL", 'm', 6},{"HORACIO", 'm', 8},{"LIONEL", 'm', 7},
	{"MIRIAM", 'f', 7},{"OMAR", 'm', 8},{"ROSA", 'f', 8},
	{"FLORENCIA", 'f', 9},{"SERGIO", 'm', 6},{"LOURDES", 'f', 10},
	{"EVANGELINA", 'f', 8},{"PABLO", 'm', 7},{"NATALIA ", 'f', 6},
	{"MARCELO", 'm', 5},{"MERCEDES", 'f', 10},{"MARCELA", 'f', 9},
	{"LUIS", 'm', 4},{"OSCAR", 'm', 8},{"SANDRA", 'f', 9},
	{"NORBERTO", 'm', 8},{"ANA", 'f', 9},{"VIRGINIA", 'f', 7},
	{"DIEGO", 'm', 8},{"BRUNO", 'm', 9},{"ROMINA", 'f', 9},
	{"FRANCO", 'm', 8}
};
	FILE *fp;

int main (void){
	int i;
	printf("DATOS.DAT\n\n");


	if(( fp=fopen(ruta, "wb")) == NULL ){
		printf("\n\nERROR AL CREAR EL ARCHIVO DATOS.DAT\n\n");
		return 1;
	}
    for(i=0; i<CANTIDAD; i++){
		fwrite( &LISTA[i] , sizeof(struct ALUMNO) , 1 , fp );
		printf("\n %d \t %-15s \t %c \t %d", i,LISTA[i].NOM, LISTA[i].SEX, LISTA[i].NOTA);
	}
	printf("\n\nESCRITOS %d REGISTROS.\n", i);
	fclose(fp);
    i=0;

  if(( fp=fopen(ruta, "rb")) == NULL ){
        printf("\n\nERROR AL ABRIR EL ARCHIVO DATOS.DAT para leer\n\n");
        return 1;
    }
    printf("\nContenido del archivo DATOS.DAT:\n\n");

    while (fread(&LISTA[i], sizeof(struct ALUMNO), 1, fp), !feof(fp) ) {
        printf("\n%d)\t %-15s \t %c \t %2d", i,LISTA[i].NOM, LISTA[i].SEX,LISTA[i].NOTA);
        i++;
//        fread(&LISTA[i], sizeof(struct ALUMNO), 1, fp);
    }

    fseek(fp, 0, SEEK_END);
    long tam = ftell(fp);
    fclose(fp);

	printf("\nTama%co del archivo: %ld bytes\n", 164,tam);
    return 0;
}
