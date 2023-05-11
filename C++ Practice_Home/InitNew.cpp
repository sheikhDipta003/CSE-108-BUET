# include <iostream>
using namespace std;

class myClass{
    int i, j;

public:
    myClass(int v1, int v2){
        i = v1;
        j = v2;

        cout << "i = " << i << "; j = " << j << endl;
    }
    int getProduct(){
        return (i * j);
    }
};

int main(){
    myClass *p;
    p = new myClass(10, 5);

    cout << "Product of i and j: " << p->getProduct() << endl;

    delete p;

    return 0;
}