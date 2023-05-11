# include <iostream>
using namespace std;

class samp{
    int a;

public:
    samp(int x){
        a = x;
    }
    int getValue(){
        return a;
    }
};

class Circle{
    double radius, center_x, center_y;

public:
    Circle(){
        radius = 1;
        center_x = 0.0;
        center_y = 0.0;
    }
    Circle(double r){
        radius = r;
        center_x = 0.0;
        center_y = 0.0;
    }
    Circle(double r, double c_x, double c_y){
        radius = r;
        center_x = c_x;
        center_y = c_y;
    }
    double area(){
        return 3.1416 * radius * radius;
    }
};

int main(){
    // Declaring and initializing array of objects of class "samp"
    // samp myArray[5] = {samp(10), samp(20), samp(30), samp(40), samp(50)};

    //Shorthand for the above
    samp myArray[5] = {10, 20, 30, 40, 50};
    // samp myArray[5]; --> Compile error

    // Declaring and initializing array of objects of class "Circle"
    Circle Array2[3] = {Circle(), Circle(1), Circle(5, 3, 4)};

    //Display the member variables of the individual objects in the array
    for(int i = 0 ; i < 5 ; i++){
        cout << "Object No. " << (i + 1) << ": a = " << myArray[i].getValue() << endl;
    }

    cout << "\nArea of 1st circle: " << Array2[0].area() << endl;
    cout << "Area of 2nd circle: " << Array2[1].area() << endl;
    cout << "Area of 3rd circle: " << Array2[2].area() << endl;

    return 0;
}