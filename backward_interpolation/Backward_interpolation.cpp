//
// Created by Andrei on 25.05.2020.
//

#include "Backward_interpolation.h"


Backward_interpolation::Backward_interpolation(const std::vector<std::pair<double, double>> &points, const int &degree,
        const double &y, const int &iterations) : Newton(find_center(points, y), points, degree) {
    polynom_ = polynomial() - Polynomial(0, y);
    derivative_ = polynom_.derivative();
    y_ = y;
    iterations_number_ = iterations;
    interpolation_point_ = find_center(points, y);
    /*
     * distance to center doesn't matter, so let dist_ be distance to the given point with smallest y error
     * May the rubbish be in point.dist_
     */
    steps_.emplace_back(point(interpolation_point_, polynom_.value(interpolation_point_), interpolation_point_));
    tangent_method();
}

void Backward_interpolation::tangent_method() {
    for (int i = 1; i < iterations_number_; ++i)
    {
        double x = steps_[i - 1].x_ - steps_[i - 1].y_ / derivative_.value(steps_[i - 1].x_);
        steps_.emplace_back(point(x, polynom_.value(x), steps_[0].x_));
    }
}

double Backward_interpolation::x_(){
    return steps_[steps_.size() - 1].x_;
}

void Backward_interpolation::answer_output(){
    std::cout << "The interpolation point is: " << interpolation_point_ << "\n";
    std::cout << "Polynomial is: ";
    polynom_.output();
    std::cout << "\nk\t|x_k\t|p(x_k)\n";
    for (int i = 0; i < interpolation_point_; ++i)
        std::cout << "x_" << i << "|" << steps_[i].x_ << "|" << steps_[i].y_ << "\n";
    std::cout << "\nFound x* :" << x_() << "|\tReal x* :" << exp(y_); //program for ln
    std::cout << "\nError: " << fabs(x_() - exp(y_));
}

double find_center(const std::vector<std::pair<double, double>> &points, const double &y) {
    int ans = 0;
    for (int i = 0; i < points.size(); ++i)
        if (fabs(points[i].second - y) < fabs(points[ans].second - y)) ans = i;
    return points[ans].first;
}

