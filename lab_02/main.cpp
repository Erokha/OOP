#include <iostream>
#include "Matrix.h"
#include <initializer_list>




using namespace std;
int main() {

    Matrix<double> a{{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
    Matrix<double> b{{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
    a *= b;
    cout << a;
    Matrix<int> c(-2, -2);
    return 0;
}