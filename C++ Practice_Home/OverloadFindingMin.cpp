# include <iostream>
# include <cstring>

using namespace std;

int min(int a, int b);
char min(char a, char b);
double min(double a, double b);

int main(){
    cout << "Minimum of 13 and -60: " << min(13, -60);
    cout << "\nMinimum of 'a' and 'v': " << min('a', 'v');
    cout << "\nMinimum of 13.383 and -60.595: " << min(13.383, -60.595);

    return 0;
}

char min(char a, char b){
    if (a < b){
        return a;
    }
    else{
        return b;
    }
}

int min(int a, int b){
    if (a < b){
        return a;
    }
    else{
        return b;
    }
}

double min(double a, double b){
    if (a < b){
        return a;
    }
    else{
        return b;
    }
}