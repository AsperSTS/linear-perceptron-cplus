#ifndef MATRIX_H
#define MATRIX_H
#include<vector>
#include<iostream>
#include <ctime>
// #include<cstddef>
template <typename T> class Matrix{
    private:
        std::vector<std::vector<T>> data;
    public:
        // Constructor que recibe una referencia constante 
        Matrix(const std::vector<std::vector<T>>& data);
        // Constructor para cuando no necesitamos la matrix original
        Matrix(const std::vector<std::vector<T>>&& data) noexcept : data(std::move(data)){}
        // Si se desea permitir la inicialización del Vector1 con una lista de valores
         
        Matrix(std::initializer_list<std::initializer_list<T>> init);
        // Constructor para crear una matriz de tamaño rows x cols con valores aleatorios entre 0 y upper_bound
        Matrix(size_t rows, size_t cols, unsigned int upper_bound);

        // Matrix duplicate_matrix(const Matrix& mat) const{
        //     return Matrix(mat.data);
        // }

        /*
            Funciones personalizadas obligatorias    
        */
        const std::vector<T>& operator[](size_t index) const;
        std::vector<T>& operator[](size_t index);
        /*
            Metodos utiles
        */
        size_t rows() const {
            return data.size();
        }

        size_t cols() const {
            return data[0].size();
        }
        void print() const;
        // Métodos para acceder al número de filas, columnas y elementos
        
        /* 
            Funciones que nos sirven para el perceptron
        */
        void transpose_matrix();
};  
#include "Matrix.cpp"
#endif 