# include <iostream>
using namespace std;

class Coord{
    int x, y;
public:
    Coord(){x = 0; y = 0;}
    Coord(int x, int y){
        this->x = x;
        this->y = y;
    }
    friend ostream& operator<<(ostream& out, Coord ob);
};

ostream &operator<<(ostream &out, Coord ob){
    out << "x = " << ob.x << ", y = " << ob.y << endl;
    return out;
}

int main()
{
    Coord c1(0, 0), c2(3, 4);

    cout << "\n\n===========================\n";
    cout << c1;
    cout << c2;
    cout << "\n===========================\n\n";

    return 0;
}