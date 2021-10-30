#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "notebook.h"
#include "marca.h"
#include "tipo.h"
#include "cliente.h"

char modelo[5][10] = {"Sur", "Norte", "Oeste", "Este", "Centro"};
int idMarcaHard[5] = {1000, 1002, 1003, 1001, 1000};
int idTipoHard[5] = {5002, 5001, 5003, 5000, 5000};
int idClienteHard[5] = {50000, 50001, 50002, 50000, 50003};
int precioNotebook[5] = {500000, 120000, 95000, 76000, 135000};

int menuNotebook()
{
	char eleccion;

	system("cls");

	printf("---------MENU---------\n");
	printf("A.  ALTA NOTEBOOK\n");
	printf("B.  MODIFICAR NOTEBOOK\n");
	printf("C.  BAJA NOTEBOOK\n");
	printf("D.  LISTAR NOTEBOOKS\n");
	printf("E.  LISTAR MARCAS\n");
	printf("F.  LISTAR TIPOS\n");
	printf("G.  LISTAR SERVICIOS\n");
	printf("H.  ALTA TRABAJO\n");
	printf("I.  LISTAR TRABAJOS\n");
	printf("J.  MOSTRAR NOTEBOOKS DE UN TIPO EN PARTICULAR\n");
	printf("K.  MOSTRAR NOTEBOOKS DE UNA MARCA EN PARTICULAR\n");
	printf("L.  MOSTRAR NOTEBOOKS MAS BARATAS\n");
	printf("Z.  SALIR\n\n");

	printf("\nElija una opcion: ");
	fflush(stdin);
	scanf(" %c", &eleccion);
	eleccion = toupper(eleccion);

	return eleccion;
}

int subMenuNotebook(eNotebook notebook[], int tam, int idNotebookModificar, eMarca marca[], int tamMarca, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente)
{
	char eleccion;

	system("cls");

	printf("----MENU DE MOFICACION----\n");
	mostrarNotebook(notebook, tam, idNotebookModificar, marca, tamMarca, tipo, tamTipo, cliente, tamCliente);
	printf("A.  PRECIO\n");
	printf("B.  TIPO\n");
	printf("C.  SALIR\n");

	printf("\nElija una opcion: ");
	fflush(stdin);
	scanf("%c", &eleccion);
	eleccion = toupper(eleccion);

	return eleccion;
}

int inicializarNotebooks(eNotebook notebook[], int tam)
{
	int todoOk;
	todoOk = -1;
	if(notebook != NULL && tam>0)
	{
		todoOk = 0;
		for(int i = 0; i<tam; i++)
		{
			notebook[i].estaVacio = 1;
		}
	}

	return todoOk;
}

int buscarEspacioVacioNotebook(eNotebook notebook[], int tam)
{
	int indice;
	indice = -1;
	{
		if(notebook != NULL && tam>0)
		{
			for(int i = 0; i<tam; i++)
			{
				if(notebook[i].estaVacio == 1)
				{
					indice = i;
					break;
				}
			}
		}
	}
	return indice;
}

int altaNotebook(eNotebook notebook[], int tam, int* id, eMarca marca[], int tamMarca, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente)
{
	int indice;
	int todoOk;
	todoOk =-1;
	eNotebook auxNotebook;

	indice = buscarEspacioVacioNotebook(notebook, tam);

	{
		if(notebook != NULL && tam>0)
		{
			if(indice==-1)
			{
				printf("El programa esta lleno. Intente eliminar alguna notebook para ingresar una nueva\n");
			}

			else
			{
				for(int i = 0; i<tam; i++)
					{

						system("cls");
						printf("-----------------------------------\n");
						printf("                ALTA               \n");
						printf("-----------------------------------\n");

						auxNotebook.idNotebook = *id;
						(*id)++;

						do
						{
							system("cls");
							printf("Ingrese el modelo de la notebook: ");
							fflush(stdin);
							gets(auxNotebook.modelo);
						}while(validarCadena(auxNotebook.modelo, 21)!=1);

						do
						{
							system("cls");
							mostrarMarcas(marca, tamMarca);
							printf("\nIngrese la ID de la marca de la notebook: ");
							scanf("%d", &auxNotebook.idMarca);
						}while(!validarEnteroBinario(auxNotebook.idMarca, 1000, 1003));

						do
						{
							system("cls");
							mostrarTipos(tipo, tamTipo);
							printf("\nIngrese la ID del tipo de la notebook: ");
							scanf("%d", &auxNotebook.idTipo);
						}while(!validarEnteroBinario(auxNotebook.idTipo, 5000, 5003));

						do
						{
							system("cls");
							printf("Ingrese el precio de la notebook: ");
							fflush(stdin);
							scanf("%d", &auxNotebook.precioNotebook);
						}while(!validarEnteroBinario(auxNotebook.precioNotebook, 0, 10000000));

						do
						{
							system("cls");
							mostrarClientes(cliente, tamCliente);
							printf("\nIngrese el ID del cliente: ");
							scanf("%d", &auxNotebook.idCliente);
						}while(!validarEnteroBinario(auxNotebook.idCliente, 50000, 50003));

						auxNotebook.estaVacio = 0;
						break;

					}

				todoOk = 0;
				notebook[indice] = auxNotebook;

			}

		}

		return todoOk;

	}
}

