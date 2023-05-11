# include <iostream>
# include <cstdlib>
using namespace std;

class array{
    int *p;
    int size;

public:
    array(int N){
        p = new int[N];
        size = N;
        cout << "Using a normal constructor\n";
    }
    ~array(){
        delete [] p;
    }
    array(const array &a);
    void put(int i, int j){
        if (i >= 0 && i <= size){
            p[i] = j;
        }
    }
    int get(int i){
        if (i >= 0 && i <= size){
            return p[i];
        }
        else{
            return EOF;
        }
    }
};

// Creates a different memory location to store the copy of "num", i.e. "x" and copies the contents of "num" to "x"
array::array(const array &a){
    size = a.size;
    p = new int[a.size];
    for(int i = 0 ; i < size ; i++){
        p[i] = a.p[i];  //How are we being able to access private member variable "p" outside of the class?
    }
    cout << "Using copy constructor\n"; 
}

int main(){
    array num(10);

    for(int i = 0 ; i < 10 ; i++){
        num.put(i, (i + 1) * 10);
    }

    cout << "\nThe array elements of num:" << endl;
    for(int i = 0 ; i < 10 ; i++){
        cout << num.get(i) << endl;
    }

    array x = num;  //This will invoke copy constructor
    cout << "\nThe array elements of x:" << endl;
    for(int i = 0 ; i < 10 ; i++){
        cout << x.get(i) << endl;
    }

    return 0;
}