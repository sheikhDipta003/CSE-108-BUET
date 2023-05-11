# include <iostream>
using namespace std;

class coordinate{
    int x, y;

public:
    coordinate(int a = 0, int b = 0){x = a; y = b;}
    void show(){cout << "x = " << x << "; y = " << y << endl;}
    int operator==(coordinate obj);
    int operator!=(coordinate obj);
    int operator&&(coordinate obj);
    int operator||(coordinate obj);
};

int coordinate::operator==(coordinate obj){
    return (this->x == obj.x && this->y == obj.y);
}

int coordinate::operator!=(coordinate obj){
    return (this->x != obj.x || this->y != obj.y);
}

int coordinate::operator&&(coordinate obj){
    return ((this->x && obj.x) && (this->y && obj.y));
}

int coordinate::operator||(coordinate obj){
    return ((this->x || obj.x) || (this->y || obj.y));
}

int main(){
    coordinate c1(0, 0), c2(20, 20);

    cout << "Output - 1:" << endl;
    if(c1 == c2){
        cout << "c1 and c2 are equal" << endl;
    }
    else{
        cout << "c1 and c2 are not equal" << endl;
    }

    cout << "Output - 2:" << endl;
    if(c1 && c2){
        cout << "Both c1 and c2 are true" << endl;
    }
    else{
        cout << "Both c1 and c2 are not true; at least one of them is false" << endl;
    }

    cout << "Output - 3:" << endl;
    if(c1 || c2){
        cout << "Either c1 or c2 or both are true" << endl;
    }
    else{
        cout << "Neither c1 nor c2 is true" << endl;
    }

    return 0;
}