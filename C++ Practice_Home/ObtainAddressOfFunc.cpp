# include <iostream>
using namespace std;

int diff(int, int);
float diff(float, float);

int main(){
    //Creating a pointer to the first function
    int (*fp1) (int, int);

    //Creating a pointer to the second function
    float (*fp2) (float, float);

    fp1 = diff; //Obtaining the address of the first function
    fp2 = diff; //Obtaining the address of the second function

    cout << "\nOutput of the first function: " << fp1(10, 2) << "\nOutput of the second function: " << fp2(10.5, 5.8) << "\n\n";

    return 0;
}

int diff(int a, int b){
    return a-b;
}

float diff(float a, float b){
    return a-b;
}
