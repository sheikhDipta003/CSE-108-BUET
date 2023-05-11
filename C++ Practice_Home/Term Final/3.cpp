// Write an example program to explain the order of execution of constructor functions for multilevel 
// inheritance and multiple inheritance. 

# include <iostream>
# include<cstring>
using namespace std;

class B1{
    char *p;
public:
    B1(char *s){
        int len;
        len = strlen(s) + 1;
        p = new char[len];
        strcpy(p, s);
        cout << "Contructor for B" << endl;
    }
    ~B1(){delete [] p; cout << "Destructor for B" << endl;}
};

class B2{
    int *ID;
public:
    B2(int i1){
        *ID = i1;
        cout << "Contructor for B2" << endl;
    }
    ~B2(){
        delete ID;
        cout << "Destructor for B2" << endl;
    }
};

class D : public B1, public B2{
public:
    D(int i2, char *s2) : B1(s2), B2(i2){cout << "Contructor for D" << endl;}
    ~D(){cout << "Destructor for D" << endl;}
};

int main(){
    D ob(10, "Hello world");

    return 0;
}