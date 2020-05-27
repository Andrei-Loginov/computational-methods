//
// Created by Andrei on 26.05.2020.
//

#include "Runge_func_approx.h"

Runge_func_approx::Runge_func_approx(const double &center, const int &degree) : center_(center), degree_(degree){
    approx_ = Newton(center_, count_points(degree_), degree_).polynomial();
}

Polynomial Runge_func_approx::polynom() {
    return approx_;
}

std::vector<std::pair<double, double>> Runge_func_approx::count_points(const int &degree) {
    std::vector<std::pair<double, double>> ans(degree + 1);
    for (int i = 0; i < degree + 1; ++i)
    {
        ans[i].first = cos((2 * (double) i + 1) / (2 * degree + 2) * pi);
        ans[i].second = Runge_function(ans[i].first);
        std::cout << ans[i].first << " " << ans[i].second << "\n";
    }
    return ans;
}

double Runge_function(const double &x){
    return 1/ (1 + x * x);
}