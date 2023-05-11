# include <iostream>
using namespace std;

class base{
public:
    int i;
};

class derived1 : virtual public base{
public:
    int j;
};

class derived2 : virtual public base{
public:
    int k;
};

class derived3 : public derived1, public derived2{
public:
    int product(){ return i * j * k; }
};

int main(){
    derived3 ob;
    ob.derived2::i = -10;
    ob.derived1::i = 10;
    
    ob.j = 20;
    ob.k = 5;

    cout << "\nob.derived1::i = " << ob.derived1::i << "\tob.derived2::i = " << ob.derived2::i << "\tProduct is " << ob.product() << endl;

    cout << "Address of ob.derived1::i = " << &ob.derived1::i << "\tAddress of ob.derived2::i = " 
    << &ob.derived2::i << endl;

    cout << "Address of ob.derived1::j = " << &ob.derived1::j << "\tAddress of ob.derived2::k = " 
    << &ob.derived2::k << endl;

    cout << "Address of ob.derived3::i = " << &ob.derived3::i << "\tob.derived3::j = " << &ob.derived3::j
    << "\tob.derived3::k = " << &ob.derived3::k << endl << endl; 
    
    return 0;
}