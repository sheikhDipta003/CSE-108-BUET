# include <iostream>
# include <string>

using namespace std;

int main(){
    string str;

    cout << "Input a string: ";

    //getline( <input stream>, <string object(not char array!)>, <delimitter char('\n' by default)> )
    getline(cin, str);
    cout << "You entered: " << str;

    return 0;
}