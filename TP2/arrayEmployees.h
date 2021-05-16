/*
 * arrayEmployees.h
 *
 *  Created on: 14 may. 2021
 *      Author: MMGyD
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include "library.h"

#define FREE 0
#define BUSSY 1
#define DELETED -1

typedef  struct{
int id;
char name[51];
char lastName[51];
float salary;
int sector;
int isEmpty;
}sEmployee;

void initEmployees(sEmployee[], int);
int AddEmployee(sEmployee[], int, float*);
void PaymetsOperation(sEmployee[], float*, int, int*, float*);
int FindFree(sEmployee[], int);
sEmployee DataSave();
int findEmployeeById(sEmployee[], int, int);
int OrderList(sEmployee[], int);
void DescendingOrderBySection(sEmployee, sEmployee);
void AscendingOrderBySection(sEmployee, sEmployee);
void ShowldAWork(sEmployee);
int printEmployees(sEmployee[], int);
int ChangeEmployee(sEmployee[], int);
int subMenuChange();
sEmployee DataChange(sEmployee, int, int);
int SubMenuOrder();
int RemoveEmployee(sEmployee[], int);
int SubMenuShowld();
void showldPayroll(sEmployee[], float, float, int);

#endif /* ARRAYEMPLOYEES_H_ */
