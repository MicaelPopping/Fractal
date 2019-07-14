#include "julia.hpp"


#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::ofstream;


/*************************************
 * Public
 * */
Julia::Julia(unsigned int threads) 
: Fractal("input_julia.txt", threads) { }


void Julia::generate_image() {

	ofstream fout("julia.ppm");

	fout << "P3" << endl; // Magic Number extensão ppm
	fout << image_width << " " << image_height << endl;
	fout << "256" << endl; // Valor máximo de cor do pixel RGB

	for(int y = 0; y < image_height; ++y) {
		for(int x = 0; x < image_width; ++x) {

			//int n = generate(x, y, -0.70176, -0.3842);
            int n = generate(x, y, -0.8, 0.156);

			int r = (n  % color_r); // CORES
			int g = (n * 3 % color_g);
			int b = (n % color_b);

			fout << r << " " << g << " " << b << " ";
		}
			fout << endl;
	}
			fout.close();
			cout << "Terminado! Julia gerado com sucesso!" << endl;
}