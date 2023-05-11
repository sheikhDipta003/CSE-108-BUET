#include <iostream>
# include <cmath>
using namespace std;

class Line{
    int m, c;

public:
    Line(){}
    Line(int slope, int y_intercept){
        m = slope;
        c = y_intercept;
    }
    int get_m(){ return m;   }
    void setVal(int m, int c){
        this->m = m;
        this->c = c;
    }
};

class Angle{
    Line l1, l2;
public:
    void setVal(Line l1, Line l2){
        this->l1 = l1;
        this->l2 = l2;
    }
    double angleBetween(){
        double m1 = l1.get_m(), m2 = l2.get_m();

        if(m1 * m2 == -1.0){
            return 90;
        }
        else{
            return atan(abs(m1 - m2) / (1 + m1 * m2)) * 180 / 3.1416;
        }
    }
};

int main()
{
    int m1, c1, m2, c2;
    Line l1, l2;

    cin >> m1 >> c1 >> m2 >> c2;
    l1.setVal(m1, c1);
    l2.setVal(m2, c2);
    Angle a;
    a.setVal(l1, l2);

    cout << a.angleBetween() << endl;

    return 0;
}
