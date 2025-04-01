#include "Utils.h"
#include <cmath>
#include <random>
// Sigmoid function
double Utils::sigmoid(double x) {
    return 1.0 / (1.0 + std::exp(-x));
}

// Get the sigmoid derivative 
double Utils::sigmoid_derivative(double sigmoid_value) {
    return sigmoid_value * (1.0 - sigmoid_value);   
}
double Utils::get_random_number() {
    std::random_device rd;
    std::mt19937 gen(rd()); // Mersenne Twister PRNG
    std::uniform_real_distribution<> dis(0.0, 1.0);
    double random_number = dis(gen);
    return random_number;
}