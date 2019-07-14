#ifndef FRACTAL_HPP
#define FRACTAL_HPP


#include <string>
using std::string;


class Fractal {

protected:
	string const input_file;
	int image_width;
	int image_height;
	int max_iterations;
	int color_r;
	int color_g;
	int color_b;
	double min_real;
	double max_real;
	double min_imaginary;
	double max_imaginary;
    unsigned int threads;

public:
    Fractal(string input_file, unsigned int threads, int max_iterations);

	virtual void generate_image() = 0;

protected:
	int generate(int x, int i, double num_real, double num_imaginary);

	double map_To_Real(int x);
	double map_To_Imaginary(int y);
};

#endif //FRACTAL_HPP