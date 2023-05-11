# include <iostream>
using namespace std;

void f(int &r){
    r = 100;
    r++;
}

int main(){
    int i = 50;
    cout << "Before passing to f(): i = " << i << endl;
    f(i);
    cout << "After passing to f(): i = " << i << endl;

    return 0;
}
