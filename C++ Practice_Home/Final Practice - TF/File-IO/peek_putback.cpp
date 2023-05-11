# include <iostream>
# include <fstream>
using namespace std;

int main(){
    char ch, str[100], *p;

    ofstream out("test.txt");
    out << 12345 << "this is a test" << 24542 << "anfmdq" << 103 << "asmdf" << endl;
    out.close();

    ifstream in("test.txt");
    cout << "\n\n===================================\n";
    do{
        p = str;
        ch = in.peek();
        
        if(isdigit(ch))
        {   
            while(isdigit(*p = in.get()))  p++;
            in.putback(*p);
            *p = '\0';
            cout << "integer: " << atoi(str) << endl;
        }
        else if(isalpha(ch)){
            while (isalpha(*p = in.get()))
                p++;
            in.putback(*p);
            *p = '\0';
            cout << "string: " << str << endl;
        }
        else{
            in.get();
        }

    }while(!in.eof());
    in.close();
    cout << "\n===================================\n\n";

    return 0;
}