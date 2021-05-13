/*
 ============================================================================
 Name        : parcial1_labo.c
 Author      : Nicolas Alejandro Penayo 1 E
 Description : Parcial 1 Laboratorio
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Arrays.h"
#include "Menu.h"
#include "Validations.h"
#include "Taxpayer.h"
#define MAIN_OPT 9
#define UPD_OPT 4
#define MAX_ATTEMPTS 3
#define TP_AMOUNT 3
void clearConsole();
void cleanBuffer();
int main(void) {
	//Set variables
	int id = 1000;
	char opt;
	Option mainMenu[MAIN_OPT];
	Option updMenut[UPD_OPT];
	int auxIndex;
	char auxName[20];
	char auxSurname[20];
	int auxCUIT;
	TaxPayer tpList[TP_AMOUNT];
	initializeTaxpayers(tpList, TP_AMOUNT)
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
		cleanBuffer();
		scanf("%c", &opt);
		if (getOption(opt, mainMenu, MAIN_OPT)) {
			clearConsole();
			switch (opt) {
			case '1':
				if (getUnassigned(tpList, TP_AMOUNT, &auxIndex)) {

					if (createTaxPayer(tpList, TP_AMOUNT, &id)) {
						printf("Carga exitosa");
						printf("\n\n | %6s | %10s | %4s | %4s |", "ID",
									"Nombre", "Apellido", "CUIL");
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

				break;
			case '3':

				break;
			case '4':

				break;
			case '5':

				break;
			case '6':

				break;
			case '7':

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

