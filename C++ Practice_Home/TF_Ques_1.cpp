# include <iostream>
using namespace std;

class Animal{
    int age;

public:
    Animal(){
        cout << "Constructing\n";
        age = 0;
    }
    ~Animal(){
        cout << "Destructing\n";
    }
};

Animal process(Animal f_a){
    cout << "In process\n" ;
    Animal f_b;
    f_b = f_a;
    return f_b;
}

int main(){
    cout << "First line\n";
    Animal a;
    cout << "Second line\n";
    Animal b = a;
    cout << "Third line\n";
    Animal c = process(b);
    cout << "Return line\n";
    return 0;
}