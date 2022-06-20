#include <iostream>
#include <string.h>

/*
Варіант 1
Клас точки Point: координата х, координата у
*/

class Point {
private:
    int x, y; // значення за замовчуванням

public:
    /*
    17-22 присвоєння параметрів
    */
    void getCoordX(int inputX) {
        x = inputX;
    }
    void getCoordY(int inputY) {
        y = inputY;
    }
    /*
    26-32 повернення значень
    */
    int getX() {
        return x;
    }

    int getY() {
        return y;
    }
    /*
    38-40 - виведення
    42-46 - створення нових об'єктів
    48-55 - конструкт за замовчуванням та десструкт
    */
    void displayPoint() {
        std::cout << "Point:\nx: " << x << "\ny: " << y << "\n\n";
    }

    Point(int inputX, int inputY) {
        x = inputX;
        y = inputY;
        displayPoint();
    }

    Point() {
        x = 0;
        y = 0;
    }

    ~Point() {
        std::cout << "Point deleted\n";
    }
};

int main(void) {
    /*
    64-66 - перший спосіб задання інформаціїї
    70 - другий спосіб заданняінформації
    72-73 - приклад копіювання
    */
    Point A;
    A.getCoordX(0);
    A.getCoordY(1);
    A.displayPoint();
    std::cout << "Point coords: (" << A.getX() << ", " << A.getY() << ")\n" << std::endl;

    Point B(5, -9);

    Point B1 = Point(B);
    B1.displayPoint();

    return 1;
}
