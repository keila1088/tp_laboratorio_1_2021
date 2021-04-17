/*
 *
 * TP-1 KEILA CEÑAL COMISION 1F
 *
Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones
 */

#include "calculator.h"


/**
 * @fn int main()
 * @brief
 * funcion principal
 * @return
 */
int main(void){
	setbuf(stdout, NULL);
    int numberA;
    int numberB;
    printf("ingrese el primer operando: ");
    scanf("%d", &numberA);
    printf("ingrese el segundo operando: ");
    scanf("%d", &numberB);
    printf("el resultado de %d+%d es: %d \n", numberA, numberB, Plus(numberA, numberB));
    printf("el resultado de %d-%d es: %d \n", numberA, numberB, Substaction(numberA, numberB));
    if(numberB!=0){
    	printf("el resultado de %d/%d es: %f \n", numberA, numberB, Division(numberA, numberB));
    }else{
    	printf("No se puede dividir por cero \n");
    }
    printf("el resultado de %d*%d es: %d \n", numberA, numberB, Multiplication(numberA, numberB));
    printf("el factorial de %d es: %d y el de %d es: %d", numberA, Factorial(numberA), numberB, Factorial(numberB));
	return 0;
}
