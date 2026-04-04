#include <SDL2/SDL.h>
#include <math.h>
#include <list>
#include <complex>
#include <iostream>
#include <vector>

namespace Math{
    const double SCALE_FACTOR = 120;
    float distanceBetween(SDL_Point p_point1, SDL_Point p_point2);
    std::complex<double> calculateVector(std::vector<std::complex<double>> p_points, int index, double magnitude);
    std::complex<double> pointToComplex(SDL_Point p_point);
    std::vector<std::complex<double>> evenlySpacePoints(std::list<SDL_Point>& p_points, double magnitude);
}