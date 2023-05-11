# include <iostream>

using namespace std;

union swapBytes
{
    void swap();
    void set_word(unsigned short i);
    void show_word();

    unsigned short u;
    unsigned char c[2];
};

int main(){
    swapBytes myUnion;

    myUnion.set_word(12100);
    myUnion.swap();
    myUnion.show_word();

    return 0;
}

void swapBytes::swap(){
    char t;

    t = c[1];
    c[1] = c[0];
    c[0] = t;
}

void swapBytes::set_word(unsigned short i){
    u = i;
}

void swapBytes::show_word(){
    cout << "The Given short integer is: " << u;
}

