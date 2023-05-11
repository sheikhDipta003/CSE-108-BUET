# include <iostream>
using namespace std;

class Circle{
    int c_x, c_y, radius;

public:
    Circle(){}
    Circle(int x, int y, int r){    c_x = x;    c_y = y;    radius = r; }
    int getRadius(){    return radius;  }
    int getX(){    return c_x;  }
    int getY(){    return c_y;  }
    void setVal(int x, int y, int r){
        c_x = x;
        c_y = y;
        radius = r;
    }
};

class Rectangle{
    int v1_x, v2_x, v3_x, v4_x, v1_y, v2_y, v3_y, v4_y;

public:
    void setVal(int v1_x, int v2_x, int v3_x, int v4_x, int v1_y, int v2_y, int v3_y, int v4_y){
        this->v1_x = v1_x;
        this->v2_x = v2_x;
        this->v3_x = v3_x;
        this->v4_x = v4_x;
        this->v1_y = v1_y;
        this->v2_y = v2_y;
        this->v3_y = v3_y;
        this->v4_y = v4_y;
    }
    int isInscribed(Circle c){
        if(c.getX() + c.getRadius() <= v2_x && c.getX() - c.getRadius() >= v1_x && c.getY() + c.getRadius() <= v1_x && c.getY() - c.getRadius() >= v3_x){
            return 1;
        }
        else{
            return 0;
        }
    }
};

int main(){
    int circle_x, circle_y, rad;
    int v1_x, v2_x, v3_x, v4_x, v1_y, v2_y, v3_y, v4_y;

    Circle my_circle;
    Rectangle my_rect;

    cin >> circle_x >> circle_y >> rad;
    my_circle.setVal(circle_x, circle_y, rad);
    cin >> v1_x >> v2_x >> v3_x >> v4_x >>v1_y >>v2_y >> v3_y >> v4_y; 
    my_rect.setVal(v1_x, v2_x, v3_x, v4_x, v1_y, v2_y, v3_y, v4_y);

    if(my_rect.isInscribed(my_circle) == 1){
        cout << "Inscribed" << endl << endl;
    }
    else{
        cout << "Not inscribed" << endl << endl;
    }

    return 0;
}