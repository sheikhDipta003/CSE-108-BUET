# include <iostream>
using namespace std;

class CheckArrBounds{
    int size;
    int *p;

public:
    CheckArrBounds(int num){
        size = num;
        p = new int[size];
    }
    int &put(int i){
        if (i < 0 || i >= size){
            cout << "Out of bounds.." << endl;
        }

        return p[i];    //--> Return a reference to ith element of the array
    }
    int get(int i){
        if (i < 0 || i >= size){
            cout << "Out of bounds.." << endl;
        }
        return p[i];    //--> Return the ith element itself
    }
    ~CheckArrBounds(){
        delete [] p;
    }
};

int main(){
    CheckArrBounds ob(5);
    
    for(int i = 0 ; i < 5 ; i++){
        ob.put(i) = (i + 1) * 100;
    }

    for(int i = 0 ; i < 5 ; i++){
        cout << "Element No. " << (i + 1) << ": " << ob.get(i) << endl;
    }

    return 0;
}