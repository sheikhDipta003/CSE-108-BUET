# include <iostream>
using namespace std;

int main(){
    int *p;

    p = new int(10);
    //set initial value of *p to 10

    if(!p){
        cout << "\nAllocation error!" << endl;
        return -1;
    }

    cout << "*p = " << *p << endl;
    *p = 100;
    cout << "Now, *p = " << *p << endl;

    delete p;

    return 0;
}