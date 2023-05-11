# include <iostream>
using namespace std;

//This class can hold either a longitude variable or latitude variable.
class angle{
    int deg;
    float min;
    char direction;
public:
    angle(int d, float m, char dir) : deg(d), min(m), direction(dir){}
    void getAngleDirection(){
        cout << "Enter degree : "; cin >> deg;
        cout << "Enter minute : "; cin >> min;
        cout << "Enter direction(N/S/E/W) : " ; cin >> direction;
    }
    void showAngleDirection(){
        cout << deg << '\xF8' << min << '\'' << " " << direction << endl;
    }
};

int main(){
    angle a1(179, 56.5, 'N');
    cout << "\n\n==================================\n";
    a1.showAngleDirection();
    while(true){
        a1.getAngleDirection();
        a1.showAngleDirection();
    }
    cout << "\n==================================\n\n";

    return 0;
}