# include <iostream>
# include <cstdio>
using namespace std;

class date{
    int day, month, year;

public:
    date(char *str);
    date(int d, int m, int y);
    void show(){
        cout << day << '/' << month << '/' << year << endl;
    }
};

date::date(char *str){
    sscanf(str, "%d%*c%d%*c%d", &day, &month, &year);
}

date::date(int d, int m, int y){
    day = d;
    month = m;
    year = y;
}

int main(){
    //construct date object using string
    date sdate("20/03/2021");

    //construct date object using integers
    date idate(20, 3, 2021);

    sdate.show();
    idate.show();

    return 0;
}