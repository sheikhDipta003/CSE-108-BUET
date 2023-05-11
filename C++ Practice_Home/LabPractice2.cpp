# include <iostream>
# include <cstdlib>
using namespace std;

struct xyz
{
    int x;
    int y;
    int z;
};

class Vectors{
    xyz *ob;
    int N;
    int *sum, *v;

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
    v = (int*) malloc(3 * sizeof(int));
    sum[0] = sum[1] = sum[2] = 0;

    ob = (xyz*) malloc(N * sizeof(xyz));
}

void Vectors::print(){
    for(int i = 0 ; i < N ; i++){
        cout << ob[i].x << " " << ob[i].y << " " << ob[i].z << endl;
    }
}

void Vectors::set(int index, int x, int y, int z){
    ob[index].x = x;
    ob[index].y = y;
    ob[index].z = z;
}

int* Vectors::get(int index){
    v[0] = ob[index].x;
    v[1] = ob[index].y;
    v[2] = ob[index].z;

    return v;
}

void Vectors::add(int x, int y, int z){
    for(int i = 0 ; i < N ; i++){
        ob[i].x += x;
        ob[i].y += y;
        ob[i].z += z;
    }
}

int* Vectors::add(){
    for(int i = 0 ; i < N ; i++){
        sum[0] += ob[i].x;
        sum[1] += ob[i].y;
        sum[2] += ob[i].z;
    }

    return sum;
}

Vectors::~Vectors(){
    free(ob);
    free(sum);
    free(v);
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