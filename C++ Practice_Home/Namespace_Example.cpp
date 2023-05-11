# include <iostream>
using namespace std;

namespace first{
    class demo{
        int i;
    public:
        demo(int x){i = x;}
        void set_i(int x){i = x;}
        int get_i(){return i;}
    };

    char str[] = "Illustrating namespaces\n";
    int counter;
}

namespace second{
    int x, y;
}

namespace  third
{
    int a;  // In namespace third
}

int z;  // In global namespace

namespace third{
    int b;  // In namespace third
}

namespace
{
    int c;
    // int c = 200;
}

int main(){
    first::demo ob(10);

    cout << "\nValue of i in ob = " << ob.get_i() << endl;
    ob.set_i(100);
    cout << "Value of i in ob = " << ob.get_i() << endl;
    // Only the class "demo" has been accessed through scope resolution operator. So, we can create object("ob") of this class. This means, all of its public member variables and public member functions can be used normally. We cannot access private members of ob("i") just like we cannot access private members of an object of any class.

    using first::str;   // "str" from namespace "first" has been made visible in this line
    cout << "String in ob = " << str << endl;
    // Once we have brought a variable, array or class name into visibility with the help of keyword "using", we can in future use them directly without using the scope resolution operator.
    
    using namespace first;
    // This line means we are bringing everything within "first" namespace into visibility. So, integer variable "counter" is brought into visibility too. That's why, we can use "counter" directly. In fact, from this line, we can use all the members of namespace "first" directly.
    // We could also write "using namespace::counter"; but then only counter would have been made visible.
    for(counter = 10 ; counter ; counter--){
        cout << counter << " " ;
    }
    cout << endl;

    second::x = 40;
    second::y = 50;
    // By using scope resolution operator like this, we are only accessing "x" and "y" in the above two lines; we are NOT bringing them into visibility in this scope, i.e in the scope of main(). Therefore, in the next line, scope resolution operator is necessary.
    cout << "x = " << second::x << "; y = " << second::y << endl;

    using namespace second;
    demo xob(x), yob(y);
    cout << "x = " << x << "; y = " << y << endl;
    cout << "x = " << xob.get_i() << "; y = " << yob.get_i() << endl;
    // By this line, however, we have brought both the first and second namespace into visibility. So, the classname "demo" from namespace "first" and the two integers "x" and "y" from namespace "second" can be used directly without using the scope resolution operator.

    using namespace third;
    a = b = z = 100;
    cout << "\na = " << a << "; b = " << b << "; z = " << z << endl;

    cout << "\nc = " << c << endl;
    c = 150;
    cout << "c = " << c << endl << endl;

    return 0;
}