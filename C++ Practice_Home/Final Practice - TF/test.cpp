# include <iostream>
using namespace std;

int main(){
    int incr = 0, sum = 0;

    for(int i = 1 ; i <= 10 ; i++){
        for(int j = 1; j <= i ; j++){
            for(int k = 1 ; k <=j ; k++){
                incr = incr + 1;
                sum = sum + incr;
            }
        }
    }

    cout << sum;

    return 0;
}