# include <iostream>
using namespace std;

class Rectangle{
    int width, height;

public:
    Rectangle(int w, int h);
    int area(){
        return (width * height);
    }
};

Rectangle::Rectangle(int w, int h){
    width = w;
    height = h;
}

Rectangle larger(Rectangle arg_rectA, Rectangle arg_rectB){
    if (arg_rectA.area() > arg_rectB.area()){
        return arg_rectA;
    }
    else{
        return arg_rectB;
    }
}

int main(){
    Rectangle rectA(10, 20), rectB(4, 16), rectC(0, 0);
    rectC = larger(rectA, rectB);

    cout << "Area of rectA: " << rectA.area() << endl;
    cout << "Area of rectB: " << rectB.area() << endl;
    cout << "Area of rectC: " << rectC.area() << endl;

    return 0;
}