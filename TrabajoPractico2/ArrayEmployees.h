#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}newEmployee;

void initEmployee(newEmployee employee[],int tam,int estado);
int buscarIndice(newEmployee employee[], int tam,int estado);
int addEmployee(newEmployee employee[],int tam,int estado,int contador);
int removeEmployee(newEmployee employee[], int tam,int ocupado,int libre);
void printEmployees(newEmployee employee[], int tam,int ocupado);
void sortEmployees(newEmployee employee[], int tam);
float totalSueldos(newEmployee employee[],int tam,int estado);
void printInform(newEmployee employee[],int tam, float promedio);
