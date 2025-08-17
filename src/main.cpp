#include<iostream>
#include <vector>
#include <ctime>
#include "Vector.h"
#include "Matrix.h"
#include "Utils.h"
// #include "Perceptron.h"
/* This is the main function
    1.- Definir la funcion basica de vector (*)
    2.- Definir la funcion basica de matriz (*)
    3.- Definir la transpuesta de una matriz (*)
    4.- Definir X y t, las caracteristicas y el target (*)
    5.- Inicializacion de M y N con la cantidad de filas y columnas de X (*)
    6.- Crear un vector w aleatorio de tamaño M (*)
    7.- Multiplicar el vector "w" con la matrix "X" (*)
    8.- f almacena la funcion sigmoide, da como resultado un vector (*)
    9.- fd almacena la derivada de la funcion sigmoide, da como resultado un vector (*)
    10.- Obtiene error cuadratico por cada elemento del vector, hace la suma (*)
    11.- Se define el learning rate (*) Perceptron.cpp
    12.- Creacion de bucle while y calcular el gradiente del error para calcular los pesos (*) -> Utils.cpp
    13.- Actualizacion line search (*)
    14.- Paso 7 a 10 (*)
*/
void gradient_test_function(){
    std::vector<double> tmp1 = {0,0,1,1};
    std::vector<std::vector<double>> tmp2 = {{0,0,1},{0,1,1},{1,0,1},{1,1,1}};

    /*
        Paso 1 al 4
    */
    std::cout<<"X: \n";
    Matrix<double> X(std::move(tmp2));
    X.print();
    X.transpose_matrix();
    std::cout<<"X':\n";
    X.print();
    std::cout<<"Target:\n";
    Vector<double> t(std::move(tmp1));
    t.print();
    
    Vector<double> f = {0.5597,0.6044, 0.5898,0.6335}; // Posible mejora
    Vector<double> fd = {0.2464,0.2391,0.2419,0.2322};
    

    Vector<double> tmp = Utils::calculate_gradient(f,t,fd,X);
    std::cout<<"Grad: ";
    tmp.print();

    /*
    Resultados matlab
    
    f =

    0.5597    0.6044    0.5898    0.6335


    fd =

    0.2464    0.2391    0.2419    0.2322

    gradT =

   -0.0181
   -0.0008
    0.0097


    w =

        4.1743   -0.3064   -1.8038

    */
}

template <typename T> void print_all(const Matrix<T>& X, const Vector<T>& t, const Vector<T>& w, 
    const Vector<T>& e, const Vector<T>& f, const Vector<T>& fd, double error_t_sum){
    std::cout<<"X':\n";
    X.print();

    std::cout<<"Target:\n";
    t.print();

    std::cout<<"w: ";
    w.print();

    std::cout<<"E: ";
    e.print();

    std::cout<<"f: ";
    f.print();

    std::cout<<"fd: ";
    fd.print();

    std::cout<<"errorT: "<<error_t_sum<<"\n";
}

int main(){
    // std::vector<double> tmp1 = {0,0,1,1};
    // std::vector<std::vector<double>> tmp2 = {{0,0,1},{0,1,1},{1,0,1},{1,1,1}};

    /*
        Function OR
    */
    // std::vector<double> tmp1 = {0,1,1,1};
    // std::vector<std::vector<double>> tmp2 = {{0,0,1},{0,1,1},{1,0,1},{1,1,1}};
    /*
        Function AND
    */
    // std::vector<double> tmp1 = {0,0,0,1};
    // std::vector<std::vector<double>> tmp2 = {{0,0,1},{0,1,1},{1,0,1},{1,1,1}};

    /*
        Function MAYORIA
    */
    // std::vector<double> tmp1 = {1,1,1,1,0,0,0,0};
    // std::vector<std::vector<double>> tmp2 = {{1,1,1,1},{1,1,0,1},{1,0,1,1},{0,1,1,1},{1,0,0,1},{0,1,0,1},{0,0,1,1},{0,0,0,1}};
    
     /*
        Function (A y B) o (B y C)
    */
    std::vector<double> tmp1 = {1,1,1,0,0,0,0,0};
    std::vector<std::vector<double>> tmp2 = {{0,1,1,1},{1,1,0,1},{1,1,1,1},{0,0,0,1},{0,0,1,1},{0,1,0,1},{1,0,0,1},{1,0,1,1}};
    /*
        Paso 1 al 4
    */
    // std::cout<<"X: \n";
    // X.print();
    Matrix<double> X(std::move(tmp2)); 
    X.transpose_matrix();
    Vector<double> t(std::move(tmp1));

    clock_t start_clock = clock();
    /*
        Paso 5
    */
    unsigned int M = X.rows();
    unsigned int N = X.cols();
    /* 
        Paso 6
    */
    Vector<double> w(M, 0, 1); // Genera un vector de tamano M con numeros aleatorios entre lower_bound y upper_bound  
    /*
        Paso 7
    */  
    Vector<double> e = w*X;
    /* 
        Paso 8 y 9; f almacena la funcion sigmoide, fd la derivada
    */
    Vector<double> f(e.size());  // Posible mejora
    Vector<double> fd(e.size());
    #pragma omp parallel for
    for(size_t i = 0; i<e.size(); i++){
        f[i] =  Utils::sigmoid(e[i]);
        fd[i] = Utils::sigmoid_derivative(f[i]);
    }
    /*
        Paso 10 ; 
    */
    double error_t_sum = Utils::get_cuadratic_error_sum(f,t);
    /*
        Paso 11
    */
    double lr = 0.01;
    /* 
        Paso 12
    */
    // print_all

    Vector<double> gradT;
    while(error_t_sum>0.01){
        gradT = Utils::calculate_gradient(f,t,fd,X);
        /* 
            Paso 13 
        */
        w = w-(lr*gradT);
        // w.print();

        /*
            Paso 14
        */
        e = w*X;
        for(size_t i = 0; i<f.size(); i++){
            f[i] =  Utils::sigmoid(e[i]);
            fd[i] = Utils::sigmoid_derivative(f[i]);
        }
        error_t_sum = Utils::get_cuadratic_error_sum(f,t);

    }
    clock_t end_clock = clock();
    double duration_clock = static_cast<double>(end_clock - start_clock) / CLOCKS_PER_SEC;

    std::cout << "El código se ejecutó en " << duration_clock << " segundos\n";

    std::cout<<"Resultados\n";
    w.print();

    return 0;
}