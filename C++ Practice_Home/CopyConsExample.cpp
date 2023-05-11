# include <iostream>
using namespace std;

class Rectangle{
    int *width, *height;

public:
    Rectangle(int, int);
    Rectangle(const Rectangle &r);
    ~Rectangle(){
        delete width;
        delete height;
        cout << "Destructing ..." << endl;
    }
    int area(){
        return (*width) * (*height);
    }
};

Rectangle::Rectangle(int w, int h){
    width = new int;
    height = new int;
    *width = w;
    *height = h;
    cout << "Constructing ..." << endl;
}

Rectangle::Rectangle(const Rectangle &r){
    width = new int;
    height = new int;
    *width = *(r.width);
    *height = *(r.height);
    cout << "Copy constructing ..." << endl;
}

Rectangle larger(Rectangle f_recta, Rectangle f_rectb){
    if(f_recta.area() > f_recta.area()){
        return f_recta;
    }
    else{
        return f_rectb;
    }
}

int main(){
    Rectangle recta(3, 4), rectb(5, 6), rectLarger(0, 0);
    // In this line, 3 objects of "Rectangle" class will be created. Hence, 3 normal constructors will be called.

    Rectangle rectc = recta;
    // Now, since this statement is actually "Initialization", copy constructor will be called which will receive the reference of "recta".

    // Rectangle rectLarger = larger(recta, rectb);
    //But if we uncomment line no. 52 instead, then copy constructor will be called and bit by bit copy will not be performed. Rather copy constructor will create a different memory location that the "width" and "height" pointers of "rectLarger" will point to and copy just the values "*width" and "*height" from "temp" to that location. Thus, even after "temp" is destroyed, it will not affect "rectLarger", since its "width" and "height" point to different memory location.

    rectLarger = larger(recta, rectb);
    // In this line, the two arguments "recta" and "rectb" are passed to "f_recta" and "f_rectb" respectively. Hence, copy constructor will be called twice. Again, before the function terminates, compiler will generate a temporary object("temp"), store the return value in "temp" and return "temp" to "main". Thus, copy constructor will be called once again. Then destructor will be called twice since both "f_recta" and "f_rectb" go out of scope. At last, after the assignment has been performed, "temp" will go out of scope too, calling its destructor as well.
    // Exactly what happens in this assignment statement, other than cons and des calling, is unlcear though!
    // => In line no 53, since it is a simple assignment statement, copy constructor will not be called. Instead, all the member variables of "temp" will be bit by bit copied to "rectLarger". This means, the "width" and "height" pointers of both "temp" and "rectLarger" will point to the same memory location. Thus, when "temp" is freed after assignment has been done, compiler gets permission to use that memory as it wants. As a result, garbage value is stored in "*width" and "*height" of "rectLarger"(since it shared the same memory with "temp") and we get the unexpected output!

    cout << "area of recta: " << recta.area() << endl;
    cout << "area of rectb: " << rectb.area() << endl;
    cout << "area of rectc: " << rectc.area() << endl;
    cout << "area of rectLarger: " << rectLarger.area() << endl;

    return 0;

    // Finally, when execution of "main" ends, destructors for "recta", "rectb", "rectc", and "rectLarger" will be called.
}