// What is the output of the following program?

#include<iostream>
using namespace std;

class Point{
private:
    int x;
    int y;
public:
    Point(int i = 0, int j = 0); //Normal Constructor
    Point(const Point &t); // Copy Constructor
} ;

Point::Point(int i, int j) {
    x = i; 
    y = j;
    cout << "Normal Constructor called\n";
}

Point :: Point (const Point &t) {
    x = t.x; 
    y = t.y;
    cout << "Copy Constructor called\n";
}

int main ()
{
    Point *t1, *t2;
    t1 = new Point(10, 15);
    t2 = new Point(*t1);

    Point t3 = *t1;
    Point t4;

    t4 = t3;

    return 0;
}
