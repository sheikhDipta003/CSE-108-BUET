# include <iostream>
# include <cstdlib>
# include <cstring>
using namespace std;

class Stack{
    int tos, size_of_stack;
    int* p;

public:
    Stack(int size);
    ~Stack();
    void push(int n);
    int pop();
};

Stack::Stack(int size){
    tos = 0;
    size_of_stack = size;

    p = (int*) malloc(size_of_stack * sizeof(int));

    if (!p){
        cout << "\nAllocation Failed!" << endl;
    }
}

void Stack::push(int n){
    if (tos > size_of_stack){
        cout << "\nStack overflow .." << endl;
        return;
    }

    p[tos++] = n;
}

int Stack::pop(){
    if (tos < 0){
        cout << "\nStack underflow .." << endl;
        return -1;
    }

    return p[--tos];
}

Stack::~Stack(){
    free(p);
}

int main(){
    Stack my_stack(5);

    my_stack.push(10);
    my_stack.push(20);
    my_stack.push(30);
    my_stack.push(40);
    my_stack.push(50);

    cout << "\nDisplaying the contents of the stack:" << endl;
    for(int i = 0 ; i < 5 ; i++){
        cout << "Element No. " << (5 - i) << ": " << my_stack.pop() << endl;
    }

    return 0;
}