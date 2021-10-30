/*#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"

eFecha IngresarFecha()
{
	eFecha fecha;
	int retorno;

	system("cls");
	printf("Ingrese una fecha (dd/mm/aaaa): ");
	fflush(stdin);
	retorno = scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

	while(!(retorno == 3) && (fecha.dia>=1 && fecha.dia<=31) && (fecha.mes>=1 && fecha.mes<=12) && (fecha.anio>=1990 && fecha.anio<=2021))
	{
		printf("Error. Ingrese nuevamente la fecha (dd/mm/aaaa");
		fflush(stdin);
		retorno = scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
	}

	return fecha;
}*/
