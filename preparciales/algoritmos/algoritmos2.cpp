/*## Ejercicio 3.2. Búsqueda binaria de la primera aparición

Se tiene un arreglo ordenado de forma descendente, que puede contener valores repetidos:
int values[] = {9, 7, 7, 7, 5, 3, 1};
El siguiente código implementa una búsqueda binaria para arreglos ordenados de forma descendente:
int BinarySearch(const int values[], int size, int target) {
  int left = 0;
  int right = size - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (values[mid] == target) {
      return mid;
    }

    if (values[mid] < target) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return -1;
}
Modifique el código para que retorne el índice de la primera aparición de `target`. Si el valor no existe, debe retornar `-1`.

Pruebas esperadas:

| Valor buscado | Resultado |
| --- | --- |
| `7` | `1` |
| `4` | `-1` |
| `9` | `0` |

Requisitos:

- Mantener la búsqueda binaria.
- Adaptar correctamente el algoritmo al orden descendente.
- Si encuentra el valor, no debe finalizar inmediatamente: debe continuar buscando si existe una aparición anterior.
- No ordenar el arreglo ni utilizar una búsqueda lineal.*/
#include <iostream>

// Busca la PRIMERA aparición de `target` en un arreglo ordenado de forma
// DESCENDENTE (de mayor a menor). Retorna su índice, o -1 si no existe.
int BinarySearch(const int values[], int size, int target) {
  int left = 0;           // Límite izquierdo del rango de búsqueda.
  int right = size - 1;   // Límite derecho del rango de búsqueda.
  int result = -1;        // Mejor candidato encontrado hasta ahora.
                          // Si nunca hay coincidencia, se queda en -1.

  // Mientras el rango [left, right] tenga al menos un elemento.
  while (left <= right) {
    // Punto medio. Se escribe así (y no (left + right) / 2)
    // para evitar un posible desbordamiento de int.
    int mid = left + (right - left) / 2;

    if (values[mid] == target) {
      // Coincidencia: la guardamos como candidato, pero NO terminamos,
      // porque podría haber otra aparición más a la izquierda.
      result = mid;

      // Seguimos buscando solo en la mitad izquierda, ya que una
      // aparición anterior tendría un índice menor que mid.
      right = mid - 1;
    } else if (values[mid] < target) {
      // Orden descendente: si el elemento del medio es MENOR que el
      // objetivo, el objetivo (si existe) está hacia la IZQUIERDA,
      // donde están los valores más grandes.
      right = mid - 1;
    } else {
      // values[mid] > target: el elemento del medio es MAYOR que el
      // objetivo, así que el objetivo (si existe) está hacia la
      // DERECHA, donde están los valores más pequeños.
      left = mid + 1;
    }
  }

  // Si hubo coincidencias, result guarda la más a la izquierda,
  // porque cada vez que apareció una nueva se sobrescribió con un
  // índice menor.
  return result;
}

int main() {
  int values[] = {9, 7, 7, 7, 5, 3, 1};  // Orden descendente, con repetidos.
  int size = 7;

  // Pruebas esperadas: 7 -> 1, 4 -> -1, 9 -> 0.
  std::cout << "Buscar 7: " << BinarySearch(values, size, 7) << "\n";
  std::cout << "Buscar 4: " << BinarySearch(values, size, 4) << "\n";
  std::cout << "Buscar 9: " << BinarySearch(values, size, 9) << "\n";

  return 0;
}