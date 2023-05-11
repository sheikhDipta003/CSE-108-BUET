# include <iostream>
using namespace std;

int main(){

    cout << 3.14 << endl;

    cout.setf(ios::showpoint | ios::scientific | ios::uppercase);

    cout << 3.14 << endl;

    return 0;
}