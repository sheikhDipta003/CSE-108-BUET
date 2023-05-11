#include<iostream>
#include <cmath>
#include<cstring>
using namespace std;

class Vector
{
    char *name;
    int x,y,z;
public:
    Vector(char *n)
    {
        int l = strlen(n);
        name = new char[l+1];
        strcpy(name,n);
        x=0;
        y=0;
        z=0;
    }
    Vector(char *n, int a, int b, int c)
    {
        int l = strlen(n);
        name = new char[l+1];
        strcpy(name,n);
        x=a;
        y=b;
        z=c;
    }

    int setX(int a){x=a;}
    int setY(int b){y=b;}
    int setZ(int c){z=c;}

    void setName(char *n)
    {
        int l = strlen(n);
        name = new char[l+1];
        strcpy(name,n);
    }

    int getX(){return x;}
    int getY(){return y;}
    int getZ(){return z;}

    char *getName(){return name;}

    ~Vector()
    {
        delete []name;
    }
    void print(){
        cout << getName() << ": " ;
        cout << x << "x";
        if(y < 0){
            cout << "-" << abs(y) << "y";
        }
        else{
            cout << "+" << y << "y";
        }
        if(z < 0){
            cout << "-" << abs(z) << "z";
        }
        else{
            cout << "+" << z << "z";
        }

        cout << endl;
    }
    Vector& operator^(Vector &v);
    int operator==(Vector &v);
    friend Vector &operator*(Vector &v, int i);
    friend Vector &operator*(int i, Vector &v);
    Vector &operator*(Vector &v);
    Vector &operator=(Vector &v);
};

Vector temp("temp");

Vector& Vector::operator^(Vector &v){
    temp.setX(this->getY() * v.getZ() - v.getY() * this->getZ());
    temp.setY(v.getX() * this->getZ() - this->getX() * v.getZ());
    temp.setZ(this->getX() * v.getY() - v.getX() * this->getY());

    return temp;
}

int Vector::operator==(Vector &v){
    if(x == v.getX() && y == v.getY() && z == v.getZ()){
        return 1;
    }
    else{
        return 0;
    }
}

Vector& operator*(Vector &v, int i){
    temp.setX(v.getX() * i);
    temp.setY(v.getY() * i);
    temp.setZ(v.getZ() * i);

    return temp;
}

Vector& operator*(int i, Vector &v){
    return v * i;
}

Vector& Vector::operator*(Vector &v){
    
    temp.setX(x * v.getX());
    temp.setY(y * v.getY());
    temp.setZ(z * v.getZ());

    return temp;
}

Vector& Vector::operator=(Vector &v){
    
    this->setX(v.getX());
    this->setY(v.getY());
    this->setZ(v.getZ());

    return *this;
}

int main()
{
    Vector v1("v1", 1,2,3), v2("v2", 4, 5, -6), v3("Result1"),v4("Result2",-27,18,-3);

    v1.print();     ///Print the components of vector v1
    v2.print();     ///Print the components of vector v2
    
    v3=v1^v2;       ///Calculate the cross product of vector v1 and vector v2 (Consider ^ as cross product for this assignment)
    v3.print();     ///Print the modified components of vector v3 (Name: Result1)

    if(v3==v4)      ///Check for equality; if two vectors contain equal component values (x, y, z), then they are equal.
        cout<<"Vectors are equal"<<endl;
    else
        cout<<"Vectors are not equal"<<endl;

    v1= v1*2;       ///Multiply each component of vector v1 with the given value
    v1.print();     ///Print the modified components of vector v1

    v2=2*v2;        ///Multiply each component of vector v2 with the given value
    v2.print();     ///Print the modified components of vector v2

    v3=v1*v2;       ///Multiply each component of vector v1 with the corresponding component of vector v2.
    v3.print();     ///Print the modified components of vector v3 (Name: Result1)

    if(v3==v4)      ///Check for equality; if two vectors contain equal component values (x, y, z), then they are equal.
        cout<<"Vectors are equal"<<endl;
    else
        cout<<"Vectors are not equal"<<endl;

    return 0;
}