#!/bin/bash

clear && gcc -o main -g $(find . -name "*.c") -lm && ./main $@
