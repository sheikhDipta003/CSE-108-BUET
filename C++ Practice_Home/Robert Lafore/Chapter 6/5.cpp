# include <iostream>
using namespace std;

class fraction{
int numerator, denominator;
public:
    void getFraction(){
        string temp;
        cin >> temp;
        int pos = (int) temp.find('/');
        numerator = stoi(temp.substr(0, pos));
        denominator = stoi(temp.substr(pos+1));
    }
    void showFraction(){
        cout << "result: " << numerator << '/' << denominator << endl;
    }
    void add(fraction f1, fraction f2){
        numerator = f1.numerator*f2.denominator + f2.numerator*f1.denominator;
        denominator = f1.denominator * f2.denominator;
    }
};

int main(){
    char ch;
    fraction f1, f2, f;
    cout << "\n\n==================================\n";
    
    do{
        cout << "Enter first fraction: ";
        f1.getFraction();
        cout << "Enter second fraction: ";
        f2.getFraction();
        f.add(f1, f2);
        f.showFraction();
        cout << "Continue? (Y/N) " ; cin >> ch;
        if(ch == 'N')   break;
        else if(ch == 'Y')  continue;
    } while(true);

    cout << "\n==================================\n\n";

    return 0;
}