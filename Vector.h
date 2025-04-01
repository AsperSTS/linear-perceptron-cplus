#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <iostream>
#include <ctime>
#include <random>
#include "Matrix.h"
template <typename T> class Vector {
    private:
        std::vector<T> data;
    public:
        // Constructors
        Vector(const std::vector<T>& data);
        Vector(size_t size, unsigned int lower_bound, unsigned int upper_bound);
        Vector(std::vector<T>&& data) noexcept;
        Vector(std::initializer_list<T> init);
        
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
        Vector<T> operator+(const Vector<T>& other) const;
        template <typename U> auto operator+(const Vector<U>& other) const;
        Vector<T>& operator+=(const Vector<T>& other);
        template <typename U> auto operator+=(const Vector<U>& other);
        Vector<T> operator-(const Vector<T>& other) const;


        // Vector by matrix operators
        Vector<T> operator*(const Matrix<T>& other) const;
        template <typename U> auto operator*(const Matrix<U>& other) const;
        template <typename U> Vector<T> operator*(const Matrix<U>& other) const;

};

#include "Vector.cpp"  // Include implementation for template class
#endif