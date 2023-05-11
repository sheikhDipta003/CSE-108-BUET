# include <iostream>
# include <fstream>

using namespace std;

int main(){
    char ch;
    /* ofstream myfile;

    myfile.open("example.txt");

    myfile << "Writing to a file ...\n";

    myfile.close(); */

    ifstream myfile("example.txt");

    if(myfile.is_open()){
        while(!myfile.eof()){
            myfile >> ch;
            cout << ch;
        }

        cout << endl;
        myfile.close();
    }
    else{
        cout << "Unable to open file";
    }

    return 0;
}


