# include <iostream>
using namespace std;

class samp{
    int i, j;

public:
    samp(int a, int b){ i = a; j = b; }
    // If we define the body of a member function inside the class, it automatically becomes an "inline" function. And it is common practice(not mandatory) to write the body of such function in one line if its definition is short enough.

    inline int divisible();
};

int samp::divisible(){
    return !(i % j);
}
//We can inline a member function as well. And it is sufficient to "inline" a function in either the prototype or the definition.

inline int min(int a, int b){
    return a < b ? a : b;
}

inline long min(long a, long b){
    return a < b ? a : b;
}

inline double min(double a, double b){
    return a < b ? a : b;
}
// We can also inline overloaded functions.

int main(){
    samp ob1(10, 2), ob2(10, 3);

    if(ob1.divisible()){
        cout << "10 is divisible by 2" << endl;
    }

    if(ob2.divisible()){
        cout << "10 is not divisible by 3" << endl;
    }

    cout << min(10, 5) << endl;
    cout << min(10.882, 5.192) << endl;
    cout << min(10384575L, 52029384L) << endl;

    return 0;
}