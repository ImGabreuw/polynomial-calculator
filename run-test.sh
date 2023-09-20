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
./main 2 "7x^2 - 6x + 7" "2x^2 - 4x + 1" "5x^2 - 2x + 6"
./main 2 "8x^3 - x^2 + 7x + 1" "2x^3 - 2x^2 + 4x - 3" "6x^3 + x^2 + 3x + 4"
./main 2 "5x^3 + 6x^2 + 7x + 7" "x^2 + 2x + 3" "5x^3 + 5x^2 + 5x + 4"
./main 2 "-3x^4 - 2x^3 - 4x^2 + 9x - 4" "-2x^3 - 3x^2 + 2x - 1" "-3x^4 - x^2 + 7x - 3"
./main 2 "-x^2 - x - 1" "-x^2 - x - 1" "0"
./main 2 "11x^4 + 2x^2 - 5x" "4x^4 - x^3 + 2x^2 - 3x - 1" "7x^4 + x^3 - 2x + 1"
./main 2 "6x^3 + 9x^2 - 3x + 21" "2x^3 + 3x^2 - x + 7" "4x^3 + 6x^2 - 2x + 14"
./main 2 "-4x^3 - 3x^2" "-4x^3 - 3x^2" "0"
./main 2 "3x^2 - x" "x^2 - x" "2x^2"
./main 2 "-1" "-3" "2"


