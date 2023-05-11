# include <iostream>
using namespace std;

class pr2;

class pr1{
    int printing;

public:
    pr1(){   printing = 0;   }
    void set_print(int status){ printing = status;}
    friend bool inuse(pr1 ob1, pr2 ob2);
};

class pr2{
    int printing;

public:
    pr2(){   printing = 0;   }
    void set_print(int status){ printing = status;}
    friend bool inuse(pr1 ob1, pr2 ob2);
};

bool inuse(pr1 ob1, pr2 ob2){
    if (ob1.printing == 1 || ob2.printing == 1){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    pr1 x;
    x.set_print(1);
    pr2 y;

    cout << "x.printing = 1, y.printing = 0" << endl;
    if(inuse(x, y)){
        cout << "One of the two printers is being used .." << endl;
    }
    else{
        cout << "Both printers are free to use .." << endl;
    }

    x.set_print(0);

    cout << "\nx.printing = 0, y.printing = 0" << endl;
    if(inuse(x, y)){
        cout << "One of the two printers is being used .." << endl;
    }
    else{
        cout << "Both printers are free to use .." << endl;
    }

    y.set_print(1);

    cout << "\nx.printing = 0, y.printing = 1" << endl;
    if(inuse(x, y)){
        cout << "One of the two printers is being used .." << endl;
    }
    else{
        cout << "Both printers are free to use .." << endl;
    }


    return 0;
}