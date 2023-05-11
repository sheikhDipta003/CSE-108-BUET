# include <iostream>
# include <cstring>
using namespace std;

class strtype{
    char *p;
    int len;

public:
    strtype();
    strtype(char *initS, int numOfBytes);
    ~strtype(){
        delete [] p;
    }
    char *getString(){
        return p;
    }
    int getLength(){
        return len;
    }
};

strtype::strtype(){
    p = new char[255];
    *p = '\0';
    len = 255;
}

strtype::strtype(char *initS, int numOfBytes){
    p = new char[numOfBytes];
    strcpy(p, initS);
    len = numOfBytes;
}

int main(){
    char *str;
    int b;
    cout << "\nEnter a string and number of bytes (<Number of bytes> <string>) : ";
    cin >> b;
    cin >> str;
    strtype temp1(str, b), temp2;
    cout << "Entered string:  " << temp1.getString() << endl;
    cout << "Length of the string: " << temp1.getLength() << endl;

    cout << "\nEnter another string : ";
    cin >> str;
    cout << "Entered string:  " << temp2.getString() << endl;
    cout << "Length of the string: " << temp2.getLength() << endl;

    return 0;
}