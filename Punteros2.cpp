/*Modificar una estructura mediante un puntero: Se define un struct Producto con precio y cantidad ; una funcion recibe el un puntero al producto y calcula 
el precio total, modificando el precio si la cantidad supera cierto limite*/
#include <iostream>
using namespace std;

struct Producto{
    float precio;
    int cantidad;
};

void calcularPrecioTotal(Producto* p) {
    if (p->cantidad > 10) {
        p->precio *= 0.9; // Aplicar un descuento del 10%
    }
    float precioTotal = p->precio * p->cantidad;
    cout << "Precio total: " << precioTotal << endl;
}



int main (){
    Producto producto = {100.0, 15};
    cout << "Precio unitario: " << producto.precio << ", Cantidad: " << producto.cantidad << endl;
    
    calcularPrecioTotal(&producto);
    return 0;
}


