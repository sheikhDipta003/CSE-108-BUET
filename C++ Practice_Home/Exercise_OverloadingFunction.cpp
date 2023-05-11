# include <iostream>
using namespace std;

class samp{
    int a;

public:
    samp(){     a = 0;  }
    samp(int x){    a = x;  }
    int get_a(){    return a;   }
};

int main(){
    samp ob(88);
    samp obArray[10];
    //Add necessary constructor(s) to "samp" so that the above two lines are valid.

    return 0;
}