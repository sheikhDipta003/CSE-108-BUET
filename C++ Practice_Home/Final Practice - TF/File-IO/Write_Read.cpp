# include <iostream>
# include <fstream>
# include <cstring>
using namespace std;

int main(){
    ofstream out = ofstream("test.txt");
    double d1 = 3.1416;
    char str1[] = "Eureka!";
    double d2 = -1.0;
    char str2[100] = "";

    out.write((char*) &d1, sizeof(double));
    out.write(str1, strlen(str1));
    out.close();

    ifstream in = ifstream("test.txt");
    in.read((char *)&d2, sizeof(double));
    in.read(str2, 100);

    cout << "\n\n===================================\n";
    cout << "double : " << d2 << ", string : " << str2 << endl;
    cout << "\n===================================\n\n";
    in.close();

    return 0;
}