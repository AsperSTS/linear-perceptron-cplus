#ifndef UTILS_H
#define UTILS_H
#include<iostream>
#include<memory>
#include<vector>
#include<string>   
class Utils{

    public:
        Utils() {
            // std::cout << "Utils created" << "\n";
        }
        ~Utils(){
            // std::cout << "Utils destroyed" << "\n";
        }  
        static double sigmoid(double);
        static double sigmoid_derivative(double);
        static double get_random_number();
        
};

#endif