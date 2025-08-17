#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <iostream>
#include <ctime>
#include <random>


template <typename T> class Matrix;

class Utils;

template <typename T> class Vector {
    private:
        std::vector<T> data;
    public:
        // Constructors
        Vector() : data() {}
        Vector(const std::vector<T>&); // Constructor que inicializa la clase con un vector que pasa como referencia constante
        Vector(size_t size, unsigned int, unsigned int); // Constructor para crear un vector aleatorio
        Vector(std::vector<T>&& data) noexcept; // Vector ??
        Vector(std::initializer_list<T> init); // Constructor que inicializa un vector con una lista de datos
        Vector(const Vector<T>& data, int number); // Constructor que inicializa un vector de tamano de otro con el numero desado
        Vector(size_t size); // Constructor que inicializa un vector de 0 de tamano 
        // Destructor
        ~Vector() = default;

        // Access methods
        const std::vector<T>& getData() const;
        T& operator[](size_t index);
        const T& operator[](size_t index) const;
        size_t size() const;
        void resize(size_t newSize);
        void push_back(const T& value);
        void push_back(T&& value);
        void print() const;

        // Operators
        Vector<T> operator+(const Vector<T>& other) const; //Suma Vector+Vector
        Vector<T>& operator+=(const Vector<T>& other);  // Operador +=
        Vector<T> operator-(const Vector<T>& other) const; // Resta Vector - Vector
        Vector<T> operator*(const Matrix<T>& other) const; // Multiplicacion vector-matriz

        template <typename U> auto operator+(const Vector<U>& other) const; // Operador suma Vector+Vector
        template <typename U> auto operator+=(const Vector<U>& other); // Operador +=
        // Vector by matrix operators
        template <typename U> auto operator*(const Matrix<U>& other) const; // Multiplicacion vector-matriz
        template <typename U> Vector<T> operator*(const Matrix<U>& other) const; // Multiplicacion vector-matriz

        // Scalar by vector
        template<typename U> friend Vector<U> operator*(const U& scalar, const Vector<U>& vec);
};

#include "Vector.tpp"  // Include implementation for template class
#endif