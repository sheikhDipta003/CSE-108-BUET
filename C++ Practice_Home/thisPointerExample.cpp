# include <iostream>
using namespace std;

class myClass{
    int a, b;

public:
    myClass(int n, int m){
        // a = n;
        this -> a = n;
        // b = m;
        this -> b = m;
    }
    int add(){
        // return (a + b);
        return (this -> a + this -> b);
    }
    void show();
};

void myClass::show(){
    int t;

    t = add();

    cout << "\nSum of a and b: " << t << endl;
}

int main(){
    myClass ob(10, 14);

    ob.show();

    return 0;
}