/*
 * functions.c
 *
 *      Author: Keila Ceñal
 */

#include "functions.h"



int MenuOptions(){
	int optionNum;
    printf("1. ALTA\n");
    printf("2. BAJA\n");
    printf("3. MODIFICACION\n");
    printf("4. LISTADO DE PRODUCTOS\n");
    printf("5. LISTADO ORDENADO POR PRECIOS\n");
    printf("5. LISTADO ORDENADO POR DESCRIPCION\n");
    printf("0. SALIR\n");
    printf("Elija una opcion:");
    scanf("%d", &optionNum);

    return optionNum;
}


