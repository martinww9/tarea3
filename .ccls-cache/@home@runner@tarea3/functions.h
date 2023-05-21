#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define MAX_TAREA 50

typedef struct {
    char nombre[MAX_TAREA];
    int prioridad;
    char precedentes[MAX_TAREA];
} Tarea;

typedef struct {
    Tarea *datos;
    int tamano;
    int capacidad;
} PriorityQueue;

void agregarTarea(PriorityQueue *pq);
void establecerPrecedencia(PriorityQueue *pq);
void mostrarTareas(PriorityQueue *pq);
void tareaCompletada(PriorityQueue *pq);
int esVacia(PriorityQueue *pq);
void eliminarTarea(PriorityQueue *pq, int index);
Tarea* buscarTarea(PriorityQueue *pq, const char *nombre);
void tareaCompletada(PriorityQueue *pq);

#endif /* FUNCTIONS_H */