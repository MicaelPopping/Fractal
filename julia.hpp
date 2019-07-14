#ifndef JULIA_HPP
#define JULIA_HPP


#include "fractal.hpp"


class Julia : public Fractal {

private:
   
public:
    Julia(unsigned int threads, int max_iterations);
   
   virtual void generate_image();
};

#endif //JULIA_HPP