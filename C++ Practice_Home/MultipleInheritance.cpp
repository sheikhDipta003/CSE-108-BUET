# include <iostream>
using namespace std;

class B1{
    int a;
public:
    B1(int x){ cout << "\nInside B1's constructor"; a = x; }
    ~B1(){ cout << "\nInside B1's destructor"; }
    int get_a(){ return a; }
};

class B2{
    int b;
public:
    B2(int x){ cout << "\nInside B2's constructor"; b = x; }
    ~B2(){ cout << "\nInside B2's destructor"; }
    int get_b(){ return b; }
};

class D: public B1, public B2{
    int c;
public:
    D(int x, int y, int z) : B2(z), B1(y){ cout << "\nInside D's constructor"; c = x; }
    ~D(){ cout << "\nInside D's destructor"; }
    void show(){
        cout << "\n" << get_a() << " " << get_b() << endl << c << endl;
    }
};

int main(){
    D ob(10, 20, 30);

    ob.show();

    return 0;
}

// Theoretically, constructors for the two base classes B1 and B2 should be called from left to right or left to right AS SPECIFIED IN THE INHERITANCE LIST in the declaration of class D [Therefore, B2's constructor should be called before B1 in this case]. But this is not happening! B1's constructor is always being called before B2!!!