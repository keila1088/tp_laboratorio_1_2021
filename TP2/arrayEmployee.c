/*
 * arrayEmployee.c
 *
 *  Created on: 14 may. 2021
 *      Author: MMGyD
 */

#include "arrayEmployees.h"


void initEmployees(sEmployee array[], int num){
	int i;
	if (array != NULL && num > 0) {
		for (i = 0; i < num; i++) {
			array[i].isEmpty = FREE;
			array[i].id=-1;
		}
	}
}

int AddEmployee(sEmployee array[], int lim, float *sumPayments){
	int rtn = 0;
	int idAux=0;
	int index = FindFree(array, lim);
	if (index != -1) {
		array[index] = DataSave(array, lim);
		if(index==0){
			array[index].id=0;
		}else{
			idAux= AutoincrementalId(array[index-1].id);
			array[index].id=idAux;
		}
		/*		para esto voy a usar punteros pero quiero ver la clase del lunes primero*/
		array[index].isEmpty = BUSSY;
		rtn = 1;
	}
	return rtn;
}


int FindFree(sEmployee array[], int num) {
	int rtn = -1;
	int i=0;

	if (array != NULL && num > 0) {

		while(i<num && array[i].isEmpty!=FREE){
			i++;
		}

		if(i==num){
			rtn=-1;
		}else{
			rtn=i;
		}
	}
	return rtn;
}

sEmployee DataSave(){
	sEmployee varAux;
	GetString(varAux.name, "ingrese nombre del empleado: ", "ERROR", 51);
	GetString(varAux.lastName, "ingrese apellido del empleado: ", "ERROR", 51);
	varAux.salary=GetFloat("ingrese salario mensual del empleado: ");
	varAux.sector=GetInt("ingrese el n° de sector del empleado: ");
	while(varAux.sector<1 || varAux.sector>5){
		varAux.sector=GetInt("no existe el sector. Debe estar comprendido entre 1 y 5. Reingrese: ");
	}
	return varAux;
}


void PaymetsOperation(sEmployee employee[], float *sumSalary, int limit, int *qEmployees, float *average){
	int item = FindFree(employee, limit);
	*qEmployees+=1;
	*sumSalary+=employee[item-1].salary;
	*average= *sumSalary / *qEmployees;

}

