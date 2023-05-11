# include <iostream>
using namespace std;

class MyBase{
public:
    int x;
    MyBase(int m){  x = m;  }
    void show_x(){  cout << "\nx = " << x << " ; "; }
};

class MyDerived:public MyBase{
public:
    int y;
    MyDerived():MyBase(0){
        y = 0;
    }
    MyDerived(int x):MyBase(x){y = 0;}
    MyDerived(int x, int y):MyBase(x){ this->y = y; }
    void show_y(){  cout << "y = " << y << endl; }
};

int main(){
    MyDerived o1;   // x = 0, y = 0
    MyDerived o2(5);    // x = 5, y = 0
    MyDerived o3(6, 7);     // x = 6, y = 7

    o2.show_x();
    o2.show_y();
    o3.show_x();
    o3.show_y();

    return 0;
}