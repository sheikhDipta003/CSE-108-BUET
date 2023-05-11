#include<iostream>
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
        name = new char[l + 1];
        strcpy(name, n);
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
        cout << name << ": " << x << "x";
        if(y < 0){
            cout << "-" << abs(y);
        } else {
            cout << "+" << abs(y);
        }
        cout << "y";
        if (z < 0)
        {
            cout << "-" << abs(z);
        }
        else
        {
            cout << "+" << abs(z);
        }
        cout << "z";
        cout << endl;
    }
    Vector operator^(Vector &v){
        Vector temp("Result1");
        temp.setX(this->getY() * v.getZ() - v.getY() * this->getZ());
        temp.setY(this->getZ() * v.getX() - v.getZ() * this->getX());
        temp.setZ(this->getX() * v.getY() - v.getX() * this->getY());
        return temp;
    }
    bool operator==(Vector v){
        return ( (this->getX() == v.getX()) && (this->getY() == v.getY()) && (this->getZ() == v.getZ()) );
    }
    Vector operator*(int i){
        Vector temp(this->getName());
        temp.setX(this->getX() * 2);
        temp.setY(this->getY() * 2);
        temp.setZ(this->getZ() * 2);
        return temp;
    }
    friend Vector operator*(int i, Vector v);
    Vector operator*(Vector v){
        Vector temp("Result1");
        temp.setX(this->getX() * v.getX());
        temp.setY(this->getY() * v.getY());
        temp.setZ(this->getZ() * v.getZ());
        return temp;
    }
    Vector operator=(Vector v){
        this->x = v.getX();
        this->y = v.getY();
        this->z = v.getZ();
        if(strlen(v.getName()) > strlen(this->getName())){
            //delete this->name;
            this->name = new char[strlen(v.getName()) + 1];
        }
        strcpy(this->name, v.getName());
    }
};

Vector operator*(int i, Vector v){
    return (v*i);
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
