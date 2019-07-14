#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <fstream>
using std::ifstream;
#include <omp.h>


#include "fractal.hpp"


/*************************************
 * Public
 * */
Fractal::Fractal(string input_file) 
: input_file(input_file) {
	
	ifstream fin(input_file);

	if(!fin) {
		cout << "Não foi possível abrir o arquivo!" << endl;
		cin.ignore();	
	}

	//Manipulando a entrada de dados
	fin >> image_width >> image_height >> max_iterations;
	fin >> min_real >> max_real >> min_imaginary >> max_imaginary;
	fin >> color_r >> color_g >> color_b;

	fin.close();

	if(color_r >= 257 || color_g >= 257 || color_b >= 257 || color_r < 1 || color_g < 1 || color_b < 1 ) {
		cout << "Valor max/min de RBG ultrapassado, entre com números >= 0 || <= 256" << endl;
		cin.ignore();
		EXIT_FAILURE;
	}
}


/*************************************
 * Protected
 * */
int Fractal::generate(int x, int y, double num_real, double num_imaginary) {
	
	int i;
	//int threads = atoi(argv[4]);
	double cr = map_To_Real(x);
	double ci = map_To_Imaginary(y);

	//inicia vrify

	# pragma omp parallel num_threads (threads)  \
		private (i)
	{
		# pragma omp for	
		for(i = 0; (i < max_iterations) && ((cr * cr + ci * ci) < 4.0); i++) {
			double temp = 2.0 * cr * ci;
			cr = cr * cr - ci * ci + num_real;
			ci = temp + num_imaginary;
		}
	}


	return i;
}

double Fractal::map_To_Real(int x) {

	double range = max_real - min_real;

	return x * (range / image_width) + min_real;
}


double Fractal::map_To_Imaginary(int y) {

	double range = max_imaginary - min_imaginary;

	return y * (range / image_height) + min_imaginary;
}


/*************************************
 * Private
 * */
bool Fractal::verify(int i, double expression) {

	if(i < max_iterations && expression < 4.0)
		return true;

	return false;
}