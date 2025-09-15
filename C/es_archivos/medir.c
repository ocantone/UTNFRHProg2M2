/*
DEVUELVE EL TAMAÑO DEL ARCHIVO EN BYTES.
*/
#include <stdio.h>
#include <stdlib.h>

FILE *fp;
long tam;

int main( int argc, char *argv[])
{
    if( argc != 2){
        printf("\nUso: medir [archivo a medir]\n\n");
		return 0;
    }
//    printf("\nargv[0]: %s", argv[0]);
//    printf("\nargv[1]: %s", argv[1]);

    if(( fp=fopen(argv[1], "rb")) == NULL ){
        printf("\n\nError al abrir el archivo %s\n\n", argv[1]);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    tam = ftell(fp);
    fclose(fp);

	printf("\nTama%co del archivo: %ld bytes\n\n", 164,tam);
    
    return 0;
}


