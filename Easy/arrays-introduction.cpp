/**
 * @file arrays-introduction.cpp
 * @author Vinayak Vohra
 * @brief 
 * link: https://www.hackerrank.com/challenges/arrays-introduction/problem
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v;
    int num, x;
    cin >> num;

    while (num != 0)
    {
        cin >> x;
        v.push_back(x);
        num--;
    }

    reverse(v.begin(), v.end());

    for (int val : v)
        cout << val << " ";
}