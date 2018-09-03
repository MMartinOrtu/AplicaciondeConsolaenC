# Aplicacion de Consola en C
Proyecto de crear una aplicación de consola en C para editar archivos de configuración del sistema operativo.

En este ejercicio he desarrollado una aplicación de consola en C para añadir pares IP URL contenidos en un archivo “pares.txt” a un archivo hosts. Solo copia los pares IP URL que no estén ya en el archivo hosts.
A continuación explico las funciones empleadas

-	Función leeCadenas: He utilizado esta función para leer la ruta que se escriben por pantalla de los archivos que utilizamos.

-	Función muestraArchivo: Esta función muestra por pantalla el contenido de un archivo. Es ligeramente distinta a la del producto anterior, ya que en esta ocasión, la ruta del archivo a mostrar la pasamos por parámetro.

-	FuncióncopiarPares: Esta función se encarga de comprobar si los pares IP URL del archivo pares.txt están en el archivo host. En caso de que no estén, los copia en un archivo temporal.

-	Función copiarContenido: Está función se encargar de copiar el contenido de un archivo (en nuestro caso, los pares IP URL del archivo temporal creado en la función anterior) al final del archivo host. Finalmente borra el archivo temporal.
