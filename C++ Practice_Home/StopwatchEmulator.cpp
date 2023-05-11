# include <iostream>
# include <ctime>
# include <windows.h>

using namespace std;

class stopwatch{
    int elapsed_time;
    clock_t start_time, end_time;

    public:
        stopwatch();
        ~stopwatch();
        void start();
        void stop();
        void show();
};

void stopwatch::start(){
    start_time = clock();
}

void stopwatch::stop(){
    end_time = clock();
}

void stopwatch::show(){
    elapsed_time = (end_time - start_time) / CLOCKS_PER_SEC;

    if (elapsed_time >= 10){
        cout << "\b\b" << elapsed_time;
    }
    else{
        cout << "\b\b" << 0 << elapsed_time;
    }
}

stopwatch::stopwatch(){
    elapsed_time = 0;
}

stopwatch::~stopwatch(){
    cout << "\nTotal time: " << elapsed_time;
}

int main(){
    stopwatch my_stopwatch;
    int sum = 0;

    my_stopwatch.start();

    for (int i = 1 ; i <= 60; i++){
        sum += i;
        Sleep(1000);

        my_stopwatch.stop();
        my_stopwatch.show();
    }
    cout << "\nSum: " << sum << endl;

    my_stopwatch.stop();
    my_stopwatch.show();

    return 0;
}