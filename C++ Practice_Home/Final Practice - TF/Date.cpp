# include <iostream>
# include <cstring>
using namespace std;

class Date{
    int day;
    int month;
    int year;
public:
    Date(int day=23, int month=12, int year=2016){
        this->day = day;
        this->month = month;
        this->year = year;
    }
    int getDay(){return day;}
    int getMonth(){return month;}
    int getYear(){return year;}
    void setDay(int d){this->day = d;}
    void setMonth(int m){this->month = m;}
    void setYear(int y){this->year = y;}
    friend istream& operator>>(istream& in, Date& d);
    friend ostream& operator<<(ostream& out, Date d);
};

Date split(char* s, char delim){
    Date d;
    int i = 0, j = 0;
    int count = 0;
    char *temp = NULL;

    for( ; i < strlen(s) ; i++){
        if(s[i] != delim){
            temp += s[i];
        }
        else {
            count++;
            if(count == 1) {
                d.setDay(atoi(temp));
            }
            else if(count == 2) {
                d.setMonth(atoi(temp));
            }
            else if(count == 3) {
                d.setYear(atoi(temp));
            }
            temp = NULL;
        }
    }

    return d;
}

istream &operator>>(istream &in, Date& d){
    char* t;
    cout << "Enter a date in Bangladeshi form: ";
    in >> t;
    d = split(t, '/');

    return in;
}

ostream &operator<<(ostream &out, Date d){
    out << "Date(Chinese format) is : " << d.getYear() << "/" << d.getDay() << "/" << d.getMonth() << endl;
    return out;
}

int main()
{
    Date d;

    cout << "\n\n===========================\n";
    /* cin >> d;
    cout << d; */
    cout << split("23/12/2016", '/').getDay() << endl;
    cout << "\n===========================\n\n";

    return 0;
}