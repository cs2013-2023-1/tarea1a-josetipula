// =============================================================================
// Tarea 1a: Matrices Dinamicas, Constructores y Sobrecarga de Operadores
// =============================================================================
// 1. Utilizar unicamente los archivos de cabecera y codigo fuente provistos. Es
//    decir: main.cpp, foo.h y foo.cpp.
// 2. No se permite el uso de librerias adicionales.

#include "foo.h"
// Puede validar su codigo con la siguiente funcion main
int main(){
    Matriz2D m1;            // Matriz cuadrada de 3x3
    Matriz2D m2(5);         // Matriz cuadrada de 5x5
    Matriz2D m3(5,2);
    Matriz2D m4 = m2;
    Matriz2D m5 = move(m2);

    Matriz2D m8 = m3 - 1.2;
    Matriz2D m9 = m3 * 5;
    Matriz2D m10 = m3 / 7;
    cout << m3;
    std::srand(time(nullptr));
}