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
    void setWidth(int w){
        *width = w;
    }
    void setHeight(int h){
        *height = h;
    }
    int getWidth(){
        return *width;
    }
    int getHeight(){
        return *height;
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

void AssignBtoA(Rectangle &ob1, Rectangle &ob2){
    ob1.setHeight(ob2.getHeight());
    ob1.setWidth(ob2.getWidth());
}

int main(){
    Rectangle rectA(3, 4), rectB(10, 5);

    cout << "Area of rectA: " << rectA.area() << endl;
    cout << "Area of rectB: " << rectB.area() << endl;

    // rectA = rectB;
    AssignBtoA(rectA, rectB);
    //Solves PARTIALLY the issue of freeing the same memory multiple times

    cout << "Area of rectA: " << rectA.area() << endl;
    cout << "Area of rectB: " << rectB.area() << endl;

    return 0;
}