#include <iostream>
#include <string.h>

//? Option 1

class Point {
private:
    int x, y;

public:
    void setCoordX(int new__X) {
        x = new__X;
    }
    void setCoordY(int new__Y) {
        y = new__Y;
    }

    int *getCoords() {
        int coords[] = {x, y};
        return coords;
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
    std::cout << "Point coords: [" << onePoint.getCoords()[0] << ", " << onePoint.getCoords()[1]<< "]\n" << std::endl;

    Point twoPoint(0, -10);
    
    Point copy__twoPoint = Point(twoPoint);
    copy__twoPoint.display();

    return 1;
}