// “There are scenarios when a friend function is very useful for operator overloading”- support this 
// statement for the following class ‘Rational’ by writing a program that has to use friend function for operator 
// overloading.

# include <iostream>
using namespace std;

class Rational 
{ 
    // numerator and denominator 
    int n, d; 
public: 
    //Constructor(s) to initialize n and d 
    Rational() 
    { 
        n=0; 
        d=0; 
    } 
    Rational(int a, int b) 
    { 
        n=a; 
        d=b; 
    } 
    int getNum(){return n;}
    int getDenum(){return d;}
    void setNum(int i){n = i;}
    void setDenum(int i){d = i;}

    friend Rational operator*(int i, Rational r);
};

Rational operator*(int i, Rational r){
    Rational t;
    t.setDenum(r.getDenum());
    t.setNum(i * r.getNum());
    return t;
}

int main(){
    Rational p(3, 5);
    int i = 2;
    p = i * p;
    cout << p.getNum() << " " << p.getDenum() << endl;

    return 0;
}