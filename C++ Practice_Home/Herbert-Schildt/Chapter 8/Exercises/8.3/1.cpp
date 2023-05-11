# include <iostream>
# include <cmath>
using namespace std;

int main(){

    // cout.setf(ios::right);   // Unnecessary, because all output values are by default right justified.
    cout.width(10);
    cout << "x" ;
    cout.width(10);
    cout << "ln(x)" ;
    cout.width(10);
    cout << "log(x)" << endl;

    for(int i = 2; i <= 100 ; i++){
        cout.width(10);
        cout << i ;
        cout.width(10);
        cout << log(i);
        cout.width(10);
        cout  << log10(i);
        cout << endl;
    }

    return 0;
}