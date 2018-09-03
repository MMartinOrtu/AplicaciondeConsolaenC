
#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

//Esta línea la he tenido que poner para evitar un error con las funciones fopen yfscan
#pragma warning(disable:4996)
//Función que permite leer cadenas con espacios en blanco en su interior
int leeCadena(char *cad, int n) {
	int i, c;
	c = getchar();
	if (c == EOF) {
		cad[0] = '\0';
		return 0;
	}
	if (c == '\n')
		i = 0;
	else {
		cad[0] = c;
		i = 1;
	}
	for (; i < n - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		cad[i] = c;

	cad[i] = '\0';
	if (c != '\n' && c != EOF)
		while ((c = getchar()) != '\n' && c != EOF);
	return 1;
};

void muestraArchivo(char ruta[]) {

	//Defino el máximo de caracteres que leerá fgets en cada invocación
	#define BUFFER_SIZE 100
	//Declaro la variable que albergará el resultado de cada lectura del archivo
	char buffer[BUFFER_SIZE];
	
	//Declaro puntero tipo FILE
	FILE * fp = NULL;
	//Asigno al puntero anterior el archivo pasado por parametro
	fp = fopen(ruta, "r");

	//Mientras no se encuentre la marca de final de archivo el programa leerá gracias a fgets e imprime el resultado por pantalla
	fgets(buffer, BUFFER_SIZE, fp);

	while (!feof(fp)) {
		printf("%s", buffer);
		fgets(buffer, BUFFER_SIZE, fp);
	};
	//Cerramos archivo para liberar recursos
	fclose(fp);
}

void copiarPares(char ruta[], char rutaPares[], char rutaTemporal[]) {

	//Declaro tres punteros tipo FILE, uno para el archivo hosts, otro par el archivo pares y otro para el archivo temporal
	//donde guardaremos los pares IP URL que no estén en el archivo hosts
	FILE * fp = NULL;
	FILE * fp2 = NULL;
	FILE * fp3 = NULL;
	//Declaro las variables que necesito para operar con los archivos
	bool noEncontrado = true;
	char *r = NULL;
	char buffer1[999];
	char buffer2[999];
	
	//Asigno los punteros a las rutas de los archivos pasados por parámetro
	fp = fopen(ruta, "r");
	fp2 = fopen(rutaPares, "r");
	fp3 = fopen(rutaTemporal, "w+");

	//Mientras no se encuentre la marca de final de archivo del archivo pares.txt
	//vamos chequeando si cada par IP URL del archivo pares.txt se encuentra en el archivo hosts
	while (!feof(fp2)) {
		noEncontrado = true;
		fgets(buffer2, BUFFER_SIZE, fp2);
		rewind(fp);
		while (!feof(fp))
		{
			fgets(buffer1, BUFFER_SIZE, fp);

			r = strstr(buffer1, buffer2);
	//Si el par IP URL se encuentra en el archivo hosts la variable noEncontrado cambia a false y salimos del bucle
			if (r != NULL) {
				noEncontrado = false;
				break;
			}
		}
	//Si el par IP URL no se ha encontrado en el archivo hosts, se copia dicho par en el archivo temporal
		if (noEncontrado == true) {
			fputs(buffer2, fp3);
		}
	}
	//Cerramos archivo para liberar recursos
	fclose(fp);
	fclose(fp2);
	fclose(fp3);
}
void copiarContenido(char ruta[], char rutaTemporal[]) {
	//Defino el máximo de caracteres que leerá fgets en cada invocación
	#define BUFFER_SIZE 100
	//Defino la variable buffer que albergará el resultado de cada lectura del archivo original
	char buffer[BUFFER_SIZE];
	//Declaro dos punteros tipo FILE, uno para el archivo hosts y otro par el archivo temporal
	FILE * fp = NULL;
	FILE * fp2 = NULL;

	//Asignamos los punteros a las rutas de los archivos pasados por parámetro
	// Usamos "a" para ubicar el puntero al final del archivo hosts, ya que vamos a copiar los nuevos pares IP URL
	fp = fopen(ruta, "a");
	fp2 = fopen(rutaTemporal, "r");

	//Leemos el contenido del archivo temporal y lo copiamos en el archivo hosts hasta la marca EOF
	do {
		fgets(buffer, BUFFER_SIZE, fp2);
		fputs(buffer, fp);
	} while (!feof(fp2));
	
	//Cerramos los dos archivos		
	fclose(fp);
	fclose(fp2);
	//Borramos el archivo original
	remove(rutaTemporal);
}