/*
 * library.h
 *
 *  Created on: 14 may. 2021
 *      Author: MMGyD
 */

#ifndef LIBRARY_H_
#define LIBRARY_H_
#define TAM_BUFFER 100
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int MenuOptions();
void GetString(char[], char[], char[], int);
int GetInt(char[]);
void PrintFunction(char[]);
float GetFloat(char[]);
int AutoincrementalId(int);

#endif /* LIBRARY_H_ */
