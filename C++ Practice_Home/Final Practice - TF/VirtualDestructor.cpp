# include <iostream>
using namespace std;

class base{
public:
    base(){
        cout << "Constructing base\n";
    }
    virtual ~base(){
        cout << "Destructing base\n";
    }
    //use of virtual destructor
};

class derived : public base{
public:
    derived(){
        cout << "Constructing derived\n";
    }
    ~derived(){
        cout << "Destructing derived\n";
    }
};

int main(){

    cout << "\n\n===========================\n";
    derived d;
    base *p;
    p = &d;
    delete p;
    cout << "\n===========================\n\n";

    return 0;
}