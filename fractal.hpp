#ifndef FRACTAL_HPP
#define FRACTAL_HPP


#include <string>
using std::string;


class Fractal {

protected:
	string const input_file = "input.txt";
	string fractal_model;
	int image_width, image_height, max_iterations;
	int color_r;
	int color_g;
	int color_b;
	double min_real;
	double max_real;
	double min_imaginary;
	double max_imaginary;
    int threads;

public:
    Fractal();

	virtual void generate_image() = 0;

protected:
	int generate(double cr, double ci, int max_iterations, double NumberR, double NumberI);

private:
	double map_To_Real(int x);
	double map_To_Imaginary(int y);
};

#endif //FRACTAL_HPP