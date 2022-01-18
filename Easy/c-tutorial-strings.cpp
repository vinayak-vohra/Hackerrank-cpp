/**
 * @file c-tutorial-strings.cpp
 * @author Vinayak Vohra
 * @brief 
 * link: https://www.hackerrank.com/challenges/c-tutorial-strings/problem
 */

#include <iostream>
#include <string>
using namespace std;

string swap(string a, string b)
{
    char temp = a[0];
    a[0] = b[0];
    b[0] = temp;
    return a + " " + b;
}

int main()
{
    // Complete the program
    string s1, s2;
    cin >> s1 >> s2;
    cout << s1.length() << " " << s2.length() << endl
         << s1 + s2 << endl
         << swap(s1, s2);
    return 0;
}
