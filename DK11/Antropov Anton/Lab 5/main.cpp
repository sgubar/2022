#include <iostream>
#include <string.h>
// Варіант 1
class Point
{
protected:
    double x, y;

public:
    void setCordX(double newx) // задання координати x
    {
        x = newx;
    }
    void setCordY(double newy) // задання координати y
    {
        y = newy;
    }

    double getX()
    {
        return x;
    }

    double getY()
    {
        return y;
    }

    Point(double newx, double newy)
    {
        x = newx;
        y = newy;
        display();
    }

    Point()
    {
        x = 0;
        y = 0;
    }

    void display()
    {
        std::cout << "\nPoint X: " << x << ", Point Y: " << y << "\n";
    }

    ~Point()
    {
        std::cout << "destroyed\n";
    }
};

int main(void)
{
    Point point;
    point.setCordX(14);
    point.setCordY(3);
    point.display();
    std::cout << "Point cords: " << point.getX() << "," << point.getY() << "\n" << std::endl;
    Point secondpoint(-9,6);
    Point copy__secondpoint = Point(secondpoint);
    copy__secondpoint.display();
    return 1;
}
