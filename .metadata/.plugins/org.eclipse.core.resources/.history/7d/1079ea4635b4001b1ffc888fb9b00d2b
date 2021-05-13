/**
 * validations.c
 *
 *  Author: Nicolas Alejandro Penayo
 *  Description: Validaciones de datos
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "validations.h"
#define attempts_MSG "Cantidad de intentos supereda. Vuelva a intentar mas tarde."

int validChar(char *requestMsg, char *errorMsg, char *output,
		char *valid_values, int arrLength, int max_attempts) {
	char aux;
	int isChar = 0;
	int valid = 0;
	int attempts = 0;
	int resp = 0;
	do {
		printf("\n%s ", requestMsg);
		__fpurge(stdin);
		isChar = scanf("%c", &aux);
		for (int i = 0; i < arrLength; i++) {
			if (aux == valid_values[i] && isChar) {
				valid = 1;
				resp = 1;
				*output = aux;
				break;
			}
		}
		if (!valid) {
			printf("\n%s ", errorMsg);
		}
		attempts++;
	} while (!valid && attempts < max_attempts);
	if (attempts == max_attempts) {
		system("clear");
		printf(
				"\nCantidad de intentos superada. Presione una tecla para volver al menu");
		__fpurge(stdin);
		getchar();
	}
	return resp;
}

int validInt(char *requestMsg, char *errorMsg, int *output, int min_value,
		int max_value, int max_attempts) {
	int aux;
	int resp = 0;
	int isInt;
	int valid = 0;
	int attempts = 0;
	do {
		printf("\n%s ", requestMsg);
		__fpurge(stdin);
		isInt = scanf("%d", &aux);
		if (isInt && (aux >= min_value && aux <= max_value)) {
			valid = 1;
			resp = 1;
			*output = aux;
			break;
		} else {
			printf("\n%s ", errorMsg);
		}
		attempts++;
	} while (!valid && attempts < max_attempts);
	if (attempts == max_attempts) {
		system("clear");
		printf(
				"\nCantidad de intentos superada. Presione una tecla para volver al menu");
		__fpurge(stdin);
		getchar();
	}
	return resp;
}

int validFloat(char *requestMsg, char *errorMsg, float *output, float min_value,
		float max_value, int max_attempts) {
	float aux;
	int resp = 0;
	float isFloat = 0;
	int valid = 0;
	int attempts = 0;
	do {
		printf("\n%s ", requestMsg);
		__fpurge(stdin);
		isFloat = scanf("%f", &aux);
		if (isFloat && (aux >= min_value || aux <= max_value)) {
			valid = 1;
			resp = 1;
			*output = aux;
			break;
		} else {
			printf("\n%s ", errorMsg);
		}
		attempts++;
	} while (!valid && attempts < max_attempts);
	if (attempts == max_attempts) {
		system("clear");
		printf(
				"\nCantidad de intentos superada. Presione una tecla para volver al menu");
		__fpurge(stdin);
		getchar();
	}
	return resp;
}
