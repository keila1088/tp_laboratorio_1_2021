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
float Plus(float, float);
float Substaction(float, float);
float Division(float, float);
float Multiplication(float, float);
int Factorial(float);
float EnterNumber();
void ShowResult(float, float, float, float, float, float, int, int);

#endif /* CALCULATOR_H_ */
