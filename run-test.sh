#!/bin/bash

gcc -o main main.c polynomial-term.c polynomial.c -lm

# Testes para resolver o polinômio
./main 1 11 "2x^2 + x + 1"
