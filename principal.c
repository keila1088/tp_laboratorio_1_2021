/*
 *
 * TP-1 KEILA CE�AL COMISION 1F
 *
Hacer una calculadora. Para ello el programa iniciar� y contar� con un men� de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) �El resultado de A+B es: r�
b) �El resultado de A-B es: r�
c) �El resultado de A/B es: r� o �No es posible dividir por cero�
d) �El resultado de A*B es: r�
e) �El factorial de A es: r1 y El factorial de B es: r2�
5. Salir
� Todas las funciones matem�ticas del men� se deber�n realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
� En el men� deber�n aparecer los valores actuales cargados en los operandos A y B
(donde dice �x� e �y� en el ejemplo, se debe mostrar el n�mero cargado)
� Deber�n contemplarse los casos de error (divisi�n por cero, etc)
� Documentar todas las funciones
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
    int opcion;
    int adicion;
    int substraction;
    int multiplication;
    int division;
    int factorialX;
    int factorialY; 
    int flag;
    flag=0;
    do
    {
        printf("1. Ingresar primer Operando\n");
        printf("2. Ingresar Segundo Operando\n");
        printf("3. Calcular Operaciones");
        printf("4. Mostrar Resultados");
        printf("5. Salir \n");
        printf("Elija una opcion:");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                flag=1;
                printf("ingrese el primer operando: ");
                scanf("%d", &numberA);
            break;
            case 2:
                if(flag==1){
                    printf("ingrese el segundo operando: ");
                    scanf("%d", &numberB);
                    flag=2;
                }else{
                    printf("Debe ingresar el primer operando: ");
                    scanf("%d", &numberA);
                }
            break;
            case 3:
                switch (flag){
                    case 0:
                        printf("para realizar operaciones debes ingresar los operandos");
                    break;
                    case 1:
                        printf("solo tienes ingresado un operando, debes tambien ingresar el segundo");
                    break;
                    case 2:
                        adicion=Plus(numberA, numberB);
                        substraction = Substaction(numberA, numberB);
                        multiplication=Multiplication(numberA, numberB);
                        division=Division(numberA, numberB);
                        factorialX=Factorial(numberA);
                        factorialY=Factorial(numberB);
                        flag=3;
                    break;
                }
            break;
            case 4:
                if(flag==3){
                    printf("el resultado de %d+%d es: %d \n", numberA, numberB, adicion);
                    printf("el resultado de %d-%d es: %d \n", numberA, numberB, substraction);
                    printf("el resultado de %d*%d es: %d \n", numberA, numberB, multiplication);
                    if(numberB!=0){
                        printf("el resultado de %d/%d es: %f \n", numberA, numberB, division);
                    }else{
                        printf("No se puede dividir por cero \n");
                    }
                    printf("el factorial de %d es: %d y el de %d es: %d",numberA, factorialX, numberB, factorialY);
                }else{
                    printf("no hay calculos realizados para mostrar");
                }
            break;
        }
    }while(opcion!=5);


    return 0;
}
