# include <iostream>
using namespace std;

class myClass{
    int x, y;
public:
    myClass(int a, int b){ x = a; y = b; }
    friend ostream& operator<<(ostream& out, myClass ob);
    friend istream& operator>>(istream& in, myClass& ob);
    int getX(){ return x; }
    int getY(){ return y; }
};

ostream& operator<<(ostream& out, myClass ob){
    out <<"\nx = " << ob.x << "; y = " << ob.y << endl;

    return out;
} 

istream& operator>>(istream& in, myClass& ob){
    int x, y;

    cout << "Enter x: ";
    in >> x;
    cout << "Enter y: ";
    in >> y;

    ob.x = x;
    ob.y = y;

    return in;
}

int main(){
    myClass firstOb(100, 50), secOb(0, 0);

    cout << firstOb;

    cin >> secOb;

    cout << "x = " << secOb.getX() << "; y = " << secOb.getY() << endl << endl;

    return 0;
}


