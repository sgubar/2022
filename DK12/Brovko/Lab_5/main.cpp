#include <iostream>
#include <string.h>

// Варік 1

class Point
{
protected:
    double x, y;

public:
    void set_Cord_X(double new_x)
    {
        x = new_x;
    }
    void set_Cord_Y(double new_y)
    {
        y = new_y;
    }

    double get_X()
    {
        return x;
    }

    double get_Y()
    {
        return y;
    }

    Point(double new_x, double new_y)
    {
        x = new_x;
        y = new_y;
        display();
    }

    Point()
    {
        x = 0;
        y = 0;
    }

    void display()
    {
        std::cout << "\nТочка X: " << x << ", Точка Y: " << y << "\n";
    }

    ~Point()
    {
        std::cout << "Об'єкт знищено !\n";
    }
};

int main(void)
{
    Point onePoint;
    onePoint.set_Cord_X(-5);
    onePoint.set_Cord_Y(12);
    onePoint.display();
    std::cout << "Координати Точки: " << onePoint.get_X() << ", " << onePoint.get_Y() << "\n"
              << std::endl;

    Point twoPoint(7, -3);

    Point copy__twoPoint = Point(twoPoint);
    copy__twoPoint.display();

    return 1;
}
