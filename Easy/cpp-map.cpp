/**
 * @file cpp-map.cpp
 * @author Vinayak Vohra
 * @brief 
 * link: https://www.hackerrank.com/challenges/cpp-map/problem
 */

#include <iostream>
#include <map>
using namespace std;

class Map
{
    map<string, int> m;

public:
    void insert(string, int);
    void remove(string);
    int has(string);
};

void Map::insert(string name, int marks)
{
    int m = this->has(name);
    if (m)
        this->remove(name);
    this->m.insert(make_pair(name, marks + m));
}

void Map::remove(string name)
{
    this->m.erase(name);
}

int Map::has(string name)
{
    map<string, int>::iterator it = this->m.find(name);
    if (it == this->m.end())
        return 0;
    return it->second;
}
int main()
{
    Map m;
    int n, marks, type;
    string name;
    cin >> n;
    while (n != 0)
    {
        cin >> type >> name;
        switch (type)
        {
        case 1:
            cin >> marks;
            m.insert(name, marks);
            break;
        case 2:

            m.remove(name);
            break;
        case 3:
            cout << m.has(name) << endl;
            break;
        }
        n--;
    }
}