int findEmployeeById(sEmployee array[], int ID, int num) {
	int rtn = -1;
	int i;

	if (array != NULL && num > 0) {
		for (i = 0; i < num; i++) {
			if (array[i].id == ID && array[i].isEmpty == BUSSY) {
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int printEmployees(sEmployee array[], int limit) {
	int rtn = 0;
	int i;
	int cantidad = 0;

	puts("\n\t> LISTADO DE EMPLEADOS");
	printf("%5s %16s %16s %16s %16s \n", "ID Empleado", "Nombre", "Apellido", "Salario Mensual", "Sector");

	if (array != NULL && limit > 0) {
		for (i=0; i<limit; i++){
			if (array[i].isEmpty==BUSSY){
				ShowldAWork(array[i]);
				cantidad++;
			}
		}
	}
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}



void DescendingOrderBySection(sEmployee varAuxI, sEmployee varAuxJ){
	sEmployee Aux;
	if(varAuxI.sector < varAuxJ.sector){
		Aux=varAuxI;
		varAuxI=varAuxJ;
		varAuxJ=Aux;
	}
}

void AscendingOrderBySection(sEmployee varAuxI, sEmployee varAuxJ){
	sEmployee Aux;
	if(varAuxI.sector > varAuxJ.sector){
		Aux=varAuxI;
		varAuxI=varAuxJ;
		varAuxJ=Aux;
	}
}

void ShowldAWork(sEmployee varEmp) {
	printf("%5d %16s %16s %16.2f %16d \n", varEmp.id, varEmp.name, varEmp.lastName, varEmp.salary, varEmp.sector);
}

int OrderList(sEmployee data[], int lim){
	sEmployee temp;
	int option;
	int i,j;
		option=SubMenuOrder();
	   for(i=0; i<lim-1; i++){
		   for(j=i+1; j<lim; j++){
			   if(data[j].isEmpty==BUSSY){
				   switch(option){
				   	   case 1:
						   if(strcmp(data[i].lastName, data[j].lastName) > 0){
							   temp = data[i];
							   data[i] = data[j];
							   data[j] = temp;
						   }else{
							   DescendingOrderBySection(data[i], data[j]);
						   }
					   break;
				   	   case 2:
						   if(strcmp(data[i].lastName, data[j].lastName) < 0){
							   temp = data[i];
							   data[i] = data[j];
							   data[j] = temp;
						   }else{
							   AscendingOrderBySection(data[i], data[j]);
						   }
						break;
				   }
			   }
		   }
	   }

	 return 0;
}

int ChangeEmployee(sEmployee array[], int lim){
	int rtn = 0;
	int id;
	int index;
	int OPTION;
	int flag = 0;
	sEmployee auxiliar;
	printEmployees(array, lim);

	if (printEmployees(array, lim)) {
		flag = 1;
	}

	if (flag) {
		printf("INGRESE ID DE EMPLEADO A MODIFICAR: ");
		scanf("%d", &id);

		index = findEmployeeById(array, id, lim);
		while (index==-1) {
			printf("NO EXISTE EL ID. REINGRESE \n");
			scanf("%d", &id);
		}

		OPTION=subMenuChange();
		auxiliar = DataChange(array[index], OPTION, lim);
		array[index] = auxiliar;

		rtn = 1;
	}

	return rtn;
}

int subMenuChange(){
	int opt;
	printf("1. Modificar Nombre \n");
	printf("2. Modificar Apellido \n");
	printf("3. Modificar Salario \n");
	printf("4. Modificar Sector \n");
	printf("Seleccione una opcion: ");
	scanf("%d", &opt);

	return opt;
}

sEmployee DataChange(sEmployee externalVar, int optChange, int limit) {
	sEmployee internalVar = externalVar;
	switch(optChange){
		case 1:
			GetString(internalVar.name, "Ingresa el nuevo nombre ", "ERROR", 51);
		break;
		case 2:
			GetString(internalVar.lastName, "Ingresa el nuevo apellido ", "ERROR", 51);
		break;
		case 3:
			internalVar.salary= GetFloat("Ingrese el nuevo salario ");
		break;
		case 4:
			internalVar.sector= GetInt("Ingrese el nuevo sector ");
		break;
	}
	return internalVar;
}

int SubMenuOrder(){
	int op;
	printf("1. Orden Ascendiente \n");
	printf("2. Orden Descendente \n");
	op=GetInt("Seleccione una opcion: ");

	return op;
}

int SubMenuShowld(){
	int i;
	printf("1. Mostrar lista ordenada de empleados \n");
	printf("2. Mostrar detalle de salarios \n");
	i=GetInt("Seleccione una opcion: ");

	return i;
}


int RemoveEmployee(sEmployee array[], int limit) {

	int rtn = 0;
	int id;
	int index;
	int flag = 0;
	int ans;

	if (printEmployees(array, limit)==1) {
		flag = 2;
	}

	if (flag==2) {
		id=GetInt("Ingrese el ID de empleado a dar de baja");

		index = findEmployeeById(array,id, limit);

		while (index==-1) {
			id=GetInt("No existe ID. Reingrese");
		}

		ans=GetInt("¿confirma la solicitud de baja del cliente? (1.SI -- 2.NO) ");
		if(ans==1){
			array[index].isEmpty = DELETED;
			rtn=1;
		}
	}

	return rtn;
}

void showldPayroll(sEmployee array[], float salaries, float average, int limit){
	int qHighSalary=0;
	printf("Suma de todos los salarios: %2.f \n", salaries);
	printf("promedio de salarios por cantidad de empleados: %2.f\n", average);
	for(int i=0; i<limit; i++){
		if(array[i].isEmpty==BUSSY){
			if(array[i].salary>average){
				qHighSalary++;
			}
		}
	}
	printf("Actualmente hay %d empleados que superan el promedio \n", qHighSalary);
}
