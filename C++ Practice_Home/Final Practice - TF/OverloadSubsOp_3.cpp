# include <iostream>
using namespace std;

class dynArray{
    int *p;
    int size;
public:
    dynArray(int s);
    ~dynArray(){
        delete [] p;
    }
    int &put(int index);
    int get(int index);
    dynArray& operator=(dynArray& ob){
        if(size < ob.size){
            delete [] p;
            p = new int[ob.size];
        }
        size = ob.size;
        for(int i = 0 ; i < size ; i++){
            p[i] = ob.get(i);
        }
        return *this;
    }
    int& operator[](int index){
        if(index < 0 || index >= size){
            cout << "\nOut of bounds" << endl;
        }
        return p[index];
    }
};

dynArray::dynArray(int s){
    size = s;
    p = new int[size];
}
int& dynArray::put(int index){
    if(index < 0 || index >= size){cout << "\nOut of bounds" << endl;   exit(1);}
    return p[index];
}
int dynArray::get(int index){
    if (index < 0 || index >= size)
    {
        cout << "\nOut of bounds" << endl;
        exit(1);
    }
    return p[index];
}

int main()
{
    dynArray a1(5);
    dynArray a2(6);

    //without using overloaded subscript([]) operator
    /* for(int i = 0 ; i < 5 ; i++){
        a1.put(i) = i + 10;
    }
    for (int i = 0; i < 6; i++)
    {
        a2.put(i) = i - 10;
    }

    cout << "\n\n===========================\n";

    for(int i = 0 ; i < 5 ; i++){
        cout << "a1[" << i << "] = " << a1.get(i) << "\t";
    }
    cout << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << "a2[" << i << "] = " << a2.get(i) << "\t";
    }

    a1 = a2;

    cout << "\nAfter assignment:" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << "a1[" << i << "] = " << a1.get(i) << "\t";
    }
    cout << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << "a2[" << i << "] = " << a2.get(i) << "\t";
    }

    cout << "\n===========================\n\n"; */

    //using overloaded subscript([]) operator
    for (int i = 0; i < 5; i++)
    {
        a1[i] = i + 10;
    }
    for (int i = 0; i < 6; i++)
    {
        a2[i] = i - 10;
    }

    cout << "\n\n===========================\n";

    for (int i = 0; i < 5; i++)
    {
        cout << "a1[" << i << "] = " << a1[i] << "\t";
    }
    cout << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << "a2[" << i << "] = " << a2[i] << "\t";
    }

    a1 = a2;

    cout << "\nAfter assignment:" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << "a1[" << i << "] = " << a1[i] << "\t";
    }
    cout << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << "a2[" << i << "] = " << a2[i] << "\t";
    }

    cout << "\n===========================\n\n";

    return 0;
}