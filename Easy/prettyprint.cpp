/**
 * @file prettyprint.cpp
 * @author Vinayak Vohra
 * @brief 
 * link: https://www.hackerrank.com/challenges/prettyprint/problem
 */

#include <iostream>
#include <iomanip>
using namespace std;

// setw(int)         : width of output
// setfill(char)     : character to fill in width
// setprecision(int) : dot precision
// showpos           : show + sign (- is always shown)
// noshowpos         : hide + sign
// hex               : hexadecmial value
// dec               : decimal value
// left              : left align output
// right             : right align output
// fixed             : fixed-point notation
// scientific        : scientific notation

int main()
{
    int T;
    cin >> T;
    cout << setiosflags(ios::uppercase);
    cout << setw(0xf) << internal;
    while (T--)
    {
        double A;
        cin >> A;
        double B;
        cin >> B;
        double C;
        cin >> C;

        cout << hex << left << showbase << nouppercase;
        cout << (long long)A << endl;

        cout << dec << right << setw(15) << setfill('_') << showpos << fixed << setprecision(2);
        cout << B << endl;

        cout << scientific << uppercase << noshowpos << setprecision(9);
        cout << C << endl;
    }
    return 0;
}