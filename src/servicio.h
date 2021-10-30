#ifndef SERVICIO_H_
#define SERVICIO_H_

struct{

	int idServicio;
	char descripcionServicio[26];
	int precioServicio;

}typedef eServicio;

#endif /* SERVICIO_H_ */

int hardcodearServicio(eServicio servicio[], int tam, int cant);
int mostrarServicios(eServicio servicio[], int tam);
int mostrarServicio(eServicio servicio[], int tam, int indice);
