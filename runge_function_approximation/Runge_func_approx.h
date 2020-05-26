//
// Created by Andrei on 26.05.2020.
//

#ifndef RUNGE_FUNCTION_APPROXIMATION_RUNGE_FUNC_APPROX_H
#include "Newton.h"
#define RUNGE_FUNCTION_APPROXIMATION_RUNGE_FUNC_APPROX_H

#define pi 3.14159265

class Runge_func_approx {
public:
    Runge_func_approx(const double &center, const int &degree);
    Polynomial polynom();
private:
    std::vector<std::pair<double, double> > points_;
    std::vector<double> count_Chebyshev_nodes();
    int degree_;
    double center_;
    Polynomial approx_;
    std::vector<std::pair<double, double> > count_points(const int &degree);
};

double Runge_function(const double &x);

#endif //RUNGE_FUNCTION_APPROXIMATION_RUNGE_FUNC_APPROX_H
