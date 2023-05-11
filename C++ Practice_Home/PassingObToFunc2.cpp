# include <iostream>
using namespace std;

class dyn_a{
    int *p;
public:
    dyn_a(int i);
    ~dyn_a(){   free(p);    cout << "Freeing ...\n";    }
    int get(){  return *p;  }
};

dyn_a::dyn_a(int i){
    p = (int *) malloc(sizeof(int));
    *p = i;
}

int neg(dyn_a ob){
    return -ob.get();
    // AFTER returning to main(), ob's scope will terminate and destructor will be called.
}

int main(){
    dyn_a o(-10);

    cout << o.get() << endl;
    cout << neg(o) << endl;

    dyn_a o2(20);
    cout << o2.get() << endl;
    cout << neg(o2) << endl;

    cout << o.get() << endl;
    cout << neg(o) << endl;

    return 0;
}