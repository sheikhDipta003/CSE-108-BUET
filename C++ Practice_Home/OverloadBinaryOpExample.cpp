# include <iostream>
using namespace std;

class coordinate{
    int x, y;

public:
    coordinate(int a = 0, int b = 0){x = a; y = b;}
    void show(){cout << "x = " << x << "; y = " << y << endl;}
    coordinate operator+(coordinate obj);
    coordinate operator+(int i);
    coordinate operator-(coordinate obj);
    coordinate operator=(coordinate obj);
    coordinate &operator=(Point &p);
    coordinate operator>>(int i);
    coordinate operator<<(int i);
};

class Point{
    int x, y;

public:
    Point(int x, int y){ this->x = x; this->y = y; }
    int getX(){ return x; }
    int getY(){ return y; }
    void show(){ cout << "x = " << x << "; y = " << y << endl; }
};

coordinate coordinate::operator+(coordinate obj){
    coordinate temp;

    temp.x = this->x + obj.x;
    temp.y = this->y + obj.y;

    return temp;
}

coordinate coordinate::operator+(int i){
    coordinate temp;

    temp.x = x + i;
    temp.y = y + i;

    return temp;
}

coordinate coordinate::operator-(coordinate obj){
    coordinate temp;

    temp.x = this->x - obj.x;
    temp.y = this->y - obj.y;

    return temp;
}

coordinate coordinate::operator=(coordinate obj){
    x = obj.x;
    y = obj.y;

    return *this;
    // Changes in the object against which this method will be called will be permanent even if we don't return anything. But then assignment statments could not be chained as in line 72.
}

coordinate& coordinate::operator=(Point &p){
    this->x = p.getX();
    this->y = p.getY();

    return *this;
    // To support chain assignment
}

coordinate coordinate::operator>>(int i){
    // (this->x)>>i;
    // return *this;
    // What is the problem in the above code??

    coordinate temp;

    temp.x = x >> i;
    temp.y = y >> i;

    return temp;
}

coordinate coordinate::operator<<(int i){
    // (this->x)<<i;
    // return *this;
    // What is the problem in the above code??

    coordinate temp;

    temp.x = x << i;
    temp.y = y << i;

    return temp;
}

int main(){
    coordinate c1(20, 20), c2(10, 10);

    cout << "Output - 1" << endl;
    coordinate c3 = c1 + c2;
    c3.show();

    cout << "\nOutput - 2" << endl;
    coordinate c4 = c3 + 5;
    c4.show();

    cout << "\nOutput - 3" << endl;
    coordinate c5 = c2 - c1;
    c5.show();

    cout << "\nOutput - 4" << endl;
    coordinate c6 = c1 + c2 + c3;
    c6.show();
    // (c6-c4).show();

    cout << "\nOutput - 5" << endl;
    c5 = c6 = c6 - c1;
    c5.show();
    c6.show();

    c1 = c2>>1;
    c4 = c3<<2;

    cout << "\nOutput - 6" << endl;
    c1.show();
    c2.show();
    c3.show();
    c4.show();

    coordinate c7(12, 36);
    Point p1(18, 54);

    cout << "\nOutput - 7" << endl;
    cout << "**************Before assignment***************" << endl;
    c7.show();
    p1.show();

    c7 = p1;
    // Gives error in this line. Why?? According to Tanzima Mam, we can assign an object of one class to another object of a different class!!

    cout << "\n**************After assignment***************" << endl;
    c7.show();
    p1.show();

    return 0;
}