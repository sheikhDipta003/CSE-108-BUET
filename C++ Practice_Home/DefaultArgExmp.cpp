# include <iostream>
using namespace std;

//"b" must be default argument as well for the program to run properly
void f(int a = 0, int b = 0){
    cout << "\na: " << a << "; b: " << b << endl;
}

int main(){
    f();
    f(10);
    f(20, 30);

    return 0;
}