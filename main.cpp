#include <iostream>

#include "fractal.hpp"
#include "julia.hpp"
#include "mandelbrot.hpp"


int main () {

    Fractal *fc = new Julia();

    fc->generate_image();

    delete fc;

    fc = new Mandelbrot();

    fc->generate_image();

    delete fc;

    return 0;
}