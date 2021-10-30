#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "notebook.h"
#include "marca.h"
#include "tipo.h"
#include "cliente.h"

int idCliente[4] = {50000, 50001, 50002, 50003};
char nombreCliente[4][21] = {"Julia", "Lucia", "Pedro", "Carlos"};
char sexo[4] = {'f', 'f', 'm', 'm'};

int hardcodearClientes(eCliente cliente[], int tam, int cant)
{
    int contador = -1;
    if (cliente != NULL && tam > 0 && cant >= 0 && cant <= tam)
    {
        contador = 0;
        for (int i = 0; i < cant;  i++)
        {
        	cliente[i].idCliente = idCliente[i];
        	cliente[i].sexo = sexo[i];
        	strcpy(cliente[i].nombre, nombreCliente[i]);
            contador++;
        }
    }
    return contador;
}

int mostrarCliente(eCliente cliente[], int tam, int indice)
{

	int todoOk;
	todoOk = -1;
	if(cliente!=NULL && tam>0)
	{
		todoOk = 0;
		printf("%d        %-10s         %c \n",
				cliente[indice].idCliente, cliente[indice].nombre, cliente[indice].sexo);
	}

	return todoOk;
}

int mostrarClientes(eCliente cliente[], int tam)
{
	int todoOk;
	todoOk = -1;
	int sinClientes = 1;
	printf("                      CLIENTE                     \n");
	printf("--------------------------------------------------\n");
	printf("   ID             NOMBRE                SEXO      \n");
	printf("--------------------------------------------------\n");
	if(cliente!=NULL && tam>0)
	{
		todoOk = 0;
		for(int i=0; i<tam; i++)
		{
			if(cliente[i].estaVacio == 0)
			{
				mostrarCliente(cliente, tam, i);
				printf("--------------------------------------------------\n");
				sinClientes = 0;
			}
		}
		if(sinClientes)
		{
			system("cls");
			printf("No hay notebooks para mostrar");
		}
	}
	return todoOk;
}

int cargarDescripcionCliente(eCliente cliente[], int tam, int idCliente, char descripcionCliente[])
{
    int todoOk = -1;
    if (cliente != NULL && tam > 0 && descripcionCliente != NULL)
    {
        todoOk = 0;
        for (int i = 0; i < tam; i++)
        {
            if (cliente[i].idCliente == idCliente)
            {
                strcpy(descripcionCliente, cliente[i].nombre);
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}

