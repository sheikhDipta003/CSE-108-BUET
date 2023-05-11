# include <fstream>
# include <iostream>
using namespace std;

int main(){
    ifstream in("test2.txt");
    char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char ch;
    int freq[26] = {0};

    while(!in.eof()){
        ch = in.get();
        if(ch != EOF){
            ch = tolower(ch);
            for(int i = 0 ; i < 26 ; i++){
                if(alphabet[i]==ch){
                    freq[i]++;
                }
            }
        }
    }

    cout << "\n\n===================================\n";
    for (int i = 0; i < 26; i++)
    {
        cout << alphabet[i] << " --- " << freq[i] << endl;
    }
    cout << "\n===================================\n\n";
    in.close();

    return 0;
}