#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"

int idTipo[4] = {5000, 5001, 5002, 5003};
char descripcionTipo[4][21] = {"Gamer", "Disenio", "Ultrabook", "Normalita"};


int hardcodearTipos(eTipo tipo[], int tam, int cant)
{
    int contador = -1;
    if (tipo != NULL && tam > 0 && cant >= 0 && cant <= tam)
    {
        contador = 0;
        for (int i = 0; i < cant;  i++)
        {
        	tipo[i].idTipo = idTipo[i];
        	strcpy(tipo[i].descripcionTipo, descripcionTipo[i]);
            contador++;
        }
    }
    return contador;
}

int mostrarTipo(eTipo tipo[], int tam, int indice)
{
	int todoOk;
	todoOk = -1;
	if(tipo!=NULL && tam>0)
	{
		todoOk = 0;
		printf("%d          %-10s \n", tipo[indice].idTipo, tipo[indice].descripcionTipo);
	}

	return todoOk;
}

int mostrarTipos(eTipo tipo[], int tam)
{
	int todoOk;
	todoOk = -1;
	printf("           TIPOS            \n");
	printf("----------------------------\n");
	printf(" ID           DESCRIPCION   \n");
	printf("----------------------------\n");
	if(tipo!=NULL && tam>0)
	{
		todoOk = 0;
		for(int i=0; i<tam; i++)
		{
			mostrarTipo(tipo, tam, i);
			printf("----------------------------\n");
		}
	}
	return todoOk;
}

int cargarDescripcionTipo(eTipo tipo[], int tam, int idTipo, char descripcionTipo[])
{
    int todoOk = -1;
    if (tipo != NULL && tam > 0 && descripcionTipo != NULL)
    {
        todoOk = 0;
        for (int i = 0; i < tam; i++)
        {
            if (tipo[i].idTipo == idTipo)
            {
                strcpy(descripcionTipo, tipo[i].descripcionTipo);
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}
