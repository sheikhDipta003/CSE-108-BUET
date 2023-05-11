# include <iostream>

using namespace std;

class Rectangle{
    int height, width;
    public:
        void set(int h, int w){
            height = h;
            width = w;
        }
        int area(){
            return (height * width);    //In case of smaller functions like this, the method is generally defined at
                                    //the time of prototyping 
        }
};

int main(){
    Rectangle my_rect;
    my_rect.set(10, 20);

    cout << "Area : " << my_rect.area() << endl;

    return 0;
}