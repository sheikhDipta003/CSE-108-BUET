# include <iostream>
# include <fstream>
using namespace std;

int main(int argc, char *argv[]){
    char ch;
    fstream f("test.txt", ios::in | ios::out | ios::binary);
    f.seekp(10, ios::beg);
    f.put('A');
    f.close();

    ifstream in("test.txt");
    while(!in.eof()){
        ch = in.get();
        if(ch != EOF)   cout << ch;
    }
    in.close();

    return 0;
}