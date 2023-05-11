# include <iostream>
# include <cstdlib>
using namespace std;

class num{  
public:
    int i;
    num(int x){ i = x; }
    virtual void shownum(){
        cout << "\nDecimal = " << i << endl;
    }
};

class outOct : public num{
public:
    outOct(int x) : num(x){}
    void shownum(){
        cout << "Octal = " << oct << i << endl;
    }
};

class outHex : public num{
public:
    outHex(int x) : num(x){}
    void shownum(){
        cout << "Hexadecimal = " << hex << i << endl;
    }
};

int main(){
    num *p;
    outOct ob1(10);
    outHex ob2(10);

    p = &ob1;
    p->shownum();

    p = &ob2;
    p->shownum();

    return 0;
}