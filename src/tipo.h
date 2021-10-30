#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED
struct{

	int idTipo;
	char descripcionTipo[21];

}typedef eTipo;

int hardcodearTipos(eTipo tipo[], int tam, int cant);
int mostrarTipos(eTipo tipo[], int tam);
int mostrarTipo(eTipo tipo[], int tam, int indice);
int cargarDescripcionTipo(eTipo tipo[], int tam, int idTipo, char descripcionTipo[]);

#endif /* TIPO_H_ */
