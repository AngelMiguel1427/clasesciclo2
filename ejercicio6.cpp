#include <iostream>
using namespace std;

struct Estudiante{
    string nombre;
    int edad;
    float promedio;
};

void MostrarEstudiante(const Estudiante* estudiante){
    cout << "Nombre: " << (*estudiante).nombre << endl;
    cout << "Edad: " << (*estudiante).edad << endl;
    cout << "Promedio: " << (*estudiante).promedio << endl;
}

void ModificarPromedio(Estudiante* estudiante, float nuevoPromedio){
    (*estudiante).promedio = nuevoPromedio;
}



bool Aprobo(const Estudiante* estudiante){
    return (*estudiante).promedio >= 6.0f;
}

int main (){
  
    Estudiante estudiante1 = {"Juan", 20, 7.5f};

    Estudiante *ptrEstudiante = &estudiante1;

    cout << "Datos del estudiante:" << endl;
    MostrarEstudiante(ptrEstudiante);

    ModificarPromedio(ptrEstudiante, 8.0f);
    cout << "Datos del estudiante despues de modificar el promedio:" << endl;
    MostrarEstudiante(ptrEstudiante);

    if (Aprobo(ptrEstudiante)) {
        cout << "El estudiante aprobo." << endl;
    } else {
        cout << "El estudiante no aprobo." << endl;
    }

    return 0;
}