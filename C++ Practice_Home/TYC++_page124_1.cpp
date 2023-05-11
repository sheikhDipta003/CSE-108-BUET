# include <iostream>
using namespace std;

class letters{
    char ch;

public:
    letters(char c){
        ch = c;
    }
    char getCh(){
        return ch;
    }
};

int main(){
    letters L[10] = {letters('A'), letters('B'), letters('C'), letters('D'), letters('E'),
                    letters('F'), letters('G'), letters('H'), letters('I'), letters('J')};

    cout << endl;
    for(int i = 0 ; i < 10 ; i++){
        cout << "Object No. " << (i + 1) << ": " << L[i].getCh() << endl;
    }

    return 0;
}