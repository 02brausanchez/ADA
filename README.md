# ADA
UEA de Análisis de algoritmos 
### 1. Librerías (Cabeceras) utilizadas

| Librería | Propósito Principal en el Código | Elementos que aporta |
| :--- | :--- | :--- |
| `<stdio.h>` | Entrada y salida estándar. Permite interactuar con la terminal. | `printf()`, `scanf()`, `getchar()` |
| `<stdlib.h>` | Funciones de utilidad estándar, incluyendo la **gestión de memoria dinámica**. | `malloc()`, `free()` |
| `<time.h>` | Manipulación y medición del tiempo del procesador. | `clock()`, `CLOCKS_PER_SEC` |
| `<stdint.h>` | Define tipos de enteros con anchos exactos garantizados sin importar la arquitectura de la PC. | `uint64_t` |
| `<inttypes.h>` | Proporciona macros para usar funciones de formato (`printf`/`scanf`) con los tipos definidos en `stdint.h`. | `PRIu64`, `SCNu64` |

### 2. Tipos de Datos aplicados

| Tipo de Dato | Tamaño en Memoria | Descripción y Uso en este Código |
| :--- | :--- | :--- |
| `uint64_t` | 8 bytes (64 bits) | **Entero sin signo**. Almacena desde 0 hasta $\approx 1.8 \times 10^{19}$. Se usó para `num`, `suma` e iteradores para evitar el desbordamiento (*overflow*) matemático. |
| `double` | 8 bytes (64 bits) | **Punto flotante de doble precisión**. Se usó para guardar el cálculo exacto de segundos (`tiempo_bruta`) y Megabytes (`memoria_bruta_mb`). |
| `long` | 4 u 8 bytes (depende del OS) | **Entero largo**. Se usó para el cálculo teórico de los bytes de las variables locales (`memoria_optimizada`). |
| `clock_t` | Variable | **Tipo aritmético**. Representa los "latidos" (ticks) del reloj de la CPU. Usado en las variables `inicio` y `fin`. |
| `uint64_t *` | 8 bytes | **Puntero de 64 bits**. Guarda una *dirección de memoria*, no un valor directo. Se usó en `*aux` para apuntar al inicio del bloque gigante de memoria RAM pedido por `malloc`. |

### 3. Funciones y Macros fundamentales

| Función / Macro | Concepto / Acción | Por qué es importante aquí |
| :--- | :--- | :--- |
| `malloc(tamaño)` | Asignación Dinámica (*Memory Allocation*). | Pide espacio continuo en el **Heap** (la zona de memoria para datos grandes). Vital para arreglos cuyo tamaño decide el usuario en tiempo de ejecución. |
| `free(puntero)` | Liberación de Memoria. | Devuelve la RAM al sistema operativo. Si lo olvidas, creas una "fuga de memoria" (*memory leak*) que puede trabar la PC. |
| `clock()` | Cronómetro del procesador. | Mide cuánto esfuerzo de CPU se usó, permitiendo hacer el benchmark (comparación de tiempo) entre los dos algoritmos. |
| `%" SCNu64 "` | Macro de Escaneo (Scan Unsigned 64). | Se pone dentro del `scanf` para asegurar que el sistema lea correctamente un número gigante ingresado por el usuario. |
| `%" PRIu64 "` | Macro de Impresión (Print Unsigned 64). | Se pone dentro del `printf` para mostrar en pantalla los valores calculados de 64 bits sin que se trunquen o muestren basura. |
