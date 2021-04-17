/*
 * calculator.c
 *
 *  Created on: 16 abr. 2021
 *      Author: Keila Ceñal
 */

#include "calculator.h"
/**
 * @fn int Plus(int, int)
 * @brief
 * funcion que realiza la suma de dos numeros y devuelve el resultado
 * @param numA
 * @param numB
 * @return
 */
int  Plus(int numA, int numB){
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
int Substaction(int numA, int numB){
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
float Division(int NumA, int NumB){
	float div;
	div=NumA/NumB;
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
int Multiplication(int NumA, int NumB){
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
int Factorial(int number){
	int resultado = 1;
    while(number > 1) {
       resultado *= number;
       number--;
    }
    return resultado;
}
