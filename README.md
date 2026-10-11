# Linear Perceptron in C++

Educational implementation of a binary classifier built in C++ with custom matrix and vector classes.

The project focuses on implementing the mathematical pieces directly instead of relying on a machine-learning framework.

## What it demonstrates

- Template-based `Vector` and `Matrix` classes.
- Operator overloading for mathematical operations.
- Forward pass with sigmoid activation.
- Quadratic error calculation.
- Gradient-based weight updates.
- Logic-function classification examples.
- Execution-time measurement.
- Optional OpenMP parallelization.

## Training flow

```text
input matrix
   ↓
weighted combination
   ↓
sigmoid activation
   ↓
error calculation
   ↓
gradient
   ↓
weight update
   ↺ until convergence
```

## Structure

```text
src/
  Matrix.h / Matrix.tpp
  Vector.h / Vector.tpp
  Perceptron.h / Perceptron.cpp
  Utils.h / Utils.cpp / Utils.tpp
  main.cpp
Makefile
```

## Build

Requires a C++ compiler and optional OpenMP support.

```bash
make all
make run
```

Or compile manually according to the standard configured in the project.

## Example problems

The current examples include AND, OR, majority and a custom boolean function.

## Scope

This is a learning project, not a production ML library. Its main value is the direct implementation of linear algebra operations and the training loop.
