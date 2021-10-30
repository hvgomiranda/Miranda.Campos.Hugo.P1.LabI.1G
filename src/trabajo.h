#include "fecha.h"
#include "tipo.h"
#include "marca.h"
#include "notebook.h"
#ifndef TRABAJO_H_
#define TRABAJO_H_

struct{
	int idTrabajo;
	int idNotebook;
	int idServicio;
	eFecha fecha;
	int estaVacio;
}typedef eTrabajo;

#endif /* TRABAJO_H_ */

int inicializarTrabajos(eTrabajo trabajo[], int tam);
int buscarEspacioVacioTrabajo(eTrabajo trabajo[], int tam);
int altaTrabajo(eTrabajo trabajo[], int tam, int* id, eNotebook notebook[], int tamNotebook, eServicio servicio[], int tamServicio, eMarca marca[], int tamMarca, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente);
int mostrarTrabajo(eTrabajo trabajo[], int tam, int indice);
int mostrarTrabajos(eTrabajo trabajo[], int tam);
