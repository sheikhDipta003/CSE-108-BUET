# include <iostream>
# include <fstream>

using namespace std;

int main(){
    ifstream in("sample.txt");

    long int pos = -1;
    in.seekg(pos, ios::end);

    char ch;
    while(in.tellg() >= 0){
        ch = in.get();
        cout << ch;
        pos--;
        in.seekg(pos, ios::end);
    }

    in.close();

    return 0;
}