# include <iostream>
using namespace std;

class myClass{
    // static int i;
public:
    static int i;
    void set_i(int n){i = n;}
    int get_i(){return i;}
};

int myClass::i;

int main(){
    myClass o1, o2;

    myClass::i = 25;

    // o1.set_i(100);

    cout << "\no1.get_i() = " << o1.get_i() << "\to2.get_i() = " << o2.get_i() << endl << endl;
    
    return 0;
}