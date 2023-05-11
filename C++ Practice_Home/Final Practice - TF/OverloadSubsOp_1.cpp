# include <iostream>
using namespace std;

const int SIZE = 5;

class arrayType{
    int a[SIZE];
public:
    arrayType(){
        for(int i = 0 ; i < SIZE ; i++) a[i] = i;
    }
    int &operator[](int i){
        if(i < 0 || i > SIZE - 1){
            cout << "\nIndex value of " << i << " is out of bounds." << endl;
            exit(1);
        }
        return a[i];
    }
    //By overloading the subscript operator ([]), we can access an array, in this case the array a[SIZE], just like a regular array.
    //Also, we can perform bounds checking within the overloaded function and create "Safe array".
    //However, such usage of array may add overhead that might not be acceptable in all situations. So, we must be careful about it.
};

int main(){
    arrayType ob;

    cout << "\n\n===========================\n";
    for(int i = 0; i < SIZE ; i++){
        cout << ob[i] << " " ;
    }
    cout << endl;
    for(int i = 0 ; i < SIZE ; i++){
        ob[i] = ob[i] + 10;
    }
    ob[SIZE + 10] = 100;
    
    cout << "\n===========================\n\n";

    return 0;
}


