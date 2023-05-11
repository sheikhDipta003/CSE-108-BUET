# include <iostream>
# include <cstdlib>
using namespace std;

long int mystrtol(const char *start, char **end, int base = 10){
    return strtol(start, end, base);
}

int main(){
    char *str = "10";
    char *p = NULL;
    cout << "\nConverted long integer(base 10): " << mystrtol(str, &p);
    cout << "\nConverted long integer(base 2): " << mystrtol(str, &p, 2) << endl;
}