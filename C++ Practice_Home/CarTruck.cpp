# include <iostream>
using namespace std;

class truck;
//A forward declaration

class car{
    int passangers, speed;

public:
    car(int p, int s){passangers = p;   speed = s;}
    friend int sp_greater(car c, truck t);
    //If we had not included the protoype of "truck" class as line no. 4, compiler would fail to recognise that class in this line. As a result, we would get compile error.
};

class truck{
    int weight, speed;

public:
    truck(int w, int s){weight = w; speed = s;}
    friend int sp_greater(car c, truck t);
};

int sp_greater(car c, truck t){
    return (c.speed - t.speed);
}

int main(){
    int t;
    car c1(6, 55), c2(2, 120);
    truck t1(10000, 55), t2(20000, 72);

    cout << "Comparing c1 and t1:\n";
    t = sp_greater(c1, t1);
    if (t < 0){
        cout << "Truck is faster.\n" ;
    }
    else if(t == 0){
        cout << "Speed of both car and truck are the same.\n" ;
    }
    else{
        cout << "Car is faster.\n" ;
    }

    cout << "\nComparing c2 and t2:\n";
    t = sp_greater(c2, t2);
    if (t < 0){
        cout << "Truck is faster.\n" ;
    }
    else if(t == 0){
        cout << "Speed of both car and truck are the same.\n" ;
    }
    else{
        cout << "Car is faster.\n" ;
    }

    return 0;
}