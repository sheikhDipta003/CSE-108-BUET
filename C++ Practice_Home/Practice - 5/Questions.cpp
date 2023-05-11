# include <iostream>
# include <cstring>
using namespace std;

class Date{
    int year, month, day;

public:
    Date(){
        year = 2000;
        month = 11;
        day = 4;
    }
    Date(int Y, int M, int D){
        year = Y;
        month = M;
        day = D;
    }
    int getY(){ return year;    }
    int getM(){ return month;    }
    int getD(){ return day;    }

    void printDate(){   cout << day << " - " << month << " - " << year << endl; }

    int compareDates(Date d){
        //returns 1 if date of the caller object is greater
        if(this->getY() > d.getY()){
            return 1;
        }
        else if (this->getY() < d.getY()){
            return -1;
        }
        else{
            if(this->getM() > d.getM()){
                return 1;
            }
            else if (this->getM() < d.getM()){
                return -1;
            }
            else{
                if(this->getD() > d.getD()){
                    return 1;
                }
                else if (this->getD() < d.getD()){
                    return -1;
                }
                else{
                    return 0;
                }
            }
        }
    }

    int numOfDays(Date d){
        int N1, N2;
        N1 = this->getY() * 360 + this->getM() * 30 + this->getD();
        N2 = d.getY() * 360 + d.getM() * 30 + d.getD();

        if(this->compareDates(d) == 1){
            return (N1 - N2);
        }
        else if(this->compareDates(d) == -1){
            return (N2 - N1);
        }
        else if(this->compareDates(d) == 0){
            return 0;
        }
    }
};

class Event{
    char *name;
    Date startEvent, endEvent;
public:
    void setName(char *s){
        int len;
        len = strlen(s);
        name = new char[len + 1];
        strcpy(name, s);
    }
    void setEventStart(Date ob){
        startEvent = ob;
    }
    void setEventEnd(Date ob){
        endEvent = ob;
    }
    char* getName(){return name;}
    Date getEventStart(){return startEvent;}
    Date getEventEnd(){return endEvent;}

    int durationDays(){
        return startEvent.numOfDays(endEvent);
    }
    bool doesConflict(Event e){
        if(startEvent.compareDates(e.startEvent) == 1 && startEvent.compareDates(e.endEvent) == 1){
            return true;
        }
        else if(startEvent.compareDates(e.startEvent) == -1 && startEvent.compareDates(e.startEvent) == -1){
            return true;
        }
        else if(startEvent.compareDates(e.startEvent) == 0 && endEvent.compareDates(e.endEvent) == 0){
            return true;
        }
        else{
            return false;
        }
    }
};

class EventList{
    Event *events;
    int n;
public:
    EventList(int size){
        n = 0;
        events = new Event[size];
    }
    void append(Event e){
        events[n] = e;
        n++;
    }
    void set(Event f[], int c){
        for(int i = 0 ; i < c ; i++){
            events[i+n] = f[i];
        }
    }
    void printEvents(){
        for(int i = 0 ; i < n ; i++){
            cout << events[i].getName() << endl;
        }
    }
    void printEvents2(Date d){
        for(int i = 0 ; i < n ; i++){
            if(events[i].getEventStart().compareDates(d) != -1 || events[i].getEventEnd().compareDates(d) != 1){
                cout << events[i].getName() << endl;
            }
        }
    }
};

int main(){
    Date d1(2000, 1, 1), d2(2001, 1, 1);
    int compDates, numDays;

    cout << "\n---------------Output 1---------------" << endl;
    d1.printDate();
    d2.printDate();

    cout << "\n---------------Output 2---------------" << endl;
    compDates = d1.compareDates(d2);
    if(compDates == 1){
        cout << "d1 comes after d2" << endl;
    }
    else if(compDates == -1){
        cout << "d1 comes before d2" << endl;
    }
    else if(compDates == 0){
        cout << "d1 is the same as d2" << endl;
    }

    cout << "\n---------------Output 3---------------" << endl;
    numDays = d1.numOfDays(d2);
    cout << "Number of days between d1 and d2 = " << numDays << endl;

    cout << "\n---------------Output 4---------------" << endl;
    Event event1, event2;
    event1.setEventStart(d1);
    event1.setEventEnd(d2);
    event2.setEventStart(d1);
    event2.setEventEnd(d2);
    event1.setName("Graphic Design Course");
    event2.setName("Term Final Ques Solving");

    cout << "Name of event1 = " << event1.getName() << "     Name of event2 = " << event2.getName() << endl;

    cout << "\n---------------Output 5---------------" << endl;
    cout << "Duration of the first event: " << event1.durationDays() << endl;
    cout << "Duration of the second event: " << event2.durationDays() << endl;

    cout << "\n---------------Output 6---------------" << endl;
    bool isConflict;
    isConflict = event1.doesConflict(event2);
    if(isConflict == true){
        cout << "The two events conflict" << endl;
    }
    else{
        cout << "The two events do not conflict" << endl;
    }

    cout << "\n---------------Output 7---------------" << endl;
    EventList list(5);
    list.append(event1);
    list.append(event2);
    list.printEvents();
    list.printEvents2(d1);

    return 0;
}