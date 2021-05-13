/*
 * income.h
 *
 *  Created on: 8 May 2021
 *      Author: npenayo
 */

#ifndef INCOME_H_
#define INCOME_H_
typedef struct {
	int id;
	int id_taxPayer;
	char month;
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
 */
int getDescription(Income *incomes, int arrLength, int id, char *output);
// Mostrar carreras y atributos
/**
 * @fn void indexincomes(income*, int)
 * @brief Mostrar todas las carreras
 * @param incomes Array de carreras
 * @param arrLength Tamanio del array
 */
void indexincomes(Income *incomes, int arrLength);
/**
 * @fn void showincome(income)
 * @brief Muestra una carrera
 *
 * @param income Carrera a mostrar
 */
void showincome(Income income);
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
int validincome(Income *incomes, int arrLength, int *output, int max_attemps);
#endif /* INCOME_H_ */