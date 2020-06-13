#include <iostream>
#include "Matrix.h"
#include <initializer_list>
#include "errors.h"




using namespace std;
int main() {

    try {
        Matrix<int> a{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        Matrix<int> b{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        if (a == b)
        {
            cout << "== for matrix is ok" << endl;
        }

        a = Matrix<int>{{1, 2}, {3, 4}, {5, 6}};
        a.transpose();
        if (a ==  initializer_list<initializer_list<int>>{{1, 3, 5}, {2, 4, 6}}){
            cout << "== for initializer_list ok" << endl;
        }

        a = Matrix<int>::unitMatrix(3);
        if (a ==  initializer_list<initializer_list<int>>{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}){
            cout << "unit matrix ok" << endl;
        }





        // *=
        a = Matrix<int> {{1, 2}, {3, 4}};
        b = Matrix<int> {{2, 4}, {6, 8}};
        a *= 2;
        if (a == b)
        {
            cout << "*= value is ok" << endl;
        }


        a = Matrix<int> {{1, 2}, {3, 4}};
        b = Matrix<int> {{1, 2}, {3, 4}};
        Matrix<int> c{{7, 10}, {15, 22}};
        a *= b;
        if (a == c)
        {
            cout << "*= for matrix is ok "<< endl;
        }

        a = Matrix<int> {{1, 2}, {3, 4}};
        a *= {{1, 2}, {3, 4}};

        if (a ==  initializer_list<initializer_list<int>>{{7, 10}, {15, 22}}){
            cout << "*= for initializer list os ok" << endl;
        }






        // *

        a = Matrix<int> {{1, 2}, {3, 4}};
        b = Matrix<int> {{2, 4}, {6, 8}};
        if (a * 2 == b)
        {
            cout << "* value is ok" << endl;
        }


        a = Matrix<int> {{1, 2}, {3, 4}};
        b = Matrix<int> {{1, 2}, {3, 4}};
        c = Matrix<int>{{7, 10}, {15, 22}};
        if (a * b== c)
        {
            cout << "* for matrix is ok "<< endl;
        }

        a = Matrix<int> {{1, 2}, {3, 4}};

        if (( a * initializer_list<initializer_list<int>>{{1, 2}, {3, 4}}) ==  initializer_list<initializer_list<int>>{{7, 10}, {15, 22}}){
            cout << "* for initializer list os ok" << endl;
        }





        a = Matrix<int> {{1, 2}, {3, 4}};
        b = Matrix<int> {{1, 0}, {-2, 2}};
        c = Matrix<int> {{2, 2}, {1, 6}};
        a += b;
        if (a == c)
        {
            cout << "+= for matrix is ok"<< endl;
        }

        a = Matrix<int> {{1, 2}, {3, 4}};
        c = Matrix<int> {{2, 2}, {1, 6}};
        a += {{1, 0}, {-2, 2}};
        if (a == c)
        {
            cout << "+= for initializer list is ok"<< endl;
        }

        a = Matrix<int> {{1, 2}, {3, 4}};
        b = Matrix<int> {{1, 0}, {-2, 2}};
        c = Matrix<int> {{2, 2}, {1, 6}};
        if (a + b == c)
        {
            cout << "+ for matrix is ok"<< endl;
        }

        a = Matrix<int> {{1, 2}, {3, 4}};
        c = Matrix<int> {{2, 2}, {1, 6}};
        if ((a + initializer_list<initializer_list<int>>{{1, 0}, {-2, 2}}) == c)
        {
            cout << "+ for initializer list is ok"<< endl;
        }


        a = Matrix<int> {{1, 2}, {3, 4}};
        b = Matrix<int> {{1, 0}, {-2, 2}};
        c = Matrix<int> {{0, 2}, {5, 2}};
        a -= b;
        if (a == c)
        {
            cout << "-= for matrix is ok"<< endl;
        }

        a = Matrix<int> {{1, 2}, {3, 4}};
        c = Matrix<int> {{0, 2}, {5, 2}};
        a -= {{1, 0}, {-2, 2}};
        if (a == c)
        {
            cout << "-= for initializer list is ok"<< endl;
        }


        a = Matrix<int> {{1, 2}, {3, 4}};
        c = Matrix<int> {{0, 2}, {5, 2}};
        if (a - initializer_list<initializer_list<int>>{{1, 0}, {-2, 2}} == c)
        {
            cout << "- for initializer list is ok"<< endl;
        }

        a = Matrix<int> {{1, 2}, {3, 4}};
        b = Matrix<int> {{1, 0}, {-2, 2}};
        c = Matrix<int> {{0, 2}, {5, 2}};
        if (a - b == c)
        {
            cout << "- for matrix list is ok"<< endl;
        }



        a = Matrix<int> {{1, 3, 3}, {4, 7, 6}, {7, 9, 9}};
        if (a.getDeterminant() == -12);
        {
            cout << "getDeterminant ok" << endl;
        }

        a = Matrix<int> {{1, 2}, {3, 4}};
        a.transpose();
        if (a == initializer_list<initializer_list<int>>{{1, 3}, {2, 4}});
        {
            cout << "transpose 1/2 ok" << endl;
        }

        a = Matrix<int> {{1, 2, 3}, {4, 5, 6}};
        a.transpose();
        if (a == initializer_list<initializer_list<int>>{{1, 4}, {2, 5}, {3, 6}});
        {
            cout << "transpose 2/2 ok" << endl;
        }


    } catch (baseError& error) {
        cout<<error.what()<<endl;
    }

    cout << endl << endl;


    try {
        Matrix<int> e(-2, -2);
    } catch (badInitSizes& error) {
        cout << "badInitSizes error is ok" << endl;
    }

    try {
        Matrix<int> e(2, 2);
        Matrix<int> f(3, 3);
        auto t = e * f;
    } catch (badMultiplySizes& error) {
        cout << "badMultiplySizes error is ok" << endl;
    }


    try {
        Matrix<int> e(2, 2);
        Matrix<int> f(3, 3);
        auto t = e + f;
    } catch (nonEqualSizesError& error) {
        cout << "nonEqualSizes error is ok" << endl;
    }

    try {
        Matrix<int> e(2, 2);
        auto t = e[3][3];
    } catch (badIndexError& error) {
        cout << "badIndexError error is ok" << endl;
    }

    try {
        Matrix<int> e(3, 2);
        e.inverse();
    } catch (UnableToFindDeterminant& error) {
        cout << "UnableToInverse error is ok" << endl;
    }


    try {
        Matrix<int> e(3, 2);
        e.getDeterminant();
    } catch (UnableToFindDeterminant& error) {
        cout << "UnableToFindDeterminant error is ok" << endl;
    }




    return 0;
}