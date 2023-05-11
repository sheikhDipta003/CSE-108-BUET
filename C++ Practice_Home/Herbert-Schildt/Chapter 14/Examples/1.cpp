# include <iostream>
# include <string>
# include <fstream>
using namespace std;

int main(){
    string str1("Demonstrating Strings");
    string str2("String Two");
    string str3;

    str3 = str1;
    cout << str1 << "; " << str3 << endl;

    str3 = str1 + str2;
    cout << str1 << "; " << str2 << "; " << str3 << endl;

    if(str3 > str1)
        cout << "str3 > str1" << endl;
    if(str3 == str1 + str2){
        cout << "str3 = str1 + str2" << endl;
    }

    str1 = "This is a normal string.\n";
    cout << str1;

    string str4(str1);
    cout << str4 << endl;

    cout << "Enter a string: " ;
    cin >> str4;
    cout << str4;

    return 0;
}