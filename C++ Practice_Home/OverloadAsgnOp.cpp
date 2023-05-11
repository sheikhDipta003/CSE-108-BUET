# include <iostream>
# include <cstring>
using namespace std;

class strtype{
    char *p;
    int len;

public:
    strtype(char *s){
        len = strlen(s) + 1;
        p = new char[len];
        strcpy(p, s);
    }
    ~strtype(){
        delete [] p;
    }
    strtype&operator=(strtype &obj);
    // When I did not specify the formal parameter and return type as reference objects, "double free error" was reported in "onlinegbd.com".

    char *getp(){   return p;   }
};

strtype& strtype::operator=(strtype &obj){
    if(len < obj.len){
        delete [] p;
        p = new char[obj.len];
    }

    len = obj.len;
    strcpy(p, obj.p);
    return *this;
    // How can we return value of a pointer as a reference from this function?
    // => Because the value of "this" pointer is copied to the value of the "temp" object created by the compiler after execution of the return statement. And it is the reference variable of "temp" that is returned to main().
    // But in that case, "temp" is destroyed as soon as it returns its value to main(). Then shouldn't its reference variable be destroyed too?
    // => Yes, both the reference variable of "temp" and "temp" itself are destroyed. But by that time, "s1" would have received the returned object already. Therefore, it does no harm even if they are destroyed.
}

int main(){
    strtype s1("BUET"), s2("CSE");
    s1 = s2;
    // s2 = s1;
    // A reference variable can only be assigned to another reference variable; then what is happening here!!!
    // => Actually, a reference variable can be assigned to any type of variable, not only to another reference!

    cout << "s1 = " << s1.getp() << endl;
    cout << "s2 = " << s2.getp() << endl;
    
    return 0;
}