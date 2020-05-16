#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int validarOperacion(char mensaje [],char mensajeError[], int devolucion){
        int aux;
        if(devolucion == 1){
            printf("%s",mensaje);
            aux=1;
        }else{
            printf("%s",mensajeError);
            aux=0;
        }
        return aux;
}
