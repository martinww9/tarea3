#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H
#include "functions.h"

PriorityQueue* create_pq();
void push(PriorityQueue *pq, Tarea tarea);
Tarea pop(PriorityQueue *pq);

#endif /* BINARY_HEAP_H */