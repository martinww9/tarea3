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

void establecerPrecedencia(PriorityQueue *pq) {
    char nombreTarea1[MAX_TAREA], nombreTarea2[MAX_TAREA];
    printf("Ingrese el nombre de la primera tarea: ");
    scanf("%s", nombreTarea1);
    printf("Ingrese el nombre de la segunda tarea: ");
    scanf("%s", nombreTarea2);

    // Buscar las tareas en la priority queue
    Tarea *tarea1 = NULL, *tarea2 = NULL;
    for (int i = 0; i < pq->tamano; i++) {
        if (strcmp(nombreTarea1, pq->datos[i].nombre) == 0) {
            tarea1 = &pq->datos[i];
        } else if (strcmp(nombreTarea2, pq->datos[i].nombre) == 0) {
            tarea2 = &pq->datos[i];
        }
    }

    // Verificar que las tareas existan
    if (tarea1 == NULL || tarea2 == NULL) {
        printf("Error: una o ambas tareas no existen.\n");
        return;
    }

    // Establecer la precedencia de tarea2 con respecto a tarea1
    char precedente[MAX_TAREA];
    strcpy(precedente, tarea1->nombre);
    strcat(precedente, " ");
    strcat(precedente, tarea2->precedentes);
    strcpy(tarea2->precedentes, precedente);

    printf("Se establecio que la tarea '%s' debe realizarse antes que la tarea '%s'.\n", tarea1->nombre, tarea2->nombre);
}