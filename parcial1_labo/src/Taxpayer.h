/*
 * Taxpayer.h
 *
 *  Created on: 29 Apr 2021
 *      Author: Nicolas Alejandro Penayo
 *      Description: Struct Taxpayer y funciones relacionadas
 */

#ifndef TAXPAYER_H_
#define TAXPAYER_H_
#include "Income.h"
#define STR_LEN 20
typedef struct {
	int id;
	char name[STR_LEN];
	char surname[STR_LEN];
	int cuil;
	int assigned;
} TaxPayer;

//CRUD alumnos
/**
 * @brief Create a new taxpayer
 * @pre
 * @post
 * @param tpList TaxPayer*
 * @param tpLens
 * @param index
 * @param icList
 * @param icLens
 * @return
 */
int createTaxpayer(TaxPayer *tpList, int tpLens,int* id);
void indexTaxpayers(TaxPayer *tpList, int tpLens, Income icList,
		int icLens);
void showTaxpayer(TaxPayer taxpayer, Income icList, int icLens);
int updateTaxpayer(TaxPayer taxpayer, TaxPayer *tpList, int tpLens);
int deleteTaxpayer(TaxPayer taxpayer, TaxPayer *tpList, int tpLens);
//Obtener alumno por id
int getTaxpayerByDocket(TaxPayer *tpList, int tpLens, int to_find,
		Income icList, int icLens, TaxPayer *output);
//Inicializar tpListay de alumnos
void initializeTaxpayers(TaxPayer *taxpayers, int tpLens);
//Obtener posicion libre en tpListay de alumnos
int getUnassigned(TaxPayer *tpList, int tpLens, int *to_assign);
//Verificar si hay registros cargados
int isEmpty(TaxPayer *tpList, int tpLens);

void orderBy(TaxPayer *tpList,int tpLens,Income *degrees,int icLens,char arg);
void swapTaxpayer(TaxPayer *tpList,int a,int b);
#endif /* TAXPAYER_H_ */