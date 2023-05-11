# include <iostream>
using namespace std;

void order(int &a, int&b);

int main(){
    int x=1, y=0;

    cout << "\nx = " << x << "; y = " << y;

    order(x, y);

    cout << "\nx = " << x << "; y = " << y << endl;

    return 0;
}

void order(int &a, int&b){
    int t;

    if(a > b){
        t = a;
        a = b;
        b = t;
    }
}