/*
    MUESTRA ALUMNAS EN EL ARCHIVO DATOS.DAT.
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
	int i=0;
	char op;

  if(( fp=fopen("C:\\Temp\\DATOS.DAT", "rb")) == NULL ){
        printf("\n\nERROR AL ABRIR EL ARCHIVO DATOS.DAT para leer\n\n");
        return 1;
    }

    do{
    printf("\n\nMostrar:\n 1)Mujeres \n 2)Varones \nopci%cn: ", 162);
    scanf(" %c", &op);
    }while( op != '1' && op != '2' );

    switch (op){
        case '1':   op = 'f';
                    break;
        case '2':   op = 'm';
                    break;

     }

    printf("\nContenido del archivo DATOS.DAT:\n\n");

    while ( fread(&unAlumno, sizeof(struct ALUMNO), 1, fp) ) {
        if( unAlumno.SEX == op){
        printf("\n%d)\t %-15s \t %c \t %2d", i+1,unAlumno.NOM, unAlumno.SEX,unAlumno.NOTA);
        i++;
        }
    }

    fseek(fp, 0, SEEK_END);     // mover el puntero al final
    long tam = ftell(fp);       // leer posición = tamaño en bytes
    fclose(fp);

	printf("\n\nTama%co del archivo : %ld bytes\n", 164,tam);
	printf("\nTama%co del registro: %llu bytes\n", 164, sizeof(unAlumno));
	printf("\nLeidos %ld registros\n", (long)(tam/sizeof(unAlumno)));
    return 0;
}
