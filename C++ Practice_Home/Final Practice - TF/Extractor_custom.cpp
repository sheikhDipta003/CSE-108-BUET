# include <iostream>
# include <cstring>
using namespace std;

int p(int b, int e);

class pwr{
    int base;
    int exponent;
    double result;
public:
    pwr(int base, int exponent){
        this->base = base;
        this->exponent = exponent;
        this->result = p(base, exponent);
    }
    pwr(){}
    friend ostream& operator<<(ostream& out, pwr& ob);
    friend istream& operator>>(istream& in, pwr& ob);
};

ostream &operator<<(ostream &out, pwr& ob){
    out << ob.base << "^" << ob.exponent << " = " << ob.result << endl;
    return out;
}

istream &operator>>(istream &in, pwr& ob){
    cout << "Enter base: ";
    in >> ob.base;
    cout << "Enter exponent: ";
    in >> ob.exponent;
    ob.result = p(ob.base, ob.exponent);
    return in;
}

int p(int b, int e){
    if(e == 0 || b == 1){
        return 1;
    }
    double result = 1;
    for (int i = 1; i <= e; i++)
    {
        result *= b;
    }
    return result;
}

int main()
{
    pwr ob1;

    cout << "\n\n===========================\n";
    cin >> ob1;
    cout << ob1;
    cout << "\n===========================\n\n";

    return 0;
}
