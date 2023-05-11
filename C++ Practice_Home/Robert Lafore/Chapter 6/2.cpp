# include <iostream>
using namespace std;

class time{
    int hour, min, sec;
public:
    time(): hour(0), min(0), sec(0){}
    time(int h, int m, int s) : hour(h), min(m), sec(s){}
    void showTime(){
        cout << hour << ":" << min << ":" << sec;
    }
    void addAndStore(time t1, time t2){
        this->sec = t1.sec + t2.sec;
        this->hour = t1.hour + t2.hour;
        this->min = t1.min + t2.min;
        while(this->sec >= 60){
            this->sec -= 60;
            this->min++;
        }
        while(this->min >= 60){
            this->min -= 60;
            this->hour++;
        }
        while(this->hour >= 12){
            this->hour -= 12;
        }
    }
};

int main(){
    time t1(5, 30, 30), t2(9, 30, 30), t3;
    t3.addAndStore(t1, t2);
    cout << "\n\n==================================\n";
    t3.showTime();
    cout << "\n==================================\n\n";

    return 0;
}