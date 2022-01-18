/**
 * @file c-tutorial-pointer.cpp
 * @author Vinayak Vohra
 * @brief 
 * link: https://www.hackerrank.com/challenges/c-tutorial-pointer/problem
 */

#include <iostream>
using namespace std;

void update(int *a, int *b)
{
    *a = *a + *b;
    *b = abs(*a - 2 * (*b));
}

int main()
{
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}