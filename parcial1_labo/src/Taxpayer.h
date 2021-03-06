/*
 * Taxpayer.h
 *
 *  Created on: 29 Apr 2021
 *      Author: Nicolas Alejandro Penayo
 *      Description: Struct Taxpayer y funciones relacionadas
 */

#ifndef TAXPAYER_H_
#define TAXPAYER_H_
//#include "Income.h"
#define STR_LEN 20
#define MAX_ATTEMPTS 3
typedef struct {
	int id;
	char name[STR_LEN];
	char surname[STR_LEN];
	long int cuil;
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
int createTaxpayer(TaxPayer *tpList, int tpLens,int* id, int index);
void indexTaxpayers(TaxPayer *tpList, int tpLens);
void showTaxPayer(TaxPayer taxPayer);
int updateTaxpayer(TaxPayer taxpayer, TaxPayer *tpList, int tpLens);
int deleteTaxpayer(TaxPayer taxpayer, TaxPayer *tpList, int tpLens);
//Obtener alumno por id
int getTaxPayerById(TaxPayer *tpList, int tpLens, int to_find,  int *output);
//Inicializar tpListay de alumnos
void initializeTaxpayers(TaxPayer *taxpayers, int tpLens);
//Obtener posicion libre en tpListay de alumnos
int getTpUnassigned(TaxPayer *tpList, int tpLens, int *to_assign);
//Verificar si hay registros cargados
int isEmpty(TaxPayer *tpList, int tpLens);

//void orderBy(TaxPayer *tpList,int tpLens,Income *degrees,int icLens,char arg);
void swapTaxpayer(TaxPayer *tpList,int a,int b);
#endif /* TAXPAYER_H_ */
