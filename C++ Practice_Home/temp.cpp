# include <iostream>
# include <cstring>
# include <ctime>

using namespace std;

struct random
{
    int x;

    public:
        random(int n);
        int getX();
};

random::random(int n){
    x = n;
}

int random::getX(){
    cout << "\nThe value of x: " << x << endl << endl;
}

int main(){
    random r(10);

    r.getX();

    return 0;
}