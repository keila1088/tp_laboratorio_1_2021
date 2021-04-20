/*
 * functions.h
 *
 *      Author: Keila Ceñal
 */
#define VACIO -1
#define OCUPADO 0

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include <stdio.h>
#include <string.h>

int MenuOptions();

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
	struct eTipóProducto product;
	int idNacionalidad;
	float precio;
}products;


#endif /* FUNCTIONS_H_ */
