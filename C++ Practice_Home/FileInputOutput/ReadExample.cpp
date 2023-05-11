# include <iostream>
# include <fstream>
# include <cstdlib>
# include <cstring>

using namespace std;

int main(){

    char str1[100] = "I am Bangladeshi, but I HATE this country and its people";
    char str2[100];

    // Create a fstream object
    fstream mystream("myfile.txt", ios::out | ios::in | ios::binary);

    // Send message to the console if the file does not open
    // The file must 'exist' in order to open it with fstream
    if(!mystream.is_open()){
        cout << "Cannot open file" << endl;
        exit(1);
    }

    // Read one character at a time from str1 and write each of them in the stream "myfile.txt"
    mystream.write(str1, strlen(str1) + 1);


    // set the input position indicator of the mystream object associated with "myfile.txt"
    mystream.seekg(0, ios::beg);  
    // Read one character at a time from "myfile.txt" and write each of them in the string str2
    mystream.read(str2, strlen(str1) + 1);

    cout << str2 << endl;

    mystream.close();

    return 0;
}

