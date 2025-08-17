#ifndef UTILS_H
#define UTILS_H
#include<iostream>  
#include <cmath>
#include <random>

template <typename T> class Vector;
template <typename T> class Matrix;
class Utils{

    public:
        Utils() {
            // std::cout << "Utils created" << "\n";
        }
        ~Utils(){
            // std::cout << "Utils destroyed" << "\n";
        }  
        static double sigmoid(double x);
        static double sigmoid_derivative(double sigmoid_value);
        static double get_random_number(unsigned int lower_bound, unsigned int upper_bound);
        static double get_cuadratic_error(double sigmoid_value, double target_value);
        static double get_cuadratic_error_sum(const Vector<double>&, const Vector<double>&);
        template <typename T> static Vector<T> calculate_gradient(const Vector<T>& f, const Vector<T>& t, 
        const Vector<T>& fd, const Matrix<T>& X);
};
#include "Utils.tpp"
#endif