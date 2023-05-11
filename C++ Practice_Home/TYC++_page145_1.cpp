# include <iostream>
using namespace std;

void neg(int &p){
    p = -p;
}

int main(){
    int i = 50;
    cout << "Before passing to f(): i = " << i << endl;
    neg(i);
    cout << "After passing to f(): i = " << i << endl;

    return 0;
}
