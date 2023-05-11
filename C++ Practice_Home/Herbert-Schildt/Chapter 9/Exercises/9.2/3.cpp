# include <iostream>
# include <fstream>

using namespace std;

int main(){
    ifstream mystream("words.txt");

    if(!mystream){
        cout << "Cannot open file for input!" ;
        return -1;
    }   

    char ch;
    int num_words = 1;

    mystream.unsetf(ios::skipws);

    while(!mystream.eof()){
        mystream >> ch;

        if(ch == ' '){
            num_words++;
        }
    }

    mystream.close();
    cout << "Total number of words: " << num_words << endl;

    return 0;
}