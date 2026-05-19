#include <stdio.h>
#include <stdlib.h> 


// Funcion por Insercion directa 
int insercionDirecta(int ini, int n, int a []){
    // aux[i] guarda las asignaciones acumuladas al terminar la iteracion i del for
    int aux[n];
    int asignacion = 0; 

    for(int i = ini+1; i < n; i++){
        int x = a[i]; // Primera asignacion
        asignacion++; 
         
        int j = i-1;  
        while((j >= ini) && (a[j] > x)){
            a[j+1] = a[j]; // Segunda asignacion 
            asignacion++; 
            j = j-1; 
        }
        a[j+1] = x; // Tercera asignacion 
        asignacion++; 
        aux[i] = asignacion; // Guarda el acumulado al final de la iteracion i
    }

    printf("Iteracion | Asignaciones acumuladas\n"); 
    for(int i = ini+1; i < n; i++){
        printf(" i = %d | %d\n", i, aux[i]);
    }
    printf("Total de asignaciones: %d\n\n",asignacion);
}


int main (){
    /*
        TC1: El mejor de los casos  -> arreglo YA ordenado ascendente
             Solo ocurre la 1ra y 3ra asignacion por iteracion (while no entra)
             Asignaciones = 2*(n-1)

        TC2: El promedio de los casos -> arreglo en orden aleatorio
             El while entra parcialmente en cada iteracion

        TC3: El peor de los casos -> arreglo ordenado DESCENDENTE
             El while recorre todo en cada iteracion
             Asignaciones = 2*(n-1) + (1+2+...+(n-1)) = maximo posible
    */

    int n;
    scanf("%d", &n); 
    int arr[n]; 
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]); 
    insercionDirecta(0, n, arr); 
    
    return 0; 
}