# include <iostream>
using namespace std;

class base{
    int i;
public:
    base(int i){ cout << "Constructing base class .." << endl; this->i = i; }
    ~base(){ cout << "Destructing base class .." << endl; }
    void show_i(){ cout << "Value for i: " << i << endl; }
};

class derived:public base{
    int j;
public:
    // derived(){ cout << "Constructing derived class .." << endl; }
    derived(int j):base(j){ cout << "Constructing derived class .." << endl; this->j = j; }
    ~derived(){ cout << "Destructing derived class .." << endl; }
    void show_j(){ cout << "Value for j: " << j << endl; }
};

int main(){
    derived obj(10);

    obj.show_i();
    obj.show_j();

    return 0;
}