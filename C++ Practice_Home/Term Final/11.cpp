// A class "Date" contains three private variable "day", "month" and "year". The users
// enter the date in Bangladeshi form, e.g., "23/12/2016" but the. output of the program
// display data in Chinese form, e.g., "2016/12/23".
// (i) Define the class along with the constructor;
// (ii) Write down an extractor function that has the following prompt: Enter a date in
// Bangladeshi form:
// (iii) Write down an inserter function generating the following output: Date (Chinese
// form) is 2016/12/23.

# include <iostream>
using namespace std;

class Date{
    int day, month, year;
public:
    Date(){}
    Date(int d, int m, int y){
        day = d;
        month = m;
        year = y;
    }
    friend istream& operator>>(istream& in, Date& d);
    friend ostream& operator<<(ostream& out, Date& d);
};

istream &operator>>(istream &in, Date &d){
    cout << "Enter a date in Bangladeshi form: ";
    string date, temp;
    in >> date;

    int pos_1, pos_2;
    pos_1 = (int) date.find('/');
    pos_2 = (int) date.rfind('/');

    temp = date.substr(0, pos_1);
    d.day = stoi(temp);

    temp = date.substr(pos_1+1, pos_2-pos_1-1);
    d.month = stoi(temp);

    temp = date.substr(pos_2+1);
    d.year = stoi(temp);

    return in;
}

ostream &operator<<(ostream &out, Date &d){
    out << "Date in Chinese form : " << d.year << "/" << d.month << "/" << d.day;
    return out;
}

int main()
{
    Date d;
    cin >> d;
    cout << d;

    return 0;
}