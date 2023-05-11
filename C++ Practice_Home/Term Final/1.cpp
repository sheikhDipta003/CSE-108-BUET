// A “Student” class has a private variable to store ID, a constructor without parameter to initialize ID 
// and a private static variable. Write the code segment for Class “Student” and to create an array of 120 
// objects of “Student” class in the main function using ‘new’ operator. IDs of 120 “Student” objects are 
// initialized in the constructor as 1, 2, …, 120, respectively.

# include <iostream>
using namespace std;

class Student{
    int ID;
    static int temp;
    // This line only tells the compiler that there is an int variable named "temp" that is static, i.e. shared by ALL the objects of this class. But it DOES NOT allocate memory for storing temp's data. This process is called "Declaration".
public:
    Student(){ID = ++temp;}
    // int getID(){
    //     return ID;
    // }
    // Only for checking, not permitted according to question; must be deleted later
};

int Student::temp;
// When I didn't write this line, the compiler gave me error; why??
// => Because precisely in this line memory is allocated for storing temp's data - this process is called "Definition". Without defining a variable, it cannot be used [since that variable simply does not exist in the memory prior to its definition]. This is the reason compiler gave "undefined reference to temp" error.

int main(){
    Student* A = new Student[120];

    // for(int i = 0 ; i < 120 ; i++){
    //     cout << A[i].getID() << endl;
    // }

    return 0;
}