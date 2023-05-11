# include <iostream>
using namespace std;

class Int{
    int data;
public:
    Int():data(0){}
    Int(int i):data(i){}
    int getData(){return data;}
    Int add(Int i2){
        Int temp;
        temp.data = this->getData() + i2.getData();
        return temp;
    }
};

int main(){
    Int i1, i2(10), i3(25);
    i1 = i2.add(i3);
    cout << "i1 = " << i1.getData() << ", i2 = " << i2.getData() << ", i3 = " << i3.getData() << endl;

    return 0;
}