#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H
#include "functions.h"

PriorityQueue* create_pq();
void push(PriorityQueue *pq, Tarea tarea);
Tarea pop(PriorityQueue *pq);
void intercambiar(Tarea *tarea1, Tarea *tarea2);

#endif /* BINARY_HEAP_H */