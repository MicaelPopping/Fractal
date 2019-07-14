#ifndef MANDELBROT_HPP
#define MANDELBROT_HPP


#include "fractal.hpp"


class Mandelbrot : public Fractal {

private:
 
public:
    Mandelbrot();

    virtual void generate_image();
};


#endif //MANDELBROT_HPP