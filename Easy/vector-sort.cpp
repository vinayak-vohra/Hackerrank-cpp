/**
 * @file vector-sort.cpp
 * @author Vinayak Vohra
 * @brief 
 * link: https://www.hackerrank.com/challenges/vector-sort/problem
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, a;
    cin >> n;
    vector<int> v;
    while (n != 0)
    {
        cin >> a;
        v.push_back(a);
        n--;
    }
    sort(v.begin(), v.end());
    for (int s : v)
        cout << s << " ";
    return 0;
}
