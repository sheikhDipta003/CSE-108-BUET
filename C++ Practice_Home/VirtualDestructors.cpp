# include <iostream>
using namespace std;

class base{
public:
    virtual ~base(){
        cout << "Destructing base ..\n" << endl;
    }
};

class derived : public base{
public:
    ~derived(){
        cout << "\nDestructing derived .." << endl;
    }
};

int main(){
    base *p = new derived;
    delete p;

    return 0;
}