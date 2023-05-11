# include <iostream>
using namespace std;

class Counter{
    int count;
public:
    Counter():count(0){}
    Counter(int c):count(c){}
    Counter operator++(){   //increment count, then return an unnamed temporary object initialized to this count
        return Counter(++count);
    }
    int getCount(){return count;}
};

int main(){
    Counter c1, c2(15);

    cout << "\n\n==================================\n";
    cout << "value of c2 = " << c2.getCount() << endl;
    ++c2;
    cout << "value of c2(after increment) = " << c2.getCount() << endl;
    c2 = ++c1;
    cout << "final value of c1 = " << c1.getCount() << endl;
    cout << "final value of c2 = " << c2.getCount() << endl;
    cout << "\n==================================\n\n";

    return 0;
}