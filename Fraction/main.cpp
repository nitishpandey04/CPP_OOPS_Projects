#include <bits/stdc++.h>

using namespace std;

#include "fraction.cpp" 

int main() {

    cout << "pre increment test\n";

    Fraction f1(10, 2);

    Fraction f2 = f1;

    ++f2;

    Fraction f3 = ++f2;

    Fraction f4 = ++(++f2);

    f1.print();
    f2.print();
    f3.print();
    f4.print();

    ++(++f4);

    f4.print();

    cout << "post increment test\n";

    Fraction f5 = f1 ++;

    f1.print();
    f5.print();

    cout << "assignment operators test\n";
    f5 += f1;
    Fraction f6 = f5 += f1;
    f5.print();
    f6.print();

    Fraction f7 = f5 -= f1;
    Fraction f8 = f5 *= f1;
    Fraction f9 = f5 /= f1;

    f5.print();
    f7.print();
    f8.print();
    f9.print();

    return 0;
}
