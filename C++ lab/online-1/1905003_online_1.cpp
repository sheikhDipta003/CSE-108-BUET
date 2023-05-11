# include <iostream>
# include <cstdlib>
using namespace std;

class Matrix{
    int M_row;
    int M_column;
    int **p;

public:
    Matrix(int r, int c);
    ~Matrix();
    void print();
    void set(int row, int column, int value);
    int get(int row, int column);
    void add(int n);
    int add();
};

Matrix::Matrix(int r, int c){
    M_row = r;
    M_column = c;

    p = (int**) malloc(M_row * sizeof(int*));
    for(int i = 0 ; i < M_row ; i++){
        p[i] = (int*) malloc(M_column * sizeof(int));
    }
}

void Matrix::print(){
    for(int i = 0 ; i < M_row ; i++){
        for(int j = 0 ; j < M_column ; j++){
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
}

void Matrix::set(int row, int column, int value){
    if (row >= 0 && row < M_row && column >= 0 && column < M_column){
        p[row][column] = value;
    }
    else{
        cout << "\nMatrix index out of bounds.." << endl;
    }
}

int Matrix::get(int row, int column){
    if(row > (M_row - 1) || column > (M_column - 1) || row < 0 || column < 0){
        return -1;
    }
    else{
        return p[row][column];
    }
}

void Matrix::add(int n){
    for(int i = 0 ; i < M_row ; i++){
        for(int j = 0 ; j < M_column ; j++){
            p[i][j] += n;
        }
    }
}

int Matrix::add(){
    int sum = 0;

    for(int i = 0 ; i < M_row ; i++){
        for(int j = 0 ; j < M_column ; j++){
            sum += p[i][j];
        }
    }

    return sum;
}

Matrix::~Matrix(){
    for(int i = 0 ; i < M_row ; i++){
        free(p[i]);
    }

    free(p);
}

int main(){
    cout<<"Hello World"<<'\n';
    Matrix m(3,3);
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            m.set(i,j,i+j);
    
    m.print();
    cout<<m.get(0,0)<<'\n';

    m.set(0,0,100);
    cout<<m.get(0,0)<<'\n';

    m.add(100);
    m.print();

    cout<<m.add()<<'\n';

    return 0;
}