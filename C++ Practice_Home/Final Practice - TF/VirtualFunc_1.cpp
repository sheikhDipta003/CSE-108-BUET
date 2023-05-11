# include <iostream>
using namespace std;

class num{
int i;
public:
num(int i){this->i = i;}
virtual void shownum(){
    cout << "number in decimal = " << i << endl;
}
int getVal(){return i;}
};

class outhex : public num{
public:
    outhex(int i) : num(i){}
    void shownum(){
        cout << std::hex << "number in hexadecimal = " << getVal() << endl;
    }
};

class outoct : public num{
public:
    outoct(int i) : num(i){}
    void shownum(){
        cout << std::oct << "number in octal = " << getVal() << endl;
    }
};

int main(){
    num* p;
    num b_ob(10);
    outhex d_ob1(12);
    outoct d_ob2(15);

    cout << "\n\n============================\n";
    p = &b_ob;
    p->shownum();

    p = &d_ob1;
    p->shownum();

    p = &d_ob2;
    p->shownum();

    cout << "\n============================\n\n";

    return 0;
}