# include <iostream>

using namespace std;

class Circle{
    double radius;

    public:
        void setRadius(double r);
        double getDiameter();
        double getArea();
        double getCircumference();
};

int main(){
    Circle my_circle;

    my_circle.setRadius(10);
    cout << "\nDiameter: " << my_circle.getDiameter() << endl;
    cout << "Circumference: " << my_circle.getCircumference() << endl;
    cout << "Area: " << my_circle.getArea() << endl;

    return 0;
}

void Circle::setRadius(double r){
    radius = r;
}

double Circle::getDiameter(){
    return 2 * radius;
}

double Circle::getCircumference(){
    return 2 * 3.1416 * radius;
}

double Circle::getArea(){
    return 3.1416 * radius * radius;
}