/*
 ============================================================================
 Name        : parcial_laboratorio.c
 Author      : Hugo Miranda Campos
 Version     :
 Copyright   : Your copyright notice
 Description : Parcial de laboratorio
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "notebook.h"
#include "marca.h"
#include "tipo.h"
#include "servicio.h"
#include "fecha.h"
#include "trabajo.h"
#include "cliente.h"
#define TAM_NOTEBOOK 100
#define TAM 4

int main(void)
{
	setbuf(stdout, NULL);

	int eleccion;
	int eleccionSubMenu;
	int proximoIdNotebook = 100;
	int proximoIdTrabajo = 10000;
	char confirmarSalir;
	eNotebook notebook[TAM_NOTEBOOK];
	eTrabajo trabajo[TAM_NOTEBOOK];
	eMarca marca[TAM];
	eTipo tipo[TAM];
	eServicio servicio[TAM];
	eFecha fecha[TAM];
	eCliente cliente[TAM];


	if(inicializarNotebooks(notebook, TAM_NOTEBOOK) == -1)
	{
		printf("Error al inicializar.");
	}

	if(inicializarTrabajos(trabajo, TAM_NOTEBOOK) == -1)
	{
		printf("Error al inicializar.");
	}

	hardcodearNotebook(notebook, TAM_NOTEBOOK, 5, &proximoIdNotebook);
	hardcodearMarca(marca, TAM, 4);
	hardcodearTipos(tipo, TAM, 4);
	hardcodearServicio(servicio, TAM, 4);
	hardcodearClientes(cliente, TAM, 4);

	do{
		eleccion = menuNotebook();
		switch(eleccion)
		{
		case 'A':
			if (altaNotebook(notebook, TAM_NOTEBOOK, &proximoIdNotebook, marca, TAM, tipo, TAM, cliente, TAM) == -1)
			{
				printf("Error al dar de alta la notebook.");
			}
			else
			{
				printf("\nAlta exitosa!\n");
			}
			break;
		case 'B':
			if(modificarNotebook(notebook, TAM_NOTEBOOK, tipo, TAM, marca, TAM, cliente, TAM) == 1)
			{
				system("cls");
				printf("Modificacion exitosa.\n");
			}
			else
			{
				system("cls");
				printf("No se realizo ninguna modificacion.\n");
			}
			break;
		case 'C':
			if(bajaNotebook(notebook, TAM_NOTEBOOK, marca, TAM, tipo, TAM, cliente, TAM) == 1)
			{
				system("cls");
				printf("Baja exitosa.\n");
			}
			else
			{
				system("cls");
				printf("No se realizo ninguna baja.\n");
			}
			break;
		case 'D':
			system("cls");
			mostrarNotebooks(notebook, TAM_NOTEBOOK, marca, TAM, tipo, TAM, cliente, TAM);
			break;
		case 'E':
			system("cls");
			mostrarTipos(tipo, TAM);
			break;
		case 'F':
			system("cls");
			mostrarMarcas(marca, TAM);
			break;
		case 'G':
			system("cls");
			mostrarServicios(servicio, TAM);
			break;
		case 'H':
			if(altaTrabajo(trabajo, TAM_NOTEBOOK, &proximoIdTrabajo, notebook, TAM_NOTEBOOK, servicio, TAM, marca, TAM, tipo, TAM, cliente, TAM))
			{
				printf("Error al dar de alta el trabajo.");
			}
			else
			{
				printf("\nAlta exitosa!\n");
			}
			break;
		case 'I':
			system("cls");
			mostrarTrabajos(trabajo, TAM_NOTEBOOK);
			break;
		case 'J':
			mostraNotebooksPorTipo(notebook, TAM_NOTEBOOK, marca, TAM, tipo, TAM, cliente, TAM);
			break;
		case 'K':
			mostraNotebooksPorMarca(notebook, TAM_NOTEBOOK, marca, TAM, tipo, TAM, cliente, TAM);
			break;
		case 'L':
			informarNotebookMasBarata(notebook, TAM_NOTEBOOK, marca, TAM, tipo, TAM, cliente, TAM);
			break;
		case 'Z':
			printf("Hasta luego!\n\n");
			break;
		default:
			printf("Opcion invalida.\n");
		}
		system("pause");

	  }while(eleccion!='Z');

	return EXIT_SUCCESS;
}
