//
// Created by Andrei on 14.05.2020.
//

#include "Polynomial.h"

Polynomial::Polynomial()
{
    polynomial_.insert(std::pair<int, double>(0 ,0));
}

Polynomial::Polynomial(const int &degree, const double &coefficient){
    polynomial_.insert(std::pair<int, double>(degree, coefficient));
}

Polynomial::Polynomial(const std::vector<std::pair<int, double>> &monomials){
    for (auto monomialsIterator = monomials.begin(); monomialsIterator != monomials.end(); ++monomialsIterator)
        if (fabs(monomialsIterator->second) > eps) {
            if (polynomial_.find(monomialsIterator->first) == polynomial_.end())
                polynomial_.insert(*monomialsIterator);
            else
                polynomial_.find(monomialsIterator->first)->second += monomialsIterator->second;
        }
}

Polynomial operator +(const Polynomial &left, const Polynomial &right){
    Polynomial ans = left;
    for (auto rightIterator = right.polynomial_.begin(); rightIterator != right.polynomial_.end(); ++rightIterator)
        if (ans.polynomial_.find(rightIterator->first) == ans.polynomial_.end())
            ans.polynomial_.insert(std::pair<int, double>(*rightIterator));
        else {
            ans.polynomial_.find(rightIterator->first)->second += rightIterator->second;
            if (fabs(ans.polynomial_.find(rightIterator->first)->second) < eps)
                ans.polynomial_.erase(rightIterator->first);
        }
    return ans;
}

Polynomial operator +(const Polynomial &left, const double &right)
{
    Polynomial ans = left;
    return (ans + Polynomial(0, right));
}

Polynomial operator +(const double &left, const Polynomial &right){
    Polynomial ans = right;
    return (ans + Polynomial(0, left));
}

Polynomial operator *(const double &left, const Polynomial &right){
    if (fabs(left) < eps) return Polynomial(0, 0);
    Polynomial ans = right;
    for (auto ansIterator = ans.polynomial_.begin(); ansIterator != ans.polynomial_.end(); ++ansIterator)
        ansIterator->second *= left;
    return ans;
}

Polynomial operator *(const Polynomial &left, const double &right){
    if (fabs(right) < eps) return Polynomial(0 ,0);
    Polynomial ans = left;
    for (auto ansIterator = ans.polynomial_.begin(); ansIterator != ans.polynomial_.end(); ++ansIterator)
        ansIterator->second *= right;
    return ans;
}

Polynomial operator -(const Polynomial &left, const Polynomial &right){
    Polynomial p = right * (-1);
    return left + p;
}

Polynomial operator -(const Polynomial &left, const double &right)
{
    Polynomial ans = left;
    return (ans - Polynomial(0, right));
}

Polynomial operator -(const double &left, const Polynomial &right){
    Polynomial ans = right;
    return (ans - Polynomial(0, left));
}


/*
 * I don't know why, but polynomial multiplication doesn't work correct for more than 2 arguments. When I tried to use
 * it for 3 arguments(a * b * c), the program crashed, because of attempt to "watch" the region of memory, which hadn't
 * been allocated for the program(process).
 */

Polynomial operator *(const Polynomial &left, const Polynomial &right){
    Polynomial ans;
    for (auto leftIterator = left.polynomial_.begin(); leftIterator != left.polynomial_.end(); ++leftIterator){
        for (auto rightIterator = right.polynomial_.begin(); rightIterator != right.polynomial_.end(); ++rightIterator){
            ans = ans +
                  Polynomial(rightIterator->first + leftIterator->first,
                             rightIterator->second * leftIterator->second);
        }

    }
    return ans;
}

void Polynomial::output() const {
    if (polynomial_.size() == 0){
        std::cout << 0 << "\n";
        return;
    }
    for (auto polynomialIterator = polynomial_.begin(); polynomialIterator != polynomial_.end(); ++polynomialIterator){
        if (fabs(polynomialIterator->second)> eps) {
            if (fabs(polynomialIterator->first) > eps) std::cout << "x^" << polynomialIterator->first << "*";
            std::cout << polynomialIterator->second << "+";
        }
    }
    std::cout << "\n";
}

double Polynomial::value(const double &x){
    double ans = 0.0;
    for (auto iter = polynomial_.begin(); iter != polynomial_.end(); ++iter)
        ans += pow(x, iter->first) * iter->second;
    return ans;
}