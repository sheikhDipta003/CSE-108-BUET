# include <iostream>
# include <ctime>
using namespace std;

class watch{
    time_t t;
    tm* now;
public:
    watch(){
        t = time(0);
        now = localtime(&t);
    }
    friend ostream &operator<<(ostream &stream, watch ob);
};

ostream &operator<<(ostream &stream, watch ob){

    stream << "Hour: " << ob.now->tm_hour << ", Min: " << ob.now->tm_min << ", Sec: " << ob.now->tm_sec << endl;

    return stream;
}

    int main()
{
    watch my_watch;

    cout << my_watch;

    return 0;
}