#!/bin/bash

OPTS="-std=c++11 -O3 -march=native -I./.. -lncurses -lm"
g++ -o main main.cpp ${OPTS}
