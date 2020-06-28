#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "funciones.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* file;
    int retorno = -1;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        file = fopen("data.csv","r");

            if(parser_EmployeeFromText(file,pArrayListEmployee)==1)
            {
                printf("\nLa carga fue realizada correctamente!\n");
                retorno = 1;
            }else
            {
                printf("\n Hubo un problemilla");
            }

    }
    return retorno;
}


/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int id;
    char nombre[22];
    int horasTrabajadas;
    int sueldo;
    Employee* this;
    id = controller_lastId(pArrayListEmployee);
    id++;
    getString("\n Ingrese el nombre: ",nombre);
    horasTrabajadas = getInt("\n Ingrese las horas trabajadas: ","Ingrese un valor correcto!!!",0,10000000);
    sueldo = getInt("\n Ingrese el sueldo: ","Ingrese un sueldo valido!!",0,10000000);
    this = employee_newParametros (id,nombre,horasTrabajadas,sueldo);
    ll_add(pArrayListEmployee,this);
    retorno = 1;


    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
        int retorno = -1;
        int i;
        int id;
        int idComparison;
        char nombre[22];
        int horasTrabajadas;
        int sueldo;
        Employee* this;
        this = employee_new();
        int len = ll_len(pArrayListEmployee);
        controller_ListEmployee(pArrayListEmployee);
        id = getInt("\nIngrese un id","Ingrese un id valido!!",0,10000000000);
        if(this!=NULL){
        for(i=0;i<len;i++)
        {


        this = ll_get(pArrayListEmployee,i);

        employee_getId(this,&idComparison);

        if(id==idComparison)
        {
            break;
        }

        }
        }
        getString("\n Ingrese el nombre: ",nombre);
        horasTrabajadas = getInt("\n Ingrese las horas trabajadas: ","Ingrese un valor correcto!!!",0,10000000);
        sueldo = getInt("\n Ingrese el sueldo: ","Ingrese un sueldo valido!!",0,10000000);
        employee_setHorasTrabajadas(this,horasTrabajadas);
        employee_setNombre(this,nombre);
        employee_setSueldo(this,sueldo);
        ll_set(pArrayListEmployee,i,this);





    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
        int retorno=-1;
        int aux =0;
        int i;
        int id;
        int idComparison;
        int len = ll_len(pArrayListEmployee);
        Employee* this;

        controller_ListEmployee(pArrayListEmployee);

        id = getInt("\nIngrese un id: ","Ingrese un id valido!!",0,10000000000);

        for(i=0;i<len;i++)

        {
        this = employee_new();

        this = ll_get(pArrayListEmployee,i);

        employee_getId(this,&idComparison);

        if(id==idComparison)
        {
            aux =1;
            break;
        }

        }

        if(aux==1)
            {

                ll_remove(pArrayListEmployee,i);
                printf("\n La baja fue exitosa!");
            }
            else
            {
                printf("\nNo se pudo realizar la baja");
            }


        return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    int horasTrabajadas;
    int sueldo;
    char nombre[128];
    Employee* employee;
    int len=ll_len(pArrayListEmployee);

    for(int i=0;i<len;i++)
    {
        employee=ll_get(pArrayListEmployee,i);
        employee_getId(employee,&id);
        employee_getNombre(employee,&nombre);
        employee_getHorasTrabajadas(employee,&horasTrabajadas);
        employee_getSueldo(employee,&sueldo);
        printf("\nID: %d HORAS: %d  SUELDO: %d NOMBRE %s",id,horasTrabajadas,sueldo,nombre);
    }





    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int returnAux=-1;
	int option;

	if(pArrayListEmployee!=NULL)
	{
		if(ll_len(pArrayListEmployee)>0)
		{
                option=MenuOrdenamiento();
				switch(option)
				{
					case 1:
						ll_sort(pArrayListEmployee,employee_sortByName,1);
					break;

					case 2:
						ll_sort(pArrayListEmployee,employee_sortByHours,1);
					break;

					case 3:
						ll_sort(pArrayListEmployee,employee_sortBySalary,1);
					break;

					case 4:
						ll_sort(pArrayListEmployee,employee_sortById,1);
					break;

		}
	}

	else{
		printf("\nHa ocurrido un error");
	}

    return returnAux;
}
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
        FILE* file;
	    Employee* this;
	    int len = -1;
	    int id;
	    int sueldo;
	    int horasTrabajadas;
	    int i;
	    char nombre[50];

	    int aux = 0;

	    if(path != NULL && pArrayListEmployee != NULL){
	        len = ll_len(pArrayListEmployee);
	        if(len > 0){
	            file = fopen(path,"w");
	            if(file!=NULL){
	            	fprintf(file,"ID NOMBRE HORAS TRABAJADAS SUELDO\n");
	                for(i=0;i<len;i++){
	                    this=(Employee*)ll_get(pArrayListEmployee,i);
	                    employee_getId(this,&id);
	                    employee_getNombre(this,nombre);
	                    employee_getHorasTrabajadas(this,&horasTrabajadas);
	                    employee_getSueldo(this,&sueldo);
	                    fprintf(file,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);
	                }
	                fclose(file);
	                if(i == len){
	                    aux = 1;
	                }
	            }
	        }
	    }
	    if(aux == 1)
	    {
	         	printf("El archivo se ha cargado correctamente\n");
	    }
	    else
	    {
	        if(len == 0)
	        {
	        	printf("La lista está vacia!!");
	        }
	        else
	        {
	        	printf("Ups!, ocurrio un error al salvar los datos");
	        }
	    }
	    return aux;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* file;
	Employee* this;
	int len = -1;
	int i;

	int aux = 0;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);
		if(len > 0)
		{
			file = fopen(path,"wb");

            for(i=0;i<len;i++)
            {
                this=ll_get(pArrayListEmployee,i);
                if(this!=NULL){
                    fwrite(this,sizeof(Employee),1,file);
                }
            }
            fclose(file);

            if(i==len)
            {
                aux=1;
            }
        		printf("Se ha realizado la operacion correctamente");
		}else
		{
		    printf("No se ha podido realizar");
		}

	}





		return aux;
}

