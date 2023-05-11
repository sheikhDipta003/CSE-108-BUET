# include <iostream>
# include <windows.h>
# include <cstring>

using namespace std;

void sleep(int sec){
    cout << "Sleep for " << sec << " seconds ..." << endl;
    Sleep(sec);
}

void sleep(char *s){
    cout << "Sleep for " << s << " seconds ..." << endl;
    Sleep(atoi(s));
}

int main(){
    cout << "\nUsing first sleep() func:" << endl;
    sleep(5000);   //miliseconds

    cout << "\nUsing second sleep() func:" << endl;
    sleep("10000");    //miliseconds

    return 0;
}