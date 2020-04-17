/*
 * utn.c
 *
 *  Created on: 12 abr. 2020
 *      Author: Maxi
 */

int pedirOpcion(void){
	int retorno;
	printf("Ingrese la opción: ");
	scanf("%d", &retorno);
	while(retorno >5 || retorno <0){
        printf("Ingrese un numero valido!");
        scanf("%d" , &retorno);
    }


	return retorno;
}
int pedirNumero(char mensaje[]){
	int retorno;
	printf("%s", mensaje);
	scanf("%d", &retorno);
	return retorno;
}



int suma(int numeroUno, int numeroDos){
        int valorEntero;

       valorEntero = numeroUno + numeroDos;

        return valorEntero;

    }
int resta(int numeroUno, int numeroDos){
        int valorEntero;

        valorEntero = numeroUno - numeroDos;

        return valorEntero;

    }
int multiplicacion(int numeroUno, int numeroDos){
        int valorEntero;

        valorEntero = numeroUno * numeroDos;

        return valorEntero;

    }
float division(int numeroUno, int numeroDos){
        float valorEntero;

        valorEntero = (float)numeroUno / numeroDos;

        return valorEntero;

    }
long int factorial(int valor){

    	long int f=1;

    	for(int i = valor; 1<= i ; i --){

    		f=f*i;
    	}

    	return f;
    }


