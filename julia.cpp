#include "julia.hpp"


#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::ofstream;


/*************************************
 * Public
 * */
Julia::Julia() {

}


void Julia::generate_image() {

    if(fractal_model == "One") {
		ofstream fout("One.ppm");
		fout << "P3" << endl; // Magic Number extensão ppm
		fout << image_width << " " << image_height << endl;
		fout << "256" << endl; // Valor máximo de cor do pixel RGB
		for(int y = 0; y < image_height; ++y) {
			for(int x = 0; x < image_width; ++x) {
				double cr = map_To_Real(x);
				double ci = map_To_Imaginary(y);
				double NumberR = -0.70176;
				double NumberI = -0.3842;
				int n = generate(cr, ci, NumberR, NumberI);

				int r = (n  % color_r); // CORES
				int g = (n * 3 % color_g);
				int b = (n % color_b);

				fout << r << " " << g << " " << b << " ";
			}
				fout << endl;
		}
				fout.close();
				cout << "Terminado! " << fractal_model << " gerado com sucesso!" << endl;
	}
}