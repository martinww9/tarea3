 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_TAREA 50

int main(void) {
    PriorityQueue* pq = create_pq();

    int opcion;
    do {
        printf("\n----- Menu de Tareas por Hacer -----\n");
        printf("1. Agregar tarea\n");
        printf("2. Establecer precedencia entre tareas\n");
        printf("3. Mostrar tareas por hacer\n");
        printf("4. Marcar tarea como completada\n");
        printf("5. Salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                // Código para agregar tarea
              agregarTarea(pq);
                break;
            case 2:
                // Código para establecer precedencia
              establecerPrecedencia(pq);
                break;
            case 3:
                // Código para mostrar tareas por hacer
              mostrarTareas(pq);
                break;
            case 4:
                // Código para marcar tarea como completada
              tareaCompletada(pq);
                break;
            case 5:
                printf("Saliendo de la aplicacion...\n");
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
                break;
        }

    } while(opcion != 5);

   return 0;
}

 