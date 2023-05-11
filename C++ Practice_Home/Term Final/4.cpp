// Given the following class declaration ‘Date’, overload the binary minus operator so that an expression 
// like ob1-ob2 will give the difference between the two Date objects in number of days, where ob1 and ob2 
// are objects of Date class. For simplicity of calculation assume that all months have 30 days. Also overload 
// left shift operator so that an expression like cout<<ob will print day-month-year (e.g., 17-1-2021), where 
// ob is an object of Date class. Include a main() function where these operators will be used.

# include <iostream>
using namespace std;

class Date{ 
    int day, month, year; 
public: 
    Date(int m, int d, int y){ 
        day=d; 
        month=m; 
        year=y; 
    }
    void setVal(int d, int m, int y){day = d; month = m ; year = y;}
    void getVal(int &d, int &m, int &y){d = day; m = month; y = year;}
    Date operator-(Date d);
    friend std::ostream& operator<<(std::ostream& stream, Date ob);
};

Date Date::operator-(Date d){
    Date temp(1, 1, 2000);
    int d1, d2, m1, m2, y1, y2;

    this->getVal(d1, m1, y1);
    d.getVal(d2, m2, y2);

    temp.setVal(d1 - d2, m1 - m2, y1 - y2);

    return temp;
}

std::ostream& operator<<(std::ostream& stream, Date ob){
    int d, m, y;
    ob.getVal(d, m, y);

    cout << d << " - " << m << " - " << y << endl;

    return stream;
}

int main(){
    Date date1(2, 2, 2000), date2(28, 2, 2000), date3(1, 1, 2000);
    cout << date1;
    date3 = date1 - date2;
    cout << date3;


    return 0;
}