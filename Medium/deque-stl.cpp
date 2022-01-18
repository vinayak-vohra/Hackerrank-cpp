/**
 * @file deque-stl.cpp
 * @author Vinayak Vohra
 * @brief 
 * link: https://www.hackerrank.com/challenges/deque-stl/problem
 * reference: Geeks for Geeks
 *            https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
 */

#include <iostream>
#include <deque>
using namespace std;

void printKMax(int arr[], int n, int k)
{
    deque<int> subArr(k);

    int i;
    for (i = 0; i < k; ++i)
    {

        while ((!subArr.empty()) && arr[i] >=
                                        arr[subArr.back()])

        {
            subArr.pop_back();
        }

        subArr.push_back(i);
    }

    for (; i < n; ++i)
    {

        cout << arr[subArr.front()] << " ";

        while ((!subArr.empty()) && subArr.front() <=
                                        i - k)

        {
            subArr.pop_front();
        }

        while ((!subArr.empty()) && arr[i] >=
                                        arr[subArr.back()])
            subArr.pop_back();

        subArr.push_back(i);
    }

    cout << arr[subArr.front()] << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t > 0)
    {
        int n, k;
        cin >> n >> k;
        int i;
        int arr[n];
        for (i = 0; i < n; i++)
            cin >> arr[i];
        printKMax(arr, n, k);
        t--;
    }
    return 0;
}
