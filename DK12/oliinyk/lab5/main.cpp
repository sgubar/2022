#include <iostream>
#include <string.h>

//? Option 1

class Point {
private:
    int x, y;

public:
    void setCoordX(int new__x) {
        x = new__x;
    }
    void setCoordY(int new__y) {
        y = new__y;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    Point(int new__x, int new__y) {
        x = new__x;
        y = new__y;
        display();
    }

    Point() {
        x = 0;
        y = 0;
    }

    void display() {
        std::cout << "\nPoint X: " << x << ", Point Y: " << y << "\n";
    }

    ~Point() {
        std::cout << "Object destroyed\n";
    }
};

int main(void) {
    Point onePoint;
    onePoint.setCoordX(-3);
    onePoint.setCoordY(9);
    onePoint.display();
    std::cout << "Point coords: [" << onePoint.getX() << ", " << onePoint.getY() << "]\n" << std::endl;

    Point twoPoint(0, -10);
    
    Point copy__twoPoint = Point(twoPoint);
    copy__twoPoint.display();

    return 1;
}