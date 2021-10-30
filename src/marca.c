#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "marca.h"



int idMarca[4] = {1000, 1001, 1002, 1003};
char descripcionMarca[4][21] = {"Compaq", "Asus", "Acer", "HP"};

int hardcodearMarca(eMarca marca[], int tam, int cant)
{
    int contador = -1;
    if (marca != NULL && tam > 0 && cant >= 0 && cant <= tam)
    {
        contador = 0;
        for (int i = 0; i < cant;  i++)
        {
        	marca[i].idMarca = idMarca[i];
        	strcpy(marca[i].descripcionMarca, descripcionMarca[i]);
            contador++;
        }
    }
    return contador;
}

int mostrarMarca(eMarca marca[], int tam, int indice)
{
	int todoOk;
	todoOk = -1;
	if(marca!=NULL && tam>0)
	{
		todoOk = 0;
		printf("%d          %-10s \n", marca[indice].idMarca, marca[indice].descripcionMarca);
	}

	return todoOk;
}

int mostrarMarcas(eMarca marca[], int tam)
{
	int todoOk;
	todoOk = -1;
	if(marca!=NULL && tam>0)
	{
		printf("          MARCAS            \n");
		printf("----------------------------\n");
		printf(" ID           DESCRIPCION   \n");
		printf("----------------------------\n");
		todoOk = 0;
		for(int i=0; i<tam; i++)
		{
			mostrarMarca(marca, tam, i);
			printf("--------------------------\n");
		}
	}
	return todoOk;
}

int cargarDescripcionMarca(eMarca marca[], int tam, int idMarca, char descripcionMarca[])
{
    int todoOk = -1;
    if (marca != NULL && tam > 0 && descripcionMarca != NULL)
    {
        todoOk = 0;
        for (int i = 0; i < tam; i++)
        {
            if (marca[i].idMarca == idMarca)
            {
                strcpy(descripcionMarca, marca[i].descripcionMarca);
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}
