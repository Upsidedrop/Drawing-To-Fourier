#include "DrawnEq.hpp"
#include "Math.hpp"

using namespace std;

DrawnEq::DrawnEq(std::list<SDL_Point> p_points, double p_magnitude){
    p_magnitude += Math::distanceBetween(p_points.front(), p_points.back());
    p_points.push_back(p_points.front());
    
    vector<complex<double>> evenPoints = Math::evenlySpacePoints(p_points, p_magnitude);

    coefficients.push_back(Math::calculateVector(evenPoints, 0, p_magnitude));
    int i = 1;
    while(i <= 100){
        coefficients.push_back(Math::calculateVector(evenPoints, i, p_magnitude));
        coefficients.push_front(Math::calculateVector(evenPoints, -i, p_magnitude));
        ++i;
    }
}
void DrawnEq::printDesmosSyntax(){
    std::string output = "";
    output.reserve(20 * coefficients.size());
    output += "[";
    for(complex<double> coeff : coefficients){
        output += std::to_string(coeff.real());
        output += " + (";
        output += std::to_string(-coeff.imag());
        output += ")i";
        output += ", ";
    }
    // get rid of last comma and space
    output.pop_back();
    output.pop_back();

    output += "]\n";

    std::cout << output;
}
double DrawnEq::checkAccuracy(vector<complex<double>> goal){
   /* for(int i = 0; i < goal.size(); ++i){
	
    }*/
}
complex<double> DrawnEq::getValue(double t){
    std::complex<double> sum = 0;
    int vecNum = (coefficients.size() - 1) / 2;
    auto arrCoeff = vector<complex<double>>(coefficients.begin(), coefficients.end());
    for(int i = -vecNum; i <= vecNum; ++i){
	sum += arrCoeff[i + vecNum] * exp(i * 2 * M_PI * 1i * t);
    }
    return sum;
}
