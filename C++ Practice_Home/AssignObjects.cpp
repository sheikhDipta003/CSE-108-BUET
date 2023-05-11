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
    Rectangle rectA(3, 4), rectB(10, 5);

    cout << "Area of rectA: " << rectA.area() << endl;
    cout << "Area of rectB: " << rectB.area() << endl;

    rectA = rectB;

    cout << "Area of rectA: " << rectA.area() << endl;
    cout << "Area of rectB: " << rectB.area() << endl;

    return 0;
}