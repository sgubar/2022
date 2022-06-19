#include <iostream>
#include <string.h>

using namespace std;

class Sensor {
private:
    int *storage;
    int size;
    float gainTime;

public:
    /* default constructor */
    Sensor() {
        storage = NULL;
        size = 0;
        gainTime = 0;
    }

    /* normal constructor */
    Sensor(int *values, int amount, float time) {
        storage = values;
        size = amount;
        gainTime = time;
    }      

    /* destructor */
    ~Sensor() {
        if (storage != nullptr)				
            delete storage;        
    }

     /* modificators */
    void setSize(int amount) {
        size = amount;
    }    

    void setValues(int *values) {
        if (storage != nullptr)				
            delete storage;        
        storage = values;
    }

    void setValuesManual() {
        storage = new int[size];
        cout << "Enter " << size << " values" << endl;
        for (int i = 0; i < size; i++) {
            cin >> storage[i];
        }
    }

    void setGainTime(float time) {
        gainTime = time;
    }

    int getValueAtIndex(int index) {
        if (index < 0 || index >= size) {
            cout << "value doesn't exist" << endl;
            return 0;         
        }
        return storage[index];             
    }   

    void printValues() {
            for (int i = 0; i < size; i++) {
                cout << "[" << i << "]: " << storage[i] << endl;
            }
        }

     void printSensor() {
        cout << "Values: " << endl;
        printValues();
        cout << "Array size: " << size << endl;
        cout << "Gain time: " << gainTime << endl;
     }

};

int main() {
    Sensor mySensor1;
    mySensor1.printSensor(); //check for default construction

    int values[] = {557, 23, 657, -23, -6, 4512};

    mySensor1.setValues(values);
    mySensor1.setSize(sizeof(values) / sizeof(values[0]));    
    mySensor1.setGainTime(3.54);

    Sensor mySensor2(NULL, 7, 8.77);
    cout << "Sensor2: " << endl;
    mySensor2.setValuesManual();  

    cout << "Sensor1: " << endl;
    mySensor1.printSensor();

    cout << "Value at index [" << 4 << "]: " << mySensor1.getValueAtIndex(4) << endl;
    cout << "Value at index [" << 7 << "]: " << mySensor1.getValueAtIndex(7) << endl;
    
    cout << "Sensor2: " << endl;
    mySensor2.printSensor();

    return 1;
}