# include <iostream>
# include <cstring>
# include <cstdlib>
using namespace std;

class samp{
    char *s;
public:
    samp(){     s = '\0';   }
    ~samp(){    if(s) free(s);    cout << "Freeing ..\n";   }
    void show(){    cout << s << endl;  }
    void set(char *str);
};

void samp::set(char *str){
    s = (char *) malloc(strlen(str) + 1);

    strcpy(s, str);
}

samp input(){
    char s[80];
    samp str;
    // Creates a new object of "samp" class. Hence, constructor will be called again.

    cout << "Enter a string: " ;
    cin >> s;

    str.set(s);
    //Sets the "s" pointer of "str" object to this "s".

    return str;
    //AFTER returning to "main()", str's scope will terminate and destructor will be called.
}

int main(){
    samp ob;
    // The parameterless constructor I defined, will be called.

    ob = input();
    // input function will be called.
    // AFTER bitwise copy of the string "s" corresponding to the returned object(say, "temp") has been performed on ob, destructor for "temp" will be called. As a result, memory for "temp" will be freed. But because of the assignment statement, "s" pointer of ob and "temp"- both point to the same memory location. So, ob's memory is freed as well.
    
    ob.show();

    return 0;
}