# include <iostream>
# include <fstream>
# include <cstring>
using namespace std;

int main(){
    char str[] = "The Taj Mahal is an ivory-white marble mausoleum on the southern bank of the river Yamuna in the Indian city of Agra.\nIt was commissioned in 1632 by the Mughal emperor Shah Jahan (reigned from 1628 to 1658) to house the tomb of his favourite wife, Mumtaz Mahal; it also houses the tomb of Shah Jahan himself.\nThe tomb is the centrepiece of a 17-hectare (42-acre) complex, which includes a mosque and a guest house, and is set in formal gardens bounded on three sides by a crenellated wall.";
    ofstream out("test2.txt");
    out.write(str, strlen(str));
    out.close();

    ifstream in("test2.txt");
    long i;
    in.seekg(0, ios::end);
    i = (long) in.tellg();
    i -= 2;
    char ch;

    for(;i>=0;i--){
        in.seekg(i, ios::beg);
        ch = in.get();
        if(ch != EOF)     cout << ch;
    }
    in.close();

    return 0;
}