# include <iostream>
# include <fstream>
# include <cstdlib>

using namespace std;

int main(){

    char str[200] = "The Great Wall of China is a series of fortifications that were built across the historical northern borders of ancient Chinese states and Imperial China.";

    ofstream out("myfile.txt", ios::out | ios::binary);
    // openmode must be specified here so that we can use put function, because by default file will be opened in text mode.

    if(!out.is_open()){
        cout << "Cannot open the file.." << endl;
        exit(1);
    }

    for(int i = 0 ; str[i] ; i++){
        out.put(str[i]);
    }

    out.close();

    return 0;
}






