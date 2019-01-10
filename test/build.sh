#!/bin/bash

OPTS="-std=c++11 -O3 -march=native -I./.. -lncurses"

g++ -o triangles triangles.cpp ${OPTS}
