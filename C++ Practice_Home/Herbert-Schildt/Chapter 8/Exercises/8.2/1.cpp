# include <iostream>

using namespace std;

int main(){
    ios::fmtflags f = cout.flags();

    if(f & ios::showpos){
        cout << "\nshowpos turned on\n";
    }
    else{
        cout << "\nshowpos turned off\n";
    }
    cout << 100;

    cout.setf(ios::showpos);
    // If this line is commented out, then "showpos turned off" is displayed the second time.

    // f = ios::showpos;
    // cout.flags(f);
    // On the other hand, if these two lines are commented out, then "showpos turned on" is displayed the second time.
    // But in both cases, a "+" sign has been appended to the integer 100 successfully!  Why???

    if (f & ios::showpos)
    {
        cout << "\nshowpos turned on\n";
    }
    else
    {
        cout << "\nshowpos turned off\n";
    }
    cout << 100 << endl;

    return 0;
}