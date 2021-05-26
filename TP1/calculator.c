/*
 * calculator.c
 *
 *  Created on: 16 abr. 2021
 *      Author: Keila Ceñal
 */

#include "calculator.h"

int MenuOptions(){
	int option;
	printf("----------------------------------------- \n");
    printf("1. Ingresar primer Operando\n");
    printf("2. Ingresar Segundo Operando\n");
    printf("3. Calcular Operaciones \n");
    printf("4. Mostrar Resultados \n");
    printf("5. Salir \n");
    printf("Elija una opcion:");
    scanf("%d", &option);
    printf("------------------------------------------ \n");

    return option;
}


/**
 * @fn int Plus(int, int)
 * @brief
 * funcion que realiza la suma de dos numeros y devuelve el resultado
 * @param numA
 * @param numB
 * @return
 */
float  Plus(float numA, float numB){
    int suma;
    suma=numA + numB;
	return suma;
}

/**
 * @fn int Substaction(int, int)
 * @brief
 * funcion que realiza la resta de dos numeros y devuelve su resultado
 * @param numA
 * @param numB
 * @return
 */
float Substaction(float numA, float numB){
	int subs;
	subs=numA-numB;
	return subs;
}


/**
 * @fn int Division(int, int)
 * @brief
 * funcion que realiza la division de dos numeros y devuelve el resultado
 * @param NumA
 * @param NumB
 * @return
 */
float Division(float NumA, float NumB){
	float div;
	if(NumB!=0){
		div=NumA/NumB;
	}else{
		div=-1;
	}
	return div;
}


/**
 * @fn int Multiplication(int, int)
 * @brief
 * funcion que realiza la multiplicacion de dos numeros y devuelve el resultado
 * @param NumA
 * @param NumB
 * @return
 */
float Multiplication(float NumA, float NumB){
	int mult;
	mult=NumA*NumB;
	return mult;
}

/**
 * @fn int Factorial(int)
 * @brief
 * funcion que realiza el calculo del factorial de un numero y devuelve el resultado
 * @param number
 * @return
 */
int Factorial(float number){
	int resultado = 1;
    while(number > 1) {
       resultado *= number;
       number--;
    }

    return resultado;
}

/**
 * @fn int EnterNumber()
 * @brief
 * funcion para ingreso del numero
 * @return
 */
float EnterNumber(){
	float num;
	printf("ingrese el numero: ");
	scanf("%f", &num);
	return num;
}


/**
 * @fn void ShowResult(int, int, int, int, int, float, int, int)
 * @brief
 * Funcion que muestra el resultado de las operaciones realizadas.
 * @param numX
 * @param numY
 * @param sum
 * @param rest
 * @param mult
 * @param div
 * @param facX
 * @param facY
 */
void ShowResult(float numX, float numY, float sum, float rest, float mult, float div, int facX, int facY){
	printf("el resultado de %.0f+%.0f es: %.0f \n", numX, numY, sum);
	printf("el resultado de %.0f-%.0f es: %.0f \n", numX, numY, rest);
	printf("el resultado de %.0f*%.0f es: %.0f \n", numX, numY, mult);
	if(numY!=0){
		printf("el resultado de %.0f/%.0f es: %.3f... \n", numX, numY, div);
	}else{
		printf("******No se puede dividir por cero****** \n");
	}
	if(facX!=-1 && facY!=-1){
		printf("el factorial de %.0f es: %d y el de %.0f es: %d \n",numX, facX, numY, facY);
	}
	else if(facX!=-1 && facY==-1){
		printf("el factorial de %.0f es: %d y el de %.0f no se puede realizar. \n", numX, facX, numY);
	}
	else if(facX==-1 && facY!=-1){
		printf("el factorial de %.0f no se puede realizar y el de %.0f es %d. \n", numX, numY, facY);
	}
}
