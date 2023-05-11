# include <iostream>
using namespace std;

void space(int count){
    for(; count ; count--){
        cout << ' ';
    }
}

void space(int count, char ch){
    for(; count ; count--){
        cout << ch;
    }
}

int main(){
    void (*fp1) (int);
    //Pointer to the function with an integer parameter

    void (*fp2) (int, char);
    //Pointer to the function with an integer and a char parameter

    fp1 = space;
    //Address of the first "space" function is assigned to fp1
    fp2 = space;
    //Address of the second "space" function is assigned to fp2

    fp1(22);
    cout << endl;

    fp2(30, 'x');
    cout << endl;

    return 0;
}