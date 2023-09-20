#!/bin/bash

gcc -o main main.c polynomial-term.c polynomial.c utils.c -lm

# Casos de testes para resolver o polinômio
echo "---------------------------- Resolver polinômio ----------------------------"
./main 1 11 2 "2x^2 + x + 1"
./main 1 5 1 "x^2 + 2x + 2"
./main 1 134 3 "3x^3 + 4x^2 + 5x + 2"
./main 1 -11 -1 "x^3 - 4x^2 + 5x - 1"
./main 1 0 0 "x^2"
./main 1 1 0 "1"
./main 1 10 2 "2x^2 - 4x + 10"
./main 1 1 1 "x^2 - x + 1"
./main 1 22 3 "3x^2 - 2x + 1"
./main 1 1 -2 "-2x^3 - 3x^2 + 2x + 1"

# Casos de teste para somar polinômios
echo "---------------------------- Somar polinômios ----------------------------"
./main 2 "2x^2 + 2x^1 + 2" "x^2 + x^1 + 1" "x^2 + x^1 + 1"
