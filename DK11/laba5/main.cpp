#include <iostream> /// 1 варіант ///
#include <string.h>
class Point {
private:
    int x, y;

public:
    void setCoordX(int new__x) 
    {
        x = new__x;
    }
    void setCoordY(int new__y)
    {
        y = new__y;
    }

    int getX()
    {
        return x;
    }

    int getY() 
    {
        return y;
    }

    Point(int new__x, int new__y) 
    {
        x = new__x;
        y = new__y;
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
        std::cout << "Об'єкт знищено !\n";
    }
};

int main(void) 
{
    Point onePoint;
    onePoint.setCoordX(-1);
    onePoint.setCoordY(3);
    onePoint.display();
    std::cout << "Координати точки: [" << onePoint.getX() << ", " << onePoint.getY() << "]\n" << std::endl;

    Point twoPoint(2, -12);
    
    Point copy__twoPoint = Point(twoPoint);
    copy__twoPoint.display();

    return 1;
}
