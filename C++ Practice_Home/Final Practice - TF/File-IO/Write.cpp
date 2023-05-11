# include <iostream>
# include <fstream>
using namespace std;

int main(){
    double d1[5] = {1.1, 5.5, 2.2, 4.4, 3.3};
    double d2[5];
    ofstream fout = ofstream("test.txt");
    fout.write((char *) &d1, sizeof(d1));
    fout.close();

    ifstream fin = ifstream("test.txt");
    fin.read((char *)&d2, sizeof(d2));

    cout << "\n\n===================================\n";
    for(int i = 0 ; i < 5 ; i++){
        cout << "d2[" << i << "] = " << d2[i] << "\t";
    }
    cout << fin.gcount() << " characters read(sizeof double = " << sizeof(double) << ")";
    cout << "\n===================================\n\n";

    fin.close();

    return 0;
}