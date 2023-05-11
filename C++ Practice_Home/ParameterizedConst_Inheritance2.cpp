# include <iostream>
using namespace std;

class vehicle{
    int num_wheels;
    int range;
public:
    vehicle(int w, int r){
        num_wheels = w;
        range = r;
    }
    void show_vehicle(){
        cout << "Wheels: " << num_wheels << endl << "Range: " << range << endl;
    }
};

class car: public vehicle{
    int passengers;
public:
    car(int p, int w, int r): vehicle(w, r){ passengers = p; }
    void show(){
        show_vehicle();
        cout << "Passengers: " << passengers << endl;
    }
};

class truck : public vehicle{
    int loadlimit;
public:
    truck(int L, int w, int r): vehicle(w, r){ loadlimit = L; }
    void show(){
        show_vehicle();
        cout << "loadlimit: " << loadlimit << endl;
    }
};

int main(){
    car c(5, 4, 500);
    truck t(30000, 12, 1200);

    cout << "Car: " << endl;
    c.show();
    cout << "\nTruck: " << endl;
    t.show();

    return 0;
}