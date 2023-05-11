# include <iostream>
using namespace std;

class myClass{
    int n, d;

public:
    myClass(int i, int j){n = i;    d = j;}
    friend int isFactor(myClass ob);
};

int isFactor(myClass ob){
    if (!(ob.n % ob.d)){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    myClass ob1(10, 2), ob2(13, 3);

    if(isFactor(ob1)){
        cout << "2 is a factor of 10" << endl;
    }
    else{
        cout << "2 is not a factor of 10" << endl;
    }

    if(isFactor(ob2)){
        cout << "3 is a factor of 13" << endl;
    }
    else{
        cout << "3 is not a factor of 13" << endl;
    }

    return 0;
}