# include <iostream>
# include <cstring>

using namespace std;

struct myStr
{
    void buildstr(char *s); // public by default
    void showstr();

    private: // now go private
        char str[255];
};


int main(){
    myStr newStr;

    newStr.buildstr("Hello World");
    newStr.showstr();

    return 0;
}

void myStr::buildstr(char *s){
    if (!*s){
        strcpy(str, '\0');
    }
    else{
        strcpy(str, s);
    }
}

void myStr::showstr(){
    cout << "Given String is: " << str;
}