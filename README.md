# Tarea: Lista de tareas por hacer

Este es un programa de lista de tareas por hacer implementado en C. Permite agregar tareas, establecer precedencia entre ellas, mostrar las tareas por hacer y marcar tareas como completadas.

## (1)

## Compilación y ejecución

Para compilar y ejecutar el programa, sigue estos pasos:

1. Asegúrate de tener un compilador de C, como GCC, instalado.

2. Abre una terminal o línea de comandos y navega hasta el directorio donde se encuentra el archivo "programa.c".

3. Compila el programa utilizando los comandos.

4. Una vez que la compilación sea exitosa, ejecuta el programa.

Al ejecutarlo, se mostrará un menú con las siguientes opciones:

1. Agregar tarea
2. Establecer precedencia entre tareas
3. Mostrar tareas por hacer
4. Marcar tarea como completada
5. Salir

Para seleccionar una opción, ingresa el número correspondiente y presiona Enter.

5. Sigue las instrucciones que se muestran en pantalla para interactuar con el programa. Puedes agregar tareas, establecer precedencia entre ellas, ver las tareas por hacer y marcar tareas como completadas.

# Función agregarTarea
Esta función permite al usuario agregar una nueva tarea a la lista de tareas por hacer. Solicita al usuario ingresar el nombre y la prioridad de la tarea y la inserta en la cola de prioridad pq utilizando la función push.

# Función establecerPrecedencia
Esta función permite establecer una relación de precedencia entre dos tareas existentes en la lista. Solicita al usuario ingresar los nombres de las dos tareas y busca las tareas en la cola de prioridad pq. Si ambas tareas existen, establece la tarea 2 como precedente de la tarea 1, concatenando los nombres de las tareas precedentes en el campo precedentes de la tarea 2. Esta función es útil para establecer la dependencia entre tareas.

# Función mostrarTareas
Esta función muestra todas las tareas por hacer en orden de prioridad y precedencia. Crea una copia de la cola de prioridad original y la ordena en una nueva cola utilizando el algoritmo de ordenación por precedencia. Luego, imprime cada tarea en orden, mostrando su nombre, prioridad y, si tiene precedentes, los muestra también.

# Función tareaCompletada
Esta función permite al usuario marcar una tarea como completada. Solicita al usuario ingresar el nombre de la tarea a marcar. Busca la tarea en la cola de prioridad pq y, si se encuentra, elimina la tarea de la lista y actualiza las referencias de precedencia en las demás tareas para reflejar la tarea completada.

## (2) 
Todas las opciones funcionan correctamente

## (3) Coevaluación del trabajo en equipo (usando rúbrica):

Trabajo individual Martin Vasquez.

## (4) Coevaluación del aporte individual de cada integrante (usando rúbrica).

Trabajo individual Martin Vasquez.

## (5) Herramientras utilizadas en el desarrollo:

Replit: Utilicé el IDE online "Replit" como mi principal herramienta de trabajo. Replit me permitió escribir, compilar y ejecutar mi código de manera eficiente. También pude trabajar en mi proyecto de forma individual gracias a este.

GitHub: Utilicé GitHub para crear y almacenar mi repositorio. GitHub es una plataforma de alojamiento de código que me brindó un control de versiones efectivo y una forma de gestionar mi proyecto de manera organizada. Subí mi código a GitHub para mantener un registro de los cambios realizados, y asegurar la entrega de mi tarea.
