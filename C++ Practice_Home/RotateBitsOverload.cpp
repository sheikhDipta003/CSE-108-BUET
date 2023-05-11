# include <iostream>
# include <cstring>

using namespace std;

int rotateBits(int num);

int main(){
    cout << "Hello world!" << endl;
    rotateBits(16);

    return 0;
}

int rotateBits(int num){
    unsigned int mask = 1 << 31;
    char numBits[32];

    for(int i = 0 ; i < 32 ; i++){
        if (num & mask != 0){
            numBits[i] = '1';
        }
        else{
            numBits[i] = '0';
        }

        mask = mask >> 1;
    }

    cout << "The Bit pattern of 16: " << numBits;
}