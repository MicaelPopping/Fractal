#ifndef FRACTAL_HPP
#define FRACTAL_HPP


class Fractal {

protected:
    protected:
		string const ArquivoInput = "input.txt";
		string fractalModel;
		int imageWidth, imageHeight, maxN;
		int ColorR, ColorG, ColorB;
		double minR, maxR, minI, maxI;
        int threads;

public:
    Fractal();
    ~Fractal();
};

#endif FRACTAL_HPP