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

void mostrarTareas(PriorityQueue *pq) {
    printf("Tareas por hacer, ordenadas por prioridad y precedencia:\n");

    // Crear una copia de la cola original
    PriorityQueue *pq_copia = create_pq();
    for (int i = 0; i < pq->tamano; i++) {
        Tarea tarea = pq->datos[i];
        push(pq_copia, tarea);
    }

    // Ordenar las tareas según sus precedentes
    PriorityQueue *pq_ordenada = create_pq();
    while (!esVacia(pq_copia)) {
        bool seMovioTarea = false;

        for (int i = 0; i < pq_copia->tamano; i++) {
            Tarea tarea = pq_copia->datos[i];

            if (strlen(tarea.precedentes) == 0) {
                // Insertar tareas sin precedentes en la cola ordenada
                push(pq_ordenada, tarea);
                eliminarTarea(pq_copia, i);
                seMovioTarea = true;
                break;
            }

            bool todosPrecedentesEnCola = true;
            char precedentes[MAX_TAREA];
            strcpy(precedentes, tarea.precedentes);
            char *precedente = strtok(precedentes, " ");
            while (precedente != NULL) {
                Tarea *tareaPrecedente = buscarTarea(pq_ordenada, precedente);
                if (tareaPrecedente == NULL) {
                    todosPrecedentesEnCola = false;
                    break;
                }
                precedente = strtok(NULL, " ");
            }

            if (todosPrecedentesEnCola) {
                // Insertar tareas con todos los precedentes en la cola ordenada
                push(pq_ordenada, tarea);
                eliminarTarea(pq_copia, i);
                seMovioTarea = true;
                break;
            }
        }

        if (!seMovioTarea) {
            printf("Error: las tareas contienen ciclos de precedencia.\n");
            break;
        }
    }

    // Mostrar las tareas ordenadas
    for (int i = 0; i < pq_ordenada->tamano; i++) {
        Tarea tarea = pq_ordenada->datos[i];
        printf("%d. %s (Prioridad: %d)", i + 1, tarea.nombre, tarea.prioridad);
        if (strlen(tarea.precedentes) > 0) {
            printf(" - Precedente: %s", tarea.precedentes);
        }
        printf("\n");
    }

    // Liberar la memoria de las colas auxiliares
    free(pq_copia);
    free(pq_ordenada);
}

int esVacia(PriorityQueue *pq) {
    return pq->tamano == 0;
}

void eliminarTarea(PriorityQueue *pq, int index) {
    if (index < 0 || index >= pq->tamano) {
        printf("Error: Índice fuera de rango.\n");
        return;
    }

    // Mover las tareas restantes hacia la izquierda para llenar el espacio de la tarea eliminada
    for (int i = index; i < pq->tamano - 1; i++) {
        pq->datos[i] = pq->datos[i+1];
    }
    pq->tamano--;
}

// Función auxiliar para buscar una tarea por nombre en la cola
Tarea* buscarTarea(PriorityQueue *pq, const char *nombre) {
    for (int i = 0; i < pq->tamano; i++) {
        if (strcmp(nombre, pq->datos[i].nombre) == 0) {
            return &pq->datos[i];
        }
    }
    return NULL;
}