#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

struct{

	int idMarca;
	char descripcionMarca[21];

}typedef eMarca;

int hardcodearMarca(eMarca marca[], int tam, int cant);
int mostrarMarcas(eMarca marca[], int tam);
int mostrarMarca(eMarca marca[], int tam, int indice);
int cargarDescripcionMarca(eMarca marca[], int tam, int idMarca, char descripcionMarca[]);

#endif /* MARCA_H_ */
