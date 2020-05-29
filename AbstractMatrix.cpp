#include <iostream>
#include "Matrix2D.h"
#include "Matrix3D.h"

using namespace std;

int main()
{
    unsigned int size2D = 2;
    unsigned int size3D = 3;
    Matrix2D m2a(size2D), m2b(size2D);
    Matrix3D m3a(size3D), m3b(size3D);
    cout << "m2a: " << endl << m2a << endl;
    cout << "m2b: " << endl << m2b << endl;
    m2a += m2b;
    cout << "Result of m2a + m2b: " << endl << m2a;
    m2a *= 5;
    cout << "Result of m2a * 5: " << endl << m2a;
    cout << endl << endl;
    cout << "m3a: " << endl << m3a << endl;
    cout << "m3b: " << endl << m3b << endl;
    m3a += m3b;
    cout << "Result of m3a + m3b: " << endl << m3a;
    m3a *= 5;
    cout << "Result of m3a * 5: " << endl << m3a;
}

