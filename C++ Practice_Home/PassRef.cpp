# include <iostream>
using namespace std;

class myClass{
    int num;

public:
    myClass(int x){
        num = x;
        cout << "Constructing " << num << " ..." << endl;
    }
    ~myClass(){
        cout << "Destructing " << num << " ..." << endl;
    }
    int id(){
        return num;
    }
};

// void showID(myClass ob){
//     cout << "Received " << ob.id() << endl;
// }
// Destructor is called twice- 1. When compier exits from showID() and object "ob" gets destroyed and
//                             2. When the entire program terminates

void showID(myClass &ob){
    cout << "Received " << ob.id() << endl;
}
// Destructor is called only once, since no copy of "mainObj" is made when passing through showID()

int main(){
    myClass mainObj(10);

    showID(mainObj);

    return 0;
}
