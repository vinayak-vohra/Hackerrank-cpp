/**
 * @file c-tutorial-struct.cpp
 * @author Vinayak Vohra
 * @brief 
 * link: https://www.hackerrank.com/challenges/c-tutorial-struct/problem
 */

#include <iostream>
using namespace std;

struct Student
{
    int age;
    int standard;
    string first_name;
    string last_name;
};

int main()
{
    Student st;

    cin >> st.age >> st.first_name >> st.last_name >> st.standard;
    cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard;

    return 0;
}