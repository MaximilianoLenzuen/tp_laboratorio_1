#include "funciones.h"
int getInt(char mensaje[],char mensajeError[],int piso, int techo){
    int entero;
    printf("%s",mensaje);
    scanf("%d",&entero);
    while (entero < piso || entero>techo ){
        printf("%s",mensajeError);
        scanf("%d",&entero);
    }
    return entero;
}

void getString(char mensaje[],char lugar[]){
    printf("%s",mensaje);
    fflush(stdin);
    gets(lugar);
}

void menu(void)
{
     printf("\nMenu:\n");
     printf("1. Cargar los datos de los empleados desde el archivo data.csv.\n");
     printf("2. Cambiar elemento de la lista de lugar \n");
     printf("3. Alta de empleado\n");
     printf("4. Modificar datos de empleado\n");
     printf("5. Baja de empleado\n");
     printf("6. Listar empleados\n");
     printf("7. Ordenar empleados\n");
     printf("8. Clonar lista de empleados.\n");
     printf("9. Determinar si el empleado está en ambas listas.\n");
     printf("10. Listar empleados de lista clonada \n");
     printf("11. Guardar los datos de los empleados en el archivo data.csv.\n");
     printf("12. Salir\n");
}

