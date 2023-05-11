// Consider the class "complex". Consider three objects of Complex class as compl, comp2 and comp3. Now write
// necessary functions so that the following statements can be executed in main():
// (i) comp3 = comp1 + comp2;
// (ii) comp3 = comp1 + 10;
// (iii) comp3 = 10 + comp1;
// (iv) compl++;
// (v) ++comp1;
// (vi) cout<<comp1;
// (vii) comp3 = comp1(5) ;

# include <iostream>
using namespace std;

class Complex{
public:
    int real, img;
    Complex(int r = 0, int i = 0){
        real = r;
        img = i;
    };
    Complex operator+(Complex c);
    Complex operator+(int i);
    friend Complex operator+(int i, Complex c);
    Complex operator++();
    //prefix
    Complex operator++(int unused);
    //postfix
    friend std::ostream& operator<<(std::ostream& stream, Complex c);
    Complex operator()(int i);
    Complex operator=(Complex c);
};

Complex Complex::operator+(Complex c){
    Complex T;
    T.real = this->real + c.real;
    T.img = this->img + c.img;

    return T;
}

Complex Complex::operator+(int i){
    Complex T;

    T.real = this->real + i;
    T.img = this->img;

    return T;
}

Complex operator+(int i, Complex c){
    Complex T;

    T.img = c.img + i;
    T.real = c.real;

    return T;
}

Complex Complex::operator++(){
    this->real++;
    this->img++;

    return *this;
}

Complex Complex::operator++(int unused){
    Complex T;

    T = *this;
    this->real++;
    this->img++;

    return T;
}

std::ostream& operator<<(std::ostream& stream, Complex c){
    stream << c.real << (c.img >= 0 ? " + " : " - ") << abs(c.img) << "i" << endl;

    return stream;
}

Complex Complex::operator()(int i){
    Complex T;
    T.real = this->real + i;
    T.img =  this->img + i;

    return T;
}

Complex Complex::operator=(Complex c){
    this->real = c.real;
    this->img = c.img;
    return *this;
}

int main()
{
    Complex comp1(1, 2), comp2(3, 4), comp3;

    cout << "\n************* Output set 1 *************" << endl;
    comp3 = comp1 + comp2;
    cout << "comp1 = " << comp1;
    cout << "comp2 = " << comp2;
    cout << "comp3 = " << comp3;

    cout << "\n************* Output set 2 *************" << endl;
    comp3 = comp1 + 10;
    cout << "comp1 = " << comp1;
    cout << "comp3 = " << comp3;

    cout << "\n************* Output set 3 *************" << endl;
    comp3 = 10 + comp1;
    cout << "comp1 = " << comp1;
    cout << "comp3 = " << comp3;

    cout << "\n************* Output set 4 *************" << endl;
    cout << "comp1 = " << comp1;
    cout << "comp1 = " << comp1++;

    cout << "\n************* Output set 5 *************" << endl;
    cout << "comp1 = " << comp1;
    cout << "comp1 = " << ++comp1;

    cout << "\n************* Output set 6 *************" << endl;
    cout << "comp1 = " << comp1;
    cout << "comp3 = " << comp3;
    comp3 = comp1(5);
    cout << "comp1 = " << comp1;
    cout << "comp3 = " << comp3;


    return 0;
}