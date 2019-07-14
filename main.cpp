#include <iostream>

#include "fractal.hpp"
#include "julia.hpp"
#include "mandelbrot.hpp"


int main () {

    Fractal *fc = new Julia();

    fc->generate_image();

    return 0;
}