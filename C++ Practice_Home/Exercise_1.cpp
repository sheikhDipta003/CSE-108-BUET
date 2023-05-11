# include <iostream>
# include <cstring>
using namespace std;

class PersonalInfo{
    char name[100];
    int telephone;

public:
    void setName(char* s){
        strcpy(name, s);
    }
    void setTelephone(int number){
        telephone = number;
    }
    char* getName(){
        return name;
    }
    int getTelephone(){
        return telephone;
    }
};

int main(){
    PersonalInfo *ob;
    ob = new PersonalInfo;
    if (!ob){
        cout << "\nAllocation error!" << endl;
        return -1;
    }

    ob->setName("Dipta");
    ob->setTelephone(9183273);

    cout << "Entered Name: " << ob->getName() << endl;
    cout << "Entered Telephone Number: " << ob->getTelephone() << endl;

    delete ob;

    return 0;
}