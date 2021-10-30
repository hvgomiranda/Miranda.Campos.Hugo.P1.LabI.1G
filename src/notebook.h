#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED

struct{
	int idNotebook;
	char modelo[21];
	int idMarca;
	int idTipo;
	int idCliente;
	int precioNotebook;
	int estaVacio;
}typedef eNotebook;

#include "marca.h"
#include "tipo.h"
#include "cliente.h"

int menuNotebook();
int subMenuNotebook(eNotebook notebook[], int tam, int idNotebookModificar, eMarca marca[], int tamMarca, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente);
int inicializarNotebooks(eNotebook notebook[], int tam);
int buscarEspacioVacioNotebook(eNotebook notebook[], int tam);
int altaNotebook(eNotebook notebook[], int tam, int* id, eMarca marca[], int tamMarca, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente);
int mostrarNotebook(eNotebook notebook[], int tam, int indice, eMarca marca[], int tamMarca, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente);
int mostrarNotebooks(eNotebook notebook[], int tam, eMarca marca[], int tamMarca, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente);
int ordenarNotebook(eNotebook notebook[], int tam, eMarca marca[], int tamMarca);
int encontrarNotebook(eNotebook notebook[], int tam, int id);
int buscarIndiceNotebookPorId(eNotebook notebook[], int tam, int id);
int bajaNotebook(eNotebook notebook[], int tam, eMarca marca[], int tamMarca, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente);
int modificarNotebook(eNotebook notebook[], int tam, eTipo tipo[], int tamTipo, eMarca marca[], int tamMarca, eCliente cliente[], int tamCliente);
int mostraNotebooksPorTipo(eNotebook notebook[], int tam, eMarca marca[], int tamMarca, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente);
int mostraNotebooksPorMarca(eNotebook notebook[], int tam, eMarca marca[], int tamMarca, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente);
int informarNotebookMasBarata(eNotebook notebook[], int tam, eMarca marca[], int tamMarca, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente);

int validarCadena(char cadena[], int tam);
int validarCaracterBinario(char caracter, int a, int b);
int validarEnteroBinario(int entero, int inferior, int superior);
int hardcodearNotebook(eNotebook notebook[], int tam, int cant, int* id);


#endif /* NOTEBOOK_H_ */
