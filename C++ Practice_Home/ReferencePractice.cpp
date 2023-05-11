# include <iostream>
using namespace std;

// void swapargs(int *p, int *q){
//     int t;
//     t = *p;
//     *p = *q;
//     *q = t;
// }

//Using Reference variables
void swapargs(int &p, int &q){
    int t;
    t = p;
    p = q;
    q = t;
}

int main(){
    int i = 20, j = 40;

    cout << "i = " << i << "; j = " << j << endl;

    swapargs(i, j);

    cout << "i = " << i << "; j = " << j << endl;

    return 0;
}