int controller_lastId(LinkedList* pArrayListEmployee)
{
    int i;
    int lastid=0;
    int len=ll_len(pArrayListEmployee);
    int maxid=0;

    Employee* employee;
    for(i=0;i<len;i++)
    {
        employee = employee_new();

        employee = ll_get(pArrayListEmployee,i);

        employee_getId(employee,&lastid);
        if(lastid>maxid)
        {
            maxid=lastid;
        }

    }
    return maxid;
}

/** \brief Determinar si el empleado está en alguna sucursal
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */


int controller_viewInSucursal(LinkedList* pArrayListEmployee,LinkedList* pArrayListEmployee2)
{
        int returnAux = -1;
        int i;
        int id;
        int contador=0;
        int idComparison;
        Employee* this;
        this = employee_new();
        printf("El tamanio de la lista es: %d ",ll_len(pArrayListEmployee));
        id = getInt("\nIngrese un id","Ingrese un id valido y menor que el tamanio de la lista!!",0,controller_lastId(pArrayListEmployee));

        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
        this = ll_get(pArrayListEmployee,i);

        employee_getId(this,&idComparison);

        if(id==idComparison)
        {
            break;
        }

        }

        if(pArrayListEmployee!= NULL && ll_contains(pArrayListEmployee,this) ==1 )
        {
            contador++;

        }
        if(pArrayListEmployee2!= NULL && ll_contains(pArrayListEmployee2,this) ==1 )
        {
            contador++;
        }

        if(contador==2)
        {
            returnAux=1;
        }
        if(contador==1)
        {
            returnAux =0;
        }
    return returnAux;
}

int controller_replace(LinkedList* pArrayListEmployee){

    int index2;
    int id;
    int i;
    int idComparison;
    int returnAux = -1;
    Employee* this;
    controller_ListEmployee(pArrayListEmployee);
    id = getInt("\nIngrese el id que desea mover: ","Ingrese un id valido!!",0,controller_lastId(pArrayListEmployee));

    for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            this = ll_get(pArrayListEmployee,i);

            employee_getId(this,&idComparison);

            if(id==idComparison)
                {
                    returnAux = 1;
                    break;
                }

        }
    this=(Employee*)ll_pop(pArrayListEmployee,i);
    printf("\n El usuario es: ID: %d - Nombre: %s Horas trabajadas: %d Sueldo: %d ",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
    printf("\nIngresar la posicion en la cual quieras agregarlo:\n");
    scanf("%d",&index2);
    ll_push(pArrayListEmployee,index2,this);



return returnAux;
}




