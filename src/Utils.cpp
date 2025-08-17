#include "Utils.h"
#include "Vector.h"
#include "Matrix.h"

// Sigmoid function
double Utils::sigmoid(double x) {
    return 1.0 / (1.0 + std::exp(-x));
}

// Get the sigmoid derivative 
double Utils::sigmoid_derivative(double sigmoid_value) {
    return sigmoid_value * (1.0 - sigmoid_value);   
}
double Utils::get_random_number(unsigned int lower_bound, unsigned int upper_bound) {
    /*
        Variables estaticas para evitar la creacion de multiples instancias 
    */
    static std::random_device rd; 
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(lower_bound, upper_bound);
    return dis(gen);
}
double Utils::get_cuadratic_error(double sigmoid_value, double target_value){
    /*
        errorT=0.5*(f-t).^2; 
    */
    return (0.5 * std::pow(sigmoid_value-target_value,2));
}
double Utils::get_cuadratic_error_sum(const Vector<double>& sigmoid_vector, const Vector<double>& target_vector){
    /*
        n es el número de puntos de datos.
        y_i es el valor objetivo (verdadero) para el punto de datos i.
        ŷ_i es el valor predicho (estimado) para el punto de datos i.
        Σ representa la suma de los cuadrados de las diferencias entre los valores objetivo y los valores predichos
    */
    if(sigmoid_vector.size() != target_vector.size()){
        throw std::invalid_argument("Los vectores no son del mismo tamano");
    }
    double sum = 0;
    for(size_t i = 0; i<sigmoid_vector.size(); i++){
        sum += 0.5 * std::pow(sigmoid_vector[i]-target_vector[i], 2);
    }
    return sum;
}
