#!/bin/sh
# g++ -std=c++11 parallel_stdlib.cpp
g++ -D_GLIBCXX_PARALLEL -fopenmp -std=c++11 parallel_stdlib.cpp
