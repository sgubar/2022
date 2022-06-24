///1 variant ///
#include <iostream>
#include <string.h>

class Point
{
private:
    int x, y;

public:
    void setCoord_X(int new_x)
    {
        x = new_x;
    }
    void setCoord_Y(int new_y) 
    {
        y = new_y;
    }

    int get_X()
    {
        return x;
    }

    int get_Y()
    {
        return y;
    }

    Point(int new_x, int new_y)
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
        std::cout << "\n Точка X: " << x << ", Точка Y: " << y << "\n";
    }

    ~Point()
    {
        std::cout << " Обєкт знищений \n";
    }
};

int main(void)
{
    Point onePoint;
    onePoint.setCoordX(-12);
    onePoint.setCoordY(33);
    onePoint.display();
    std::cout << "Координати точки : [" << onePoint.get_X() << ", " << onePoint.get_Y() << "]\n" << std::endl;

    Point twoPoint(2, -11);
    
    Point copy__twoPoint = Point(twoPoint);
    copy__twoPoint.display();

    return 1;
}
