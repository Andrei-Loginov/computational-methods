//
// Created by Andrei on 03.03.2020.
//

#include "Newton.h"

Newton::Newton(const double &center, std::vector<std::pair<double, double>> points, const int &degree) : center_(center), degree_(degree)
{
    for (auto pointsIterator = points.begin(); pointsIterator != points.end(); ++pointsIterator)
        points_.emplace_back(point(pointsIterator->first, pointsIterator->second, center_));
    sort(points_.begin(), points_.end(), compare());
    countDividedDifferences();
    multiplier = Polynomial(0, 1);
    polynomial_ = Polynomial(0, points_[0].y_);
    for (int i = 1; i <= degree_; ++i){
        multiplier = multiplier * (Polynomial(1, 1) - Polynomial(0, points_[i - 1].x_));
        polynomial_ = polynomial_ + multiplier * dividedDifferences[0][i - 1];
    }
    polynomial_.output();
}

void Newton::countDividedDifferences() {
    dividedDifferences.resize(points_.size());
    for (int i = 0; i < points_.size(); ++i)
        dividedDifferences[i].resize(points_.size() - i - 1);
    for (int i = 0; i < dividedDifferences.size() - 1; ++i)
        dividedDifferences[i][0] = (points_[i + 1].y_ - points_[i].y_) / (points_[i + 1].x_ - points_[i].x_);
    for (int i = 1; i < dividedDifferences.size() - 1; ++i)
        for (int j = 0; j < points_.size() - i - 1; ++j)
            dividedDifferences[j][i] = (dividedDifferences[j + 1][i - 1] - dividedDifferences[j][i - 1]) /
                                       (points_[j + 1 + i].x_ - points_[j].x_);
    for (int i = 0; i < points_.size(); ++i)
    {
        std::cout << points_[i].x_ << " " << points_[i].y_ << ": ";
        for (int j = 0; j < dividedDifferences[i].size(); ++j)
            std::cout << dividedDifferences[i][j] << " ";
        std::cout << "\n";
    }
}

Polynomial Newton::polynomial() {
    return polynomial_;
}

void Newton::answerOutput() {
    std::cout << "Nodes | ";
    for (int i = 0; i <= degree_; ++i)
        std::cout << points_[i].x_ << " | ";
    std::cout << "\nValues | ";
    for (int i = 0; i <= degree_; ++i)
        std::cout << polynomial_.value(points_[i].x_) << " | ";
    std::cout << "\nExact error | ";
    for (int i = 0; i <= degree_; ++i)
        std::cout << polynomial_.value(points_[i].x_) - points_[i].y_ << " | ";
    //this program has been written for ln, so derivatives are counted for ln
    std:: cout << "\nValue in point " << center_ << ": "<< polynomial_.value(center_) << "\tln(" << center_ << ")" << log(center_);
    std::cout << "\nError in point 4: " << polynomial_.value(center_) - log(center_) << "\n";
    int maximal_derivative = 24; // 24/x^5, x = 1
    Polynomial w = multiplier * (Polynomial(1, 1) - Polynomial(0, points_[degree_].x_));
    std::cout << "error estimation: " << maximal_derivative * fabs(w.value(center_)) / 120;

}