/*
 * principal11-1.c
 *      Author: Keila Ceñal

Una empresa importadora que comercializa productos Apple, decide registrar de sus productos los siguientes datos:
idProducto (numerico)
descripcion (alfanumérico)
nacionalidad (numerico)
tipo (numérico)
precio (numérico decimal)
Agregar la estructura etipoProducto, que definirá los siguientes campos:
idTipo (numérico)
descripcionTipo(alfanumérico)
Para esta estructura en principio trabajaremos con datos hardcodeados:


Agregar la estructura eNacionalidad, que definirá los siguientes campos:
idNacionalidad (numérico)
descripcionNacionalidad(alfanumérico)
Para esta estructura en principio trabajaremos con datos hardcodeados:
idNacionalidad
descripcionNacionalidad
1
EEUU
2
CHINA
3
OTRO


Realizar un programa que permita interactuar con un menú de usuarios con las siguientes opciones:
ALTA Producto: Se ingresan los datos de UN solo producto. Siempre y cuando haya espacio disponible en el array. Al momento de dar de alta el producto, el usuario podrá elegir el tipo de producto, de una lista que se le desplegará en pantalla.
BAJA Producto: A partir del ingreso del ID. Si existe el producto desaparece de la lista, dejando espacio disponible para un nuevo producto.
MODIFICACIÓN Producto: A partir del ingreso del ID. Si existe se podrá modificar el precio o el tipo. Si modifica el tipo de producto, se utilizara el mismo criterio que para dar de alta.
LISTADO Productos.
LISTADO ordenado por precio.
LISTADO ordenado por descripción.
Agregar los siguientes informes:
El/los  productos más caros.
Precio promedio por tipo de producto. Se deberá mostrar la descripción del tipo y a continuación el precio promedio.
El listado de todos los productos con la descripción del tipo.
Por cada tipo la lista de productos.
Se agregan los siguientes listados:
El/los tipos de productos con mas productos elaborados.
 *
 */

#include "functions.h"
#define MAX_PRODUCTS 4
#define MAX_COUNTRY 3
#define MAX_SELLS 10


int main(void){
	setbuf(stdout, NULL);
	int option;
	eTipoProducto productList[MAX_PRODUCTS]={{1000, "Iphone"},{1001, "Ipad"}, {1002, "Mac"}, {1003, "Accesorios"}};
	eNacionalidad countryList[MAX_COUNTRY]={{1,"EEUU"},{2, "CHINA"},{3, "OTRO"}};
	products sellsList[MAX_SELLS];//INICIALIZAR CON LA FUNCION INICIALIZAR ALUMNOS
	do
	    {
			option=MenuOptions();

	        switch(option)
	        {
	            case 1:

	            break;
	            case 2:

	            break;
	            case 3:

	            break;
	            case 4:

	            break;
	            case 5:

	            break;
	        }
	    }while(option!=0);
	return 0;
}



