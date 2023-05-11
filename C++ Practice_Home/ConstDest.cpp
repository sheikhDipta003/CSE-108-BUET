# include <iostream>
# include <ctime>

using namespace std;

class Timer{
    clock_t start;

    public:
        Timer();
        ~Timer();
};

Timer::Timer(){
    start = clock();
}

Timer::~Timer(){
    clock_t end;

    end = clock();

    cout << "Total time elapsed: " << (end - start) / CLOCKS_PER_SEC << "\n\n";
}

int main(){
    Timer my_timer;
    char c;

    //some code
    cout << "\nEnter any character: ";
    cin >> c;


    return 0;
}