/*
	AUTHOR: KEILA CEÑAL
	COMISION: 1F

 * principal-source.c
 *
 *  Created on: 26 abr. 2021
 *Enunciado
Una empresa requiere un sistema para administrar su n�mina de empleados. Se sabe que
dicha n�mina bajo ninguna circunstancia superara los 1000 empleados.
El sistema deber� tener el siguiente men� de opciones:

*1. ALTAS: Se debe permitir ingresar un empleado calculando autom�ticamente el n�mero
de Id. El resto de los campos se le pedir� al usuario.

*2. MODIFICAR: Se ingresar� el N�mero de Id, permitiendo modificar: o Nombre o Apellido
o Salario o Sector

*3. BAJA: Se ingresar� el N�mero de Id y se eliminar� el empleado del sistema.

*4. INFORMAR:
	4.1. Listado de los empleados ordenados alfab�ticamente por Apellido y Sector.
	4.2. Total y promedio de los salarios, y cu�ntos empleados superan el salario promedio.

NOTA: Se deber� realizar el men� de opciones y las validaciones a trav�s de funciones.
Tener en cuenta que no se podr� ingresar a los casos 2, 3 y 4; sin antes haber realizado la
carga de alg�n empleado.
Para la realizaci�n de este programa, se utilizar� una biblioteca llamada �ArrayEmployees� que
facilitar� el manejo de la lista de empleados y su modificaci�n. En la secci�n siguiente se
detallan las funciones que esta biblioteca debe tener.

 */

#include "arrayEmployees.h"


#define MAX_EMPLOYEES 1000

int main(void){
	setbuf(stdout, NULL);
	int option;
	int flag;
	//variables
	float sumPayments;
	int qEmployees;
	float average;
	sumPayments=0;
	qEmployees=0;
	average=0;
	sEmployee employeeList[MAX_EMPLOYEES];
	initEmployees(employeeList, MAX_EMPLOYEES);
	do{
		option=MenuOptions();
		switch(option){
			case 1:
				if(AddEmployee(employeeList, MAX_EMPLOYEES, &sumPayments)){
					PaymetsOperation(employeeList, &sumPayments, MAX_EMPLOYEES, &qEmployees, &average);
					PrintFunction("EMPLEADO AGREGADO CON �XITO");
					flag=1;
				}else{
					PrintFunction("NO HAY ESPACIO PARA AGREGAR EMPLEADO");
				}
			break;
			case 2:
				if(flag==1){
					if(ChangeEmployee(employeeList, MAX_EMPLOYEES)){
						PrintFunction("MODIFICACION EXITOSA");
					}else{
						PrintFunction("MODIFICACION NO REALIZADA");
					}
				}else{
					PrintFunction("DEBE AGREGAR UN EMPLEADO PRIMERO");
				}
				system("pause");
			break;
			case 3:
				if(flag==1){
					if(RemoveEmployee(employeeList, MAX_EMPLOYEES)){
						PrintFunction("BAJA DE EMPLEADO REALIZADA");
					}else{
						PrintFunction("BAJA DE EMPLEADO CANCELADA");
					}
				}else{
					PrintFunction("DEBE AGREGAR UN EMPLEADO PRIMERO");
				}
			break;
			case 4:
				if(SubMenuShowld()==1){
					OrderList(employeeList, MAX_EMPLOYEES);
					printEmployees(employeeList, MAX_EMPLOYEES);
				}else{
					showldPayroll(employeeList, sumPayments, average, MAX_EMPLOYEES);
				}
				system("pause");
			break;
		}
	}
	while(option!=10);
	return 0;
}




