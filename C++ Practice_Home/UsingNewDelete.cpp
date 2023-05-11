# include <iostream>
using namespace std;

class temp{
    int i, j;

public:
    void setValues(int v1, int v2){
        i = v1;
        j = v2;
    }
    int getProduct(){
        return (i * j);
    }
};

int main(){
    temp *q;
    int *p;

    q = new temp;
    if(!q){
        cout << "\nAllocation error!" << endl;
        return -1;
    }
    q->setValues(10, 2);
    cout << "Result = " << q->getProduct() << endl;

    p = new int;
    if(!p){
        cout << "\nAllocation error!" << endl;
        return -1;
    }
    *p = 1000;
    cout << "p = " << *p << endl;

    delete p;

    return 0;
}