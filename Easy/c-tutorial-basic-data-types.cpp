/**
 * @file c-tutorial-basic-data-types.cpp
 * @author Vinayak Vohra
 * @brief printf/scanf
 * link: https://www.hackerrank.com/challenges/c-tutorial-basic-data-types/problem
 */

#include <iostream>
using namespace std;

int main()
{
    int i;    // 4 byte
    long l;   // 8 byte
    char c;   // 1 byte
    float f;  // decimal
    double d; // decimal

    scanf("%d %ld %c %f %lf", &i, &l, &c, &f, &d);

    printf("%d\n", i);
    printf("%ld\n", l);
    printf("%c\n", c);
    printf("%.3f\n", f);
    printf("%.9lf\n", d);
}