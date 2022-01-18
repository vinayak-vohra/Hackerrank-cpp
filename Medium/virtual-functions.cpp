/**
 * @file virtual-functions.cpp
 * @author Vinayak Vohra
 * @brief 
 * link: https://www.hackerrank.com/challenges/virtual-functions/problem
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include <numeric>
class Person
{
    int age;
    string name;

public:
    virtual void getdata()
    {
        cin >> this->name >> this->age;
    }
    virtual void putdata()
    {
        cout << this->name << " " << this->age << " ";
    }
};

class Professor : public Person
{
    int publications, id;

public:
    static int counter;
    void getdata()
    {
        Person::getdata();
        cin >> this->publications;
        counter++;
        this->id = counter;
    }
    void putdata()
    {
        Person::putdata();
        cout << this->publications << " " << this->id << endl;
    }
};
int Professor::counter = 0;

class Student : public Person
{
    vector<int> marks;
    int id;

public:
    static int counter;
    void getdata();
    void putdata()
    {
        Person::putdata();
        cout << accumulate(this->marks.begin(), this->marks.end(), 0) << " " << this->id << endl;
    }
};
int Student::counter = 0;

void Student::getdata()
{
    Person::getdata();
    for (int i = 0; i < 6; i++)
    {
        int n;
        cin >> n;
        this->marks.push_back(n);
    }
    counter++;
    this->id = counter;
}

int main()
{

    int n, val;
    cin >> n; //The number of objects that is going to be created.
    Person *per[n];

    for (int i = 0; i < n; i++)
    {

        cin >> val;
        if (val == 1)
        {
            // If val is 1 current object is of type Professor
            per[i] = new Professor;
        }
        else
            per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.
    }

    for (int i = 0; i < n; i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;
}