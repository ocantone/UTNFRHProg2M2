/**
Realiza copia backup del archivo C:\Temp\DATOS.DAT en DATOS.BACK
**/
#include<stdio.h>
#define CANTIDAD 40

struct ALUMNO{
	char NOM[15];
	char SEX;
	int NOTA;
};

struct ALUMNO unAlumno;
	FILE *orig;
	FILE *dest;

int main (void){
	int i=0;
	printf("Backup de DATOS.DAT en DATOS.BAK\n\n");

    if(( orig=fopen("C:\\Temp\\DATOS.DAT", "rb")) == NULL ){
        printf("\n\nERROR AL ABRIR EL ARCHIVO DATOS.DAT para leer\n\n");
        return 1;
    }
    if(( dest=fopen("C:\\Temp\\DATOS.BACK", "wb")) == NULL ){
		printf("\n\nERROR AL CREAR EL ARCHIVO DATOS.BACK\n\n");
		return 1;
	}
    while (fread(&unAlumno, sizeof(struct ALUMNO), 1, orig), !feof(orig) ) {
        printf("\n%d)\t %-15s \t %c \t %2d", i+1,unAlumno.NOM, unAlumno.SEX, unAlumno.NOTA);
		fwrite( &unAlumno , sizeof(struct ALUMNO) , 1 , dest );
        i++;
    }

	printf("\n\nESCRITOS %d REGISTROS.\n", i);

    fseek(dest, 0, SEEK_END);     // mover el puntero al final
    long tam = ftell(dest);       // leer posición = tamaño en bytes
    fclose(orig);
    fclose(dest);

	printf("\nTama%co del archivo: %ld bytes\n", 164,tam);
    return 0;
}
