//
// Created by Andrei on 25.05.2020.
//

#ifndef BACKWARD_INTERPOLATION_BACKWARD_INTERPOLATION_H
#include "Newton.h"
#define BACKWARD_INTERPOLATION_BACKWARD_INTERPOLATION_H



class Backward_interpolation: public Newton {
public:
    Backward_interpolation(const std::vector<std::pair<double, double>> &points,
                           const int &degree, const double &y, const int &iterations);
    double x_();
    void answer_output();
private:
    double y_;
    Polynomial polynom_, derivative_;
    std::vector<point> steps_;
    void tangent_method();
    int iterations_number_;
    double interpolation_point_;
};

double find_center(const std::vector<std::pair<double,double>> &points, const double &y);
#endif //BACKWARD_INTERPOLATION_BACKWARD_INTERPOLATION_H
