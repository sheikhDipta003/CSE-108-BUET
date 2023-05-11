# include <iostream>
# include <fstream>
using namespace std;

// Not working correctly. Don't know why!!

int main(){
    
    ifstream mystream_in("test.txt");   // create an ifstream object associated with the file "test.txt"
    ofstream mystream_out("test.txt");  // create an ofstream object associated with the file "test.txt"

    if(!mystream_in){
        cout << "Cannot open file for output" << endl;
        return -1;
    }
    // Check if the file has been opened successfully

    if (!mystream_out)
    {
        cout << "Cannot open file for input" << endl;
        return -1;
    }
    // Check if the file has been opened successfully

    char ch;

    mystream_in.unsetf(ios::skipws);

    while(!mystream_in.eof()){
        mystream_in >> ch;

        if(ch == ' '){
            ch = '|';
        }

        if(!mystream_in.eof())
            mystream_out << ch;
    }

    mystream_in.close();
    mystream_out.close();

    return 0;
}