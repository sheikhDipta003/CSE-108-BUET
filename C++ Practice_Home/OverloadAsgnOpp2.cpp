# include <iostream>
# include <cstring>
using namespace std;

class dyn_arr{
    int *p;
    int size;

public:
    dyn_arr(int s);
    ~dyn_arr(){     delete [] p;    }
    int &put(int i);
    int get(int i);
    // dyn_arr& operator=(dyn_arr& ob);
};

dyn_arr::dyn_arr(int s){
    size = s;
    p = new int[size];
}

int& dyn_arr::put(int i){
    if(i >= 0 && i < size){
        return p[i];
    }
    else{
        cout << "\nArray index out of bounds.." << endl;
        exit(0);
    }
}

int dyn_arr::get(int i){
    if(i >= 0 && i < size){
        return p[i];
    }
    else{
        cout << "\nArray index out of bounds.." << endl;
        exit(0);
    }
}

// dyn_arr& dyn_arr::operator=(dyn_arr& ob){
//     if(ob.size > this->size){
//         delete [] this->p;

//         this->size = ob.size;
//         this->p = new int[this->size];
//     }

//     for(int i = 0 ; i < ob.size ; i++){
//         this->p[i] = ob.p[i];
//     }

//     return *this;
// }

// The program is behaving in the same way whether "=" operator is overloaded or not. Why??

int main(){
    dyn_arr A1(5), A2(3);

    for(int i = 0 ; i < 5 ; i++){
        A1.put(i) = (i + 1) * 10;
    }

    for(int i = 0 ; i < 3 ; i++){
        A2.put(i) = (i + 8) * 10;
    }

    cout << "\n**************Before assignment***************" << endl;
    cout << "Elements of A1: " << endl;
    for(int i = 0 ; i < 5 ; i++){
        cout << A1.get(i) << " " ;
    }
    cout << endl;

    cout << "\nElements of A2: " << endl;
    for(int i = 0 ; i < 3 ; i++){
        cout << A2.get(i) << " " ;
    }
    cout << endl;

    A2 = A1;

    cout << "\n**************After assignment***************" << endl;
    cout << "Elements of A1: " << endl;
    for(int i = 0 ; i < 3 ; i++){
        cout << A1.get(i) << " " ;
    }
    cout << endl;

    cout << "\nElements of A2: " << endl;
    for(int i = 0 ; i < 3 ; i++){
        cout << A2.get(i) << " " ;
    }
    cout << endl << endl;

    return 0;
}