# Documentación

Atencion, varios de los algoritmos implementados, fueron basados en los del sitio Geeks for Geeks, los detalles/enlace se encuentran en el encabezado de cada codigo.

## Entrega

La entrega se realiza vía **aula.usm.cl** en formato `.zip`.

Link al repositorio en GitHub: https://github.com/agomezrr/Tarea1Agustin

## Requisitos y Entorno (Detallado en informe tambien)
* **Sistema Operativo:** WSL Ubuntu / Linux
* **Compilador:** `g++`
* **Construcción:** `make` para la compilación mediante Makefile, hay un Makefile para sorting y matrix_multiplication respectivamente.
* **Python:** Requiere las librerias `pandas`, `matplotlib` y `seaborn` para el analisis y generacion de los graficos

## Multiplicación de matrices

Se implementaron los algoritmos de Naive ($O(n^3)$) y Strassen ($O(n^{2,81})$).


### Programa principal

El programa en C++ ejecuta ambos algoritmos sobre matrices densas, dispersas y diagonales de tamaños $N {16, 64, 256, 1024}$.
1. **1. Compilar** Ubicarse en `./code/matrix_multiplication/` y ejecutar el comando `make`.
2. **2. Ejecutar:** Antes de correr el compilado generado `./matrix_mult`, no olvidar generar los archivos .txt con matrix_generator.py, una vez generados, correr el compilado, este toma su tiempo en ejecutarse (en mi caso 20 minutos aproximadamente). 
3. **3. Salida:** El programa medirá los tiempos en microsegundos y exportara los resultados en el archivo `salida_matrix.csv`, guardado en `./code/matrix_multiplication/data/measurements/` de igual manera, los resultados de las multiplicaciones estaran en la carpeta `./code/matrix_multiplication/data/matrix_output`

### Scripts

Dentro de `./code/matrix_multiplication/scripts/`
* **Para generar las matrices:** Ejecutar el script generador (`matrix_generator.py`) para crear los archivos de texto `.txt
con las matrices de prueba en dominios D0 y D10.
* **Para los plots:** Ejecutar el script de graficos (`plot_generator.py`). Este script lee `salida_matrix.csv` y exporta las graficas correspondientes en `.png` dentro del directorio `data/plots/`.

## Ordenamiento de arreglo unidimensional

Algoritmos: MergeSort, QuickSort, PatienceSort, std::sort.

### Programa principal

El programa evalua el rendimiento de los algoritmos de ordenamiento de acuerdo a distintos dominios (D1, D7) y estados iniciales (aleatorio, ascendente, descendente)
en arreglos de tamaños $N {10, 10^3, 10^5, 10^7}$.
1. **1. Compilar:** Ubicarse en `./code/sorting/` y ejecutar el comando `make`.
2. **2. Ejecutar:** Antes de Correr el compilado generado `./sorting_comp`, generar los arreglos de prueba mediante el script array_generator.py (indicado en el siguiente punto).
3. **3. Salida:** El programa medira los tiempos en microsegundos y exportara los resultados en el archivo `salida_sort.csv`, guardado en `./code/sorting/data/measurements/`, ademas, los arreglos ordenados para cada caso pueden encontrarse en `./code/sorting/data/array_output`

### Scripts

Dentro de `./code/sorting/scripts/`
* **Para generar los arreglos:** Ejecutar el script generador (`array_generator.py`) para crear los arreglos de prueba con diferentes distribuciones
* **Para los plots:** Ejecutar el script de graficos (`plot_generator.py`). Este script lee `salida_sorting.csv` y exporta las graficas correspondientes en `.png` dentro del directorio `data/plots/`.

### Para compilar Latex:

Una vez ya con los plots creados en las respectivas carpetas para sorting y matrix multiplicaction, ubicarse en `./report/` en la terminal, ejecutar el codigo `pdflatex report.tex`, esperar a que compile todo, luego indicara que se corra el comando `biber report` (para incluir las bibliografias), luego compilamos dos veces mas con `pdflatex report.tex`, y el archivo `report.pdf` estará listo.