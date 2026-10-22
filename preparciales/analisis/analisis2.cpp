
#include <vector>

// Cuenta cuántos pares de elementos tienen el mismo valor.
int CountPairs(const std::vector<int>& values) {

    // Inicializa el contador de pares encontrados.
    int count = 0;

    // Obtiene la cantidad de elementos del vector.
    int size = static_cast<int>(values.size());

    // El ciclo externo selecciona el primer elemento de cada par.
    for (int i = 0; i < size; ++i) {

        // El ciclo interno compara values[i] con los elementos
        // que están después de él para evitar comparar dos veces
        // el mismo par y para no comparar un elemento consigo mismo.
        for (int j = i + 1; j < size; ++j) {

            // Comprueba si los dos elementos del par son iguales.
            if (values[i] == values[j]) {

                // Si tienen el mismo valor, aumenta el contador.
                ++count;
            }
        }
    }

    // Devuelve la cantidad total de pares iguales encontrados.
    return count;
}

/*Responda:

a. ¿Qué función cumple cada uno de los dos ciclos?
Externo (i): escoge un elemento de referencia.
Interno (j): lo compara con todos los elementos que vienen después.

b. ¿Por qué analizar únicamente el ciclo externo no es suficiente para determinar la complejidad?
R // Porque dentro de cada vuelta del externo hay otro ciclo que también depende de n. 
Si solo se mira el externo, saldría O(n), y eso es incorrecto.

c. Exprese el número exacto de comparaciones entre elementos para un arreglo de tamaño \(n\).
R// (n - 1) + (n - 2) + ... + 1 + 0 = n(n - 1) / 2

d. Determine la complejidad temporal en notación Big-O y explique por qué.
R// n(n - 1)/2 es (n² - n)/2. En Big-O se quitan la constante y el término pequeño, y queda n².

e. Si el tamaño del arreglo se duplica, ¿cómo cambia aproximadamente el número de comparaciones para tamaños grandes?
R//Las comparaciones se multiplican por 4 aproximadamente (ejemplo: con n = 1000 hay 499 500 y con n = 2000 hay 1 999 000).

*/