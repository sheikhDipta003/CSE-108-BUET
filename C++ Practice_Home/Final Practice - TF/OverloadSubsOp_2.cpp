# include <iostream>
# include <cstring>
using namespace std;

class strType{
    char *p;
    int len;
public:
    strType(char* s){
        len = strlen(s) + 1;
        p = new char[len];
        strcpy(p, s);
    }
    ~strType(){
        delete [] p;
    }
    char* get(){return p;}
    strType &operator=(strType& ob){
        if(len < ob.len){
            delete [] p;
            p = new char[ob.len];
        }
        len = ob.len;
        strcpy(p, ob.get());
        return *this;
    }
    char &operator[](int i){
        if(i < 0 || i >= len){
            cout << "\nOut of bounds" << endl;
        }
        else {
            return p[i];
        }
    }
};

int main(){
    strType s1("Hello world");
    strType s2("I am having very bad day");
    cout << "\n\n===========================\n";
    cout << "First string : " << s1.get() << "\nSecond string : " << s2.get() << endl;
    s1 = s2;
    cout << "First string : " << s1.get() << "\nSecond string : " << s2.get() << endl;
    strType s3 = s1;
    cout << "The sixth character of s3 : " << s3[5] << endl;
    s3[5] = 'l';
    cout << "The sixth character of s3(after replacement) : " << s3[5] << endl;
    cout << "s3 (after replacement) : " << s3.get();
    cout << "\n===========================\n\n";

    return 0;
}