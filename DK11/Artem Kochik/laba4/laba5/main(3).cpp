#include <iostream>
#include <string.h>
/// 1 variant ///
class Point
{
private:
    float x, y;

public:
    void setCoord_X(float new_x)
    {
        x = new_x;
    }
    void setCoord_Y(float new_y)
    {
        y = new_y;
    }

    float get_X()
    {
        return x;
    }

    float get_Y()
    {
        return y;
    }

    Point(float new_x, float new_y)
    {
        x = new_x;
        y = new_y;
        //display();
    }

    Point()
    {
        x = 0;
        y = 0;
    }

    void display()
    {
        std::cout << "\n Point X: " << x << ", Point Y: " << y << "\n";
    }

    ~Point()
    {
        std::cout << " Point delete \n";
    }
};

int main(void)
{
    Point onePoint;
    onePoint.setCoord_X(-12.1);
    onePoint.setCoord_Y(33.5);
    onePoint.display();
    std::cout << "Coordinates of points : [" << onePoint.get_X() << ", " << onePoint.get_Y() << "]\n" << std::endl;

    Point twoPoint(2.3, -11.5);

    Point copy__twoPoint = Point(twoPoint);
    copy__twoPoint.display();

    return 1;
}
