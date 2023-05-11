# include <iostream>
# include <cstring>

using namespace std;

//define a class named "Employee"
class Employee{
    char name[100]; //private by default

    public:
        void putName(char *s);
        void getName(char *t);
    
    private:
        double wages;
    
    public:
        void putWage(double w);
        double getWage();
};

int main(){
    char temp[100];

    Employee newEmployee;

    //initialize wages and name
    newEmployee.putName("Thanos");
    newEmployee.putWage(100000.292);

    //print wages and name
    newEmployee.getName(temp);
    cout << "The name of the new employee is: " << temp;
    cout << "\nAnd his wages are: " << newEmployee.getWage();

    return 0;
}

void Employee::putName(char *s){
    strcpy(name, s);
}

void Employee::getName(char *t){
    strcpy(t, name);
}

void Employee::putWage(double w){
    wages = w;
}

double Employee::getWage(){
    return wages;
}