int mostrarNotebook(eNotebook notebook[], int tam, int indice, eMarca marca[], int tamMarca, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente)
{
	char descripcionTipo[21];
	char descripcionMarca[21];
	char descripcionCliente[21];

	cargarDescripcionTipo(tipo, tam, notebook[indice].idTipo, descripcionTipo);
	cargarDescripcionMarca(marca, tam, notebook[indice].idMarca, descripcionMarca);
	cargarDescripcionCliente(cliente, tam, notebook[indice].idCliente, descripcionCliente);

	int todoOk;
	todoOk = -1;
	if(notebook!=NULL && tam>0)
	{
		todoOk = 0;
		printf("%d   %-10s %-10s  %-10s  %-10s  %5d\n",
				notebook[indice].idNotebook, notebook[indice].modelo, descripcionMarca, descripcionTipo, descripcionCliente, notebook[indice].precioNotebook);
	}

	return todoOk;
}

int mostrarNotebooks(eNotebook notebook[], int tam, eMarca marca[], int tamMarca, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente)
{
	int todoOk;
	todoOk = -1;
	int sinNotebooks = 1;
	printf("                         NOTEBOOKS                       \n");
	printf("---------------------------------------------------------\n");
	printf("ID    MODELO     MARCA       TIPO    CLIENTE    PRECIO   \n");
	printf("---------------------------------------------------------\n");
	if(notebook!=NULL && tam>0)
	{
		ordenarNotebook(notebook, tam, marca, tamMarca);
		todoOk = 0;
		for(int i=0; i<tam; i++)
		{
			if(notebook[i].estaVacio == 0)
			{
				mostrarNotebook(notebook, tam, i, marca, tamMarca, tipo, tamTipo, cliente, tamCliente);
				printf("---------------------------------------------------------\n");
				sinNotebooks = 0;
			}
		}
		if(sinNotebooks)
		{
			system("cls");
			printf("No hay notebooks para mostrar");
		}
	}
	return todoOk;
}

int ordenarNotebook(eNotebook notebook[], int tam, eMarca marca[], int tamMarca)
{
	int todoOk = -1;
	char descripcionMarcaI[21];
	char descripcionMarcaJ[21];
	eNotebook auxNotebook;


	if(notebook!=NULL && tam>0 )
	{
		todoOk=0;
		for (int i = 0; i < tam -1; i++)
			{
				cargarDescripcionMarca(marca, tamMarca, notebook[i].idMarca, descripcionMarcaI);
				for (int j = i+1; j < tam; j++)
				{
					cargarDescripcionMarca(marca, tamMarca, notebook[j].idMarca, descripcionMarcaJ);

					if ( strcmp(descripcionMarcaI, descripcionMarcaJ) > 0 ||
							(strcmp(descripcionMarcaI, descripcionMarcaJ) == 0 && notebook[i].precioNotebook > notebook[j].precioNotebook))
					{
						auxNotebook = notebook[i];
						notebook[i] = notebook[j];
						notebook[j] = auxNotebook;
						todoOk=1;
					}
				}
			}
	}
	return todoOk;
}

int encontrarNotebook(eNotebook notebook[], int tam, int id)
{
	int todoOk = -1;
	if(notebook != NULL && tam>0)
	{
		todoOk = 0;
		for(int i = 0; i<tam; i++)
		{
			if(notebook[i].idNotebook == id)
			{
				todoOk = 1;
				break;
			}
		}
	}

	return todoOk;
}

