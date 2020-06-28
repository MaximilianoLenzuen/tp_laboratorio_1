#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

int main()
{
    int option;
    int aux;
    int flagCarga=0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaEmpleados2 = NULL;





    do{
            menu();
            option = getInt("\nIngrese una opcion: ","Ingrese una opcion valida!!",0,13);
            switch(option)
            {

                case 1:
                    system("cls");
                    controller_loadFromText("data.csv",listaEmpleados);
                    break;
                case 2:
                       system("cls");
                    if(controller_replace(listaEmpleados))
                    {
                        printf("Operacion realizada con exito!");
                    }else
                    {
                        printf("No se pudo realizar la operacion");
                    }

                    break;
                case 3:
                    system("cls");
                    if(controller_addEmployee(listaEmpleados)==1)
                    {
                        printf("Operacion realizada con exito!");
                    }else
                    {
                        printf("No se pudo realizar la operacion");
                    }

                    break;
                case 4:
                     system("cls");
                    if(ll_len(listaEmpleados)>0)
                        {

                            controller_editEmployee(listaEmpleados);
                        }else
                    {
                        printf("\n No hay empleados para editar");
                    }
                    break;
                case 5:
                    if(ll_len(listaEmpleados)>0)
                        {
                            system("cls");
                            controller_removeEmployee(listaEmpleados);
                        }else
                    {
                        printf("\No hay empleados que remover!");
                    }
                    break;
                case 6:
                    if(ll_len(listaEmpleados)>0)
                        {
                            system("cls");
                            controller_ListEmployee(listaEmpleados);
                        }else
                        {
                            printf("\nNo hay empleados que listar");
                        }
                    break;
                case 7:
                    system("cls");
                    if(ll_len(listaEmpleados)>0){
                    system("cls");
                    controller_sortEmployee(listaEmpleados);
                    }else
                    {
                        printf("\No hay empleados que ordenar!!");
                    }
                    break;
                case 8:
                    system("cls");
                    listaEmpleados2=ll_clone(listaEmpleados);

                    if(listaEmpleados2!=NULL)
                    {
                        printf("Operacion realizada con exito.");

                    }else
                    {
                        printf("No se pudo clonar. No hay lista para clonar! !");
                    }
                    break;
                case 9:
                    system("cls");
                    aux= controller_viewInSucursal(listaEmpleados,listaEmpleados2);
                    if(aux==1)
                    {
                        printf("El empleado se encuentra en ambas sucursales!!");
                    } else if(aux==0)
                    {
                        printf("El empleado solo se encuentra en una lista");
                    }else
                    {
                        printf("El empleado no está en ninguna lista");
                    }
                    break;
                case 10:
                    system("cls");
                    if(listaEmpleados2!=NULL)
                    {
                        controller_ListEmployee(listaEmpleados2);
                    }
                    else
                    {
                        printf("No hay lista clonada!");
                    }

                    break;
                case 11:
                    system("cls");
                    break;
                case 12:
                    system("cls");
                    controller_saveAsText("data.csv",listaEmpleados);
                    break;
                case 13:
                    system("cls");
                    printf("\nGracias por utilizar el menu!");
                    break;


        }
    }while(option != 13);

    return 0;
}
