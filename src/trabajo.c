#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"
#include "servicio.h"
#include "notebook.h"
#include "trabajo.h"
#include "cliente.h"

int inicializarTrabajos(eTrabajo trabajo[], int tam)
{
	int todoOk;
	todoOk = -1;
	if(trabajo != NULL && tam>0)
	{
		todoOk = 0;
		for(int i = 0; i<tam; i++)
		{
			trabajo[i].estaVacio = 1;
		}
	}

	return todoOk;
}

int buscarEspacioVacioTrabajo(eTrabajo trabajo[], int tam)
{
	int indice;
	indice = -1;
	{
		if(trabajo != NULL && tam>0)
		{
			for(int i = 0; i<tam; i++)
			{
				if(trabajo[i].estaVacio == 1)
				{
					indice = i;
					break;
				}
			}
		}
	}
	return indice;
}

int altaTrabajo(eTrabajo trabajo[], int tam, int* id, eNotebook notebook[], int tamNotebook, eServicio servicio[], int tamServicio, eMarca marca[], int tamMarca, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente)
{
	int indice;
	int todoOk;
	int retorno;
	todoOk =-1;
	eTrabajo auxTrabajo;

	indice = buscarEspacioVacioTrabajo(notebook, tam);

	{
		if(trabajo != NULL && tam>0)
		{
			if(indice==-1)
			{
				printf("El programa esta lleno. Intente eliminar algun trabajo para ingresar uno nuevo\n");
			}

			else
			{

				for(int i = 0; i<tam; i++)
				{

					system("cls");
					printf("-----------------------------------\n");
					printf("            ALTA TRABAJO           \n");
					printf("-----------------------------------\n");

					auxTrabajo.idTrabajo = *id;
					(*id)++;

					do
					{
						system("cls");
						mostrarNotebooks(notebook, tam, marca, tamMarca, tipo, tamTipo, cliente, tamCliente);
						printf("Ingrese el ID de una notebook: ");
						scanf("%d", &auxTrabajo.idNotebook);
					}while(encontrarNotebook(notebook, tamNotebook, auxTrabajo.idNotebook)!=1);

					do
					{
						system("cls");
						mostrarServicios(servicio, tamServicio);
						printf("\nIngrese la ID del servicio que desee realizar: ");
						scanf("%d", &auxTrabajo.idServicio);
					}while(validarEnteroBinario(auxTrabajo.idServicio, 20000, 20003)==0);

					printf("Ingrese una fecha (dd/mm/aaaa): ");
					fflush(stdin);
					retorno = scanf("%d/%d/%d", &auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes, &auxTrabajo.fecha.anio);

					while(!(retorno == 3) && (auxTrabajo.fecha.dia>=1 && auxTrabajo.fecha.dia<=31) && (auxTrabajo.fecha.mes>=1 && auxTrabajo.fecha.mes<=12) && (auxTrabajo.fecha.anio>=1990 && auxTrabajo.fecha.anio<=2021))
					{
						printf("Error. Ingrese nuevamente la fecha (dd/mm/aaaa");
						fflush(stdin);
						retorno = scanf("%d/%d/%d", &auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes, &auxTrabajo.fecha.anio);
					}

					auxTrabajo.estaVacio = 0;
					break;

				}

				todoOk = 0;
				trabajo[indice] = auxTrabajo;

			}

		return todoOk;

		}
	}
}

int mostrarTrabajo(eTrabajo trabajo[], int tam, int indice)
{
	int todoOk;
	todoOk = -1;
	if(trabajo!=NULL && tam>0)
	{
		todoOk = 0;
		printf("%5d   %3d             %4d          %2d/%2d/%4d\n",
				trabajo[indice].idTrabajo, trabajo[indice].idNotebook, trabajo[indice].idServicio, trabajo[indice].fecha.dia, trabajo[indice].fecha.mes, trabajo[indice].fecha.anio);
	}

	return todoOk;
}

int mostrarTrabajos(eTrabajo trabajo[], int tam)
{
	int todoOk;
	todoOk = -1;
	int sinTrabajos = 1;
	printf("                   TRABAJOS                  \n");
	printf("---------------------------------------------\n");
	printf("ID      ID NOTEBOOK     ID SERVICIO    FECHA \n");
	printf("---------------------------------------------\n");
	if(trabajo!=NULL && tam>0)
	{
		todoOk = 0;
		for(int i=0; i<tam; i++)
		{
			if(trabajo[i].estaVacio == 0)
			{
				mostrarTrabajo(trabajo, tam, i);
				printf("---------------------------------------------\n");
				sinTrabajos = 0;
			}
		}
		if(sinTrabajos)
		{
			system("cls");
			printf("No hay trabajos para mostrar");
		}
	}
	return todoOk;
}
