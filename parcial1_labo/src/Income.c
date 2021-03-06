/*
 * income.c
 *
 *  Created on: 8 May 2021
 *      Author: npenayo
 */

#include "Income.h"
#include "Taxpayer.h"
#include "Arrays.h"
#include "Validations.h"
#include <string.h>
#include <stdio_ext.h>
#include <stdlib.h>

int getId(Income *incomes, int arrLength, char *description, int *output) {
	int resp = 0;
	for (int i = 0; i < arrLength; i++) {
		/*if (!(strcmp(incomes[i].description, description))) {
		 *output = incomes[i].id;
		 resp = 1;
		 break;
		 }*/
	}
	return resp;
}

int getDescription(Income *incomes, int arrLength, int id, char *output) {
	int resp = 0;
	for (int i = 0; i < arrLength; i++) {
		if (incomes[i].id == id) {
			//strcpy(output, incomes[i].description);
			resp = 1;
			break;
		}
	}
	return resp;
}

void indexIncomes(Income *incomes, int arrLength) {
	printf("\n************ Carreras disponibles ************");
	printf("\n\n%-15s | %6s", "Codigo_Carrera", "Descripcion");
	printf("\n-----------------------------");
	for (int i = 0; i < arrLength; i++) {
		//showincome(incomes[i]);
	}
}

void showIncome(Income income) {
	//printf("\n %6d%10s %-20s", income.id,"",income.description);
}

int validIncome(Income *incomes, int arrLength, int *output, int max_attempts) {
	int resp = 0;
	int valid = 0;
	int attempts = 0;
	int isincome;
	int aux;
	do {
		indexIncomes(incomes, arrLength);
		printf("\nCodigo de carrera: ");
		__fpurge(stdin);
		isincome = scanf("%d", &aux);
		for (int i = 0; i < arrLength; i++) {
			if (isincome && incomes[i].id == aux) {
				valid = 1;
				resp = 1;
				*output = aux;
				break;
			}
		}
		if (!valid) {
			printf("\nError. Carrera invalida");
		}
		attempts++;
	} while (!valid || attempts >= max_attempts);
	if (attempts == max_attempts) {
		system("clear");
		printf(
				"\nCantidad de intentos superada. Presione una tecla para volver al menu");
		__fpurge(stdin);
		getchar();
	}
	return resp;

}
int createIncome(Income *icList, int icLens, int *id, int index, IcType *tyList,
		int tyLens, TaxPayer *tpList, int tpLens) {
	int resp = 0;
	int id_taxPayer;
	int month;
	int id_type;
	float amount;
	char surname[STR_LEN];
	initializeChar(surname, STR_LEN);
	printf("\n*************** Alta Contribuyentes *********");
	indexTaxpayers(tpList, tpLens);
	printf("\nEscriba ID de contribuyente: ");
	__fpurge(stdin);
	scanf("%d", &id_taxPayer);
	if (getTaxPayerById(tpList, tpLens, id_taxPayer, &id_taxPayer)) {
		if (validInt("Mes", "Error.Mes invalido", &month, 1, 12,
				MAX_ATTEMPTS)) {
			indexTypes(tyList, tpLens);
			printf("\nCodigo de tipo: ");
			scanf("%d", &id_type);
			if (validType(tyList, tyLens, MAX_ATTEMPTS, &id_type)
					&& validFloat("Importe", "Error.Dato invalido", &amount, 1,
							10000, MAX_ATTEMPTS)) {
				Income newIncome;
				newIncome.id = *id;
				*id += 1;
				newIncome.month = month;
				newIncome.id_type = id_type;
				newIncome.id_taxPayer = id_taxPayer;
				newIncome.amount = amount;
				icList[index] = newIncome;
				resp = 1;
			}
		}
	}

	return resp;
}
void initializeIncomes(Income *icList, int tsLens) {
	for (int i = 0; i < tsLens; i++) {
		icList[i].assigned = 0;
	}

}
int getIcUnassigned(Income *icList, int icLens, int *to_assign) {
	int resp = 0;
	for (int i = 0; i < icLens; i++) {
		if (!(icList[i].assigned)) {
			*to_assign = i;
			resp = 1;
			break;
		}
	}
	return resp;
}
int validType(IcType *list, int lens, int max_attempts, int *output) {
	int resp = 0;
	int valid = 0;
	int attempts = 0;
	int isType;
	int aux;
	do {
		indexTypes(list, lens);
		printf("\nCodigo de recaudacion: ");
		__fpurge(stdin);
		isType = scanf("%d", &aux);
		for (int i = 0; i < lens; i++) {
			if (isType && list[i].id == aux) {
				valid = 1;
				resp = 1;
				*output = aux;
				break;
			}
		}
		if (!valid) {
			printf("\nError. Carrera invalida");
		}
		attempts++;
	} while (!valid || attempts >= max_attempts);
	if (attempts == max_attempts) {
		system("clear");
		printf(
				"\nCantidad de intentos superada. Presione una tecla para volver al menu");
		__fpurge(stdin);
		getchar();
	}
	return resp;
}
void indexTypes(IcType *list, int lens) {
	printf("\n************ Recaudaciones disponibles ************");
	printf("\n\n%-15s | %6s", "Codigo_Recaudacion", "Descripcion");
	printf("\n-----------------------------");
	for (int i = 0; i < lens; i++) {
		showType(list[i]);
	}
}
void showType(IcType icType) {
	printf("\n %6d%10s %-20s", icType.id, "", icType.description);
}

