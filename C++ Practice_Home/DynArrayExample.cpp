# include <iostream>
using namespace std;

int main(){
    int *p;

    p = new int[5]; // --> Allocate memory for an array consisting of 5 integers
    for(int i = 0 ; i < 10 ; i++){
        p[i] = (i + 1) * 10;
    }

    cout << endl;
    for(int i = 0 ; i < 10 ; i++){
        cout << "p[" << i << "] = " << p[i] << endl;
    }

    delete [] p;    //--> Release memory

    return 0;
}
