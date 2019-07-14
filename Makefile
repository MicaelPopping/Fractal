CC=g++

.PHONY: all

all: compilar

compilar:  main.cpp fractal.hpp fractal.cpp julia.hpp julia.cpp mandelbrot.hpp mandelbrot.cpp
	$(CC) main.cpp fractal.cpp julia.cpp mandelbrot.cpp -o fc -fopenmp

clean:
	rm -rf test