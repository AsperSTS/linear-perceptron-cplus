#pragma once

#include "Utils.h"
#include "Vector.h"
#include "Matrix.h"

template <typename T>  Vector<T> Utils::calculate_gradient(const Vector<T>& f, const Vector<T>& t, 
    const Vector<T>& fd, const Matrix<T>& X){
        size_t n = f.size();  // Número de ejemplos
        size_t m = X.rows();  // Número de características
    
        // Matriz para almacenar gradientes individuales
        Matrix<T> grad(m, n);
    
        // Calcular gradiente para cada ejemplo
        for (size_t i = 0; i < n; ++i) {
            double error = f[i] - t[i];
            double delta = error * fd[i];
    
            // X(:,i) es la columna i de X (ejemplo i)
            Vector<T> x_col = X.get_column(i);
    
            // Actualizar columna i de la matriz de gradiente
            for (size_t j = 0; j < m; ++j) {
                grad[j][i] = delta * x_col[j];
            }
        }
        // std::cout<<"Grad Mat: \n";
        // grad.print();
        // Sumar gradientes por filas para obtener el gradiente total
        Vector<T> gradT(m);
        for (size_t j = 0; j < m; ++j) {
            double sum = 0.0;
            for (size_t i = 0; i < n; ++i) {
            sum += grad[j][i];
        }
        gradT[j] = sum;
        }
    
        return gradT;
}

