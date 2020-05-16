#include "ArrayEmployees.h"
#define T 3
#define OCUPADO 1
#define LIBRE 0

void initEmployee(newEmployee employee[],int tam,int estado){
    for(int i=0;i<tam;i++){
        employee[i].isEmpty = estado;
    }
}

int buscarIndice(newEmployee employee[], int tam,int estado){

    int indice= -1;
    int i;
    for(i=0; i < tam; i++){
    if(employee[i].isEmpty==estado){
        indice=i;
        return indice;

    }
    }
    return indice;
    }

int addEmployee(newEmployee employee[], int tam,int estado, int contador){

    int guardarIndice;
    int i;
    guardarIndice = buscarIndice(employee, T,LIBRE);
    printf("******ALTA EMPLEADO ******\n");
    if(guardarIndice != -1){
        employee[guardarIndice].id=1+contador;
        getString("Ingrese nombre del empleado: ",employee[guardarIndice].name);
        getString("Ingrese apellido del empleado: ",employee[guardarIndice].lastName);
        printf("Ingrese el salario: ");
        scanf("%f",&employee[guardarIndice].salary);
        employee[guardarIndice].sector=getInt("Ingrese el sector del empleado:","Ingrese un numero valido!",0,1000000);
        employee[guardarIndice].isEmpty=estado;
        return 1;
    }
    return 0;

}

int modifyEmployee(newEmployee employee[], int tam, int estado){
    int i;
    int opcion;
    int idModificar;
    printf("\nIngrese el numero de id: ");
    scanf("%d",&idModificar);

    for(i=0; i < tam; i++){
            if(employee[i].id == idModificar && employee[i].isEmpty == estado ){
                printf("\n1: Modificar nombre:\n2: Modificar apellido:\n3: Modificar sueldo:\n4: Modificar sector:\n5: Volver ");
                opcion=getInt("\nIngrese una opcion:","Ingrese una opcion valida",0,5);
                do{
                switch(opcion){
                case 1:
                    getString("Ingrese el nombre: ",employee[i].name);
                    break;
                case 2:
                    getString("Ingrese el apellido: ",employee[i].lastName);
                    break;
                case 3:
                    employee[i].salary=getInt("Ingrese el salario: ","Ingrese un salario valido!",0,1000000);
                    break;
                case 4:
                   employee[i].salary=getInt("Ingrese el sector: ","Ingrese un sector valido!",0,1000000);
                    break;
                case 5:
                    printf("-");
                    break;

                }
                printf("\nElija otra opcion o ingrese[5] para volver ?");
                opcion=getInt(":", "Ingrese una opcion valida",0,5);


                }while(opcion!=5);
                return 1;


    }

    }
     return 0;
    }

int removeEmployee(newEmployee employee[], int tam,int ocupado,int libre){

int i;
int idEliminar;
printf("\nIngrese el numero de id a dar de baja: ");
scanf("%d",&idEliminar);
for(i=0; i < tam; i++){
            if(employee[i].id == idEliminar && employee[i].isEmpty == ocupado ){
                employee[i].isEmpty= libre;
                return 1;
            }
}
return 0;
}

void printEmployees(newEmployee employee[], int tam,int ocupado){
    printf("ID*************Nombre******Apellido******Salario******Sector\n");
    for(int i=0;i<tam;i++){
        if(employee[i].isEmpty==ocupado){
        printf("%3d%15s %15s      %6.2f      %d\n",employee[i].id,employee[i].name,employee[i].lastName,employee[i].salary,employee[i].sector);
    }
}
}

void sortEmployees(newEmployee employee[], int tam){
    {
    int i;
    int j;
    newEmployee aux;
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(employee[i].lastName,employee[j].lastName)>0)
            {
                aux=employee[i];
                employee[i]=employee[j];
                employee[j]=aux;
            }
            else
            {
                if(employee[i].sector>employee[j].sector && strcmp(employee[i].name,employee[j].name)==0)
                {
                    aux=employee[i];
                    employee[i]=employee[j];
                    employee[j]=aux;
                }

            }
        }
    }

}
}

float totalSueldos(newEmployee employee[],int tam,int estado){
    float total=0;
    for(int i=0;i<tam;i++){
        if(employee[i].isEmpty==estado){
            total=total+employee[i].salary;
        }
    }
     return total;
}

void printInform(newEmployee employee[],int tam, float promedio){
    int contadorSalariosAltos=0;
    for(int i=0; i<tam; i++)
        {
        if(employee[i].salary>promedio)
        {
                contadorSalariosAltos++;
        }
        }
        printf("\nLa cantidad de empleados con el sueldo por encima del promedio son: %d ",contadorSalariosAltos);
}





