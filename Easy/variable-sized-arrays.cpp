/**
 * @file variable-sized-arrays.cpp
 * @author Vinayak Vohra
 * @brief 
 * link: https://www.hackerrank.com/challenges/variable-sized-arrays/problem
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int rows, queries;
    cin >> rows >> queries;

    vector<int> dynamicArr[rows];

    int temp = 0;
    // input rows
    while (temp < rows)
    {
        int len;
        cin >> len; // no. of columns

        // input columns
        while (len != 0)
        {
            int elem;
            cin >> elem;
            dynamicArr[temp].push_back(elem);
            len--;
        }
        temp++;
    }

    // input queries
    while (queries != 0)
    {
        int row, col;
        cin >> row >> col;
        cout << dynamicArr[row][col] << "\n";
        queries--;
    }
}