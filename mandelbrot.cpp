#include "mandelbrot.hpp"


#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::ofstream;


/*************************************
 * Public
 * */
Mandelbrot::Mandelbrot() 
: Fractal("Mandelbrot") {

}


void Mandelbrot::generate_image() {

		ofstream fout("Two.ppm");
		fout << "P3" << endl; // Magic Number extensão ppm
		fout << image_width << " " << image_height << endl;
		fout << "256" << endl; // Valor máximo de cor do pixel RGB
		
		for(int y = 0; y < image_width; ++y) {
			for(int x = 0; x < image_height; ++x) {
				double cr = map_To_Real(x);
				double ci = map_To_Imaginary(y);
				double NumberR = cr;
				double NumberI = ci;
				int n = generate(cr, ci, NumberR, NumberI);

				int r = (n  % color_r); // CORES
				int g = (n * 3 % color_g);
				int b = (n % color_b);

				fout << r << " " << g << " " << b << " ";
			}
				fout << endl;
		}
				fout.close();
				cout << "Terminado! Mandelbrot gerado com sucesso!" << endl;
}