# include <iostream>
using namespace std;

class samp{
    int i;
public:
    samp(int n){    i = n;  cout << "Constructing ...\n";   }
    ~samp(){    cout << "Destructing ...\n";    }
    int get_i(){    return i;   }
};

int squareIt(samp ob){
    return ob.get_i() * ob.get_i();
}
//Function to square "i" of an object of "samp" class

int main(){
    samp a(10);
    // Constructor of "a" is called

    cout << "\n" << squareIt(a) << "\n\n";
    // When calling "squareIt(a)", constructor is NOT called, but AFTER the function prints the square of "i", its parameter ob's scope terminates and destructor is called for ob. At last, when the program terminates, destructor is called for "a".

    return 0;
}