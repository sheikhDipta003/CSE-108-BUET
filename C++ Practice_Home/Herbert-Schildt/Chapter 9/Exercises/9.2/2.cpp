# include <iostream>
# include <cstring>
# include <fstream>
using namespace std;

int main(){

    ofstream mystream("phone.txt");

    if(!mystream){
        cout << "Cannot open the file for output";
        return -1;
    }

    char residents[200] = "Issac Newton, 415 555-3423\nRobert Goddard, 213 555-2312\nEnricho Fermi, 202 555-1111";

    mystream << residents;

    mystream.close();

    return 0;
}