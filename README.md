# Busqueda-exhaustiva
Actividad 2.6: Problema práctico en OpenMP.
Integrantes: Rubio Calderon Gererdo Josue, Gutiérrez Hurtado Argenis Adán

## Descripción de la solución
Proyecto académico en C++ diseñado para realizar una búsqueda exhaustiva (fuerza bruta) sobre un espacio de claves generado dinámicamente. Implementa una arquitectura orientada a objetos (`BuscadorClaves`) que permite comparar la ejecución en un entorno **secuencial** contra uno **paralelo**, distribuyendo el espacio de trabajo equitativamente entre múltiples hilos para medir y comparar el rendimiento (*Speedup*).

## Caracteres utilizados
El espacio de búsqueda utiliza un alfabeto de **36 caracteres** (Base 36):
* **Mayúsculas:** A-Z (26 caracteres)
* **Números:** 0-9 (10 caracteres)

## Algoritmos implementados
* **Mapeo Numérico a Combinación (`numACombinacion`):** Convierte una posición numérica (`unsigned long long`) a su representación equivalente en cadena mediante la conversión de base 10 a base 36, evitando la generación simultánea de combinaciones en memoria.
* **Búsqueda Secuencial (`busquedaSecuencial`):** Recorre el espacio de búsqueda elemento por elemento desde el origen hasta encontrar la clave.
* **Búsqueda Paralela con Parada Temprana (`busquedaParalela`):** Divide el rango de búsqueda total de forma equitativa entre los hilos asignados. Implementa mecanismos de sincronización para detener el trabajo de todos los hilos en el momento en que uno de ellos encuentra la coincidencia.

## Directivas OpenMP utilizadas
* `#pragma omp parallel`: Crea la región paralela e inicializa el equipo de hilos.
* `#pragma omp critical`: Protege la sección donde se registra el hilo ganador y la clave encontrada, evitando condiciones de carrera (*race conditions*).
* `#pragma omp flush`: Forzó la actualización inmediata de la memoria principal para la variable compartida `encontradaGlobal`, permitiendo la notificación rápida de parada.
* `#pragma omp ordered`: Garantiza la impresión ordenada y secuencial de las salidas por pantalla sin interrumpir la ejecución paralela de los cálculos.
* `omp_get_wtime()`: Mide de forma precisa el tiempo de ejecución secuencial y paralelo.
* `omp_get_thread_num()`: Obtiene el identificador único de cada hilo.

## Instrucciones básicas de compilación y ejecución

### Requisitos previos
* Compilador de C++ con soporte para OpenMP (`g++`).

### Compilando el proyecto
Abre tu terminal en la carpeta del proyecto y ejecuta:

```bash
g++ -fopenmp main.cpp BuscadorClaves.cpp -o BuscadorClaves