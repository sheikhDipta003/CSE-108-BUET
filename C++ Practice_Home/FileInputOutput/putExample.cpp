# include <iostream>
# include <fstream>
# include <cstdlib>

using namespace std;

int main(){
    char ch;

    ifstream in("myfile.txt", ios::in | ios::binary);

    if(!in.is_open()){
        cout << "Cannot open the file.." << endl;
        exit(1);
    }

    while (!in.eof())
    {
        in.get(ch);
        cout << ch;
    }
    
    cout << endl;
    in.close();

    return 0;
}


