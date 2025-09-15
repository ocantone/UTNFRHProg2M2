/*
    OBTIENE LISTADOS DE MEJORES ALUMNOS.
*/
#include<stdio.h>
#define CANTIDAD 40

struct ALUMNO{
	char NOM[15];
	char SEX;
	int NOTA;
};
    FILE *fp;
    struct ALUMNO unAlumno;

int main (void){
	int i = 0;
    int mejorNota = 0;

  if(( fp=fopen("C:\\Temp\\DATOS.DAT", "rb")) == NULL ){
        printf("\n\nERROR AL ABRIR EL ARCHIVO DATOS.DAT para leer\n\n");
        return 1;
    }

    printf("\nMejores alumnos:\n\n");

    while ( fread(&unAlumno, sizeof(struct ALUMNO), 1, fp) ) {
        if(i == 0){
            mejorNota = unAlumno.NOTA;
        }
        else{
            if( unAlumno.NOTA > mejorNota){
                    mejorNota = unAlumno.NOTA;
            }
        }
        i++;
    }
    printf("\nMejor nota: %d", mejorNota);
    rewind(fp);             //reposiciona fp.
    i = 0;
    while ( fread(&unAlumno, sizeof(struct ALUMNO), 1, fp) ) {
        if( unAlumno.NOTA == mejorNota){
            printf("\n%d)\t %-15s \t %c \t %2d", i+1,unAlumno.NOM, unAlumno.SEX,unAlumno.NOTA);
        }
        i++;
    }
    fseek(fp, 0, SEEK_END);     // pone el puntero al final
    long tam = ftell(fp);       // leer posición = tamaño en bytes
    fclose(fp);

	printf("\n\nTama%co del archivo : %ld bytes\n", 164,tam);
	printf("\nTama%co del registro: %llu bytes\n", 164, sizeof(unAlumno));
	printf("\nLeidos %ld registros\n", (long)(tam/sizeof(unAlumno)));
    return 0;
}
