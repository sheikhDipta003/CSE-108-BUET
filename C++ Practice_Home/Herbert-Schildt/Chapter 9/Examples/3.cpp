# include <iostream>
# include <fstream>
using namespace std;

int main(){
    fstream mystream("test.txt", ios::in | ios::out | ios::binary);

    if(!mystream){
        cout << "Error! Could not open file";
        return -1;
    }

    long int pos = 10;
    mystream.seekg(pos, ios::beg);
    mystream.put('z');

    mystream.close();

    return 0;
}
