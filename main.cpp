#include <iostream>
using std::cout;
using std::endl;
#include "fractal.hpp"
#include "julia.hpp"
#include "mandelbrot.hpp"


int main (int argc, char *argv[]) {

    Fractal *fc = nullptr;
    string model = argv[1];

    if(model == "julia")
        fc = new Julia(atoi(argv[2]), atoi(argv[3]));
    else if(model == "mandelbrot")
        fc = new Mandelbrot(atoi(argv[2]), atoi(argv[3]));

    fc->generate_image();

    delete fc;

    return 0;
}