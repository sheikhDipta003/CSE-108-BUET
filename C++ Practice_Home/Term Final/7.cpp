# include <iostream>
using namespace std;

class ListItem{
    int item;
    ListItem *next;
public:
    ListItem(int arg){item = arg; next = NULL;}
    int getItem(){return item;}
    void setNext(ListItem *n){next = n;}
    ListItem* getNext(){return next;}
};

class List{
public:
    ListItem *head;
    ListItem *tail;

    List(){head = NULL; tail = NULL;}
    virtual void store(int item) = 0;
    virtual int retrieve() = 0;
    virtual void print() = 0;
};

class Queue : public List{
public:
    void store(int item){
        ListItem *newItem;
        newItem = new ListItem(item);
        newItem->setNext(NULL);

        if(tail!=NULL){ tail->setNext(newItem); }
        tail = newItem;
        newItem->setNext(NULL);
        if(head==NULL){ head = tail; }
    }
    int retrieve(){
        int retrievedVal;
        ListItem* retrievedItem;

        if(head == NULL){
            //cout << "\nList is empty.\n";
            return -1;
        }

        retrievedVal = head->getItem();

        retrievedItem = head;
        head = head->getNext();
        delete retrievedItem;

        return retrievedVal;
    }
    void print(){
        int value;
        do{
            value = retrieve();
            if (value == -1)
                break;
            cout << value << ", ";
        } while(true);
    }
};

int main(){
    List* p;

    Queue q_ob;
    p = &q_ob;

    p->store(10);
    p->store(20);
    p->store(30);

    cout << "\n\n==========================================\n";
    p->print();
    cout << "\n==========================================\n\n";

    return 0;
}