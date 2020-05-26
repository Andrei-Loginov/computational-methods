#include "Runge_func_approx.h"
#include <fstream>

int main() {
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    int degree;
    double center;
    std::cin >> center >> degree;
    Polynomial p1 = Runge_func_approx(center, degree).polynom();
    std::vector<std::pair<double, double>> points;
    double i = -1.0;
    double step = 2.0 / degree;
    while (i <= 1.0) {
        std::cout << i << " " << Runge_function(i) <<"\n";
        points.emplace_back(std::pair<double, double>(i, Runge_function(i)));
        i += step;
    }
    Polynomial p2 = Newton(center, points, degree).polynomial();
    std::cout << "Runge function approximation:\nusing Chebyshev nodes: P_1(x) = ";
    p1.output();
    std::cout << "using equally spaced nodes: P_2(x) = ";
    p2.output();
    std::cout << Runge_function(center) << " " << p1.value(center) << " " << p2.value(center) << "\n";
    std::cout << "P_1(" << center << ")" << p1.value(center) << "\n";
    std::cout << "P_2(" << center << ")" << p2.value(center) << "\n";
    std::cout << "True value: " << Runge_function(center) << "\n";
    std::cout << "P_1 error: " << fabs(p1.value(center) - Runge_function(center)) << "\n";
    std::cout << "P_2 error: " << fabs(p2.value(center) - Runge_function(center)) << "\n";
    return 0;
}
