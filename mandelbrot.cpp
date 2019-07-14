#include "mandelbrot.hpp"


#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::ofstream;


/*************************************
 * Public
 * */
Mandelbrot::Mandelbrot(unsigned int threads, int max_iterations) 
: Fractal("input_mandelbrot.txt", threads, max_iterations) { }


void Mandelbrot::generate_image() {

	int array[image_width][image_height];
	int x, y;
	
	# pragma omp parallel num_threads (threads)  \
		shared (array) \
		private (x, y)
 	{
		# pragma omp for
		for(x = 0; x < image_width; ++x) {
			for(y = 0; y < image_height; ++y) {

				int n = generate(x, y, map_To_Real(x), map_To_Imaginary(y));
				array[x][y] = n;
			}
		}	
	}

	ofstream fout("mandelbrot.ppm");

	fout << "P3" << endl; // Magic Number extensão ppm
	fout << image_width << " " << image_height << endl;
	fout << "256" << endl; // Valor máximo de cor do pixel RGB
	
	for (int i = 0; i < image_width; i++) {
		for (int j = 0; j < image_height; j++) {

			int n = array[i][j];

			int r = (n  % color_r);
			int g = (n * 3 % color_g);
			int b = (n % color_b);
			
			fout << r << " " << g << " " << b << " ";
		}

		fout << endl;
	}

	fout.close();
	cout << "Terminado! Mandelbrot gerado com sucesso!" << endl;
}