/*
 * income.h
 *
 *  Created on: 8 May 2021
 *      Author: npenayo
 */

#ifndef INCOME_H_
#define INCOME_H_
#include "Taxpayer.h"
typedef struct {
	int id;
	char description[STR_LEN];
} IcType;
typedef struct {
	int id;
	int id_taxPayer;
	int month;
	int id_type;
	float amount;
	int assigned;
} Income;

/**
 * @fn int getId(income*, int, char*, int*)
 * @brief Obtener el id de una carrera mediante descripcion
 *
 * @param incomes Array de carreras
 * @param arrLength Tamanio del array de carreras
 * @param description Descripcion de la carrera a buscar
 * @param output Variable donde se guarda el id obtenido
 * @return 1 si se encontro el ID | 0 si no se encontro
 */
int getId(Income *incomes, int arrLength, char *description, int *output);
/**
 * @fn void getDescription(income*, int, int, char*)
 * @brief Obtener descripcion de una carrera mediante un id
 *

 * @param incomes Array de carreras
 * @param arrLength Tamanio del array de carreras
 * @param id ID de la carrera a buscar
 * @param output Variable donde se guarda la descripcion obtenida
 * @return 1 si se encontro el ID | 0 si no se encontro
 */int getDescription(Income *incomes, int arrLength, int id, char *output);

/**
 * @fn void indexincomes(income*, int)
 * @brief Mostrar todas las carreras
 * @param incomes Array de carreras
 * @param arrLength Tamanio del array
 */
void indexIncomes(Income *incomes, int arrLength);
/**
 * @fn void showincome(income)
 * @brief Muestra una carrera
 *
 * @param income Carrera a mostrar
 */
void showIncome(Income income);
/**
 * @fn int validincome(income*, int, int*, int)
 * @brief Comprobar que se seleccione una carrera valida
 *
 * @param incomes Array de carreras
 * @param arrLength Tamanio del array
 * @param output Variable donde guardar el ID de la carrera
 * @param max_attempts Cantidad de intentos
 * @return 1 si es valido | 0 si no es valido
 */
int validIncome(Income *incomes, int arrLength, int *output, int max_attempts);
void initializeIncomes(Income *icList, int tsLens);
int createIncome(Income *icList, int icLens, int *id, int index, IcType *tyList,
		int tyLens, TaxPayer *tpList, int tpLens);
int getIcUnassigned(Income *icList, int icLens, int *to_assign);
int validType(IcType *list, int lens, int max_attempts, int *output);
void indexTypes(IcType *list, int lens);
void showType(IcType icType);
#endif /* INCOME_H_ */
