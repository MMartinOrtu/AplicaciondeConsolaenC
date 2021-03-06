// Producto3.cpp: define el punto de entrada de la aplicación de consola.
//
#include "stdafx.h"
#include "fArchivos.h"
#include "fArchivos.cpp"

int main()
{
	//Declaramos las variables donde guardaremos las rutas de los archivos
	char ruta[100];
	char rutaPares[100];
	char rutaTemporal[100];

	//Introducimos la ruta del archivo hosts 
	printf("Introduce la ruta del archivo hosts:\n");
	leeCadena(ruta, 100);
	//Se muestra por pantalla el contenido del archivo hosts
	muestraArchivo(ruta);
	system("pause");
	system("cls");

	//Introducimos la ruta del archivo pares.txt
	printf("Introduce la ruta del archivo donde estan los pares a leer:\n");
	leeCadena(rutaPares, 100);
	//Se muestra por pantalla el contenido del archivo pares.txt
	muestraArchivo(rutaPares);

	//Introducimos la ruta del archivo temporal para guardar los pares IP URL que faltan en el archivo hosts
	printf("Introduce la ruta del archivo temporal donde se guardaran los pares IP URL que faltan en el archivo hosts:\n");
	leeCadena(rutaTemporal, 100);
	copiarPares(ruta, rutaPares, rutaTemporal);
	//Se muestra por pantalla el contenido del archivo temporal
	printf("El contenido del archivo temporal es el siguiente:\n");
	muestraArchivo(rutaTemporal);
	
	//Se copia el contenido del archivo temporal al archivo host y se elimina el archivo temporal
	copiarContenido(ruta, rutaTemporal);
	system("pause");	
	system("cls");
	
	//Mostramos de nuevo el contenido del archivo hosts
	printf("El contenido actualizado del archivo hosts es el siguiente:\n\n");
	muestraArchivo(ruta);	
	system("pause");
	return 0;
}
