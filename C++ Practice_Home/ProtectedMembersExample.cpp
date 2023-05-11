# include <iostream>
using namespace std;

class sample{
    int a;
protected:
    int b;
public:
    int c;
    sample(int n, int m){   a = n; b = m;   }
    int get_a(){ return a; }
    int get_b(){ return b; }
};

int main(){
    sample ob(10, 20);

    // ob.b = 5;
    // protected members cannot be accessed outside of the base class and derived class
    ob.c = 30;

    cout << ob.get_a() << " " << ob.get_b() << " " << ob.c << endl;

    return 0;
}