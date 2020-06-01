//
// Created by Andrei on 27.05.2020.
//

#ifndef HERMITE_POLYNOMIAL_H
#include <vector>
#include <map>
#include <cmath>
#include <iostream>
#define HERMITE_POLYNOMIAL_H


#define eps 0.00000001

class Polynomial {
public:
    Polynomial();
    Polynomial(const int &degree, const double &coefficient);
    Polynomial(const std::vector<std::pair<int, double>> &monomials);
    Polynomial& operator =(const Polynomial &right) {
        this->polynomial_.clear();
        for (auto rightIterator = right.polynomial_.begin(); rightIterator != right.polynomial_.end(); ++rightIterator)
            this->polynomial_.insert(*rightIterator);
        return *this;
    }
    friend Polynomial operator +(const Polynomial &left, const Polynomial &right);
    friend Polynomial operator +(const Polynomial &left, const double &right);
    friend Polynomial operator +(const double &left, const Polynomial &right);
    friend Polynomial operator -(const Polynomial &left, const Polynomial &right);
    friend Polynomial operator -(const Polynomial &left, const double &right);
    friend Polynomial operator -(const double &left, const Polynomial &right);
    friend Polynomial operator *(const Polynomial &left, const double &right);
    friend Polynomial operator *(const double &left, const Polynomial &right);
    friend Polynomial operator *(const Polynomial &left, const Polynomial &right);
    /*
     * Multiplication works correct only for 2 operands. If you try to use it for 3 or more arguments(a * b * c), it
     * will crash.
     */
    void output() const;
    double value(const double &x);
    Polynomial derivative();


private:
    std::map<int, double> polynomial_;
};

#endif //HERMITE_POLYNOMIAL_H
