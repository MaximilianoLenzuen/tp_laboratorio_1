#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "ArrayEmployees.h"
#define T 3
#define LIBRE 0
#define OCUPADO 1


int main()
{
    int flagUno=0;
    int opcion;
    int contador=0;
    int contadorID=0;
    int controlUno;
    int controlTres;
    float total;
    float promedioSalarios;
    newEmployee employee[T];

        initEmployee(employee,T,LIBRE);


        printf("1-ALTAS\n2-MODIFICAR\n3-BAJA\n4-INFORMAR\n5-SALIR");
        opcion=getInt("\nIngrese la opcion:","Opcion no valida!",0,5);
    do{
        system("cls");
        printf("1-ALTAS\n2-MODIFICAR\n3-BAJA\n4-INFORMAR\n5-SALIR\n\n");
    	switch(opcion){
    	case 1:
        controlUno=validarOperacion("La carga fue realizada con exito","No hay lugar disponible para otro empleado o hubo un error",addEmployee(employee,T,OCUPADO,contadorID));
        if(controlUno==1){
        contador++;
        contadorID++;
        flagUno=1;
        }
        break;
    	case 2:
        if(flagUno==1){
        printEmployees(employee,T,OCUPADO);
        validarOperacion("La operación fue realizada correctamente!","La operacion no se pudo realizar",modifyEmployee(employee,T,OCUPADO));

        }else{
        printf("Todavia no ingreso ningun empleado!");
        }
        break;
        case 3:
        if(flagUno==1){
        printEmployees(employee,T,OCUPADO);
        controlTres=validarOperacion("La baja del empleado fue realizada con exito","No se pudo dar de baja al empleado",removeEmployee(employee,T,OCUPADO,LIBRE));
        if(controlTres==1){
        contador--;
        }
        }else{
        printf("Todavia no ingreso ningun empleado!");
        }
        break;
        case 4:
        if(flagUno==1){
        total=totalSueldos(employee,T,OCUPADO);
        promedioSalarios=total/contador;
        sortEmployees(employee,T);
        printEmployees(employee,T,OCUPADO);
        printf("\nEl total de sueldos es: %f\nEl promedio de los salarios es: %.2f",total,promedioSalarios);
        printInform(employee,T,promedioSalarios);
        }else{
        printf("Todavia no ingreso ningun empleado!");
        }

        break;
        case 5:
        printf("Gracias por utilizar el menu");
        break;
    		}
        printf("\nIngrese otra opcion: ");
        scanf("%d",&opcion);
    	}while(opcion!=5);
        printf("\nGracias por utilizar el menu!");

    }



