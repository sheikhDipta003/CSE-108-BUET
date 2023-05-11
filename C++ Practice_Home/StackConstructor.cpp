# include <iostream>
# include <cstring>

using namespace std;

# define SIZE 10

class stack{
    char stck[SIZE];
    int tos;

    public:
        stack();    //constructor for class stack()
        void push(char ch);
        char pop();
};

stack::stack(){
    cout << "Constructing a new stack\n";
    tos = 0;
}

void stack::push(char ch){
    if (tos == SIZE){
        cout << "Stack is full\n";
        return;
    }

    stck[tos] = ch;
    tos++;
}

char stack::pop(){
    if (tos == 0){
        cout << "Stack Underflow ..." << endl;
        return '0';
    }

    tos--;
    return stck[tos];
}

int main(){
    stack my_stack;
    
    //initialize stack
    my_stack.push('10');
    my_stack.push('20');
    my_stack.push('30');
    my_stack.push('40');
    my_stack.push('50');
    my_stack.push('60');
    my_stack.push('70');
    my_stack.push('80');
    my_stack.push('90');
    my_stack.push('100');

    //show all the elements
    for(int i = 0 ; i < SIZE ; i++){
        cout <<  "\nElement No - " << (i + 1) << my_stack.pop();
    }

    return 0;
}