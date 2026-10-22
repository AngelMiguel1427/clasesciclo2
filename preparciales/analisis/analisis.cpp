
#include <vector>

// Cuenta cuántos elementos del vector son mayores que target.
int CountGreater(const std::vector<int>& values, int target) {

    // Inicializa el contador en cero, ya que todavía
    // no se ha encontrado ningún elemento que cumpla la condición.
    int count = 0;

    // Obtiene el tamaño del vector y lo convierte a entero
    // para utilizarlo como límite del ciclo.
    int size = static_cast<int>(values.size());

    // Recorre todos los elementos del vector desde el índice 0.
    for (int i = 0; i < size; ++i) {

        // Comprueba si el elemento actual es mayor que target.
        if (values[i] > target) {

            // Si cumple la condición, aumenta el contador en uno.
            ++count;
        }
    }

    // Obtiene el último elemento del vector si tiene elementos.
    // Si el vector está vacío, asigna el valor 0.
    int last_value = size > 0 ? values[size - 1] : 0;

    // Comprueba nuevamente si el último valor es mayor que target.
    if (last_value > target) {

        // Si cumple la condición, vuelve a aumentar el contador.
        ++count;
    }

    // Devuelve la cantidad total encontrada.
    return count;
}


/*Responda:

a. Identifique tres operaciones o instrucciones cuyo costo no crece con el tamaño del vector.
    -int count = 0;
    -values.size()
    -int last_value = ... (un acceso a una posición del vector)
b. ¿Qué parte del código determina principalmente el crecimiento del tiempo de ejecución?
R // El ciclo for, porque se repite una vez por cada elemento del vector.

c. ¿Cuál es la complejidad temporal en notación Big-O? Justifique.
R // El ciclo hace n pasos y cada paso es rápido (O(1)). Lo que está fuera del ciclo se hace una sola vez, así que no cambia el resultado.

d. Si el tamaño del vector se duplica, ¿cómo cambia aproximadamente el trabajo realizado por el ciclo principal?
R// El trabajo del ciclo también se duplica (de n a 2n pasos).
*/
