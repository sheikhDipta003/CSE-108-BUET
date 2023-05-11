# include <iostream>
# include <cstring>
# include <cmath>
using namespace std;

class Coord{
    int x, y;
    char *pointname;
public:
    Coord(){
        x = 0; y = 0;
        pointname = new char[100];
        strcpy(pointname, "");
    }
    Coord(int x, int y, char* name){
        this->x = x;
        this->y = y;
        pointname = new char[strlen(name)+1];
        strcpy(pointname, name);
    }
    Coord(const Coord& ob){
        this->x = ob.x;
        this->y = ob.y;
        int len = strlen(ob.pointname);

        delete pointname;
        pointname = new char[len + 1];

        strcpy(pointname, ob.pointname);
    }
    Coord operator+(const Coord& ob);
    friend Coord operator+(int i, const Coord& ob);
    Coord operator=(const Coord& ob);
    operator int(){
        return (int)sqrt(x * x + y * y);
    }
    int getX(){return x;}
    int getY(){return y;}
    char* getName(){return pointname;}
};

Coord operator+(int i, const Coord &ob){
    Coord temp;
    temp.x = i + ob.x;
    temp.y = i + ob.y;
    return temp;
}

Coord Coord::operator+(const Coord &ob)
{
    Coord temp;
    temp.x = this->x + ob.x;
    temp.y = this->y + ob.y;
    return temp;
}

Coord Coord::operator=(const Coord& ob){
    this->x = ob.x;
    this->y = ob.y;
    int len = strlen(ob.pointname);

    if (len > strlen(pointname))
    {
        delete pointname;
        pointname = new char[len + 1];
    }

    strcpy(pointname, ob.pointname);

    return *this;
}

int main(){

    Coord ob1, ob2, ob3;
    Coord ob4(30, 40, "origin");

    cout << "\n\n=========================Output-1==============================\n";
    cout << "ob1 = (" << ob1.getX() << "," << ob1.getY() << ")\t";
    cout << "ob2 = (" << ob2.getX() << "," << ob2.getY() << ")\t";
    cout << "ob3 = (" << ob3.getX() << "," << ob3.getY() << ")\t";
    cout << "ob4 = (" << ob4.getX() << "," << ob4.getY() << ")\n";

    ob1 = ob2 + ob3 + ob4;
    cout << "=========================Output-2==============================\n";
    cout << "ob1 = (" << ob1.getX() << "," << ob1.getY() << ")\t";
    cout << "ob2 = (" << ob2.getX() << "," << ob2.getY() << ")\t";
    cout << "ob3 = (" << ob3.getX() << "," << ob3.getY() << ")\t";
    cout << "ob4 = (" << ob4.getX() << "," << ob4.getY() << ")\n";

    ob1 = 100 + ob2;
    cout << "=========================Output-3==============================\n";
    cout << "ob1 = (" << ob1.getX() << "," << ob1.getY() << ")\t";
    cout << "ob2 = (" << ob2.getX() << "," << ob2.getY() << ")\t";
    cout << "ob3 = (" << ob3.getX() << "," << ob3.getY() << ")\t";
    cout << "ob4 = (" << ob4.getX() << "," << ob4.getY() << ")\n";

    int value = 100 + (int)ob4;
    //without explicit cast, code not working
    cout << "=========================Output-4==============================\n";
    cout << "value = " << value << endl;
    cout << "ob1 = (" << ob1.getX() << "," << ob1.getY() << ")\t";
    cout << "ob2 = (" << ob2.getX() << "," << ob2.getY() << ")\t";
    cout << "ob3 = (" << ob3.getX() << "," << ob3.getY() << ")\t";
    cout << "ob4 = (" << ob4.getX() << "," << ob4.getY() << ")\n\n";

    return 0;
}
