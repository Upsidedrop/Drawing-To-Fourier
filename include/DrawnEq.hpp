#include <list>
#include <vector>
#include <complex>
#include <SDL2/SDL.h>

class DrawnEq{
    public:
    DrawnEq(std::list<SDL_Point> p_points, double p_magnitude);
    void printDesmosSyntax();
    private:
    std::list<std::complex<double>> coefficients;
};