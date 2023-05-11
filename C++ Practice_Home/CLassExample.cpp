# include <iostream>
# include <cstring>

using namespace std;

class card{
    char title[100];
    char author[100];
    int numOfCopies;
    public:
        void store(char t[], char a[], int c);
        void show();
};

int main()
{
    card myCard;

    myCard.store("Teach Yourself C++", "Herbert Schildt", 100000);

    myCard.show();
}

void card::store(char t[], char a[], int c){
    strcpy(title, t);
    strcpy(author, a);
    numOfCopies = c;
}

void card::show(){
    cout << "Title: " << title;
    cout << "\nAuthor Name: " << author;
    cout << "\nNumber of copies available : " << numOfCopies;
}
