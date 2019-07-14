#ifndef MANDELBROT_HPP
#define MANDELBROT_HPP


#include "fractal.hpp"


class Mandelbrot : public Fractal {

private:
 
public:
    Mandelbrot(unsigned int threads);

    virtual void generate_image();
};


#endif //MANDELBROT_HPP