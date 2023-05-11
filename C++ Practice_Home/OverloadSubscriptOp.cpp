# include <iostream>
using namespace std;

const int SIZE = 5;

class arraytype{
    int a[SIZE];

public:
    arraytype(){
        for(int i = 0 ; i < SIZE; i++){
            a[i] = (i + 1) * 10;
        }
    }

    int& operator[] (int i){
        return a[i];
    }
};

int main(){
    arraytype ob;

    cout << "\n**************Before assignment***************" << endl;
    for(int i = 0 ; i < SIZE ; i++){
        cout << ob[i] << ' ';
    }
    // ob[i] := ob.operator[](i)

    for(int i = 0 ; i < SIZE ; i++){
        ob[i] = ob[i] + 10;
        // ob[i] can be used both in the right and left of assignment operator since the overloaded function is returning a reference.
    }

    cout << "\n**************After assignment***************" << endl;
    for(int i = 0 ; i < SIZE ; i++){
        cout << ob[i] << ' ';
    }

    cout << endl << endl;

    return 0;
}