int buscarIndiceNotebookPorId(eNotebook notebook[], int tam, int id)
{
    int indice = -1;
    for (int i = 0; i < tam; i++)
    {
        if (notebook[i].idNotebook == id && notebook[i].estaVacio == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int bajaNotebook(eNotebook notebook[], int tam, eMarca marca[], int tamMarca, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente)
{
	int todoOk = -1;
	int idBaja;
	char confirmacion;
	int indice;
	eNotebook auxNotebook;

	if(notebook!=NULL && tam>0)
	{
		todoOk = 0;
		system("cls");
		do
		{
			mostrarNotebooks(notebook, tam, marca, tamMarca, tipo, tamTipo, cliente, tamCliente);
			printf("\n\nElija el ID de la notebook que desee eliminar: ");
			scanf("%d", &idBaja);
		}while(encontrarNotebook(notebook, tam, idBaja) != 1);

		indice = buscarIndiceNotebookPorId(notebook, tam, idBaja);

		auxNotebook.estaVacio = 1;

		do
		{
			printf("\nDesea eliminar la notebook ID %d. Es correcto? (s/n) ", idBaja);
			fflush(stdin);
			scanf("%c", &confirmacion);
			confirmacion = tolower(confirmacion);

		}while(validarCaracterBinario(confirmacion, 's', 'n')!=1);

		if(confirmacion == 's')
		{
			notebook[indice].estaVacio = auxNotebook.estaVacio;
			todoOk = 1;
		}
		else
		{
			system("cls");
			printf("Baja cancelada");
		}
	}
	return todoOk;
}

int modificarNotebook(eNotebook notebook[], int tam, eTipo tipo[], int tamTipo, eMarca marca[], int tamMarca, eCliente cliente[], int tamCliente)
{
	int todoOk = -1;
	int idNotebookModificar;
	int eleccionSubMenu;
	int indice;
	char confirmacion;
	eNotebook auxNotebook;

	if(notebook != NULL && tam>0)
	{
		todoOk = 0;
		do
		{
			system("cls");
			mostrarNotebooks(notebook, tam, marca, tamMarca, tipo, tamTipo, cliente, tamCliente);
			printf("Ingrese el ID de la notebook a modificar: ");
			scanf("%d", &idNotebookModificar);
		}while(encontrarNotebook(notebook, tam, idNotebookModificar) != 1);

		indice = buscarIndiceNotebookPorId(notebook, tam, idNotebookModificar);

		do
		{
			eleccionSubMenu = subMenuNotebook(notebook, tam, indice, marca, tamMarca, tipo, tamTipo, cliente, tamCliente);

			switch(eleccionSubMenu)
			{
			case 'A':
				system("cls");
				printf("Cual es el nuevo precio de la notebook?: ");
				scanf("%d", &auxNotebook.precioNotebook);
				do
				{
					printf("\nEl nuevo precio es $ %d. Es correcto? (s/n) ", auxNotebook.precioNotebook);
					fflush(stdin);
					scanf("%c", &confirmacion);

				}while(validarCaracterBinario(confirmacion, 's', 'n')==0);
				if(confirmacion == 's')
				{
					notebook[indice].precioNotebook = auxNotebook.precioNotebook;
					todoOk = 1;
				}
				else
				{
					system("cls");
					printf("Modificacion cancelada");
				}
				break;
			case 'B':
				system("cls");
				int mostrarTipos(eTipo tipo[], int tam);
				printf("Cual es el nuevo ID del tipo de notebook?: ");
				scanf("%d", &auxNotebook.idTipo);
				do
				{
					printf("\nEl nuevo ID del tipo es $ %d. Es correcto? (s/n) ", auxNotebook.idTipo);
					scanf("%c", &confirmacion);

				}while(validarCaracterBinario(confirmacion, 's', 'n')==0);

				if(confirmacion == 's')
				{
					notebook[indice].idTipo = auxNotebook.idTipo;
					todoOk = 1;
				}
				else
				{
					system("cls");
					printf("Modificacion cancelada");
				}
				break;
			case 'C':
				break;
			default:
				printf("Opcion invalida.\n");
				break;
			}
		}while(eleccionSubMenu!='C');
	}
	return todoOk;
}

int mostraNotebooksPorTipo(eNotebook notebook[], int tam, eMarca marca[], int tamMarca, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente)
{
	int todoOk = -1;
	char tipoElegido[21];
	char descripcionTipo[21];
	int sinTipos = 1;

	if(notebook!=NULL && tam>0 && marca!=NULL && tamMarca>0 && tipo!=NULL && tamTipo>0 && cliente!=NULL && tamCliente>0)
	{
		int eleccion;

		system("cls");
		printf("  TIPOS  \n");
		printf("1.  Gamer\n");
		printf("2.  Disenio\n");
		printf("3.  Ultrabook\n");
		printf("4.  Normalita\n\n");
		printf("Elegí un tipo: ");
		scanf("%d", &eleccion);


		switch(eleccion)
		{
		case 1:
			strcpy(tipoElegido, "Gamer");
			for(int i=0; i<tam; i++)
			{
				cargarDescripcionTipo(tipo, tam, notebook[i].idTipo, descripcionTipo);

				if(strcmp(tipoElegido, descripcionTipo) == 0 && notebook[i].estaVacio==0)
				{
					mostrarNotebook(notebook, tam, i, marca, tamMarca, tipo, tamTipo, cliente, tamCliente);
				}
			}
			break;
		case 2:
			strcpy(tipoElegido, "Disenio");
			for(int i=0; i<tam; i++)
			{
				cargarDescripcionTipo(tipo, tam, notebook[i].idTipo, descripcionTipo);

				if(strcmp(tipoElegido, descripcionTipo) == 0 && notebook[i].estaVacio==0)
				{
					mostrarNotebook(notebook, tam, i, marca, tamMarca, tipo, tamTipo, cliente, tamCliente);
				}
			}
			break;
		case 3:
			strcpy(tipoElegido, "Ultrabook");
			for(int i=0; i<tam; i++)
			{
				cargarDescripcionTipo(tipo, tam, notebook[i].idTipo, descripcionTipo);

				if(strcmp(tipoElegido, descripcionTipo) == 0 && notebook[i].estaVacio==0)
				{
					mostrarNotebook(notebook, tam, i, marca, tamMarca, tipo, tamTipo, cliente, tamCliente);
				}
			}
			break;
		case 4:
			strcpy(tipoElegido, "Normalita");
			for(int i=0; i<tam; i++)
			{
				cargarDescripcionTipo(tipo, tam, notebook[i].idTipo, descripcionTipo);

				if(strcmp(tipoElegido, descripcionTipo) == 0 && notebook[i].estaVacio==0)
				{
					mostrarNotebook(notebook, tam, i, marca, tamMarca, tipo, tamTipo, cliente, tamCliente);
				}
			}
			break;
		default:
			printf("Opcion incorrecta.\n");
			break;
		}
	}
}

int mostraNotebooksPorMarca(eNotebook notebook[], int tam, eMarca marca[], int tamMarca, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente)
{
	int todoOk = -1;
	char marcaElegida[21];
	char descripcionMarca[21];
	int sinTipos = 1;

	if(notebook!=NULL && tam>0 && marca!=NULL && tamMarca>0 && tipo!=NULL && tamTipo>0 && cliente!=NULL && tamCliente>0)
	{
		todoOk = 0;
		int eleccion;

		system("cls");
		printf("  TIPOS  \n");
		printf("1.  Compaq\n");
		printf("2.  Asus\n");
		printf("3.  Acer\n");
		printf("4.  HP\n\n");
		printf("Elegí un tipo: ");
		scanf("%d", &eleccion);

		switch(eleccion)
		{
		case 1:
			strcpy(marcaElegida, "Compaq");
			for(int i=0; i<tam; i++)
			{
				cargarDescripcionMarca(tipo, tam, notebook[i].idMarca, descripcionMarca);

				if(strcmp(marcaElegida, descripcionMarca) == 0 && notebook[i].estaVacio==0)
				{
					todoOk = 1;
					mostrarNotebook(notebook, tam, i, marca, tamMarca, tipo, tamTipo, cliente, tamCliente);
				}
			}
			break;
		case 2:
			strcpy(marcaElegida, "Asus");
			for(int i=0; i<tam; i++)
			{
				cargarDescripcionMarca(tipo, tam, notebook[i].idMarca, descripcionMarca);

				if(strcmp(marcaElegida, descripcionMarca) == 0 && notebook[i].estaVacio==0)
				{
					todoOk = 1;
					mostrarNotebook(notebook, tam, i, marca, tamMarca, tipo, tamTipo, cliente, tamCliente);
				}
			}
			break;
		case 3:
			strcpy(marcaElegida, "Acer");
			for(int i=0; i<tam; i++)
			{
				cargarDescripcionMarca(tipo, tam, notebook[i].idMarca, descripcionMarca);

				if(strcmp(marcaElegida, descripcionMarca) == 0 && notebook[i].estaVacio==0)
				{
					todoOk = 1;
					mostrarNotebook(notebook, tam, i, marca, tamMarca, tipo, tamTipo, cliente, tamCliente);
				}
			}
			break;
		case 4:
			strcpy(marcaElegida, "HP");
			for(int i=0; i<tam; i++)
			{
				cargarDescripcionMarca(tipo, tam, notebook[i].idMarca, descripcionMarca);

				if(strcmp(marcaElegida, descripcionMarca) == 0 && notebook[i].estaVacio==0)
				{
					todoOk = 1;
					mostrarNotebook(notebook, tam, i, marca, tamMarca, tipo, tamTipo, cliente, tamCliente);
				}
			}
			break;
		default:
			printf("Opcion incorrecta.\n");
			break;
		}
	}
	return todoOk;
}

int informarNotebookMasBarata(eNotebook notebook[], int tam, eMarca marca[], int tamMarca, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente)
{
	int todoOk = -1;
	int bandera = 1;
	int indice;
	int menorPrecio;

	if(notebook!=NULL & tam>0)
	{
		todoOk = 0;
		for(int i=0; i<tam; i++)
		{
			if(notebook[i].estaVacio == 0)
			{
				if(bandera == 1 || notebook[i].precioNotebook < menorPrecio)
				{
					menorPrecio = notebook[i].precioNotebook;
					bandera = 0;
				}

			}
		}

		system("cls");
		{
			printf("Notebook(s) con menos precio: \n");
		    for(int i = 0; i<tam;i++)
		    {
				if(notebook[i].estaVacio == 0 && notebook[i].precioNotebook == menorPrecio)
				{
					mostrarNotebook(notebook, tam, i, marca, tamMarca, tipo, tamTipo, cliente, tamCliente);
					todoOk = 1;
				}
		    }


		}

	}
	return todoOk;
}

/*int informarNotebooksPorMarca()
{
	int todoOk;
	char descripcionMarca[21];

	if(notebook!=NULL && tam>0)
	{
		system("cls");
		printf("Notebooks por marca: ");

		for (int i = 0; i < tam; i++)
		{
			cargarDescripcionMarca(tipo, tam, notebook[i].idMarca, descripcionMarca);
			printf("Marca: %s", descripcionMarca);
			if(strcmp(descripcionMarca, notebook[i], ))



		}


	}

}*/

int validarCadena(char cadena[], int tam)
{
	int todoOk = -1;
	if(cadena!=NULL && strlen(cadena)>0 && strlen(cadena)<=tam)
	{
		todoOk = 1;
	}
	else
	{
		printf("Incorreto, intente nuevamente.\n");
		todoOk = 0;
	}
	return todoOk;
}

int validarCaracterBinario(char caracter, int a, int b)
{
	int todoOk = 0;
	if(caracter == a || caracter == b)
	{
		todoOk = 1;
	}

	return todoOk;
}

int validarEnteroBinario(int entero, int inferior, int superior)
{
    int todoOk = 0;
    if(entero >=inferior && entero <= superior)
    {
    	todoOk = 1;
    }

	return todoOk;
}

int hardcodearNotebook(eNotebook notebook[], int tam, int cant, int* id)
{
    int contador = -1;
    if (notebook != NULL && tam > 0 && cant >= 0 && cant <= tam)
    {
        contador = 0;
        for (int i = 0; i < cant;  i++)
        {
        	notebook[i].idNotebook = *id;
			(*id)++;
        	notebook[i].idMarca = idMarcaHard[i];
        	notebook[i].idTipo = idTipoHard[i];
        	notebook[i].idCliente = idClienteHard[i];
        	notebook[i].precioNotebook = precioNotebook[i];
        	strcpy(notebook[i].modelo, modelo[i]);
        	notebook[i].estaVacio = 0;
            contador++;
        }
    }
    return contador;
}
