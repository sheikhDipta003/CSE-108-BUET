# include <iostream>
using namespace std;

class pwr{
    int base;
    int exponent;
    int result;

public:
    pwr(int b, int e);
    // inserter
    friend ostream &operator<<(ostream &stream, pwr ob);
    friend istream &operator>>(istream &stream, pwr &ob);
};

ostream &operator<<(ostream &stream, pwr ob){
    stream << "base: " << ob.base << ", exponent: " << ob.exponent << ", result: " << ob.result << endl;
    return stream;
}

istream &operator>>(istream &stream, pwr &ob){
    int b, e;

    cout << "Enter base: ";
    stream >> b; // stream >> ob.base gave wrong output!!
    cout << "Enter exponent: ";
    stream >> e; // stream >> ob.exponent gave wrong output!!

    pwr temp(b, e);

    ob = temp;

    return stream;
}

    pwr::pwr(int b, int e)
{
    base = b;
    exponent = e;
    result = 1;

    for(int i = 0 ; i < e ; i++){
        result *= base;
    }
}

int main()
{   
    pwr p(2, 4);

    cout << p;

    cin >> p;

    cout << p;

    return 0;
}
