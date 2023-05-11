// Explain what is wrong with the following code segment? Rewrite the code to solve
// the problem. What will be the output of the code once you fix it?

# include <iostream>
using namespace std;

class A{
    int x;
public:
    void setX(int i){x = i;}
    void print(){cout << x << endl;}
};

class B : public A{
public:
    B(){setX(10);}
};

class C : public A{
public:
    C(){setX(20);}
};

class D : public B, public C{
};

int main(){
    D d;
    d.print();

    return 0;
}