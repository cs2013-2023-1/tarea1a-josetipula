#include "foo.h"

Matriz2D::Matriz2D():filas(3),columnas(3){
    // Constructor por defecto
    ptr = new float*[3];
    for (int i = 0; i < 3; i++) {
        ptr[i] = new float[3];
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ptr[i][j] = static_cast<double>(rand())/RAND_MAX;
        }
    }
}

Matriz2D::Matriz2D(int n):filas(n),columnas(n){
    // Constructor con un parametro
    ptr = new float*[n];
    for (int i = 0; i < n; i++) {
        ptr[i] = new float[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ptr[i][j] = static_cast<double>(rand())/RAND_MAX;
        }
    }

}

Matriz2D::Matriz2D(int n, int m):filas(n),columnas(m){
    // Constructor con dos parametros
    ptr = new float*[n];
    for (int i = 0; i < n; i++) {
        ptr[i] = new float[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ptr[i][j] = static_cast<double>(rand())/RAND_MAX;
        }
    }
}

Matriz2D::Matriz2D(const Matriz2D& m){
    // Constructor de copia
    this->filas= m.filas;
    this->columnas= m.columnas;
    ptr = new float*[filas];
    for(int i = 0; i < filas; i++){
        ptr[i] = new float[columnas];
    }
    for (int i = 0; i < m.filas; i++) {
        for (int j = 0; j < m.columnas; j++) {
            this->ptr[i][j] = m.ptr[i][j];
        }
    }
}

Matriz2D::Matriz2D(Matriz2D&& m) {
    // Constructor de movimiento
    ptr = new float*[filas];
    for(int i = 0; i < filas; i++){
        ptr[i] = new float[columnas];
    }

    this->filas = filas;
    this->columnas = columnas;
    ptr=m.ptr;
    m.ptr= nullptr;
}

Matriz2D t(Matriz2D& m){
    // Transpuesta de una matriz
    Matriz2D transpuesta(m.columnas, m.filas);
    for (int i = 0; i < m.columnas; i++) {
        for (int j = 0; j < m.filas; j++) {
            transpuesta.ptr[i][j] = m.ptr[j][i];
        }
    }
    return transpuesta;
}

std::ostream& operator<<(std::ostream& os, const Matriz2D& m){
    // Sobrecarga del operador <<
    for(int i = 0; i < m.filas; i++){
        for(int j = 0; j < m.columnas; j++){
            os << m.ptr[i][j] << " ";
        }
        os << endl;
    }
}

Matriz2D operator+(const Matriz2D& m1, const Matriz2D& m2) {
    // Sobrecarga del operador +
    Matriz2D Suma(m2.filas, m2.columnas);
    for (int i = 0; i < m2.filas; i++) {
        for (int j = 0; j < m2.columnas; j++) {
            Suma.ptr[i][j] = m1.ptr[i][j] + m2.ptr[i][j];
        }
    }
    return Suma;
}

Matriz2D operator-(const Matriz2D& m1, const Matriz2D& m2) {
    // Sobrecarga del operador -
    Matriz2D Resta(m2.filas, m2.columnas);
    for (int i = 0; i < m2.filas; i++) {
        for (int j = 0; j < m2.columnas; j++) {
            Resta.ptr[i][j] = m1.ptr[i][j] - m2.ptr[i][j];
        }
    }
    return Resta;
}

Matriz2D operator*(const Matriz2D& m1, const Matriz2D& m2) {
    // Sobrecarga del operador *
    Matriz2D Suma(m2.filas, m2.columnas);
    for (int i = 0; i < m2.filas; i++) {
        for (int j = 0; j < m2.columnas; j++) {
            Suma.ptr[i][j] = m1.ptr[i][j] * m2.ptr[i][j];
        }
    }
    return Suma;
}

    Matriz2D operator+(const Matriz2D &m, float n) {
        // Sobrecarga del operador +
        Matriz2D Suma2(m.filas, m.columnas);
        for (int i = 0; i < m.filas; i++) {
            for (int j = 0; j < m.columnas; j++) {
                Suma2.ptr[i][j] = m.ptr[i][j] + n;
            }
        }
        return Suma2;
    }

    Matriz2D operator-(const Matriz2D &m, float n) {
        // Sobrecarga del operador -
        Matriz2D Resta2(m.filas, m.columnas);
        for (int i = 0; i < m.filas; i++) {
            for (int j = 0; j < m.columnas; j++) {
                Resta2.ptr[i][j] = m.ptr[i][j] - n;
            }
        }
        return Resta2;
    }

Matriz2D operator*(const Matriz2D& m, float n){
    // Sobrecarga del operador *
    Matriz2D Multi2(m.filas, m.columnas);
    for (int i = 0; i < m.filas; i++) {
        for (int j = 0; j < m.columnas; j++) {
            Multi2.ptr[i][j] = m.ptr[i][j] * n;
        }
    }
    return Multi2;
}

Matriz2D operator/(const Matriz2D& m, float n){
    // Sobrecarga del operador /
    Matriz2D Divi2(m.filas, m.columnas);
    for (int i = 0; i < m.filas; i++) {
        for (int j = 0; j < m.columnas; j++) {
            Divi2.ptr[i][j] = m.ptr[i][j] / n;
        }
    }
    return Divi2;
}

float Matriz2D::get(int i, int j){
    return ptr[i][j];
}

int Matriz2D::getFilas(){
    return filas;
}

int Matriz2D::getColumnas(){
    return columnas;
}