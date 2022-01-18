/**
 * @file c-tutorial-for-loop.cpp
 * @author Vinayak Vohra
 * @brief 
 * link: https://www.hackerrank.com/challenges/c-tutorial-for-loop/problem
 */

#include <iostream>
using namespace std;

int main()
{
    int start, end;
    cin >> start >> end;
    string name[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    for (; start <= end; start++)
    {
        if (start > 9)
        {
            if (start % 2 == 0)
                cout << "even\n";
            else
                cout << "odd\n";
        }
        else
        {
            cout << name[start - 1] << "\n";
        }
    }
}