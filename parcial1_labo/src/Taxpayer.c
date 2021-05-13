/*
 * TaxPayer.c
 *
 *  Created on: 29 Apr 2021
 *      Author: Nicolas Alejandro Penayo
 *     Description: Struct TaxPayer y funciones relacionadas
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Taxpayer.h"

#include "Validations.h"
#define MAX_ATTEMPTS 3
//CRUD TaxPayer
int createTaxPayer(TaxPayer *tpList, int tpLens, int *id) {
	int resp = 0;
	char name[STR_LEN];
	char surname[STR_LEN];
	int cuil;
	int assigned;
	initializeString(name, STR_LEN);
	initializeString(surname, STR_LEN);
	printf("\n*************** Alta Contribuyentes *********");
	if (validString("Nombre",
			"Error.El nombre no puede estar vacio o contener numeros", name, 20,
			MAX_ATTEMPTS)
			&& validString("Apellido",
					"Error.El apellido no puede estar vacio o contener numeros",
					surname, 20, MAX_ATTEMPTS)
			&& validInt("CUIL(sin - )", "Error.Tipo de dato ingresado invalido",
					&cuil, 20000000000, 40000000000,
					MAX_ATTEMPTS)) {
		TaxPayer newTaxPayer;
		newTaxPayer.id = *id;
		*id += 1;
		strcpy(newTaxPayer.name, name);
		strcpy(newTaxPayer.surname, surname);
		newTaxPayer.cuil = cuil;
		newTaxPayer.assigned = 1;
		tpList[index] = newTaxPayer;
		resp = 1;
	}

	return resp;
}
void indexTaxPayer(TaxPayer TaxPayer[], int TaxPayerLength, Income incomes[],
		int icLens) {
	printf("\n************ Listado de Contribuyentes ************");
	printf("\n\n | %6s | %10s | %4s | %4s |", "ID", "Nombre", "Apellido",
			"CUIL");
	printf(
			"\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ");

	for (int i = 0; i < TaxPayerLength; i++) {
		showTaxPayer(TaxPayer[i], incomes, icLens);
	}
}
void showTaxPayer(TaxPayer taxPayer,) {
	char degDescription[20];
	if (taxPayer.assigned) {
		taxPayer.surname[0] = toupper(taxPayer.surname[0]);
		printf("\n | %6d | %-10s | %4d | %4c ", taxPayer.id, taxPayer.name,
				taxPayer.surname, taxPayer.cuil);
	}

}
int updateTaxPayer(TaxPayer taxPayer, TaxPayer *tpList, int tpLens) {
	int resp = 0;
	for (int i = 0; i < tpLens; i++) {
		if (tpList[i].id == taxPayer.id) {
			tpList[i] = taxPayer;
			resp = 1;
		}
	}

	return resp;
}
int deleteTaxPayer(TaxPayer taxpayer, TaxPayer *tpList, int tpLens) {
	int resp = 0;
	for (int i = 0; i < tpLens; i++) {
		if (tpList[i].id == taxpayer.id) {
			taxpayer.assigned = 0;
			tpList[i] = taxpayer;
			resp = 1;
		}
	}
	return resp;
}
//Get TaxPayer attributes
int getTaxPayerById(TaxPayer *tpList, int tpLens, int to_find, Income incomes[],
		int icLens, TaxPayer *output) {
	int resp = 0;
	for (int i = 0; i < tpLens; i++) {
		if (tpList[i].id == to_find && tpList[i].assigned) {
			*output = tpList[i];
			resp = 1;
			break;
		}
	}
	return resp;
}
void initializeTaxPayer(TaxPayer *tpList, int tpLens) {
	for (int i = 0; i < tpLens; i++) {
		tpList[i].assigned = 0;
	}

}
int getUnassigned(TaxPayer *tpList, int tpLens, int *to_assign) {
	int resp = 0;
	for (int i = 0; i < tpList; i++) {
		if (!(tpList[i].assigned)) {
			*to_assign = i;
			resp = 1;
			break;
		}
	}
	return resp;
}
int isEmpty(TaxPayer *tpList, int tpLens) {
	int resp = 0;
	int aux = 0;
	for (int i = 0; i < tpLens; i++) {
		if (!tpList[i].assigned) {
			aux++;
		}
	}
	if (aux == tpLens) {
		resp = 1;
	}
	return resp;
}
void orderBy(TaxPayer *tpList, int tpLens, Income *icList, int icLens, char arg,
		char mode) {
	int auxInt[20];
	float auxFloat[20];
	initializeInt(auxInt, STR_LEN);
	initializeFloat(auxFloat, 20);
%6d | %6d | %8.2f | %7s
switch (arg) {
	//Por legajo
	case 'a':
	for (int i = 0; i < tpLens; i++) {
		if (tpList[i].assigned) {
			appendIntToTaxPayeray(tpList[i].id, auxInt, i);
		}
	}
	if (mode == 'a') {
		quicksortIntAsc(&auxInt[tpLens], 0, tpLens);
		for (int i = 0; i < tpLens - 1; i++) {
			swapTaxPayer(tpList, i, i + 1);
		}
	} else {

	}
	break;
	//Por apellido
	case 'b':
	if (mode == 'a') {
		for (int i = 0; i < tpLens - 1; i++) {
			for (int j = i; j < tpLens; j++) {
				if (tpList[i].assigned && tpList[j].assigned) {
					if (strcmp(tpList[i].surname, tpList[j].surname) > 0) {
						swapTaxPayer(tpList, i, j);
					}
				}
			}

		}
	} else {

	}
	break;
	//Por promedio, si el promedio es igual, por legajo
	case 'c':
	if (mode == 'a') {
		for (int i = 0; i < tpLens; i++) {

		}
	} else {

	}
	break;
}
}

void swapTaxPayer(TaxPayer *tpList, int a, int b) {
TaxPayer aux;
aux = tpList[a];
tpList[a] = tpList[b];
tpList[b] = aux;
}
