# Linear Perceptron Implementation in C++

A C++ implementation of a linear perceptron using gradient descent for binary classification problems. This project includes custom vector and matrix classes with template support and optimized mathematical operations.

## Features

- **Custom Linear Algebra**: Template-based Vector and Matrix classes
- **Gradient Descent Optimization**: Automatic weight adjustment using calculated gradients
- **Sigmoid Activation**: Non-linear activation function with derivative calculation
- **Multiple Logic Functions**: Support for AND, OR, MAJORITY, and custom logical functions
- **Performance Timing**: Built-in execution time measurement
- **OpenMP Parallelization**: Optimized for multi-core processing

## Project Structure

```
├── README.md
├── Makefile                # Build configuration
├── build/
│   └── linearPerceptron    # Compiled executable
└── src/
    ├── main.cpp           # Main implementation and test functions
    ├── Matrix.h           # Matrix class header
    ├── Matrix.tpp         # Matrix template implementations
    ├── Vector.h           # Vector class header
    ├── Vector.tpp         # Vector template implementations
    ├── Utils.h            # Utility functions header
    ├── Utils.cpp          # Utility functions implementation
    ├── Utils.tpp          # Utility template implementations
    ├── Perceptron.h       # Perceptron class header
    ├── Perceptron.cpp     # Perceptron implementation
    └── test.cpp           # Additional test functions
```

## Algorithm Overview

The perceptron implements the following steps:

1. **Data Initialization**: Define feature matrix X and target vector t
2. **Weight Initialization**: Create random weight vector w
3. **Forward Pass**: Compute e = w * X
4. **Activation**: Apply sigmoid function f(e) and calculate derivatives
5. **Error Calculation**: Compute quadratic error sum
6. **Gradient Descent**: Calculate gradient and update weights
7. **Iteration**: Repeat until convergence (error < 0.01)

## Supported Logic Functions

### AND Function
```cpp
std::vector<double> tmp1 = {0,0,0,1};
std::vector<std::vector<double>> tmp2 = {{0,0,1},{0,1,1},{1,0,1},{1,1,1}};
```

### OR Function
```cpp
std::vector<double> tmp1 = {0,1,1,1};
std::vector<std::vector<double>> tmp2 = {{0,0,1},{0,1,1},{1,0,1},{1,1,1}};
```

### Majority Function (3 inputs)
```cpp
std::vector<double> tmp1 = {1,1,1,1,0,0,0,0};
std::vector<std::vector<double>> tmp2 = {{1,1,1,1},{1,1,0,1},{1,0,1,1},{0,1,1,1},
                                         {1,0,0,1},{0,1,0,1},{0,0,1,1},{0,0,0,1}};
```

### Custom Function: (A AND B) OR (B AND C)
```cpp
std::vector<double> tmp1 = {1,1,1,0,0,0,0,0};
std::vector<std::vector<double>> tmp2 = {{0,1,1,1},{1,1,0,1},{1,1,1,1},{0,0,0,1},
                                         {0,0,1,1},{0,1,0,1},{1,0,0,1},{1,0,1,1}};
```

## Build and Run

### Prerequisites
- C++ compiler with C++23 support (g++)
- OpenMP support (optional, for parallelization)

### Compilation
```bash
# Build and run
make

# Or build only
make all

# Run existing binary
make run
```

### Manual Compilation
```bash
g++ -std=c++2b src/main.cpp src/Utils.cpp -o build/linearPerceptron
./build/linearPerceptron
```

## Key Components

### Vector Class
- Template-based generic vector operations
- Overloaded operators for mathematical operations
- Random initialization support

### Matrix Class
- Template-based matrix operations
- Matrix-vector multiplication
- Transpose operations
- Print utilities

### Utils Class
Key mathematical functions:
- `sigmoid(x)`: Sigmoid activation function
- `sigmoid_derivative(f_x)`: Derivative of sigmoid
- `calculate_gradient()`: Gradient calculation for weight updates
- `get_cuadratic_error_sum()`: Error calculation

## Algorithm Parameters

- **Learning Rate**: 0.01 (adjustable)
- **Convergence Threshold**: 0.01 (error tolerance)
- **Weight Initialization**: Random values between 0 and 1
- **Activation Function**: Sigmoid with derivative

## Performance Features

- **Execution Timing**: Automatic measurement of training time
- **Parallel Processing**: OpenMP optimization for sigmoid calculations
- **Memory Efficiency**: Template-based classes minimize overhead
- **Fast Convergence**: Optimized gradient descent implementation

## Example Output

```
El código se ejecutó en 0.234 segundos
Resultados
w: [4.1743, -0.3064, -1.8038]
```

## Mathematical Foundation

The perceptron uses:
- **Sigmoid Function**: f(x) = 1 / (1 + e^(-x))
- **Gradient Descent**: w_new = w_old - α * ∇E
- **Quadratic Error**: E = Σ(t_i - f_i)²

## Extensibility

The modular design allows for:
- Different activation functions
- Custom optimization algorithms
- Multi-layer extensions
- Different error functions

