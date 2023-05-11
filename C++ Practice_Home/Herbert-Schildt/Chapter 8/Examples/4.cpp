# include <iostream>
using namespace std;

int main(){

    cout << "hello" << endl;

    cout.width(10);
    cout << "hello" << endl;

    cout.fill('%');
    cout.width(10);
    cout << "hello" << endl;

    cout.fill('%');
    cout.width(3);
    cout << "hello" << endl;

    cout.setf(ios::left);
    cout.width(10);
    cout << "hello" << endl;

    cout.precision(10);
    cout.width(10);
    cout.fill('0');
    cout << 123.456 << endl;

    return 0;
}