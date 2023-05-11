# include <iostream>
# include <cmath>
using namespace std;

class Point
{
    // x and y coordinate
    int x, y;

public:
    //Add necessary constructor(s) to initialize x and y 
    Point(){};
    Point(int p_x, int p_y);

    //Add your set and get functions for x and y
    void setX(int p_x);
    int getX();
    void setY(int p_y);
    int getY();
    
    void print()
    {
        cout << "Coordinate: "<< x <<", " << y << endl;
    }
};

Point::Point(int p_x, int p_y){
    x = p_x;
    y = p_y;
}

void Point::setX(int p_x){
    x = p_x;
}

int Point::getX(){
    return x;
}

void Point::setY(int p_y){
    y = p_y;
}

int Point::getY(){
    return y;
}

class Circle 
{
    Point p;
    int radius;

public:
    // Add necessary constructor(s) to initialize p and radius
    Circle(int c_x, int c_y, int r);

    // Overload “upload” functions 
    void print()
    {
        cout << "Center ";
        p.print();
        cout << "Radius: " << radius << endl; 
    }

    void update(int d_x, int d_y, int d_r){
        p.setX(p.getX() + d_x);
        p.setY(p.getY() + d_y);
        radius += d_r;
    }

    void update(int d_x, int d_y){
        p.setX(p.getX() + d_x);
        p.setY(p.getY() + d_y);
    }

    void update(int d_r){
        radius += d_r;
    }
};

Circle::Circle(int c_x, int c_y, int r){
    p.setX(c_x);
    p.setY(c_y);
    radius = r;
}

class Line{
    Point p1;
    Point p2;

public:
    Line(int a1, int b1, int a2, int b2);

    void printLineLength(){
        int temp_x, temp_y;
        temp_x = p1.getX() - p2.getX();
        temp_y = p1.getY() - p2.getY();

        cout << "Length of the line: " << sqrt(temp_x * temp_x + temp_y * temp_y) << endl;
    }
};

Line::Line(int a1, int b1, int a2, int b2){
    p1.setX(a1);
    p1.setY(b1);
    p2.setX(a2);
    p2.setY(b2);
}

int main()
{
    Point p(5,5);
    Circle c(2, 3, 5);
    Line l(0, 0, 3, 4);
    cout << endl << "Point Display" <<endl;
    p.print(); 
    cout << endl << "Circle Display" <<endl;
    c.print();
    cout << endl;
 
 
    //First update
    cout << "First Update" << endl;
    // call “update” function of Circle class to increase the center’s x 
    // coordinate by 5 and y coordinate by 5; 
    c.update(5, 5);
    c.print();
    cout <<endl;
    
    //Second update
    cout << "Second Update" << endl;
    
    // call “update” function of Circle class to increase the radius by 6;
    c.update(6);
    c.print();
    cout << endl;
    
    //Third update
    cout << "Third Update" << endl;
    
    // call “update” function of Circle class to increase the center’s x 
    // coordinate by 2 and y coordinate by 2 and the radius by 2;
    c.update(2, 2, 2);
    c.print();
    cout << endl;

    //print length of "l"
    l.printLineLength();

    return 0;
}