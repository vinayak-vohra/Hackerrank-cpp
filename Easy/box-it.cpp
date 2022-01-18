/**
 * @file box-it.cpp
 * @author Vinayak Vohra
 * @brief 
 * link: https://www.hackerrank.com/challenges/box-it/problem
 */

#include <bits/stdc++.h>

using namespace std;
class Box
{
    int l, b, h;

public:
    Box()
    {
        this->l = this->b = this->h = 0;
    }
    Box(int l, int b, int h)
    {
        this->l = l;
        this->b = b;
        this->h = h;
    }
    Box(const Box &B)
    {
        this->l = B.l;
        this->b = B.b;
        this->h = B.h;
    }

    int getLength()
    {
        return this->l;
    }
    int getBreadth()
    {
        return this->b;
    }
    int getHeight()
    {
        return this->h;
    }
    long long CalculateVolume()
    {
        return (unsigned long long)this->l * this->b * this->h;
    }
    bool operator<(Box const &B)
    {
        if ((this->l < B.l) || (this->l == B.l && this->b < B.b) || (this->l == B.l && this->b == B.b && this->h < B.h))
            return true;
        return false;
    }

    friend ostream &operator<<(ostream &out, const Box &B);
};

ostream &operator<<(ostream &out, const Box &B)
{
    out << to_string(B.l) + " " + to_string(B.b) + " " + to_string(B.h);
    return out;
}

void check2()
{
    int n;
    cin >> n;
    Box temp;
    for (int i = 0; i < n; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            cout << temp << endl;
        }
        if (type == 2)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            temp = NewBox;
            cout << temp << endl;
        }
        if (type == 3)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            if (NewBox < temp)
            {
                cout << "Lesser\n";
            }
            else
            {
                cout << "Greater\n";
            }
        }
        if (type == 4)
        {
            cout << temp.CalculateVolume() << endl;
        }
        if (type == 5)
        {
            Box NewBox(temp);
            cout << NewBox << endl;
        }
    }
}

int main()
{
    check2();
}