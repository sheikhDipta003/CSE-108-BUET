// What is the output of the following code segment?

# include <iostream>
using namespace std;

int& f();
int x;

int main(){
    f() = 10;

    int a = 10;
    int b = 10;

    int& ref = a;
    ref = b;

    cout << a << " " << b << " " << ref << " " << x << endl;

    return 0;
}

int& f(){return x;}