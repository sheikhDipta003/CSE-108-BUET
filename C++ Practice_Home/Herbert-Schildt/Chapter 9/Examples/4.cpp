# include <iostream>
# include <fstream>

using namespace std;

void check_status(ifstream &in);

int main(){

    ifstream in("test.txt");

    char ch;
    while(!in.eof()){
        in >> ch;
        check_status(in);
    }

    check_status(in);

    in.close();

    return 0;
}

void check_status(ifstream &in){
    ios::iostate i;

    i = in.rdstate();

    if(i & ios::eofbit){
        cout << "EOF encountered\n";
    }
    else if(i & ios::failbit){
        cout << "Non-fatal I/O error encountered\n";
    }
    else if (i & ios::badbit)
    {
        cout << "Fatal I/O error encountered\n";
    }
}