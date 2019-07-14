#ifndef FRACTAL_HPP
#define FRACTAL_HPP


#include <string>
using std::string;


class Fractal {

protected:
    protected:
		string const input_file = "input.txt";
		string fractal_model;
		int image_width, image_height, max_iterations;
		int color_r;
		int color_g;
		int color_b;
		double min_r;
		double max_r;
		double min_i;
		double max_i;
        int threads;

public:
    Fractal();
    ~Fractal();
};

#endif //FRACTAL_HPP