/*
 * calculator.h
 *
 *  Created on: 16 abr. 2021
 *      Author: Keila Ceñal
 */

#ifndef CALCULATOR_H_
#define CALCULATOR_H_
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int MenuOptions();
int Plus(int, int);
int Substaction(int, int);
float Division(int, int);
int Multiplication(int, int);
int Factorial(int);
int EnterNumber();
void ShowResult(int, int, int, int, int, float, int, int);


#endif /* CALCULATOR_H_ */
