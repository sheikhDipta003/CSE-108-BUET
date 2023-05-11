# include <iostream>
using namespace std;

class Distance{
    int feet;
    double inches;
public:
    Distance(): feet(0), inches(0){}
    Distance(int ft, double in): feet(ft), inches(in){}
    void getDist(){
        cout << "\nEnter feet: "; cin >> feet;
        cout << "Enter inches: " ; cin >> inches;
    }
    void showDist(){
        cout << feet << "\'-" << inches << "\"" << endl;
    }
    void addDist(Distance d1, Distance d2);
};

void Distance::addDist(Distance d1, Distance d2){
    inches = d1.inches + d2.inches;
    feet = 0;
    if(inches >= 12.0){
        inches -= 12;
        feet++;
    }
    feet += d1.feet + d2.feet;
}

int main()
{
    Distance d1, d3;
    Distance d2(11, 6.25);

    cout << "\n\n=======================================\n";

    d1.getDist();
    d3.addDist(d1, d2);

    cout << "\nd1 = "; d1.showDist();
    cout << "\nd2 = "; d2.showDist();
    cout << "\nd3 = "; d3.showDist();

    cout << "\n=======================================\n\n";

    return 0;
}