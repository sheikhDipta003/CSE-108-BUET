# include <iostream>
using namespace std;

# define SIZE 10

class stack{
char stck[SIZE];
int tos;

public:
    stack();
    void push(char ch);
    char pop();
    friend ostream &operator<<(ostream &stream, stack ob);
};

stack::stack(){
    tos = 0;
}

void stack::push(char ch){
    if(tos == SIZE){
        cout << "stack is full" << endl;
        return;
    }
    stck[tos] = ch;
    tos++;
}

char stack::pop(){
    if(tos == 0){
        cout << "Stack is empty" << endl;
        return 0;
    }
    tos--;
    return stck[tos];
}

ostream &operator<<(ostream &stream, stack ob){
    for(int i = 0 ; i < SIZE; i++){
        stream << ob.pop() << endl;
    }

    return stream;
}

    int main()
{
    stack my_stack;

    for(int i = 65 ; i < (SIZE + 65); i++){
        my_stack.push( char(i) );
    }

    cout << my_stack;

    return 0;
}