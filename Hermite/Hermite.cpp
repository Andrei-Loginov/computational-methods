//
// Created by Andrei on 27.05.2020.
//

#include "Hermite.h"

point_h::point_h(){

}

point_h::point_h(const double &x, const double &y, const std::vector<double> &derivative) : x_(x), y_(y), derivatives(derivative){

}

Hermite::Hermite(const std::vector<point_h> &points) : points_(points){
    count_divided_differences();
    multiplier_ = Polynomial(0 ,1);
    approx_ = Polynomial(0, divided_differences_[0][0]);
    for (int i = 1; i < total_points_; ++i){
        multiplier_ = multiplier_ * (Polynomial(1, 1) - Polynomial(0, nodes_[i - 1]));
        approx_ = approx_ + multiplier_ * divided_differences_[0][i];
    }
}

void Hermite::count_divided_differences() {
    sort(points_.begin(), points_.end(), comp);
    total_points_ = 0;
    for (auto iter = points_.begin(); iter != points_.end(); total_points_ += 1 + iter->derivatives.size(),  ++iter);
    divided_differences_.resize(total_points_);
    nodes_.resize(total_points_);
    int k = 0;
    for (auto iter = points_.begin(); iter != points_.end(); ++iter){
        for (int i = 0; i <= iter->derivatives.size(); ++i) {
            divided_differences_[k].resize(total_points_ - k, 0);
            divided_differences_[k][0] = iter->y_;
            nodes_[k] = iter->x_;
            k++;
        }
    }
    for (k = 1; k < total_points_; ++k){
        for (int i = 0; i < total_points_ - k; ++i){
            if (nodes_[i] == nodes_[i + k]){
                auto it = points_.begin();
                for (; it->x_ != nodes_[i]; ++it);
                divided_differences_[i][k] = it->derivatives[k - 1] / factorial(k);
            }
            else divided_differences_[i][k] = (divided_differences_[i + 1][k - 1] - divided_differences_[i][k - 1]) /
                        (nodes_[i + k] - nodes_[i]);
        }
    }
    std::cout << "Divided differences:\n";
    for (int i = 0; i < total_points_; ++i, std::cout << "\n"){
        std::cout << nodes_[i] << " ";
        for (int j = 0; j < divided_differences_[i].size(); ++j)
            std::cout << divided_differences_[i][j] << " ";
    }
}

Polynomial Hermite::polynomial() {
    return approx_;
}

bool comp(const point_h &left, const point_h &right){
    return (left.x_ < right.x_);
}

int factorial(const int &x){
    int ans = 1;
    for (int i = 2; i <= x; ans *= i, ++i);
    return ans;
}