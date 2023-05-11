# include <iostream>
using namespace std;

class coordinate{
    int x, y;

public:
    coordinate(int a = 0, int b = 0){x = a; y = b;}
    void show(){cout << "x = " << x << "; y = " << y << endl;}
    coordinate operator++();
    coordinate operator++(int unused);
    coordinate operator-();
    coordinate operator-(coordinate obj);
};

coordinate coordinate::operator++(){
    ++x;
    ++y;
    return *this;
}
//prefix unary plus

coordinate coordinate::operator++(int unused){
    coordinate temp;
    temp.x = x++;
    temp.y = y++;

    return temp;
}
//postfix unary plus

coordinate coordinate::operator-(){
    coordinate temp;

    temp.x = -x;
    temp.y = -y;

    return temp;
    // Since a new "temp" object is created, it will not affect the original values of x and y of c1

    // this->x = -x;
    // this->y = -y;

    // return *this;
    // This permenantly changes the values of x and y of c1
}

coordinate coordinate::operator-(coordinate obj){
    // Method 1:
    // coordinate temp;

    // temp.x = this->x - obj.x;
    // temp.y = this->y - obj.y;

    // Method 2:
    coordinate temp = *this;
    x++;
    y++;

    return temp;
}

int main(){
    coordinate c1(10, 10), c2(10, 10);

    cout << "Output - 1:" << endl;
    coordinate c3 = ++c1;
    c1.show();
    c3.show();

    cout << "\nOutput - 2:" << endl;
    coordinate c5 = -c1;
    c1.show();
    c5.show();

    cout << "\nOutput - 3:" << endl;
    coordinate c6 = c3 - c2;
    c6.show();

    cout << "\nOutput - 4:" << endl;
    coordinate c7 = c2++;
    c2.show();
    c7.show();

    return 0;
}