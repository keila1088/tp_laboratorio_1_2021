/*
 *
 * TP-1 KEILA CEÑAL COMISION 1F
 * Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
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
 * funcion principal. se realiza la definicion de las variables y las validaciones correspondientes a cada opcion del menu.
 * @return
 */
int main(void){
	setbuf(stdout, NULL);
    int numberA;
    int numberB;
    int option;
    int adicion;
    int substraction;
    int multiplication;
    float division;
    int factorialX;
    int factorialY;
    int flag;
    flag=0;
    do
    {
    	option=MenuOptions();
        switch(option)
            {
                case 1:
                	numberA=EnterNumber();
                    flag=1;
                break;
                case 2:
                    if(flag==1){
                    	numberB=EnterNumber();
                        flag=2;
                    }else{
                        printf("Para ingresar el segundo operando primero debe ingresar el primero: \n");
                        numberA=EnterNumber();
                        flag=1;
                    }
                break;
                case 3:
                    switch (flag){
                        case 0:
                            printf("******para realizar operaciones debes ingresar los operandos****** \n");
                        break;
                        case 1:
                            printf("******solo tienes ingresado un operando, debes tambien ingresar el segundo****** \n");
                        break;
                        case 2:
                            adicion=Plus(numberA, numberB);
                            substraction = Substaction(numberA, numberB);
                            multiplication=Multiplication(numberA, numberB);
                            division=Division(numberA, numberB);
                            factorialX=Factorial(numberA);
                            factorialY=Factorial(numberB);
                            flag=3;
                            printf("******Cálculos realizados****** \n");
                        break;
                    }
                break;
                case 4:
                	if(flag==3){
                		ShowResult(numberA, numberB, adicion, substraction, multiplication, division, factorialX, factorialY);
                		flag=0;
                	}else{
                		printf("*********No hay calculos realizados para mostrar********* \n");
                	}
                break;
            }
    }while(option!=5);


    return 0;
}
