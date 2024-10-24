#!/bin/bash
gcc -std=c99 -pedantic -Wall -Wextra -Wconversion -Wmissing-prototypes -O3 -flto -march=native main.c ref/*.c