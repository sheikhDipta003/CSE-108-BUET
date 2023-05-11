# include <iostream>
# include <fstream>
using namespace std;

int main(int argc, char *argv[]){
    if(argc != 3){
        cout << "Usage: " << "<program name> <input file name> <output file name>\n";
        return 0;
    }
    ifstream in = ifstream(argv[1]);
    ofstream out = ofstream(argv[2]);
    if(!in){
        cout << "Error in opening file_1.txt for input\n";
        return 0;
    }
    if (!out)
    {
        cout << "Error in opening file_2.txt for output\n";
        return 0;
    }

    char ch;
    in.unsetf(ios::skipws);
    while(!in.eof()){
        in >> ch;
        if(ch == ' ')   ch = '|';
        if(!in.eof())   out << ch;
    }

    in.close();
    out.close();

    return 0;
}