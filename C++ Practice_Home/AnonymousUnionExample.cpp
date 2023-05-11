# include <iostream>
# include <cstring>

using namespace std;

int main(){
    //No objects can be declared of an anonymous union
    union {
        long l;
        double d;
        char s[4];
    };

    //However, the members of the anonymous union can be referred to directly
    l = 100000;
    cout << "l = " << l;

    d = 3.1416;
    cout << "\nd = " << d;

    strcpy(s, "Hello WOrld!");
    cout << "\ns = " << s;
}