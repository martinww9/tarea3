#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "binary_heap.h"
#include "functions.h"
#define MAX_TAREA 50

PriorityQueue* create_pq() {
    PriorityQueue* pq = malloc(sizeof(PriorityQueue));
    if (pq == NULL) {
        printf("Error: no se pudo asignar memoria para la priority queue.\n");
        exit(1);
    }
    int capacidad = 10;
    pq->datos = malloc(capacidad * sizeof(Tarea));
    pq->tamano = 0;
    pq->capacidad = capacidad;
    return pq;
}

void push(PriorityQueue *pq, Tarea tarea) {
    if (pq->tamano == pq->capacidad) {
        printf("Error: priority queue llena\n");
        return;
    }
    pq->datos[pq->tamano] = tarea;
    pq->tamano++;
    int pos = pq->tamano - 1;
    while (pos > 0 && pq->datos[pos].prioridad < pq->datos[(pos-1)/2].prioridad) {
        // Intercambiar la tarea con su padre
        Tarea temp = pq->datos[pos];
        pq->datos[pos] = pq->datos[(pos-1)/2];
        pq->datos[(pos-1)/2] = temp;
        // Actualizar la posición
        pos = (pos-1)/2;
    }
  }

Tarea pop(PriorityQueue *pq) {
    // Obtener la tarea de mayor prioridad
    Tarea tarea = pq->datos[0];

    // Reemplazar la tarea de mayor prioridad por la última tarea
    pq->datos[0] = pq->datos[pq->tamano - 1];
    pq->tamano--;

    // Reordenar el árbol para mantener la propiedad de heap
    int padre = 0;
    int hijo_izq = 2 * padre + 1;
    int hijo_der = 2 * padre + 2;

    while ((hijo_izq < pq->tamano && pq->datos[hijo_izq].prioridad < pq->datos[padre].prioridad) ||
           (hijo_der < pq->tamano && pq->datos[hijo_der].prioridad < pq->datos[padre].prioridad)) {

        if (hijo_der >= pq->tamano || pq->datos[hijo_izq].prioridad < pq->datos[hijo_der].prioridad) {
            // El hijo izquierdo tiene una prioridad menor
            intercambiar(&pq->datos[padre], &pq->datos[hijo_izq]);
            padre = hijo_izq;
        } else {
            // El hijo derecho tiene una prioridad menor o igual
            intercambiar(&pq->datos[padre], &pq->datos[hijo_der]);
            padre = hijo_der;
        }

        hijo_izq = 2 * padre + 1;
        hijo_der = 2 * padre + 2;
    }

    return tarea;
}

void intercambiar(Tarea *tarea1, Tarea *tarea2) {
    Tarea temporal = *tarea1;
    *tarea1 = *tarea2;
    *tarea2 = temporal;
}