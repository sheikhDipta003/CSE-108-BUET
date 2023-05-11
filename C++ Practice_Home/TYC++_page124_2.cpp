# include <iostream>
using namespace std;

class squares{
    int num, sqr;

public:
    squares(int a, int b){
        num = a;
        sqr = b;
    }
    void show(){
        cout << num << ' ' << sqr << endl;
    }
};


int main(){
    squares S[10] = {squares(1, 1 * 1), squares(2, 2 * 2), squares(3, 3 * 3), squares(4, 4 * 4), squares(5, 5 * 5),
                    squares(6, 6 * 6), squares(7, 7 * 7), squares(8, 8 * 8), squares(9, 9 * 9),squares(10, 10 * 10)};

    cout << endl;
    for(int i = 0 ; i < 10 ; i++){
        S[i].show();
    }

    return 0;
}