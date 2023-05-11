// Consider the following MyInt class which simulates a user-defined integer class:
// Assume that there is no copy constructor available. Overload the following operators for the MyInt class:
// (i) '+' operator so that two MyInt objects can be added.
// (ii) '*' operator so that a MyInt object can be multiplied by an integer (built-in)
// number. The integer number can be in either side ofthe operator. The result should be
// a MyInt object.
// (iii) '=' operator so that one MyInt object can be safety assigned to another MyInt
// object.


# include <iostream>
using namespace std;

class MyInt{
    int *x;
public:
    MyInt(int argx){x = new int; *x = argx;}
    int getx() const {return *x;}
    void setx(int argx){*x = argx;}
    ~MyInt(){delete x;}
    MyInt& operator+(MyInt& i);
    MyInt& operator*(int i);
    friend MyInt& operator*(int i, MyInt ob);
    MyInt& operator=(MyInt& ob){
        x = new int;
        *x = ob.getx();
        return *this;
    }
};

MyInt T(0);

MyInt& MyInt::operator+(MyInt& i){
    T.setx(i.getx() + this->getx());
    return T;
}

MyInt& MyInt::operator*(int i){
    T.setx(this->getx() * i);
    return T;
}

MyInt& operator*(int i, MyInt ob){
    return ob * i;
}

int main(){
    cout << "\n------------------Output 1--------------------" << endl;
    MyInt ob1(10), ob2(20), ob3(0), ob4(0);
    cout << "ob1.getx() = " << ob1.getx() << "\tob2.getx() = " << ob2.getx() << endl;

    cout << "\n------------------Output 2--------------------" << endl;
    ob3 = ob1 + ob2;
    cout << "ob1.getx() = " << ob1.getx() << "\tob2.getx() = " << ob2.getx() << "\tob3.getx() = " << ob3.getx() << endl;

    cout << "\n------------------Output 3--------------------" << endl;
    ob1 = ob1 * 2;
    ob2 = 2 * ob2;
    cout << "ob1.getx() = " << ob1.getx() << "\tob2.getx() = " << ob2.getx() << endl;
    // ob2.getx() is returning garbage value- why??
    // because the int pointer must be re-initialized with "new"

    cout << "\n------------------Output 4--------------------" << endl;
    cout << "ob3.getx() = " << ob3.getx() << "\tob4.getx() = " << ob4.getx() << endl;
    ob4 = ob3;
    cout << "ob3.getx() = " << ob3.getx() << "\tob4.getx() = " << ob4.getx() << endl;

    return 0;
}