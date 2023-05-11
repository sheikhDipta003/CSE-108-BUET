# include <iostream>
# include <cstring>
using namespace std;

class myBase{
    char str[100];
public:
    myBase(char *s){ strcpy(str, s); }
    char *get(){ return str; }
};

class myDerived: public myBase{
    int len;
public:
    myDerived(char *r):myBase(r){ len = strlen(r); };
    int getLen(){ return len; }
    void show(){ cout << get() << endl; }
};

int main(){
    myDerived ob("Hello");
    ob.show();

    cout << ob.getLen() << endl;

    return 0;
}