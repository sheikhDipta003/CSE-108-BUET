# include <iostream>
# include <cstring>
using namespace std;

class what{
    char name[100];
    char id;
public:
    what(char);
    ~what(){cout << "Destructing who #" << id << endl;}
    void setName(char *p){ strcpy(name, p); }
};

what::what(char c){
    id = c;
    cout << "Constructing who #" << id << endl;
}

what make_what(){
    what ob('y');
    ob.setName("Object created in make_what()");
    return ob;
}

int main(){
    what my_ob('x');
    my_ob.setName("Object created in main()");

    my_ob = make_what();

    return 0;
}