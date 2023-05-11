# include <iostream>
# include <fstream>
using namespace std;

int main(){

    ofstream mystream_out("test.txt");  // create new file

    if(!mystream_out){      // mystream will evaluate to false if failure occurs in opening the file
        cout << "Cannot open file for output!" << endl;
        return -1;
    }

    mystream_out << "Hello!\n";
    mystream_out << 100 << " " << hex << 100 << endl;

    mystream_out.close();

    ifstream mystream_in("test.txt");

    if (!mystream_in)
    { // mystream will evaluate to false if failure occurs in opening the file
        cout << "Cannot open file for input!" << endl;
        return -1;
    }

    char str[100];
    int i, j;

    mystream_in >> str >> i >> j;
    cout << "String from the file: " << str << "; integers from the file: " << i << ", " << j << endl;

    mystream_in.close();

    return 0;
}