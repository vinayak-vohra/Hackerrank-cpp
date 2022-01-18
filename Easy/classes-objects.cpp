/**
 * @file classes-objects.cpp
 * @author Vinayak Vohra
 * @brief 
 * link: https://www.hackerrank.com/challenges/classes-objects/problem
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
#include <numeric>
// Write your Student class here
class Student
{
    vector<int> grades;

public:
    void input();
    int calculateTotalScore();
};

void Student::input()
{
    for (int i = 0; i < 5; i++)
    {
        int a;
        cin >> a;
        this->grades.push_back(a);
    }
}

int Student::calculateTotalScore()
{
    return accumulate(this->grades.begin(), this->grades.end(), 0);
}

int main()
{
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students

    for (int i = 0; i < n; i++)
    {
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        int total = s[i].calculateTotalScore();
        if (total > kristen_score)
        {
            count++;
        }
    }

    // print result
    cout << count;

    return 0;
}