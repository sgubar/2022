// ВАРІАНТ 1

#include <iostream>
#include <string.h>

class Point {
private:
    float x, y; 

public:
    void set_CoordX(float new__x) { 
        x = new__x;
    }
    void set_CoordY(float new__y) {
        y = new__y;
    }

    float get_X() { 
        return x;
    }

    float get_Y() {
        return y;
    }

    Point(float new__x, float new__y) { 
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
        std::cout << "Destroyed\n";
    }
};

int main(void) {
    Point onePoint;
    onePoint.set_CoordX(-3.4567);
    onePoint.set_CoordY(9.67);
    onePoint.display();
    std::cout << "Coords: [" << onePoint.get_X() << ", " << onePoint.get_Y() << "]\n" << std::endl;

    Point twoPoint(0, -10);

    Point copy__twoPoint = Point(twoPoint);
    copy__twoPoint.display();

    return 1;
}
