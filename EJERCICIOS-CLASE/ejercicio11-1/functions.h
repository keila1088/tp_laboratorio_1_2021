/*
 * functions.h
 *
 *      Author: Keila Ceñal
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include <stdio.h>
#include <string.h>

#define FREE -1
#define BUSSY 0
#define MAX_PRODUCTS 4


typedef struct{
	int idTipo;
	char descripcionTipo[25];
}eTipoProducto;

typedef struct{
	int idNacionalidad;
	char descripcionNacionalidad[25];
}eNacionalidad;

typedef struct{
	int idProducto;
	char descriptionProduct;
	int idTipo;
	int idNacionalidad;
	float precio;
	int ocupation;
}products;

int MenuOptions();
void InicializationSellList(products[], int);
int FunctionSearchFree(products[], int);
void CreateItem(products[], int);
void showldTypeProd(eTipoProducto);
int showldProduct(eTipoProducto[]);
products ChargeItem();

#endif /* FUNCTIONS_H_ */
