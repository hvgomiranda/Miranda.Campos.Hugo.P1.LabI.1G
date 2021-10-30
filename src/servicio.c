#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"

int idServicio[4] = {20000, 20001, 20002, 20003};
char descripcionServicio[4][21] = {"Bateria", "Display", "Mantenimiento", "Fuente"};
int precioServicio[4] = {2250, 10300, 4400, 5600};

int hardcodearServicio(eServicio servicio[], int tam, int cant)
{
    int contador = -1;
    if (servicio != NULL && tam > 0 && cant >= 0 && cant <= tam)
    {
        contador = 0;
        for (int i = 0; i < cant;  i++)
        {
        	servicio[i].idServicio = idServicio[i];
        	strcpy(servicio[i].descripcionServicio, descripcionServicio[i]);
        	servicio[i].precioServicio = precioServicio[i];
            contador++;
        }
    }
    return contador;
}

int mostrarServicio(eServicio servicio[], int tam, int indice)
{
	int todoOk;
	todoOk = -1;
	if(servicio!=NULL && tam>0)
	{
		todoOk = 0;
		printf("%d    %-10s     %7d \n", servicio[indice].idServicio, servicio[indice].descripcionServicio, servicio[indice].precioServicio);
	}

	return todoOk;
}

int mostrarServicios(eServicio servicio[], int tam)
{
	int todoOk;
	todoOk = -1;
	printf("             SERVICIOS            \n");
	printf("----------------------------------\n");
	printf("ID       TIPO            PRECIO   \n");
	if(servicio!=NULL && tam>0)
	{
		todoOk = 0;
		for(int i=0; i<tam; i++)
		{
			mostrarServicio(servicio, tam, i);
			printf("----------------------------------\n");
		}
	}
	return todoOk;
}
