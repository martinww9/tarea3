#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "binary_heap.h"
#include "functions.h"
#define MAX_TAREA 50

void agregarTarea(PriorityQueue *pq) {
    Tarea tarea;
    printf("Ingrese el nombre de la tarea: ");
    scanf("%s", tarea.nombre);
    printf("Ingrese la prioridad de la tarea: ");
    scanf("%d", &tarea.prioridad);
    tarea.precedentes[0] = '\0'; // Inicializar el campo de precedentes como una cadena vacía
    push(pq, tarea);
    }