/*
    CREA Y CARGA LOS ARCHIVOS EMPLEADOS.DAT Y SUCURSALES.DAT
*/
#include<stdio.h>
#define CANTIDAD 40

struct EMPLEADO{
	char NOMBRE[15];
	char SEXO;
	int SUCURSAL;
};

struct SUCURSALES{
    int codigoSUC;
    char nomSucursal[20];
    int totalEmpleados;
};

struct EMPLEADO LISTA[] = {
	{"JUAN", 'm', 1},{"ISMAEL", 'm', 1},{"ROSENDO", 'm', 1},
	{"JULIAN", 'm', 2},{"ALFREDO", 'm', 2},{"CARLA", 'f', 2},
	{"CAROLA", 'f', 2},{"AMBAR", 'f', 3},{"FEDERICO", 'm', 3},
	{"PEDRO", 'm', 2},{"RITA", 'f', 1},{"MANUEL", 'm', 3},
	{"LISA", 'f', 2},{"MARIELA", 'f', 1},{"GIMENA", 'f', 1},
	{"ARIEL", 'm', 3},{"HORACIO", 'm', 3},{"LIONEL", 'm', 2},
	{"MIRIAM", 'f', 3},{"OMAR", 'm', 1},{"ROSA", 'f', 2},
	{"FLORENCIA", 'f', 1},{"SERGIO", 'm', 2},{"LOURDES", 'f', 2},
	{"EVANGELINA", 'f', 3},{"PABLO", 'm', 3},{"NATALIA ", 'f', 3},
	{"MARCELO", 'm', 2},{"MERCEDES", 'f', 2},{"MARCELA", 'f', 1},
	{"LUIS", 'm', 1},{"OSCAR", 'm', 3},{"SANDRA", 'f', 2},
	{"NORBERTO", 'm', 1},{"ANA", 'f', 1},{"VIRGINIA", 'f', 3},
	{"DIEGO", 'm', 1},{"BRUNO", 'm', 1},{"ROMINA", 'f', 2},
	{"FRANCO", 'm', 3}
};
struct SUCURSALES LISTA_SUC[] = {
    {1,"BUENOS AIRES", 68}, {2,"CORDOBA", 38},{3,"ROSARIO", 32}
};

	FILE *fp1;
	FILE *fp2;


int main (void){

	char archivo1[] = {"EMPLEADOS.DAT"};
	char archivo2[] = {"SUCURSALES.DAT"};

	int cantEmpleados  = sizeof(LISTA) / sizeof(struct EMPLEADO);
	int cantSucursales = sizeof(LISTA_SUC) / sizeof(struct SUCURSALES);
    long tam;
    int i=0;

/*  EMPLEADOS.DAT   */
	printf("CREA ARCHIVO EMPLEADOS\n");

	if(( fp1=fopen(archivo1, "wb")) == NULL ){
		printf("\n\nERROR AL CREAR EL ARCHIVO %s\n\n", archivo1);
		return 1;
	}

    for(i=0; i<cantEmpleados; i++){
		fwrite( &LISTA[i] , sizeof(struct EMPLEADO) , 1 , fp1 );
		printf("\n %d \t %-15s \t %c \t %d", i,LISTA[i].NOMBRE, LISTA[i].SEXO, LISTA[i].SUCURSAL);
	}
	printf("\n\nESCRITOS %d REGISTROS.\n", i);
	fclose(fp1);
    i=0;

  if(( fp1=fopen(archivo1, "rb")) == NULL ){
        printf("\n\nERROR AL ABRIR EL ARCHIVO %s para leer\n\n", archivo1);
        return 1;
    }
    printf("\nContenido del archivo %s:\n\n", archivo1);

    while (fread(&LISTA[i], sizeof(struct EMPLEADO), 1, fp1), !feof(fp1) ) {
        printf("\n%d)\t %-15s \t %c \t %2d", i,LISTA[i].NOMBRE, LISTA[i].SEXO, LISTA[i].SUCURSAL);
        i++;
    }

    fseek(fp1, 0, SEEK_END);
    tam = ftell(fp1);
    fclose(fp1);
	printf("\n\nTama%co del archivo %s: %ld bytes\n", 164, archivo1, tam);


/*  SUCURSALES.DAT  */
	printf("\n\nCREA ARCHIVO SUCURSALES\n");

	if(( fp2=fopen(archivo2, "wb")) == NULL ){
		printf("\n\nERROR AL CREAR EL ARCHIVO %s\n\n", archivo2);
		return 1;
	}

    for(i=0; i<cantSucursales; i++){
		fwrite( &LISTA_SUC[i] , sizeof(struct SUCURSALES) , 1 , fp2 );
		printf("\n %d %-20s %6d",LISTA_SUC[i].codigoSUC, LISTA_SUC[i].nomSucursal, LISTA_SUC[i].totalEmpleados);
	}
	printf("\n\nESCRITOS %d REGISTROS.\n", i);
	fclose(fp2);
    i=0;

  if(( fp2=fopen(archivo2, "rb")) == NULL ){
        printf("\n\nERROR AL ABRIR EL ARCHIVO %s para leer\n\n", archivo2);
        return 1;
    }
    printf("\nContenido del archivo %s:\n\n", archivo2);

    while (fread(&LISTA_SUC[i], sizeof(struct SUCURSALES), 1, fp2), !feof(fp2) ) {
		printf("\n %d %-20s %6d",LISTA_SUC[i].codigoSUC, LISTA_SUC[i].nomSucursal, LISTA_SUC[i].totalEmpleados);
        i++;
    }

    fseek(fp2, 0, SEEK_END);
    tam = ftell(fp2);
    fclose(fp2);
	printf("\n\nTama%co del archivo %s: %ld bytes\n", 164, archivo2, tam);



    return 0;
}
