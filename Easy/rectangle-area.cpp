/**
 * @file rectangle-area.cpp
 * @author Vinayak Vohra
 * @brief 
 * link: https://www.hackerrank.com/challenges/rectangle-area/problem
 */

#include <iostream>

using namespace std;
/*
 * Create classes Rectangle and RectangleArea
 */
class Rectangle
{
    int width, height;

public:
    void update(int w, int h)
    {
        this->width = w;
        this->height = h;
    }
    void display()
    {
        cout << this->width << " " << this->height << endl;
    }
    int area()
    {
        return this->width * this->height;
    }
};

class RectangleArea : public Rectangle
{
public:
    void read_input()
    {
        int w, h;
        cin >> w >> h;
        update(w, h);
    }
    void display()
    {
        cout << area();
    }
};

int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;

    /*
     * Read the width and height
     */
    r_area.read_input();

    /*
     * Print the width and height
     */
    r_area.Rectangle::display();

    /*
     * Print the area
     */
    r_area.display();

    return 0;
}