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
/* Busca el valor de la mejor nota del archivo. */
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
	
    rewind(fp);             /* reposiciona fp al inicio */
    i = 0;
	
	/* Informa los alumnos con la mejor nota. */
    while ( fread(&unAlumno, sizeof(struct ALUMNO), 1, fp) ) {
        if( unAlumno.NOTA == mejorNota){
            printf("\n%d)\t %-15s \t %c \t %2d", i+1,unAlumno.NOM, unAlumno.SEX,unAlumno.NOTA);
        }
        i++;
    }
    fclose(fp);

    return 0;
}

