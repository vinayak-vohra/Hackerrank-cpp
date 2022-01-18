/**
 * @file cpp-variadics.cpp
 * @author Vinayak Vohra
 * @brief 
 * link: https://www.hackerrank.com/challenges/cpp-variadics/problem
 */

#include <iostream>
#include <cmath>
using namespace std;

// Exit condition for variadic function
template <int power>
int binary_to_decimal()
{
    return 0;
}

// variadic function to find binary
template <int power, bool start, bool... rest>
int binary_to_decimal()
{
    return pow(2, power) * start + binary_to_decimal<power + 1, rest...>();
}

template <bool... digits>
int reversed_binary_value()
{
    return binary_to_decimal<0, digits...>();
}

template <int n, bool... digits>
struct CheckValues
{
    static void check(int x, int y)
    {
        CheckValues<n - 1, 0, digits...>::check(x, y);
        CheckValues<n - 1, 1, digits...>::check(x, y);
    }
};

template <bool... digits>
struct CheckValues<0, digits...>
{
    static void check(int x, int y)
    {
        int z = reversed_binary_value<digits...>();
        std::cout << (z + 64 * y == x);
    }
};

int main()
{
    int t;
    std::cin >> t;

    for (int i = 0; i != t; ++i)
    {
        int x, y;
        cin >> x >> y;
        CheckValues<6>::check(x, y);
        cout << "\n";
    }
}
