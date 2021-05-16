/*
 * library.c
 *
 *  Created on: 14 may. 2021
 *      Author: MMGyD
 */
#include "library.h"

int MenuOptions(){
	int optionNum;

    printf("1. Alta empleado\n");
    printf("2. Modificar datos de empleado \n");
    printf("3. Dar de baja empleado \n");
    printf("4. Mostrar \n");
    printf("10. SALIR \n");
    optionNum=GetInt("Elija una opcion: ");

    return optionNum;
}

int GetInt(char print[]){
	int varInt;

	printf("%s", print);
	scanf("%d", &varInt);

	return varInt;
}

float GetFloat(char print[]){
	float varFloat;

	printf("%s \n", print);
	scanf("%f", &varFloat);

	return varFloat;
}

void PrintFunction(char print[]){
	printf("%s \n", print);
	system("pause");
}

int AutoincrementalId(int ID){
	ID++;
	return ID;
}

void GetString(char CADENA[], char MSJ[], char MSJ_ERROR[], int TAM){
	char buffer[TAM_BUFFER];

	printf("%s", MSJ);
	fflush(stdin);
	gets(buffer);

	while(strlen(buffer)==0 || strlen(buffer)>TAM)
	    {
	        printf("%s, %s", MSJ_ERROR, MSJ);
	        fflush(stdin);
	        gets(buffer);
	    }
	strcpy(CADENA, buffer);
}
