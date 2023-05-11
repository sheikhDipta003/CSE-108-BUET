# include <iostream>
# include <fstream>
using namespace std;

int main(){

    ifstream in("sample.txt");

    if(!in){
        cout << "Could not open file for input!";
        return -1;
    }

    char str[100];

    while(!in.eof()){

        in.getline(str, 100, '\n');
        cout << str << endl;
    }

    in.close();

    return 0;
}