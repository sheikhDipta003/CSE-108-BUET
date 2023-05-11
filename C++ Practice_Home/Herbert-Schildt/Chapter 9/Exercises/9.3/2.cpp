# include <iostream>
# include <cstring>
# include <fstream>
using namespace std;

class account{
    int custnum;
    char name[80];
    double balance;

public:
    account(int c, char *n, double b){
        custnum = c;
        strcpy(name, n);
        balance = b;
    }
    //inserter
    friend ofstream &operator<<(ofstream &stream, account ob);
};

ofstream &operator<<(ofstream &stream, account ob){

    stream << "Customer No. " << ob.custnum << endl;
    stream << "Customer name: " << ob.name << endl;
    stream << "Balance: " << ob.balance;

    return stream;
}

    int main()
{
    account ob(1001, "Tony Stark", 1000000);

    ofstream out("customer-info.txt");

    out << ob;

    out.close();

    return 0;
}