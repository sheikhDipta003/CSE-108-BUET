# include <iostream>
# include <cstdlib>
using namespace std;

class Stack{
protected:
    enum{SIZE = 100};
    int arr[SIZE];
    int top;
    int len;
public:
    Stack(){ top = -1; len = 0; }
    void push(int i){ arr[++top] = i; len = top + 1; }
    int pop(){ return arr[top--]; }
};

class StackSafe: public Stack{
public:
    void push(int i){
        if(top >= SIZE){
            cout << "\nStack full\n";
            exit(0);
        }
        Stack::push(i);
    }
    int pop(){
        if(top < 0){
            cout << "\nStack empty\n";
            exit(0);
        }
        return Stack::pop();
    }
    int getlen() { return len; }
};

int main(){
    StackSafe s1;
    s1.push(10);
    s1.push(35);
    s1.push(56);
    s1.push(29);
    s1.push(-67);

    cout << "\n\n==================================\n";
    for(int i = 0 ; i < s1.getlen()+10 ; i++){
        cout << s1.pop() << "\t";
    }
    cout << "\n==================================\n\n";

    return 0;
}
