//
// Created by Andrei on 26.05.2020.
//

#ifndef RUNGE_FUNCTION_APPROXIMATION_NEWTON_H
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include "Polynomial.h"
#define RUNGE_FUNCTION_APPROXIMATION_NEWTON_H

struct point{
    double x_, y_, dist_;
    point(const double &x, const double& y, const double &center): x_(x), y_(y){
        dist_ = fabs(x_ - center);
    }
};

class Newton {
public:
    Newton(const double &center, const std::vector<std::pair<double, double>> &points, const int &degree);
    //sort by distance from center_
    struct compare{
        bool operator()(const point &left, const point &right)const{
            return (left.dist_ < right.dist_);
        }
    };
    Polynomial polynomial();


private:
    double center_;
    std::vector<point> points_;
    int degree_;
    Polynomial polynomial_;
    std::vector<std::vector<double>> dividedDifferences;
    void countDividedDifferences();
    Polynomial multiplier;
};


#endif //RUNGE_FUNCTION_APPROXIMATION_NEWTON_H
