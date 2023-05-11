# include <iostream>
using namespace std;

void printRow(int cols, int curr_row);

class Triangle
{
    int height, base;
public:
    Triangle(int base, int height){
        this->height = height;
        this->base = base;
    }
    friend ostream &operator<<(ostream &out, Triangle t);
};

ostream &operator<<(ostream &out, Triangle t){
    for(int i = 0 ; i < t.height ; i++){
        printRow(t.base, i);
        cout << endl;
    }
    return out;
}

void printRow(int cols, int curr_row)
{
    for(int i = 0 ; i <= curr_row ; i++){
        cout << "*";
    }
    for(int i = 0 ; i < (cols - curr_row - 1) ; i++){
        cout << " ";
    }
}

int main()
{
    Triangle t1(5, 5), t2(10, 10);

    cout << "\n\n===========================\n";
    cout << t1 << "\n" << t2;
    cout << "\n===========================\n\n";

    return 0;
}