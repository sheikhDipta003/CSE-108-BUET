# include <iostream>
# include <cstring>
using namespace std;

void reverse(char*, int);

int main(){
    char str[100];
    cout << "\nEnter a string: ";
    // cin.get(str, 100);
    // When I use the above line instead to input string, "reverse" does not work correctly(why??)
    cin >> str;

    cout << "\nYou entered: " << str << endl;
    reverse(str, 5);
    cout << "Reversing 4 letters : " << str << "\n\n";

    return 0;
}

void reverse(char* s, int c = 0){
    char t;

    for(int i = 0 ; i < c/2 ; i++){
        t = s[i];
        s[i] = s[c - i - 1];
        s[c - i - 1] = t;
    }
}