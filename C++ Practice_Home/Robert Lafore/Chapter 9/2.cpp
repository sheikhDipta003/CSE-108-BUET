# include <iostream>
using namespace std;

enum posneg{ pos, neg };

class Distance{
protected:
    int ft;
    double in;
public:
    Distance(){ ft = 0; in = 0.0; }
    Distance(int ft, double in){ this->ft = ft; this->in = in; }
    void getDist(){
        cout << "Enter foot: "; cin >> this->ft;
        cout << "Enter inches: "; cin >> this->in;
    }
    void showDist(){
        cout << ft << "\'\\" << in << "\"" << endl;
    }
};

class SignedDistance : public Distance{
    posneg sign;
public:
    SignedDistance():Distance(){ sign = pos; }
    SignedDistance(int ft, double in, posneg sign=pos): Distance(ft, in){
        this->sign = sign;
    }
    void getDist()
    {
        char ch;
        cout << "Enter sign (+ or -): "; cin >> ch;
        sign = (ch == '+') ? pos : neg;
        Distance::getDist();
    }
    void showDist()
    {
        cout << ((sign == pos) ? "+ " : "- ");
        Distance::showDist();
    }
};

int main(){
    SignedDistance alpha;          //no-arg constructor
    alpha.getDist();               //get alpha from user

    SignedDistance beta(11, 6.25); //2-arg constructor
    SignedDistance gamma(100, 5.5, neg); //3-arg constructor

    //display all distances
    cout << "\nalpha = "; alpha.showDist();
    cout << "\nbeta = "; beta.showDist();
    cout << "\ngamma = "; gamma.showDist();
    cout << endl;

    return 0;
}