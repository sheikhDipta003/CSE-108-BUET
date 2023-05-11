# include <iostream>
# include <cstring>
using namespace std;

class array{
    int nums[10];

public:
    array();
    void set(int n[10]);
    // void set(int *n);
    void show();
    array operator+(array ob2);
    array operator-(array ob2);
    int operator==(array ob2);
};

array::array(){
    for(int i = 0; i < 10 ; i++){
        nums[i] = 0;
    }
}

void array::set(int *n){
    for(int i = 0; i < 10 ; i++){
        nums[i] = n[i];
    }
}

void array::show(){
    cout << endl;

    for(int i = 0; i < 10 ; i++){
        cout << nums[i] << " ";
    }
}

array array::operator+(array ob2){
    array temp;
    int T[10] = {0};

    for(int i = 0 ; i < 10 ; i++){
        T[i] = this->nums[i] + ob2.nums[i];
    }

    temp.set(T);

    return temp;
}

array array::operator-(array ob2){
    array temp;
    int T[10] = {0};

    for(int i = 0 ; i < 10 ; i++){
        T[i] = this->nums[i] - ob2.nums[i];
    }

    temp.set(T);

    return temp;
}

int array::operator==(array ob2){
    for(int i = 0 ; i < 10 ; i++){
        if(this->nums[i] != ob2.nums[i]){
            return 0;
        }
    }
    return 1;
}

int main(){
    array o1, o2, o3;

    int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    o1.set(A);
    o2.set(A);

    o3 = o1 + o2;
    o3.show();

    o3 = o1 - o3;
    o3.show();

    if(o1 == o2){
        cout << "\no1 equals o2" << endl;
    }
    else{
        cout << "\no1 does not equal o2" << endl;
    }

    if(o1 == o3){
        cout << "o1 equals o3" << endl;
    }
    else{
        cout << "o1 does not equal o3" << endl << endl;
    }
}