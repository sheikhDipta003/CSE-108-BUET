# include <iostream>
using namespace std;

class area{
    double dim1, dim2;
public:
    void setdim(double d1, double d2){
        dim1 = d1;
        dim2 = d2;
    }
    void getdim(double &d1, double &d2){
        d1 = dim1;
        d2 = dim2;
    }
    virtual double getarea() = 0;
    // Pure virtual function : when a function inside a base class is specified in this way, that class becomes an "abstract class" and every derived class inheriting that base class must redefine their own versions of getarea() [otherwise, compile error will be reported!]. We cannot create objects of an abstract class but we can create pointers and references of it.
};

class Rect : public area{
public:
    double getarea(){
        double d1, d2;
        getdim(d1, d2);
        return d1 * d2;
    }
};

class Trg : public area{
public:
    double getarea(){
        double d1, d2;
        getdim(d1, d2);
        return 0.5 * d1 * d2;
    }
};

int main(){
    area *p;
    Rect r;
    Trg t;

    r.setdim(3.3, 4.5);
    t.setdim(4, 5);

    p = &t;
    cout << "\nArea of the triangle = " << p->getarea() << endl << endl;

    return 0;
}