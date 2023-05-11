# include <iostream>
# include <fstream>
# include <cstring>

using namespace std;

int main(){

    char str[100];
    char str2[100];
    ifstream in("myfile2.txt", ios::in | ios::binary);

    if(!in.is_open()){
        cout << "Cannot open file" << endl;
        exit(1);
    }

    in.get(str, 50);
    cout << "\nOutput of the first overloaded get() : " << str << endl;
    // Hello, my name is Dipta

    // set the input position indicator of the mystream object associated with "myfile2.txt"
    in.seekg(0, ios::beg); 
    in.get(str, 50, ',');
    cout << "Output of the second overloaded get() : " << str << endl;
    // Hello

    // set the input position indicator of the mystream object associated with "myfile2.txt"
    in.seekg(0, ios::beg);
    cout << "Output of the third overloaded get() : ";
    while(!in.eof()){
        cout << (char)in.get();
        // Without typecasting, it was showing a sequence of integers(ascii values, probably??)
    }
    cout << endl;
    // Hello, my name is Dipta
    // I am the biggest idiot in the world

    // // set the input position indicator of the mystream object associated with "myfile2.txt"
    // in.seekg(0, ios::beg);
    // in.getline(str2, 10);
    // cout << "\nOutput of the first overloaded getline(): " << str2;
    // Not working, don't know why??

    // in.seekg(0, ios::beg);
    // cout << "\nOutput of peek() : ";
    // while(!in.eof()){
    //     cout << in.peek();
    // }
    // cout << endl << endl;
    // Infinite loop, why??

    

    return 0;
}

