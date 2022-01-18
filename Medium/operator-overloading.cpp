/**
 * @file operator-overloading.cpp
 * @author Vinayak Vohra
 * @brief 
 * link: https://www.hackerrank.com/challenges/operator-overloading/problem
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Matrix
{
public:
    vector<vector<int>> a;
    Matrix operator+(Matrix &);
};

Matrix Matrix::operator+(Matrix &m)
{
    Matrix c;
    vector<int> v;
    for (auto i = 0; i < m.a.size(); i++)
    {
        for (auto j = 0; j < m.a[0].size(); j++)
        {
            v.push_back(this->a[i][j] + m.a[i][j]);
        }
        c.a.push_back(v);
        v.clear();
    }
    return c;
}

int main()
{
    int cases, k;
    cin >> cases;
    for (k = 0; k < cases; k++)
    {
        Matrix x;
        Matrix y;
        Matrix result;
        int n, m, i, j;
        cin >> n >> m;
        for (i = 0; i < n; i++)
        {
            vector<int> b;
            int num;
            for (j = 0; j < m; j++)
            {
                cin >> num;
                b.push_back(num);
            }
            x.a.push_back(b);
        }
        for (i = 0; i < n; i++)
        {
            vector<int> b;
            int num;
            for (j = 0; j < m; j++)
            {
                cin >> num;
                b.push_back(num);
            }
            y.a.push_back(b);
        }
        result = x + y;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                cout << result.a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
