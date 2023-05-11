# include <iostream>
# include <cstdlib>
# include <cctype>
using namespace std;

class list{
public:
    list *head; //pointer to start of the list
    list *tail; // pointer to end of the list
    list *next; // pointer to next item
    int num;    // value to be stored

    list(){ head = tail = next = NULL; }
    virtual void store(int i) = 0;
    virtual int retrieve() = 0;
    // This is an abstract class since there are two Pure Virtual Functions [actually, if a class contains at least one pure virtual function, then it will be an abstract class].
};

class queue : public list{
public:
    void store(int i);
    int retrieve();
};
// Creating a queue type list

void queue::store(int i){
    list *item;

    item = new queue;

    if(!item){
        cout << "Allocation error" << endl;
        exit(0);
    }

    item->num = i;

    if(tail)    tail->next = item;

    tail = item;
    item->next = NULL;
    if(!head)   head = tail;
}

int queue::retrieve(){
    int i;
    list *p;

    if(!head){
        cout << "List empty" << endl;
        return 0;
    }

    i = head->num;
    p = head;
    head = head->next;
    delete p;
    // Remove from the start of list

    return i;
}

class stack : public list{
public:
    void store(int i);
    int retrieve();
};

void stack::store(int i){
    list *item;

    item = new stack;

    if(!item){
        cout << "Allocation error" << endl;
        exit(0);
    }

    item->num = i;
    if(head)    item->next = head;
    head = item;
    if(!tail)   tail = head;
}

int stack::retrieve(){
    int i;
    list *p;

    if(!head){
        cout << "List empty" << endl;
        return 0;
    }

    i = head->num;
    p = head;
    head = head->next;
    delete p;
    // Remove from the start of list

    return i;
}

int main(){
    list *p;

    queue q_ob;
    p = &q_ob;

    p->store(10);
    p->store(20);
    p->store(30);

    cout << "\nQueue: ";
    cout << p->retrieve() << "\t" ;
    cout << p->retrieve() << "\t";
    cout << p->retrieve() << "\t";

    cout << endl;

    stack s_ob;
    p = &s_ob;

    p->store(40);
    p->store(50);
    p->store(60);

    cout << "Stack: ";
    cout << p->retrieve() << "\t";
    cout << p->retrieve() << "\t";
    cout << p->retrieve() << "\t";

    cout << endl << endl;

    return 0;
}