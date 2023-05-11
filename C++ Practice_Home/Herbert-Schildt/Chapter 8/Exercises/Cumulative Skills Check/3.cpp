# include <iostream>
using namespace std;

class ft_to_inches{
    double feet;
    double inches;

public:
    void set(double f){
        feet = f;
        inches = 12 * f;
    }
    friend ostream &operator<<(ostream &stream, ft_to_inches ob);
    friend istream &operator>>(istream &stream, ft_to_inches &ob);
};

ostream &operator<<(ostream &stream, ft_to_inches ob){
    stream << "Feets : " << ob.feet << ", Inches: " << ob.inches << endl;

    return stream;
}

istream &operator>>(istream &stream, ft_to_inches &ob){
    int f;

    cout << "Enter number of feet: " ;
    stream >> f;

    ft_to_inches newOb;
    newOb.set(f);

    ob = newOb;

    return stream;
}

    int main()
{
    ft_to_inches cvt_feet;

    cvt_feet.set(10);

    cout << cvt_feet;

    cin >> cvt_feet;

    cout << cvt_feet;

    return 0;
}