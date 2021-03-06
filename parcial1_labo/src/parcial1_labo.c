/*
 ============================================================================
 Name        : parcial1_labo.c
 Author      : Nicolas Alejandro Penayo 1 E
 Description : Parcial 1 Laboratorio
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "Arrays.h"
#include "Menu.h"
#include "Validations.h"
#include "Taxpayer.h"
#include "Income.h"
#define MAIN_OPT 9
#define UPD_OPT 4
#define MAX_ATTEMPTS 3
#define TP_AMOUNT 3
#define IC_AMOUNT 3
void clearConsole();
void cleanBuffer();
int main(void) {
	//Set variables
	int tpId = 1000;
	int icId = 100;
	char opt;
	Option mainMenu[MAIN_OPT];
	Option updMenut[UPD_OPT];
	int auxIndex;
	int auxId;
	char auxName[20];
	char auxSurname[20];
	long int auxCUIL;
	TaxPayer tpList[TP_AMOUNT];
	Income icList[IC_AMOUNT];
	IcType types[3] = {{'1','ARBA',0},{'2','IIBB',0},{'3','GANANCIAS',0}};
	initializeTaxpayers(tpList, TP_AMOUNT);
	initializeIncomes(icList, IC_AMOUNT);
	//Set options

	//Main Menu
	setOption('1', "Alta de contribuyente", mainMenu, 0);
	setOption('2', "Modificar datos contribuyente", mainMenu, 1);
	setOption('3', "Baja de contribuyente", mainMenu, 2);
	setOption('4', "Recaudacion", mainMenu, 3);
	setOption('5', "Refinanciar Recaudacion", mainMenu, 4);
	setOption('6', "Saldar Recaudacion", mainMenu, 5);
	setOption('7', "Imprimir Contribuyentes", mainMenu, 6);
	setOption('8', "Imprimir Recaudacion", mainMenu, 7);
	setOption('x', "Salir", mainMenu, 8);

	//Update Menu
	setOption('a', "Nombre", updMenut, 0);
	setOption('b', "Apellido", updMenut, 1);
	setOption('c', "CUIL", updMenut, 2);
	setOption('x', "Recaudacion", updMenut, 3);

	do {
		printMenu(mainMenu, MAIN_OPT);
		printf("\nElija una opcion: ");
		cleanBuffer();
		scanf("%c", &opt);
		if (getOption(opt, mainMenu, MAIN_OPT)) {
			clearConsole();
			switch (opt) {
			case '1':
				if (getTpUnassigned(tpList, TP_AMOUNT, &auxIndex)) {
					do {
						if (!(opt == 'n')
								&& createTaxpayer(tpList, TP_AMOUNT, &tpId,
										auxIndex)) {

							printf("\n\n | %6s | %10s | %4s | %4s |", "ID",
									"Nombre", "Apellido", "CUIL");
							showTaxPayer(tpList[auxIndex]);

							printf(
									"\n\nCarga exitosa. Desea cargar otro contribuyente?(s/n) ");
							cleanBuffer();
							scanf("%c", &opt);
							if (opt == 'n') {
								break;
							}
						} else {
							printf(
									"Error. Algo salio mal en la carga de datos, intente nuevamente.");
							printf("\nPresione una tecla para volver al menu");
							cleanBuffer();
							getchar();
						}

					} while (!(opt == 'n'));
					if (createTaxpayer(tpList, TP_AMOUNT, &tpId, auxIndex)) {

						printf("\n\n | %6s | %10s | %4s | %4s |", "ID",
								"Nombre", "Apellido", "CUIL");
						showTaxPayer(tpList[auxIndex]);
						printf("Carga exitosa");
						printf("\nPresione una tecla para volver al menu");
						cleanBuffer();
						getchar();
					} else {
						printf(
								"Error. Algo salio mal en la carga de datos, intente nuevamente.");
						printf("\nPresione una tecla para volver al menu");
						cleanBuffer();
						getchar();
					}
				} else {
					clearConsole();
					printf(
							"\nError.La base de contribuyentes esta llena. Debe borrar un registro.");
					printf("\nPresione una tecla para volver al menu");
					cleanBuffer();
					getchar();
				}

				break;
			case '2':
				if (!(isEmpty(tpList, TP_AMOUNT))) {
					do {
						indexTaxpayers(tpList, TP_AMOUNT);
						if (validInt("Ingrese el ID",
								"ID incorrecto. Intente nuevamente", &auxId,
								1000, tpId, MAX_ATTEMPTS)) {
							clearConsole();
							printMenu(updMenut, UPD_OPT);
							printf("\nElija una opcion: ");
							cleanBuffer();
							scanf("%c", &opt);
							switch (opt) {
							case 'a':
								clearConsole();
								if (validString("Nuevo nombre",
										"Error.El nombre no puede estar vacio o contener numeros",
										auxName, 20,
										MAX_ATTEMPTS)) {
									if (getTaxPayerById(tpList, TP_AMOUNT,
											auxId, &auxIndex)) {
										strcpy(tpList[auxIndex].name, auxName);
										clearConsole();
										printf(
												"\n Se nombre el nombre con exito");
									}

								}
								break;
							case 'b':
								clearConsole();
								if (validString("Nuevo apellido",
										"Error.El apellido no puede estar vacio o contener numeros",
										auxSurname, 20, MAX_ATTEMPTS)) {
									if (getTaxPayerById(tpList, TP_AMOUNT,
											auxId, &auxIndex)) {
										strcpy(tpList[auxIndex].surname,
												auxSurname);
										clearConsole();
										printf(
												"\n Se nombre el apellido con exito");
									}

								}
								break;
							case 'c':
								clearConsole();
								if (validLongInt("CUIL(sin - )",
										"Error.Tipo de dato ingresado invalido",
										&auxCUIL, 20000000000, 40000000000,
										MAX_ATTEMPTS)) {
									if (getTaxPayerById(tpList, TP_AMOUNT,
											auxId, &auxIndex)) {
										tpList[auxIndex].cuil = auxCUIL;
										clearConsole();
										printf(
												"\n Se modifico el CUIL con exito");
									}

								}
								break;
							}
							printf("\nDesea modificar otro dato? (s/n): ");
							cleanBuffer();
							scanf("%c", &opt);
						}
					} while (!(opt == 'x' || opt == 'n'));
				} else {
					clearConsole();
					printf("\nNo hay contribuyentes cargados para mostrar.");
				}
				break;
			case '3':
				if (!(isEmpty(tpList, TP_AMOUNT))) {
					if (getIcUnassigned(icList, IC_AMOUNT, &auxId)) {
						do {

						} while (!(opt == 'n'));
					}
					clearConsole();
					printf(
							"\nError.La base de recaudaciones esta llena. Debe borrar un registro.");
					printf("\nPresione una tecla para volver al menu");
					cleanBuffer();
					getchar();
				} else {
					clearConsole();
					printf("\nNo hay contribuyentes cargados para mostrar.");
				}
				break;
			case '4':
				if (!(isEmpty(tpList, TP_AMOUNT))) {
					if (createIncome(icList, IC_AMOUNT, &icId, auxIndex, types, 3, tpList, TP_AMOUNT)) {
						printf(
								"\n\nCarga exitosa. Desea cargar otra recaudacion?(s/n) ");
						cleanBuffer();
						scanf("%c", &opt);
					}
				} else {
					clearConsole();
					printf(
							"\nNo hay contribuyentes cargados para asignarles una recaudacion.");
				}
				break;
			case '5':

				break;
			case '6':

				break;
			case '7':
				if (!(isEmpty(tpList, TP_AMOUNT))) {

				} else {
					clearConsole();
					printf("\nNo hay recaudaciones cargadas para mostrar.");
				}
				break;
			case '8':

				break;
			default:
				break;
			}
		} else {
			clearConsole();
			printf("\nError.Opcion invalida");
			printf("\nPresione una tecla para volver al menu");
			cleanBuffer();
			getchar();
		}
	} while (!(opt == 'x'));

	return EXIT_SUCCESS;
}
void clearConsole() {
#if defined( __linux__)
	system("clear");
#elif defined( __MINGW32__)
	sytem("cls");
#endif
}
void cleanBuffer() {
#if defined(__linux__)
	__fpurge(stdin);
#elif defined(__MINGW32__)
	fflush(stdin);
#endif
}

