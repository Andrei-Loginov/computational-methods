#include <fstream>
#include "Newton.h"

double f(const double &x){
    return exp(3 * x);
}

double der(const double &x){
    return 3 * exp(3 * x);
}

double der2(const double &x){
    return 9 * exp(3 * x);
}

//formula 4 from the book
double der1h2(const double &x, const double &h){
    return (-3 * f(x) + 4 * f(x+ h) - f(x + 2 * h)) / (2 * h);
}

/*
 * d1h1 - first derivative O(h)
 * mist1h1 - first derivative O(h) mistake
 * d1h2 - first derivative O(h^2)
 * mist1h2 - first derivative O(h^2) mistake
 * d2h2 - second derivative
 * mist2h2 - second derivative mistake
 */
struct line{
    double x, y, d1h1, mist1h1, d1h2, mist1h2, d2h2, mist2h2, d1fact, d2fact;
    void output(){
        std::cout << x << " | " << y << " | " << d1fact << " | "<< d1h1 << " | " << mist1h1 << " | " << d1h2 << " | " << mist1h2 << " | ";
        std::cout << d2fact << " | " << d2h2 << " | " << mist2h2 << "\n";
    }
};


//variant 10

int main() {
    freopen("output.txt", "w", stdout);
    std::cout << "Task 1\n";
    double a = 0.0, b = 2.0, h = 0.1;

    //task 1
    std::vector<line> table((int)((b - a) / h) + 1);
    for (int i = 0; i < table.size(); ++i){
        table[i].x = a + i * h;
        table[i].y = f(table[i].x);
        table[i].d1fact = der(table[i].x);
        table[i].d2fact = der2(table[i].x);
    }
    //print the "head" of the table
    std::cout << "x  |y  |f(x)  | f'(x)  | ~f'(x) | mist O(h)| ~~f'(x)| mist O(h^2)| f''(x) | mist O(h^2)\n";

    //fill in the first line
    table[0].d1h1 = (table[1].y - table[0].y) / h;
    table[0].mist1h1 = fabs(table[0].mist1h1 - table[0].d1fact);
    table[0].d1h2 = (-3.0 * table[0].y + 4 * table[1].y - table[2].y) / (2 * h);
    table[0].mist1h2 = fabs(table[0].d1h2 - der(table[0].x));
    table[0].output();

    //fill in the other lines
    for (int i = 1; i < table.size(); ++i) {
        table[i].d1h1 = (table[i].y - table[i - 1].y) / h;
        table[i].mist1h1 = fabs(table[i].d1h1 - table[i].d1fact);
        if (i < table.size() - 1) {
            table[i].d1h2 = (table[i + 1].y - table[i - 1].y) / (2 * h);
            table[i].d2h2 = (table[i + 1].y - 2 * table[i].y + table[i - 1].y) / pow(h, 2);
            table[i].mist2h2 = fabs(table[i].d2h2 - table[i].d2fact);
        }
        else
            table[i].d1h2 = (3 * table[i].y - 4 * table[i - 1].y + table[i - 2].y) / (2 * h);
        table[i].mist1h2 = fabs(table[i].d1h2 - table[i].d1fact);
        table[i].output();
    }
    //let's make the border
    std::cout << "______________________________________________________________________________________________\n";
    //task 2
    std::cout << "Task 2\n";
    double x = 1;
    h = 0.5;
    int k = 1;
    std::cout << "mistake | h\n";
    while (fabs(der1h2(x, h) - der(x)) > fabs(der1h2(x, h / 2) - der(x))){
        std::cout << fabs(der1h2(x, h) - der(x)) << " | " << h << "\n";
        h /= 2;
        k++;
    }
    std::cout << fabs(der1h2(x, h) - der(x)) << " " << h << "\n";
    std::cout << "___________________________\n\n";
    std::cout << "optimal h is 2^-" << k << " = " << pow(2, -k) << "\n";
    std::cout << "_____________________________________________\n";
    std::cout << "Task 3\n";

    std::ifstream fin("input.txt");
    //if (fin.is_open()) std::cout << "The file has been opened successfully\n";
    //else std::cout << "Can't open the file\n";
    int degree;
    double left_border, right_border, x_1;
    std::vector<std::pair<double, double>> v;

    fin >> degree >> left_border >> right_border >> x_1;
    fin.close();
    //std::cout << degree << "\n";
    h = (right_border - left_border) / degree;
    for (double i = left_border; i <= right_border; i+= h)
        v.push_back(std::make_pair(i, f(i)));
    Newton p(x_1, v, degree);
    //p.polynomial().output();
    //p.polynomial().derivative().output();
    Polynomial polynomial_derivative = p.polynomial().derivative();
    std::cout << "P'(" << x_1 << ") = " << polynomial_derivative.value(x_1) << "\n";
    std::cout << "f''(" << x_1 << ") = " << der(x_1) << "\n";
    std::cout << "error: " << fabs(der(x_1) - polynomial_derivative.value(x_1));
    return 0;
}
