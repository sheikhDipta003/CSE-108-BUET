# include <iostream>
# include <cstring>
# include <cstdlib>

# define SIZE 25

using namespace std;

class strtype{
    char *s;
    int len;

    public:
        strtype();
        ~strtype();
        void set(char *user);
        void display();
};

int main(){
    //create an object of strtype class
    strtype my_str;

    my_str.set("Dipta");
    my_str.display();

    return 0;
}

strtype::strtype(){
    cout << "\nInside constructor ..." << endl;

    //allocate memory for *s
    s = (char*) malloc(SIZE * sizeof(char));

    if (*s){
        cout << "Allocation Failed .." << endl;
        exit(1);
    }

    *s = '\0';  //set all the characters of *s to '\0'

    len = 0;
}

strtype::~strtype(){
    //free the memory
    cout << "\nInside destructor ..." << endl;
    free(s);
}

void strtype::set(char *user){
    if (strlen(user) > SIZE){
        cout << "Too large string .." << endl;
        return;
    }

    strcpy(s, user);
    len = strlen(user);
}

void strtype::display(){
    cout << "The String : " << s << endl;
    cout << "Length of the string: " << len << endl;
}