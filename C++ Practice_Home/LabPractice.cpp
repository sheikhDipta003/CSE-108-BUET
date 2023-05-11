# include <iostream>
# include <cstdlib>
using namespace std;

class Vectors{
    int **p;
    int *sum;
    int N;

public:
    Vectors(int maxVectors);
    ~Vectors();
    void print();
    void set(int index, int x, int y, int z);
    int* get(int index);
    void add(int x, int y, int z);
    int* add();
};

Vectors::Vectors(int maxVectors){
    N = maxVectors;

    sum = (int*) malloc(3 * sizeof(int));

    sum[0] = sum[1] = sum[2] = 0;

    p = (int**) malloc(N * sizeof(int*));

    for(int i = 0 ; i < N ; i++){
        p[i] = (int*) malloc(3 * sizeof(int));
    }
}

void Vectors::set(int index, int x, int y, int z){
    p[index][0] = x;
    p[index][1] = y;
    p[index][2] = z;
}

int* Vectors::get(int index){
    return p[index];
}

void Vectors::add(int x, int y, int z){
    for(int i = 0 ; i < N ; i++){
        p[i][0] += x;
        p[i][1] += y;
        p[i][2] += z;
    }
}

int* Vectors::add(){
    for(int i = 0 ; i < N ; i++){
        sum[0] += p[i][0];
        sum[1] += p[i][1];
        sum[2] += p[i][2];
    }

    return sum;
}

void Vectors::print(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < 3 ; j++){
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
}

Vectors::~Vectors(){
    free(sum);

    for(int i = 0 ; i < N ; i++){
        free(p[i]);
    }
    free(p);
}

int main(){
    cout << "Hello world" << "\n";

    Vectors m(3);

    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            m.set(i, i+j, i-j, i*j);
        }
    }

    m.print();

    int* array = m.get(0);
    cout << array[0] << " " << array[1] << " " << array[2] << "\n";
    m.set(0, 100, 100, 100);
    array = m.get(0);
    cout << array[0] << " " << array[1] << " " << array[2] << "\n";
    m.add(100, 100, 100);
    m.print();

    array = m.add();
    cout << array[0] << " " << array[1] << " " << array[2] << "\n";

    return 0;
}
