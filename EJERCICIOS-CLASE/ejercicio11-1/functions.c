/*
 * functions.c
 *
 *      Author: Keila Ceñal
 */

#include "functions.h"


/**
 * @fn int MenuOptions()
 * @brief
 *
 * @return
 */
int MenuOptions(){
	int optionNum;
    printf("1. ALTA\n");
    printf("2. BAJA\n");
    printf("3. MODIFICACION\n");
    printf("4. LISTADO DE PRODUCTOS\n");
    printf("5. LISTADO ORDENADO POR PRECIOS\n");
    printf("5. LISTADO ORDENADO POR DESCRIPCION\n");
    printf("0. SALIR\n");
    printf("Elegir opcion:");
    scanf("%d", &optionNum);

    return optionNum;
}

/**
 * @fn void InicializationSellList(products[], int)
 * @brief
 *
 * @param lista
 * @param size
 */
void InicializationSellList(products lista[], int size){
	for(int i=0; i<size; i++){
		lista[i].ocupation = FREE;
	}
}

/**
 * @fn int FunctionSearchFree(products[], int)
 * @brief
 *
 * @param lista
 * @param size
 * @return
 */
int FunctionSearchFree(products lista[], int size){
	int i;
	int index;
	index = -1;
	while(lista[i].ocupation!=FREE || i<size){
		i++;
	}
	if(i!=size){
		index=i;
	}

	return index;
}

/**
 * @fn void CreateItem(products[], int, int)
 * @brief
 *
 * @param list
 * @param size
 * @param sizeType
 */
void CreateItem(products list[], int size){
	int i;
	i=FunctionSearchFree(list, size);
	if(i!=-1){
		list[i]=ChargeItem();
		printf("Item cargado con éxito");
	}else{
		printf("No se encontró espacio para cargar una venta nueva");
	}
}

/**
 * @fn void showldTypeProd(eTipoProducto)
 * @brief
 *
 * @param product
 */
void showldTypeProd(eTipoProducto product){
	printf("%d --- %s\n", product.idTipo, product.descripcionTipo);
}

/**
 * @fn int showldProduct(eTipoProducto[])
 * @brief
 *
 * @param prod
 * @return
 */
int showldProduct(eTipoProducto prod[]){
	int id;
	printf("ingrese el tipo de producto del item a ingresar. las opciones son: \n");
	for(int i=0; i<MAX_PRODUCTS; i++){
		showldTypeProd(prod[i]);
	}
	scanf("%d", &id);

	return id;
}

/**
 * @fn products ChargeItem(int)
 * @brief
 *
 * @param tam
 * @return
 */
products ChargeItem(){
	products item;
	eTipoProducto typeP[MAX_PRODUCTS]={{1000, "Iphone"},{1001, "Ipad"}, {1002, "Mac"}, {1003, "Accesorios"}};
	printf("ingrese el id del producto a cargar: \n");
	scanf("%d", &item.idProducto);
	printf("ingrese el nombre o descripcion del producto: \n");
	fflush(stdin);
	scanf("%[^\n]", &item.descriptionProduct);
	item.idTipo=showldProduct(typeP);
	printf("ingrese el precio del producto: \n");
	scanf("%f", item.precio);

	return item;
}
