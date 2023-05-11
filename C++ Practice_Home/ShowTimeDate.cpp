# include <iostream>
# include <cstring>
# include <ctime>

using namespace std;

class t_and_d{
    char Time[100], Date[100];
public:
    t_and_d(char time[], char date[]);
    void showTimeDate();
};

t_and_d::t_and_d(char time[], char date[]){
    strcpy(Time, time);
    strcpy(Date, date);
}

void t_and_d::showTimeDate(){
    cout << "\nCurrent System time: " << Time << endl;
    cout << "Date of today: " << Date << endl;
}

int main(){
    time_t t = time(NULL);
    char Time[100], Date[100];

    strftime(Time, sizeof(Time), "%H %M %S", localtime(&t));

    strftime(Date, sizeof(Date), "%d %m %Y", localtime(&t));

    t_and_d ob(Time, Date);
    ob.showTimeDate();

    return 0;
}