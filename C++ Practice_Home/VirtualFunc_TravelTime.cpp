# include <iostream>
using namespace std;

class dist{
public:
    double distance;
    dist(double x){ distance = x; }
    virtual void trav_time(){
        cout << "\nTime taken to travel(distnace in miles) = " << distance/60.0 << " hour" << endl;
    }
};

class metric : public dist{
public:
    metric(int y) : dist(y){}
    void trav_time(){
        cout << "\nTime taken to travel(distnace in kilometers) = " << distance * 1.61 / 100.0 << " hour" << endl;
    }
};

int main(){
    dist *p;
    dist ob(1200);
    p = &ob;
    p->trav_time();
    
    metric m(1000);
    p = &m;
    p->trav_time();

    return 0;
}