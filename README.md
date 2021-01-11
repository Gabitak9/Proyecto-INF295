# Proyecto-INF295
Proyecto para el ramo **INF-295 Inteligencia Artificial** en donde se aborda el MCLP (*Maximal Covergin Location Problem*) con una heurística de **Forward-Checking**.

### Sobre las Instancias
Las instancias fueron obtenidas  del  INPE (Instituto Nacional de Pesquisas Espaciais) http://www.lac.inpe.br/ lorena/instancias.html, y estas se pueden encontrar en la carpeta `test-cases`.

### Compilando el Programa
Para compilar el programa sólo debe utilizar el siguiente comando:
```
make
```

Con esto se creará el archivo para correr el programa (`main`).

### Corriendo el Programa
Para correr el programa debe ejecutar el siguiente comando:
```
./main <ARCHIVO_DE_COORDENADAS> <ARCHIVO_DE_DEMANDAS> <CANTIDAD_DE_SERVIDORES> <RANGO_DE_COBERTURA>
```

Donde:
- `ARCHIVO_DE_COORDENADAS` corresponde al archivo de la instancia que contiene las coordenadas de los nodos. (Ej. SCJ10.txt)
-`ARCHIVO_DE_DEMANDAS` corresponde al archivo de la instancia que contiene las demandas de los nodos (Ej. demand-SCJ10.txt)
-`CANTIDAD_DE_SERVIDORES` corresponde a la cantidad de servidores (p) que se desean instalar
-`RANGO_DE_COBERTURA` corresponde al rango de cobertura que tienen (S) los servidores

### Experimentos
Pude automatizar la ejecución de todas las instancias para distintos parámetros de p y de S. Utilice el siguiente comando (Los resultados tanto de la ejecución cono los tiempos de computación serán volcados en el archivo `resultados_experimentos.txt`).
```
./experiments.sh
```
