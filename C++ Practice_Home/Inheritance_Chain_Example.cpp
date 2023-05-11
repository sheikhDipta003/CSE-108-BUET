# include <iostream>
using namespace std;

class Point{
    double x, y;
public:
    Point(double x, double y){
        this->x = x;
        this->y = y;
    }
    void get_xy(double &x, double &y){
        x = this->x;
        y = this->y;
    }
    virtual double area(){return 0.0;}
};

class Circle : public Point{
protected:
    double rad;
public:
    Circle(double x, double y, double r);
    double area(){return 3.14 * rad * rad;}
};

Circle::Circle(double x, double y, double r) : Point(x, y){
    rad = r;
}

class Cylinder : public Circle{
    double height;
public:
    Cylinder(double x, double y, double r, double h);
    double area(){return 2 * 3.14 * rad * height;}
    double volume(){return 3.14 * rad * rad * height;}
};

Cylinder::Cylinder(double x, double y, double r, double h) : Circle(x, y, r){
    height = h;
}

int main(){
    Point p(0, 0);
    double p_x, p_y;
    p.get_xy(p_x, p_y);
    cout << "\n***    Point   ***" << endl;
    cout << "x = " << p_x << "; y = " << p_y << endl;

    Point *q;
    Circle c2(-1, -1, 10);
    q = &c2;
    cout << "\n***    Checking virtual function's usage   ***" << endl;
    cout << q->area() << endl;

    Circle c(3, 4, 5);
    c.get_xy(p_x, p_y);
    // member variable for storing radius "rad" cannot be accessed through "c" since it is protected
    cout << "\n***    Circle   ***" << endl;
    cout << "x = " << p_x << "; y = " << p_y << "; Area = " << c.area() << endl;

    Cylinder cyl(6, -8, 10, 20);
    cyl.get_xy(p_x, p_y);
    // member variable for storing radius "rad" cannot be accessed through "c" since it is protected
    // member variable for storing height "height" cannot be accessed through "cyl" since it is private
    cout << "\n***    Cylinder   ***" << endl;
    cout << "x = " << p_x << "; y = " << p_y << "; Area = " << cyl.area() << "; Volume = " << cyl.volume() << endl;

    return 0;
}