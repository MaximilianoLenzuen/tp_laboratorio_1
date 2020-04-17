/*
 ============================================================================
 Name        : TrabajoPractico1.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    setbuf(stdout,NULL);
    int opcion;
    int numeroUno;
    int numeroDos;
    int flagUno=0;
    int flagDos=0;
    int flagTres=0;
    int resultadoSuma;
    int resultadoResta;
    int resultadoMultiplicacion;
    long int resultadoFactorialA;
    long int resultadoFactorialB;
    float resultadoDivision;



    printf("1 - Ingrese un numero\n2- Ingrese otro numero\n3- Calcular todas sus operaciones\n4- Informar resultados\n5 -Salir\n");

    opcion=pedirOpcion();

    do{


        switch(opcion){
        case 1:
            numeroUno=pedirNumero("Ingrese el primer numero: ");
            opcion = 10;
            flagUno = 1;
            break;
        case 2:
            numeroDos=pedirNumero("Ingrese el segundo numero");
            opcion =10;
            flagDos = 1;
            break;
        case 3:
            if(flagUno == 1 && flagDos == 1){
                resultadoSuma = suma(numeroUno ,numeroDos);
                resultadoResta = resta(numeroUno ,numeroDos);
                resultadoMultiplicacion = multiplicacion(numeroUno , numeroDos);
                resultadoDivision = division(numeroUno , numeroDos);
                resultadoFactorialA = factorial(numeroUno);
                resultadoFactorialB = factorial(numeroDos);
                opcion=10;
                flagTres=1;
                printf("\n Calculos realizados:\n ");
            }else{
                printf("Primero tiene que ingresar los dos numeros!!");
                opcion=10;
            }
            break;

        case 4:
             if(flagUno == 1 && flagDos == 1 && flagTres == 1 ){
            printf("El resultado de A+B es: %d", resultadoSuma);
            printf("\nEl resultado de A-B es: %d", resultadoResta);
            if(numeroDos==0){
                printf("\nEs imposible dividir por 0!!!");
            }else{
            printf("\nEl resultado de A/B es: %.2f", resultadoDivision);
            }
            printf("\nEl resultado de A*B es: %d\n", resultadoMultiplicacion);
            printf("\nEl resultado de !A es: %li\n", resultadoFactorialA);
            printf("\nEl resultado de !B es: %li\n", resultadoFactorialB);

            opcion=10;
            } else if(flagUno ==1 && flagDos == 1){
                printf("Ya ingresó los numeros pero no se realizo ningun cálculo!");
                opcion=10;
            }else{
            	 printf("Primero debe ingresar los dos numeros \n");
            	 opcion=10;

            }
            break;

        }

        if (opcion == 10){
            printf("Ingrese otra opcion: ");
            scanf("%d", &opcion);
            while(opcion >5 || opcion <0){
            printf("Ingrese un numero valido!");
            scanf("%d" , &opcion);
    }

        }


    } while(opcion != 5);


printf("Gracias por utilizar el menu!");

return 0;
}
