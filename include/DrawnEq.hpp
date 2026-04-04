#include <list>
#include <vector>
#include <complex>
#include <SDL2/SDL.h>

class DrawnEq{
    public:
    DrawnEq(std::list<SDL_Point> p_points, double p_magnitude);
    double checkAccuracy(std::vector<std::complex<double>> goal);
    void printDesmosSyntax();
    std::complex<double> getValue(std::complex<double> t);
    private:
    std::list<std::complex<double>> coefficients;
};
