#include "Hermite.h"
#include <fstream>

int main() {
    std::ifstream fin("input.txt");
    freopen("output.txt", "w", stdout);
    int n, k, max_der = 0;
    fin >> n;
    std::vector<point_h> v(n);
    for (int i = 0; i < n; ++i){
        fin >> v[i].x_ >> v[i].y_ >> k;
        if (k > max_der) max_der = k;
        v[i].derivatives.resize(k);
        for (int j = 0; j < k; ++j)
            fin >> v[i].derivatives[j];
    }
    fin.close();
    Hermite interpolation(v);
    Polynomial approximation = interpolation.polynomial();
    std::vector<Polynomial> derivatives(max_der);
    derivatives[0] = approximation.derivative();
    for (int i = 1; i < max_der; derivatives[i] = derivatives[i - 1].derivative(),++i);
    std::cout << "P(x) is:";
    approximation.output();
    for (int i = 0; i < max_der; ++i){
        std::cout << "derivative" << i + 1 << ": ";
        derivatives[i].output();
    }
    std::cout << "Table for approximation polynomial:\n";
    std::cout << "\nx\t|P(x)\t|P'(x)\t|";
    for (int i = 2; i <= max_der; ++i){
        std::cout << "P";
        for (int j = 0; j < i; std::cout << "'", ++j);
        std::cout << "(x)\t|";
    }
    std::cout << "\n";
    for (int i = 0; i < v.size(); ++i){
        std::cout << v[i].x_ << " | " << approximation.value(v[i].x_) << " | ";
        for (int j = 0; j < v[i].derivatives.size(); ++j)
            std::cout << derivatives[j].value(v[i].x_) << " | ";
        std::cout << "\n";
    }
    std::cout << "Initial data:\n";
    std::cout << "\nx\t|f(x)\t|f'(x)\t|";
    for (int i = 2; i <= max_der; ++i){
        std::cout << "f";
        for (int j = 0; j < i; std::cout << "'", ++j);
        std::cout << "(x)\t|";
    }
    std::cout << "\n";
    for (int i = 0; i < v.size(); ++i){
        std::cout << v[i].x_ << " | " << v[i].y_ << " | ";
        for (int j = 0; j < v[i].derivatives.size(); ++j)
            std::cout << v[i].derivatives[j] << " | ";
        std::cout << "\n";
    }
    return 0;
}
