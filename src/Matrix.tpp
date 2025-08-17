#ifndef MATRIX_CPP
#define MATRIX_CPP
#include "Matrix.h"
#include "Vector.h"

/*
    Definicion de constructores
*/
template <typename T> Matrix<T>::Matrix(const std::vector<std::vector<T>>& data) : data(data){
    // Code goes here    
}


// Constructor para inicializar la matriz con una lista de valores
template <typename T> Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> init){
    for (const auto& row : init) {
        data.emplace_back(row); // Usar emplace_back para construir cada fila
    }
}

// Constructor para inicializar una matriz aleatoria 
template <typename T> Matrix<T>::Matrix(size_t rows, size_t cols, unsigned int upper_bound) {
    data.resize(rows, std::vector<T>(cols)); // Inicializar la matriz con tamaño rows x cols
    std::srand(std::time(0)); // Inicializar la semilla para números aleatorios
    for (size_t i = 0; i < rows; ++i) { 
        for (size_t j = 0; j < cols; ++j) {
            data[i][j] = std::rand() % upper_bound; // Valores aleatorios entre 0 y 99
        }
    }
}
// Construtor para inicializar una matriz de ceros de tamano mxn
template <typename T> Matrix<T>::Matrix(size_t rows, size_t cols){
    data.resize(rows, std::vector<T>(cols)); // Inicializar la matriz con tamaño rows x cols
    for(size_t i = 0; i < rows; i++){
        for(size_t j=0; j < cols; j++){
            data[i][j] = 0;
        }
    }
}
/*
    Funciones personalizadas necesarias
*/

template <typename T>const std::vector<T>& Matrix<T>::operator[](size_t index) const {
    return data[index];
}

template <typename T>std::vector<T>& Matrix<T>::operator[](size_t index) {
    return data[index];
}

/*
    Funciones utiles
*/
template <typename T> void Matrix<T>::print() const{
    size_t tmp_cols = cols();
    for(size_t i=0; i<rows(); i++){
        std::cout<<"[";
        for(size_t j=0; j<tmp_cols; j++){
            std::cout<<data[i][j];
            if (j < tmp_cols - 1) {
                std::cout << ", ";
            }
        } 
        std::cout<<"]\n";
    }
}

/*
    Definicion de constructores
*/


template <typename T> void Matrix<T>::transpose_matrix() {
    // Solo funciona para matrices cuadradas
    if (rows() != cols()) {
        // Implementación con matriz temporal para matrices no cuadradas
        std::vector<std::vector<T>> transposed(cols(), std::vector<T>(rows()));
        for (size_t i = 0; i < rows(); i++) {
            for (size_t j = 0; j < cols(); j++) {
                transposed[j][i] = data[i][j];
            }
        }
        data = std::move(transposed);
        return;
    }
    
    // Transpuesta in-place para matrices cuadradas
    for (size_t i = 0; i < rows(); i++) {
        for (size_t j = i + 1; j < cols(); j++) {
            std::swap(data[i][j], data[j][i]);
        }
    }
}
template <typename T> Vector<T> Matrix<T>::get_column(size_t index) const{
    if(cols() < index){
        throw std::invalid_argument("La matrix no cuenta con las columnas necesarias");
    }
    Vector<T> x_cols(rows()); 
    for(size_t i= 0; i < rows(); i++){
        x_cols[i] = data[i][index];
    }
    return Vector<T>(std::move(x_cols));
}
#endif