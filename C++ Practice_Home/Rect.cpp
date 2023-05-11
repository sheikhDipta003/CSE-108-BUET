# include <iostream>
using namespace std;

class Rectangle{
    int *width, *height;

public:
    Rectangle(int w, int h);
    ~Rectangle();
    int area(){
        return (*width) * (*height);
    }
};

Rectangle::Rectangle(int w, int h){
    width = new int;
    height = new int;

    *width = w;
    *height = h;
}

Rectangle::~Rectangle(){
    delete width;
    delete height;
}

int main(){
    Rectangle rectA(3, 4), rectB(10, 5), *rectP, *rectQ;

    rectP = new Rectangle(5, 6);
    rectQ = &rectB;

    cout << "Area of rectA: " << rectA.area() << endl;
    cout << "Area of rectB: " << rectB.area() << endl;
    cout << "Area of rectP: " << rectP->area() << endl;
    cout << "Area of rectQ: " << rectQ->area() << endl;

    delete rectP;

    return 0;
}