#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

double f(const double &x){
    return sin(x) * pow(1 - x, 3.0 / 4.0);
}

//only 2 nodes, only f function
double rectangle_formula(const double &a, const double &b){
    return (b - a) * f((b + a) / 2);
}

int main() {
    freopen("output.txt", "w", stdout);
    //task 1
    double exact_result = 0.196423;
    std::cout << "Task 1\n'Exact result': " << exact_result << "  (WolframAlpha)\n";
    //task 2
    double rectangle_res = rectangle_formula(0, 1);
    std::cout << "Task 2\nRectangle formula result: " << rectangle_res << "\n";
    std::cout << "Error: " << fabs(exact_result - rectangle_res) << "\n";
    std::cout << "_________________________________________________________________________\n";
    //task 3
    double mu_0 = 0.57143, mu_1 = 0.20779, mu_2 = 0.11082, mu_3 = 0.06993, x_1 = 0.25, x_2 = 0.75;
    std::cout << "Task3\nmu_0 =" << mu_0 << "\nmu_1=" <<mu_1 << "\nmu_2=" << mu_2 << "\nmu_3 = " << mu_3 << "   (WolframAlpha)\n";
    double A_1 = 34.0/77, A_2 = 10.0/77;
    std::cout << "A_1 = " << A_1 << "\tA_2 = " << A_2 << "\n";
    double ans = f(x_1) * A_1 + f(x_2)* A_2;
    std::cout << "Result, counted using weights: " << ans << "\n";
    std::cout << "Error: " << fabs(ans - exact_result) << "\n";
    std::cout << "_________________________________________________________________________\n";
    //task 4
    std::cout << "Task 4\nGauss formula\n";
    std::cout << "(integrate(f(x) dx), -1< x < 1) = f(-1/sqrt(3)) + f(1/sqrt(3))) - written in the book\n";
    std::cout << "Let's change the variable to calculate integral 0 < x < 1\n";
    std::cout << "(integrate(f(x)dx), 0 < x < 1) = 1/2 * (f(-0.5/sqrt(3) + 1/2) + f(0.5/sqrt(3) + 1/2))\n";
    std::cout << "Result is: " << 0.5 * (f(-0.5/sqrt(3) + 0.5) + f(0.5/sqrt(3) + 0.5)) << "\n";
    std::cout << "Error:" << fabs(exact_result - 0.5 * (f(-0.5/sqrt(3) + 0.5) + f(0.5/sqrt(3) + 0.5))) << "\n";
    std::cout << "_________________________________________________________________________\n";
    //task 4
    std::cout << "Task 4\nGauss-like formula\n";
    std::cout << "The system: \n";
    std::cout << "a_1 * " << mu_1 << " + a_2 * " << mu_0 << " = " << -mu_2 << "\n";
    std::cout << "a_1 * " << mu_2 << " + a_2 * " << mu_1 << " = " << -mu_3 << "\n";
    double a_1 = -16.0/19, a_2 = 32.0/285;
    std::cout << "a_1 = " << a_1 << ", a_2 = " << a_2 << "   (Wolfram)\n";
    x_1 = 8.0/19 - 4*sqrt(22.0/15)/19.0;
    x_2 = 8.0/19 + 4*sqrt(22.0/15)/19.0;
    std::cout << "x_1 = " << x_1 << " , x_2 = " << x_2 << "\n";
    A_1 = 1 / (x_1 - x_2) * (mu_1 - x_2 * mu_0);
    A_2 = 1 / (x_2 - x_1) * (mu_1 - x_1 * mu_0);
    std::cout << "Check: A_1 + A_2 = " << A_1 + A_2 <<" ; mu_0 = " << mu_0 << "\n";
    ans = A_1 * f(x_1) + A_2 * f(x_2);
    std::cout << "Result is: " << ans << "\n";
    std::cout << "Error: " << fabs(ans - exact_result) << "\n";
    return 0;
}
