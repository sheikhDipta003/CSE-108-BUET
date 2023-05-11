# include <iostream>
using namespace std;

namespace firstNS{
    class demo{
        int i;
        public:
        demo(int i){this->i=i;}
        int geti(){return i;}
        void seti(int i){this->i=i;}
    };

    char str[] = "Illustrating namespaces\n";
    int counter;
};

namespace secondNS{
    int x, y;
}

int main(){
    firstNS::demo ob(10);
    cout << "\n\n=======================================\n";
    cout << "value of ob: " << ob.geti() << endl;
    ob.seti(-10);
    cout << "value of ob now: " << ob.geti() << endl;

    using firstNS::str;
    cout << str;

    using namespace firstNS;
    for(counter = 10 ; counter ; counter--){
        cout << counter << "\t";
    }
    cout << endl;

    secondNS::x = 50;
    secondNS::y = 60;
    cout << "(x, y) = " << "(" << secondNS::x << ", " << secondNS::y << ")" << endl;

    using namespace secondNS;
    demo xob(x), yob(y);
    cout << "value of xob: " << xob.geti() << ", value of yob: " << yob.geti() << endl;

    cout << "\n=======================================\n\n";

    return 0;
}