# include <iostream>
# include <cstdlib>
using namespace std;

class base{
public:
    int i;
    base(int x){ i = x; }
    virtual void func(){
        cout << "\nUsing base version of func(): " << endl;
        cout << "i = " << i << endl;
    }
};

class derived1: public base{
public:
    derived1(int x) : base(x){}
    void func(){
        cout << "Using derived1's version of func(): " << endl;
        cout << "Square of i = " << i * i << endl;
    }
};

class derived2 : public base{
public:
    derived2(int x): base(x){}
    void func(){
        cout << "Using derived1's version of func(): " << endl;
        cout << "Cube of i = " << i * i * i << endl << endl;
    }
    // If the virtual function func() defined in base class is not redefined here, then at runtime when the compiler tries to access derived2's version of func() it will not find it and hence it will execute base class's func() instead.
};

int main(){
    base *p;
    // base ob(10);
    derived1 d_ob1(25);
    derived2 d_ob2(30);
    int j;

    // p = &ob;
    // p->func();

    // p = &d_ob1;
    // p->func();

    // p = &d_ob2;
    // p->func();

    for(int i = 0; i < 3 ; i++){
        j = rand();
        if(j % 2){ p = &d_ob1; }
        else{ p = &d_ob2; }

        p->func();
    }
    // randomly calls functions of d_ob1 and d_ob2

    return 0;
}