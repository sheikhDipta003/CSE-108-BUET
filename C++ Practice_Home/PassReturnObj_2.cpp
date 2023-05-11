# include <iostream>
using namespace std;

class Rectangle{
    int *width, *height;

public:
    Rectangle(int w, int h){
        width = new int;
        height = new int;
        *width = w;
        *height = h;
    }
    int area(){
        return (*width) * (*height);
    }
    ~Rectangle(){
        delete width;
        delete height;
    }
};

Rectangle &larger(Rectangle &arg_rectA, Rectangle &arg_rectB){
    if (arg_rectA.area() > arg_rectB.area()){
        return arg_rectA;
    }
    else{
        return arg_rectB;
    }
}

int main(){
    Rectangle rectA(3, 4), rectB(5, 6), rectC(0, 0);
    Rectangle &ref_rectC = rectC;
    ref_rectC = larger(rectA, rectB);

    // cout << "Area of rectA: " << rectA.area() << endl;
    // cout << "Area of rectB: " << rectB.area() << endl;
    cout << "Area of rectC: " << rectC.area() << endl;
    //Unexpected results when reference is not used!

    return 0;
}