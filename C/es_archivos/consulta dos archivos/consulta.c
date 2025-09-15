/*
    LISTA LOS EMPLEADOS CON EL NOMBRE DE LA SUCURSAL
*/
#include<stdio.h>


struct EMPLEADO{
	char NOMBRE[15];
	char SEXO;
	int numSucursal;
};

struct SUCURSAL{
    int codigoSUC;
    char nomSucursal[20];
    int totalEmpleados;
};

	FILE *fp1;
	FILE *fp2;


int main (void){

	char archivo1[] = {"EMPLEADOS.DAT"};
	char archivo2[] = {"SUCURSALES.DAT"};

    struct EMPLEADO unEmpleado;
    struct SUCURSAL unaSucursal;

    int i=0;

  printf("Lista Empleados:\n\n");
  if(( fp1=fopen(archivo1, "rb")) == NULL ){
        printf("\n\nERROR AL ABRIR EL ARCHIVO %s para leer\n\n", archivo1);
        return 1;
    }
  if(( fp2=fopen(archivo2, "rb")) == NULL ){
        printf("\n\nERROR AL ABRIR EL ARCHIVO %s para leer\n\n", archivo2);
        return 1;
    }


    while (fread(&unEmpleado, sizeof(struct EMPLEADO), 1, fp1), !feof(fp1) ) {
        fseek(fp2, ((unEmpleado.numSucursal)-1)*sizeof(struct SUCURSAL), SEEK_SET);
        fread(&unaSucursal, sizeof(struct SUCURSAL), 1, fp2 );

        printf("\n%d)\t %-20s \t%c \t%s", i,unEmpleado.NOMBRE, unEmpleado.SEXO, unaSucursal.nomSucursal);
        i++;
    }

    return 0;
}
