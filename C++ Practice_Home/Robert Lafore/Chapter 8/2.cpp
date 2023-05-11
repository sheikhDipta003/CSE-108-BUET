# include <iostream>
using namespace std;
# include <cstring>
# include <cstdlib>

class String{
    enum{SIZE=80};
    char str[SIZE];
public:
    String(){
        strcpy(str, "");
    }
    String(char s[]){
        strcpy(str, s);
    }
    void display() const{
        cout << str << endl;
    }
    String operator+(String s){
        String temp;
        if(strlen(this->str) + strlen(s.str) <= SIZE){
            strcpy(temp.str, this->str);
            strcat(temp.str, s.str);
        } else {
            cout << "String overflow\n";
            exit(0);
        }
        return temp;
    }
    bool operator==(String s){
        return (strcmp(this->str, s.str) == 0)?true:false;
    }
};

int main(){
    String s1, s2("Hello world"), s3;
    cout << "\n\n==================================\n";
    cout << "s1 = "; s1.display(); cout << "s2 = " ; s2.display(); cout << "s3 = "; s3.display(); cout << endl;
    s3 = s1 + s2;
    cout << "s1(after assignment) = ";
    s1.display();
    cout << "s2(after assignment) = ";
    s2.display();
    cout << "s3(after assignment) = ";
    s3.display();
    cout << endl;
    cout << "s1 equals s3 : " << (s1==s3?"true":"false") <<endl;
    cout << "s2 equals s3 : " << (s2 == s3 ? "true" : "false") << endl;
    cout << "\n==================================\n\n";

    return 0;
}