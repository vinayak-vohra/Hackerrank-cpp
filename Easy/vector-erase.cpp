/**
 * @file vector-erase.cpp
 * @author Vinayak Vohra
 * @brief 
 * link: https://www.hackerrank.com/challenges/vector-erase/problem
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, inp, x, a, b;
    cin >> n;
    vector<int> v;
    while (n != 0)
    {
        cin >> inp;
        v.push_back(inp);
        n--;
    }
    cin >> x >> a >> b;
    v.erase(v.begin() + x - 1);
    v.erase(v.begin() + a - 1, v.begin() + b - 1);
    cout << v.size() << endl;
    for (int c : v)
        cout << c << " ";
    return 0;
}
