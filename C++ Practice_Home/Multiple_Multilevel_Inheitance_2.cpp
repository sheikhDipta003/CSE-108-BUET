# include <iostream>
using namespace std;

class B1{
    int *m;
public:
    B1(int x){
        m = new int(x);
        cout << "\nConstructor for B1\n";
    }
    ~B1(){ delete m; cout << "Destructor for B1\n"; }
    void show_m(){ cout << "\nm = " << *m << "\t"; }
};

// class B2{
//     int *n;
// public:
//     B2(int x){
//         n = new int(x);
//         cout << "Constructor for B2\n";
//     }
//     ~B2(){ delete n; cout << "Destructor for B2\n"; }
//     void show_n(){ cout << "n = " << *n << "\t"; }
// };

class B2 : public B1{
    int *n;
public:
    B2(int x, int y) : B1(y){
        n = new int(x);
        cout << "Constructor for B2\n";
    }
    ~B2(){ delete n; cout << "Destructor for B2\n"; }
    void show_n(){ cout << "n = " << *n << "\t"; }
};

class D : public B2{
    int *k;
public:
    D(int a, int b, int c) : B2(b, c){
        k = new int(a);
        cout << "Constructor for D\n";
    }
    ~D(){ delete k; cout << "Destructor for D\n"; }
    void show_k(){ cout << "k = " << *k << "\n\n"; }
};

int main(){
    D ob(5, 10, 15);
    ob.show_m();
    ob.show_n();
    ob.show_k();

    return 0;
}