# include <iostream>
# include <fstream>

using namespace std;

int main(){
    fstream in_out("swap.txt");

    if(!in_out){
        cout << "Could not open file" ;
        return -1;
    }

    in_out.setf(ios::skipws);

    char left, right, temp;
    while(!in_out.eof()){
        in_out >> left >> right;

        temp = left;
        left = right;
        right = temp;

        in_out.seekg(-2, ios::cur);

        in_out.put(left);
        in_out.put(right);
    }

    in_out.close();

    return 0;
}