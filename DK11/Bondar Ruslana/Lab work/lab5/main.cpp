#include <iostream>
#include <string.h>
using namespace std;

///////////////
//           //
// ВАРІАНТ 2 //
//           //
///////////////

//Клас давача Sensor: масив накопичених значень – масив цілих чисел,
//  кількість накопичених значень, час накопичення – дійсне число  секунд.
class Sensor
{
private:
    int *values, count, time; // значення за замовчуванням

public:
    void set_Values(int new__values[]) // модифікатор
    {
        values = new__values;
    }

    void set_Count(int new__count)
    {
        count = new__count;
    }

    void set_Time(int new__time)
    {
        time = new__time;
    }

    int get_Value(int index) // селектор
    {
        if (index >= count )
            exit(0);
        return values[index];
    }

    Sensor(int *new__values, int new__count, int new__time) // конструктор для нових об'єктів
    {
        values = new__values;
        count = new__count;
        time = new__time;
        display();
    }

    Sensor()  // конструктор за замовчуванням
    {
        values = 0;
        time = 0;
    }

    void display() // виведення
    {
        cout << "Values: ";
        for (int i = 0; i < count; i++)
        {
            cout << values[i] << ", ";
        }
        cout << "\nCount values: " << count << "\nTime: " << time << "\n" << endl;
    }

    ~Sensor() // деструктор
    {
        cout << "Sensor destroyed\n"; // отримаемо повідомлення декілька разів(залежить від кількості об'єктів зроблених через конструктор)
    }
};
int main(void) //  приклад роботи програми
{
    Sensor Sensor1; // перший спосіб задання інформації
    int values[] = {1, 7, 34, 6, 21, 12};
    Sensor1.set_Values(values);
    Sensor1.set_Count(sizeof(values) / sizeof(values[0]));
    Sensor1.set_Time(765);
    Sensor1.display();
    int index = 4;
    cout << "Index " << index << " is the value \"" << Sensor1.get_Value(index) << "\"\n" << endl;// приклад роботи селектора

    int values2[] = {11, 0, -4, 2}; // другий спосіб задання інформації
    Sensor Sensor2(values2, sizeof(values2) / sizeof(values2[0]), 100);


    return 1;
}

