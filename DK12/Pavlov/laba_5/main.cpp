#include <iostream>
#include <string.h>
using namespace std;

/* Варіант 2 */

class Sensor
{
private:
    int *values, count, time;

public:
    void setValues(int new__values[])
    {
        values = new__values;
    }

    void setCout(int new__count)
    {
        count = new__count;
    }

    void setTime(int new__time)
    {
        time = new__time;
    }

    int getValue(int index)
    {
        if (index >= count)
            exit(0);
        return values[index];
    }

    Sensor(int *new__values, int new__count, int new__time)
    {
        values = new__values;
        count = new__count;
        time = new__time;
        display();
    }

    Sensor()
    {
        values = 0;
        time = 0;
    }

    void display()
    {
        cout << "Values: ";
        for (int i = 0; i < count; i++)
        {
            cout << values[i] << ", ";
        }
        cout << "\nCount values: " << count << "\nTime: " << time << "\n" << endl;
    }

    ~Sensor()
    {
        cout << "Sensor destroyed\n";
    }
};

int main(void)
{
    Sensor Sensor1;
    int values[] = {1, 7, 34, 6, 3, 0, -10, 21, 12};
    Sensor1.setValues(values);
    Sensor1.setCout(sizeof(values) / sizeof(values[0]));
    Sensor1.setTime(246);
    Sensor1.display();
    int index = 3;
    cout << "Index " << index << " is the value \"" << Sensor1.getValue(index) << "\"\n" << endl;

    int values2[] = {11, 0, -4, 64, 2};
    Sensor Sensor2(values2, sizeof(values2) / sizeof(values2[0]), 100);

    Sensor copy__Sensor2 = Sensor(Sensor2);
    copy__Sensor2.display();

    return 1;
}