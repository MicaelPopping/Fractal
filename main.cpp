#include <iostream>

#include "fractal.hpp"
#include "julia.hpp"
#include "mandelbrot.hpp"


int main (int argc, char *argv[]) {

    Fractal *fc = new Julia(atoi(argv[1]));

    fc->generate_image();

    delete fc;

    fc = new Mandelbrot(atoi(argv[1]));

    fc->generate_image();

    delete fc;

    return 0;
}