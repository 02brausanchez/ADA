#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>   // Para uint64_t
#include <inttypes.h> // Para macros PRIu64 (imprimir) y SCNu64 (escanear)

// Algoritmo 1: O(n) en tiempo y O(n) en espacio
uint64_t algoritmo_fuerza_bruta(uint64_t num) {
    uint64_t contador = 0;
    
    // Asignamos memoria en el Heap asegurando que el tamaño sea uint64_t
    uint64_t *aux = (uint64_t *)malloc(num * sizeof(uint64_t));
    if (aux == NULL) {
        printf("Error: Memoria insuficiente en el Heap.\n");
        return 0; 
    }

    for (uint64_t i = 1; i < num; i++) {
        if (num % i == 0) {
            aux[contador++] = i;
        }
    }

    uint64_t suma = 0;
    for (uint64_t i = 0; i < contador; i++) {
        suma += aux[i];
    }

    free(aux); // Liberamos la memoria para evitar fugas
    return suma;
}

// Algoritmo 2: O(sqrt(n)) en tiempo y O(1) en espacio
uint64_t algoritmo_optimizado(uint64_t num) {
    uint64_t suma = 1; // 1 siempre es divisor
    
    for (uint64_t i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            suma += i;
            if (i != (num / i)) {
                suma += (num / i); // Sumamos el divisor par correspondiente
            }
        }
    }
    return suma;
}

int main() {
    uint64_t num;
    
    printf("--- Benchmarking de Algoritmos (Suma de divisores) ---\n");
    printf("Ingresa el numero a evaluar: ");
    
    // Usamos SCNu64 para escanear un número de 64 bits de forma segura
    if (scanf("%" SCNu64, &num) != 1 || num <= 1) {
        printf("Por favor, ingresa un numero entero mayor a 1.\n");
        return 1;
    }

    // Calculamos la memoria requerida teóricamente
    double memoria_bruta_mb = (double)(num * sizeof(uint64_t)) / (1024 * 1024);
    long memoria_optimizada = 3 * sizeof(uint64_t); // num, suma, i

    printf("\n[Memoria Asignada por cada ejecucion]\n");
    printf("Algoritmo 1 (Fuerza Bruta): ~%.2f MB asignados dinamicamente.\n", memoria_bruta_mb);
    printf("Algoritmo 2 (Optimizado): ~%ld bytes (solo variables locales).\n", memoria_optimizada);

    printf("\n[Ejecutando pruebas de tiempo para una sola ejecucion...]\n");

    clock_t inicio, fin;
    double tiempo_bruta = 0.0, tiempo_optimizado = 0.0;
    uint64_t suma_real = 0;

    // --- PRUEBA ALGORITMO 1 ---
    // Candado de seguridad: Evitamos fuerza bruta si requiere más de 1 GB de RAM (~134 millones de iteraciones)
    if (num > 134217728ULL) {
        printf("\n[ADVERTENCIA] Saltando Algoritmo 1: Requiere demasiada memoria y colapsaria el sistema.\n");
    } else {
        inicio = clock();
        algoritmo_fuerza_bruta(num);
        fin = clock();
        tiempo_bruta = ((double)(fin - inicio)) / CLOCKS_PER_SEC;
    }

    // --- PRUEBA ALGORITMO 2 ---
    inicio = clock();
    suma_real = algoritmo_optimizado(num);
    fin = clock();
    tiempo_optimizado = ((double)(fin - inicio)) / CLOCKS_PER_SEC;

    // --- RESULTADOS ---
    printf("\n=== RESULTADOS ===\n");
    if (suma_real < num) {
        printf("El numero %" PRIu64 " es DEFICIENTE (Suma de divisores: %" PRIu64 ")\n\n", num, suma_real);
    } else {
        printf("El numero %" PRIu64 " NO es deficiente (Suma de divisores: %" PRIu64 ")\n\n", num, suma_real);
    }

    if (num <= 134217728ULL) {
        printf("Tiempo Algoritmo 1 (Fuerza Bruta): %f segundos.\n", tiempo_bruta);
    }
    printf("Tiempo Algoritmo 2 (Optimizado)  : %f segundos.\n", tiempo_optimizado);
    
    // Solo calculamos el multiplicador si ambos algoritmos se ejecutaron y el tiempo optimizado no es 0
    if (num <= 134217728ULL && tiempo_optimizado > 0) {
        printf("\nEl Algoritmo 2 fue %.2fx mas rapido en esta prueba.\n", tiempo_bruta / tiempo_optimizado);
    }

    // Limpieza del búfer de entrada
    while (getchar() != '\n'); 
    printf("\nPresiona Enter para salir...");
    getchar(); 

    return 0;
}