//
// Created by Andrei on 27.05.2020.
//

#ifndef HERMITE_HERMITE_H
#include "Polynomial.h"
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <iostream>
#define HERMITE_HERMITE_H

struct point_h{
    double x_, y_;
    std::vector<double> derivatives;
    point_h();
    point_h(const double &x, const double &y, const std::vector<double> &derivatives);
};


class Hermite {
public:
    Hermite(const std::vector<point_h> &points);
    Polynomial polynomial();
private:
    std::vector<point_h> points_;
    Polynomial approx_;
    std::vector<std::vector<double>> divided_differences_; //[i][0] is y; [i][j] is jth divided difference j != 0
    std::vector<double> nodes_;
    void count_divided_differences();
    int total_points_;
    Polynomial multiplier_;
};

bool comp(const point_h &left, const point_h &right);

int factorial(const int &x);

#endif //HERMITE_HERMITE_H
