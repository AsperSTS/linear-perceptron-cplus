#include<iostream>
#include <vector>
#include "Vector.h"
#include "Matrix.h"
/* This is the main function
    1.- Definir la funcion basica de vector (*)
    2.- Definir la funcion basica de matriz (*)
    3.- Definir la transpuesta de una matriz (*)
    4.- Definir X y t, las caracteristicas y el target (*)
    5.- Inicializacion de M y N con la cantidad de filas y columnas de X (*)
    6.- Crear un vector W aleatorio de tamaño M (*)
    7.- Multiplicar el vector "W" con la matrix "X"
*/

int main(){
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
    
    /*
    Paso 5
    */
    unsigned int M = X.rows();
    unsigned int N = X.cols();
    std::cout<<"M: "<<M<<std::endl;
    std::cout<<"N: "<<N<<std::endl;
    /* 
    Paso 6
    */
    std::cout<<"W: ";
    Vector<double> W(M, 0, 1); // Genera un vector de tamano M con numeros aleatorios entre lower_bound y upper_bound
    W.print();

    /*
    Paso 7
    */
    std::cout<<"E: ";
    Vector<double> e = W*X;
    e.print();

    /* 
    Paso 8
    */
    return 0;
}