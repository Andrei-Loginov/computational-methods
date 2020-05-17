#include "Polynomial.h"
#include "Newton.h"
#include <fstream>
#include <math.h>

//for cos(x)

Polynomial readPolynomial(std::ifstream &fin){
    int n;
    std::vector<std::pair<int, double>> monomials;
    fin >> n;
    monomials.resize(n);
    for (int i = 0; i < n; ++i)
        fin >> monomials[i].first >> monomials[i].second;
    return Polynomial(monomials);
}

int main() {
    std::ifstream fin("input.txt");
    int degree;
    double center, right_border, left_border, h;
    std::vector<std::pair<double, double>> v;
    fin >> degree >> left_border >> right_border >> h >> center;
    fin.close();
    for (double i = left_border; i <= right_border; i +=h)
        v.push_back(std::make_pair(i, cos(i)));
    Newton p(center, v, degree);
    p.answerOutput();
    return 0;
}