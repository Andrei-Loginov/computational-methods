#include "Polynomial.h"
#include "Newton.h"
#include "Backward_interpolation.h"
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
    freopen("output.txt", "w", stdout);
    int n, degree, iterations;
    double y;
    std::vector<std::pair<double, double>> v;
    fin >> n >> degree >> y >> iterations;
    v.resize(n);
    for (int i = 0; i < n; ++i)
    {
        fin >> v[i].first >> v[i].second;
    }
    fin.close();
    Backward_interpolation bi(v, degree, y, iterations);
    bi.answer_output();
    return 0;
}