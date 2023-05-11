# include <iostream>
# include <cstring>
using namespace std;

class base{
    char *name;
public:
    // base(){
    //     name = new char[10 + 1];
    //     strcpy(name, "HelloWorld");
    //     cout << "\nConstructor of base class(default)" << endl;
    // }
    base(char *s){
        int len;
        len = strlen(s);
        name = new char[len + 1];
        strcpy(name, s);
        cout << "\nConstructor of base class(parameterized)" << endl;
    }
    ~base(){
        delete [] name; 
        cout << "Destructor of base class\n" << endl;
    }
    void getName(){cout << "\nName = " << name << endl;}
};

class derived : private base{
    int size;
    int *A;
public:
    // derived(){
    //     size = 5;
    //     A = new int[size]; 
    //     cout << "Constructor of derived class(default)" << endl;
    // }
    derived(int N, char *p) : base(p){
        size = N;
        A = new int[size]; 
        cout << "Constructor of derived class(parameterized)" << endl;
    }
    ~derived(){
        delete [] A; 
        cout << "Destructor of derived class" << endl;
    }
    void setVal(int pos, int val){
        A[pos] = val;
    }
    void showVal(){
        for(int i = 0 ; i < size ; i++){
            cout << "A[" << i << "] = " << A[i] << "\n";
        }
        cout << endl;
    }
};

int main(){
    // derived ob;
    derived ob(10, "Base class");

    cout << "\n";
    // Insert values for the array
    for(int i = 0 ; i < 10 ; i++){
        ob.setVal(i, 10 * i + 10);
    }
    
    ob.showVal();

    return 0;
}