# include <iostream>
using namespace std;

class track{
    static int slNo;
public:
    track(){slNo++;}
    void getSerialNo(){cout << "I am object number " << slNo << endl;}
};

int track::slNo = 0;

int main(){
    cout << "\n\n==================================\n";
    track t1;
    t1.getSerialNo();
    track t2;
    t2.getSerialNo();
    track t3;
    t3.getSerialNo();
    cout << "\n==================================\n\n";

    return 0;
}