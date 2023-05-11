# include <iostream>
using namespace std;

class coordinate{
    int x, y;

public:
    coordinate(int a = 0, int b = 0){x = a; y = b;}
    void show(){cout << "x = " << x << "; y = " << y << endl;}
    friend coordinate operator+(coordinate obj1, coordinate obj2);
    friend coordinate operator+(int i, coordinate obj);
    friend coordinate operator+(coordinate obj, int i);
    friend coordinate operator++(coordinate &obj);
    //Here we need to pass a reference to the calling object, because we want the changes performed inside this overloaded operator function to be reflected to the calling object as well.
};

coordinate operator+(coordinate obj1, coordinate obj2){
    coordinate temp;

    temp.x = obj1.x + obj2.x;
    temp.y = obj1.y + obj2.y;

    return temp;
}

coordinate operator+(int i, coordinate obj){
    coordinate temp;

    temp.x = i + obj.x;
    temp.y = i + obj.y;

    return temp;
}

coordinate operator+(coordinate obj, int i){
    coordinate temp;

    temp.x = i + obj.x;
    temp.y = i + obj.y;

    return temp;
}

coordinate operator++(coordinate &obj){
    obj.x++;
    obj.y++;

    return obj;
}

int main(){
    coordinate c1(20, 20), c2(10, 10);

    cout << "\nOutput - 1:" << endl;
    coordinate c3 = c1 + c2;
    c3.show();

    cout << "\nOutput - 2:" << endl;
    coordinate c4 = 5 + c3;
    c4.show();

    c4 = c4 + 5;
    c4.show();
    // The int constant(5) can be both on the left and right side of "+" operator

    (++c4).show();
    // ++c4;
    // c4.show();

    return 0;
}