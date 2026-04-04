#include <Math.hpp>

using namespace std;

namespace Math{
    constexpr double INTEGRAL_PRECISION = 10000;
    float distanceBetween(SDL_Point p_point1, SDL_Point p_point2){
        return sqrt(pow(p_point1.x - p_point2.x, 2) + pow(p_point1.y - p_point2.y, 2));
    }
    complex<double> pointToComplex(SDL_Point p_point){
        return complex<double>(p_point.x, p_point.y);
    }
    complex<double> calculateVector(std::vector<std::complex<double>> p_points, int index, double magnitude){
        complex<double> res = 0;

        for(int i = 0; i < p_points.size(); ++i){
            // std::cout << index << ": " << i / INTEGRAL_PRECISION * 100 << "%\n";
            res += ((p_points[i] / SCALE_FACTOR) * exp(-index * 2 * M_PI * 1i * (i/INTEGRAL_PRECISION))) / INTEGRAL_PRECISION;
        }
        
        return res;
    }
    vector<complex<double>> evenlySpacePoints(list<SDL_Point>& p_points, double magnitude){
        vector<complex<double>> res;
        res.reserve(INTEGRAL_PRECISION);

        auto first = p_points.begin();
        auto second = first;

        second++;

        double counter = 0;
        double target = magnitude / INTEGRAL_PRECISION;

        while(true){
            counter += distanceBetween(*first, *second);
            while(counter >= target){
                double mid = 1 - (counter - target) / distanceBetween(*first, *second);

                complex<double> zfirst, zsecond;
                zfirst = pointToComplex(*first);
                zsecond = pointToComplex(*second);

                res.push_back(zfirst + (zsecond - zfirst) * mid);
                target += magnitude / INTEGRAL_PRECISION;

                if(target >= magnitude){
                    goto end;
                }
            }
            ++first;
            ++second;
        }
        end:
        if(res.size() > INTEGRAL_PRECISION){
            std::cout << "IMPRECISE SIZE\n";
        }
        return res;
    }
}