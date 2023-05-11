# include <iostream>
using namespace std;

class base{
    int x;
public:
    void set_x(int i){ x = i; }
    int get_x(){ return x; }
};

class derived : public base{
    int y;
public:
    void set_y(int i){ y = i; }
    int get_y(){ return y; }
};

int main(){
    base *p;
    base b_ob;
    derived d_ob;

    p = &b_ob;
    p->set_x(10);
    cout << "\nBase object x = " << p->get_x();

    p = &d_ob;
    p->set_x(100);

    d_ob.set_y(50);

    cout << "\nDerived object x = " << p->get_x() << endl;
    cout << "Derived object y = " << d_ob.get_y() << endl << endl;

    return 0;
}