#ifndef VECTOR_TPP
#define VECTOR_TPP
#include "Vector.h"
#include <stdexcept>
#include "Matrix.h"
#include "Utils.h"
/* 
    Constructores
*/
template <typename T> Vector<T>::Vector(const std::vector<T>& data) : data(data) {
    // std::cout << "Initializing constant reference constructor\n";
}

// Constructor para crear un vector aleatorio
template <typename T> Vector<T>::Vector(size_t size, unsigned int lower_bound, unsigned int upper_bound) {
    data.resize(size);
    for (size_t i = 0; i < size; ++i) {
        data[i] = static_cast<T>(Utils::get_random_number(lower_bound, upper_bound));
    }
}

template <typename T> Vector<T>::Vector(std::vector<T>&& data) noexcept : data(std::move(data)) {
    // std::cout << "Initializing movement constructor\n";
}

template <typename T> Vector<T>::Vector(std::initializer_list<T> init) : data(init) {
    // std::cout << "Initializing list constructor\n";
}
template <typename T> Vector<T>::Vector(const Vector<T>& other, int number){
    data.resize(other.size());
    for(size_t i=0; i<other.size(); i++){
        data[i] = number;
    }
}
template <typename T> Vector<T>::Vector(size_t size){
    data.resize(size);
    for(size_t i=0; i<size; i++){
        data[i] = 0;
    }
}

/* 
    Otras funciones
*/
template <typename T> const std::vector<T>& Vector<T>::getData() const {
    return data;
}

template <typename T> T& Vector<T>::operator[](size_t index) {
    return data[index];
}

template <typename T> const T& Vector<T>::operator[](size_t index) const {
    return data[index];
}

template <typename T> size_t Vector<T>::size() const {
    return data.size();
}

template <typename T> void Vector<T>::resize(size_t newSize) {
    data.resize(newSize);
}

template <typename T> void Vector<T>::push_back(const T& value) {
    data.push_back(value);
}

template <typename T> void Vector<T>::push_back(T&& value) {
    data.push_back(std::move(value));
}

template <typename T> void Vector<T>::print() const {
    std::cout << "[";
    size_t size = data.size();
    for (size_t i = 0; i < size; ++i) {
        std::cout << data[i];
        if (i < size - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}

template <typename T> Vector<T> Vector<T>::operator+(const Vector<T>& other) const {
    if (data.size() != other.data.size()) {
        throw std::invalid_argument("Vectors must have the same size");
    }
    
    std::vector<T> result(data.size());
    for (size_t i = 0; i < data.size(); ++i) {
        result[i] = data[i] + other.data[i];
    }
    
    return Vector<T>(std::move(result));
}

template <typename T> template <typename U> auto Vector<T>::operator+(const Vector<U>& other) const {
    if (data.size() != other.getData().size()) {
        throw std::invalid_argument("Vectors must have the same size");
    }
    
    using ResultType = decltype(std::declval<T>() + std::declval<U>());
    std::vector<ResultType> result(data.size());
    
    for (size_t i = 0; i < data.size(); ++i) {
        result[i] = data[i] + other.getData()[i];
    }
    
    return Vector<ResultType>(std::move(result));
}

template <typename T> Vector<T>& Vector<T>::operator+=(const Vector<T>& other) {
    if (data.size() != other.data.size()) {
        throw std::invalid_argument("Vectors must have the same size");
    }
    
    for (size_t i = 0; i < data.size(); ++i) {
        data[i] += other.data[i];
    }            
    return *this;
}

template <typename T> template <typename U> auto Vector<T>::operator+=(const Vector<U>& other) {
    if (data.size() != other.getData().size()) {
        throw std::invalid_argument("Vectors must have the same size");
    }
    
    for (size_t i = 0; i < data.size(); ++i) {
        data[i] += other.getData()[i];
    }            
    return *this;
}

template <typename T> Vector<T> Vector<T>::operator-(const Vector<T>& other) const {
    if (data.size() != other.data.size()) {
        throw std::invalid_argument("Vectors must have the same size");
    }
    
    std::vector<T> result(data.size());
    for (size_t i = 0; i < data.size(); ++i) {
        result[i] = data[i] - other.data[i];
    }
    
    return Vector<T>(std::move(result));
}

template <typename T>  Vector<T> Vector<T>::operator*(const Matrix<T>& other) const{
    unsigned int matrix_rows = other.rows(); 
    unsigned int matrix_cols = other.cols(); 
    unsigned int vector_cols = data.size();    
    // Vector para el resultado
    std::vector<T> result(matrix_cols, 0); // Inicializa con ceros

    if (vector_cols != matrix_rows) {
        throw std::invalid_argument("Vector and matrix dimensions are incompatible for multiplication.");
    }
    for(size_t i = 0; i < matrix_cols; i++) {
        for(size_t j = 0; j < matrix_rows; j++) {
            result[i] += other[j][i] * data[j];                
        }
    }
    
    return Vector<T>(std::move(result)); 
}
template <typename T> template <typename U>Vector<T> Vector<T>::operator*(const Matrix<U>& other) const {
    size_t matrix_rows = other.rows();
    size_t matrix_cols = other.cols();
    size_t vector_cols = data.size();

    std::vector<T> result(matrix_cols, 0); // Vector para el resultado, del tipo del vector.

    if (vector_cols != matrix_rows) {
        throw std::invalid_argument("Vector and matrix dimensions are incompatible for multiplication.");
    }
    for (size_t i = 0; i < matrix_cols; i++) {
        for (size_t j = 0; j < matrix_rows; j++) {
            result[i] += static_cast<T>(other[j][i]) * static_cast<T>(data[j]);
        }
    }
    
    return Vector<T>(std::move(result));
}
template <typename T> template <typename U> auto Vector<T>::operator*(const Matrix<U>& other) const{
    std::cout<<"Overload 3\n";
    unsigned int matrix_rows = other.rows(); 
    unsigned int matrix_cols = other.cols(); 
    unsigned int vector_cols = data.size();    
    // Vector para el resultado
    std::vector<U> result(matrix_cols, 0); // Inicializa con ceros
    
    if (vector_cols != matrix_rows) {
        throw std::invalid_argument("Vector and matrix dimensions are incompatible for multiplication.");
    }
    for(size_t i = 0; i < matrix_cols; i++) {
        for(size_t j = 0; j < matrix_rows; j++) {
            result[i] += other[j][i] * data[j];                
        }

    }
    return Vector<U>(std::move(result)); 
}

/*
    Implementacion del operador escalar por vector
*/
template<typename T> Vector<T> operator*(const T& scalar, const Vector<T>& vec) {
    std::vector<T> result(vec.size());
    for(size_t i=0; i<vec.size(); i++) {
        result[i] = scalar * vec[i];
    }
    return Vector<T>(std::move(result));  // Asegúrate de que hay un punto y coma aquí
}
#endif