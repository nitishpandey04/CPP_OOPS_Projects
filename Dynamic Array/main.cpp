#include <bits/stdc++.h>

using namespace std;

#include "DynamicArray.cpp" 

int main() {

    DynamicArray d1;

    d1.insert(10);
    d1.insert(20);
    d1.insert(30);
    d1.insert(40);
    d1.insert(50);
    d1.insert(60);

    d1.print();

    cout << "Sum of d1 is " << d1.sum() << "\n";

    cout << "Max of d1 is " << d1.max() << "\n";

    cout << "Min of d1 is " << d1.min() << "\n";

    cout << "Third value of d1 is " << d1.get(2) << "\n";

    DynamicArray d2(d1); // copy constructor doing deep copy

    DynamicArray d3;

    d3 = d1; // copy assignment operator doing deep copy

    d1.insert(1, 70);

    d1.print();
    d2.print();
    d3.print();

    return 0;
}
