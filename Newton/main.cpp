#include "Polynomial.h"
#include "Newton.h"
#include <fstream>

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
    int n, degree;
    double center;
    std::vector<std::pair<double, double>> v;
    fin >> n >> degree >> center;
    v.resize(n);
    for (int i = 0; i < n; ++i)
    {
        fin >> v[i].first >> v[i].second;
    }
    fin.close();
    Newton p(center, v, degree);
    p.answerOutput();
    return 0;
}