# include <iostream>

using namespace std;

int main(){

    cout << 123.23 << " hello " << 100 << endl;
    cout << 10 << ' ' << -10 << endl;
    cout << 100.0 << endl;

    cout.unsetf(ios::dec);
    cout.setf(ios::hex | ios::scientific);
    cout << 123.23 << " hello " << 100 << endl;

    cout.setf(ios::showpos);
    cout << 10 << ' ' << -10 << endl;

    cout.setf(ios::showpoint | ios::fixed);
    cout << 10.0 << endl;

    return 0;
}
