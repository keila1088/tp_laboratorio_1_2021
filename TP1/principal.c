/*
 *
 * TP-1 KEILA CE?AL COMISION 1F
 * Hacer una calculadora. Para ello el programa iniciar? y contar? con un men? de opciones:
1. Ingresar 1er operando (OPERADOR A=x)
2. Ingresar 2do operando (OPERADOR B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) ?El resultado de A+B es: r?
b) ?El resultado de A-B es: r?
c) ?El resultado de A/B es: r? o ?No es posible dividir por cero?
d) ?El resultado de A*B es: r?
e) ?El factorial de A es: r1 y El factorial de B es: r2?
5. Salir
? Todas las funciones matem?ticas del men? se deber?n realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
? En el men? deber?n aparecer los valores actuales cargados en los operandos A y B
(donde dice ?x? e ?y? en el ejemplo, se debe mostrar el n?mero cargado)
? Deber?n contemplarse los casos de error (divisi?n por cero, etc)
? Documentar todas las funciones
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
	float numberA;
	float numberB;
    int option;
    float adicion;
    float substraction;
    float multiplication;
    float division;
    int intNumA;
    int intNumB;
    int factorialX;
    int factorialY;
    int flag;
    flag=0;
    do
    {
    	option=MenuOptions();
    	if(option==1 || option==2 || option==3 || option==4 || option==5){
			switch(option){
					case 1:
						numberA=EnterNumber();
						printf("OPERADOR A= %.0f \n", numberA);
						flag=1;
						system("pause");
					break;
					case 2:
						if(flag==1){
							numberB=EnterNumber();
							printf("OPERADOR B= %.0f \n", numberB);
							flag=2;
							system("pause");
						}else{
							printf("Para ingresar el segundo operando primero debe ingresar el primero: \n");
							numberA=EnterNumber();
							printf("OPERADOR A= %.0f \n", numberA);
							flag=1;
							system("pause");
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

								if(numberA>=0){
									factorialX=Factorial(numberA);
								}else{
									factorialX=-1;
								}
								if(numberB>=0){
									factorialY=Factorial(numberB);
								}else{
									factorialY=-1;
								}
								flag=3;
								printf("******C?lculos realizados****** \n");
								system("pause");
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
						system("pause");
					break;
				}
    		}else{
    			printf("opcion ingresada incorrecta.\n");
    		}
    }while(option!=5);


    return 0;
}
