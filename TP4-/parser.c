#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
	int cantidad;
	char buffer1[128];
	char buffer2[128];
	char buffer3[128];
	char buffer4[128];
	Employee* newEmp;

	fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer1, buffer2, buffer3, buffer4);

	if(pFile!=NULL && pArrayListEmployee!=NULL){

		while(!feof(pFile)){
			cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",buffer1,buffer2,buffer3,buffer4);
			newEmp=employee_newParametros(atoi(buffer1),buffer2,atoi(buffer3),atoi(buffer4));

			if(newEmp!=NULL){
				ll_add(pArrayListEmployee,newEmp);
				retorno=1;
			}

			if(cantidad<4){
				if(feof(pFile)){
					break;
				}

				else{
					retorno=0;
					break;
				}
			}

		}
	}

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
	int cantidad;
	Employee* newEmp;



	if(pFile!=NULL && pArrayListEmployee!=NULL){

		while(!feof(pFile)){
            newEmp=employee_new();
			cantidad = fread(newEmp,sizeof(Employee),1,pFile);

			if(newEmp!=NULL){
				ll_add(pArrayListEmployee,newEmp);
				retorno=1;
			}


			else{
				employee_delete(newEmp);
			}


			if(cantidad<1){
				if(feof(pFile)){
					break;
				}

				else{
					retorno=0;
					break;
				}
			}


		}
		}


    return retorno;
}
