#ifndef CLIENTE_H_
#define CLIENTE_H_

struct
{
	int idCliente;
	char nombre[21];
	char sexo;
	int estaVacio;

}typedef eCliente;

#endif /* CLIENTE_H_ */


int hardcodearClientes(eCliente cliente[], int tam, int cant);
int mostrarCliente(eCliente cliente[], int tam, int indice);
int mostrarClientes(eCliente cliente[], int tam);
int cargarDescripcionCliente(eCliente cliente[], int tam, int idCliente, char descripcionCliente[]);
